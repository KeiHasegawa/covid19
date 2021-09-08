#include <iostream>
#include <fstream>
#include <map>
#include <cassert>
#include <vector>
#include <sstream>

#include <unistd.h>

using namespace std;

inline void usage(const char* prog)
{
  cerr << "usage % " << prog << " file\n";
}

enum class ShapeType {
  NullShape = 0,
  Point = 1,
  PolyLine = 3,
  Polygon = 5,
  MultiPoint = 8,
  PointZ = 11,
  PolyLineZ = 13,
  PolygonZ = 15,
  MultiPointZ = 18,
  PointM = 21,
  PolyLineM = 23,
  PolygonM = 25,
  MultiPointM = 28,
  MultiPatc = 31
};

struct FileHeader {
  uint32_t length;
  uint32_t version;
  ShapeType type;
  double bounding_box[8];
};

uint32_t read_32b(istream& is)
{
  uint32_t ret = 0;
  for (int i = 0 ; i != 4; ++i) {
    ret <<= 8;
    ret |= is.get();
  }
  return ret;
}

uint32_t read_32l(istream& is)
{
  union {
    uint32_t v;
    char c[4];
  } u = {read_32b(is)};
  swap(u.c[0], u.c[3]);
  swap(u.c[1], u.c[2]);
  return u.v;
}

double read_double(istream& is)
{
  union {
    char c[8];
    double d;
  } u;
  for (int i = 0 ; i != sizeof u.c/sizeof u.c[0]; ++i)
    u.c[i] = is.get();
  return u.d;
}

void rd(istream& is, FileHeader& fh)
{
  auto file_code = read_32b(is);
  if (file_code != 9994) {
    is.setstate(ios_base::badbit);
    return;
  }
  for (int i = 0 ; i != 5 ; ++i) {
    if (read_32b(is) != 0) {
      is.setstate(ios_base::badbit);
      return;
    }
  }
  fh.length = read_32b(is);
  fh.version = read_32l(is);
  if (fh.version != 1000) {
    is.setstate(ios_base::badbit);
    return;
  }
  fh.type = (ShapeType)read_32l(is);

  int N = sizeof fh.bounding_box/sizeof fh.bounding_box[0];
  for (int i = 0 ; i != N ; ++i)
    fh.bounding_box[i] = read_double(is);
}

struct RecordHeader {
  uint32_t number;
  uint32_t length;
};

void rd(istream& is, RecordHeader& rh)
{
  rh.number = read_32b(is);
  rh.length = read_32b(is);
}

struct rect {
  pair<double, double> top_left;
  pair<double, double> bottom_right;
};

inline double width(const rect& r)
{
  return r.bottom_right.first - r.top_left.first;
}

inline bool include(const rect& r, pair<double, double> p)
{
  auto x = p.first;
  if (r.bottom_right.first < x)
    return false;
  if (x < r.top_left.first)
    return false;
  auto y = p.second;
  if (r.top_left.second < y)
    return false;
  if (y < r.bottom_right.second)
    return false;
  return true;
}

struct Shape {
  ShapeType id;
  Shape(ShapeType i) : id{i} {}
  virtual bool rd(istream& is, bool all, const rect& area) const
  {
    ShapeType type = (ShapeType)read_32l(is);
    if (type != id) {
      assert(type == (ShapeType)-1);
      return false;
    }
    return true;
  }
};

struct Point : Shape {
  Point(ShapeType id = ShapeType::Point) : Shape(id) {}
  bool common(istream& is, bool all, const rect& area, bool newline) const
  {
    if (!Shape::rd(is, all, area))
      return false;
    auto x = read_double(is);
    auto y = read_double(is);
    if (width(area)) {
      if (!include(area, make_pair(x,y)))
	return true;
    }
    cout << x << ' ' << y;
    if (newline)
      cout << '\n';
    return true;
  }
  bool rd(istream& is, bool all, const rect& area) const override
  {
    return common(is, all, area, true);
  }
};

struct PointZ : Point {
  PointZ() : Point(ShapeType::PointZ) {}
  bool rd(istream& is, bool all, const rect& area) const override
  {
    if (!Point::common(is, all, area, false))
      return false;
    auto z = read_double(is);
    auto m = read_double(is);
    cout << z << ' ' << m << '\n';
    return true;
  }
};

struct PolyLine : Shape {
  PolyLine(ShapeType id = ShapeType::PolyLine) : Shape(id) {}
  bool
  common(istream& is, bool all, const rect& area, uint32_t* npoints_p) const
  {
    if (!Shape::rd(is, all, area))
      return false;
    double bounding_box[4];
    for (int i = 0 ; i != sizeof bounding_box/sizeof bounding_box[0] ; ++i)
      bounding_box[i] = read_double(is);
    auto nparts = read_32l(is);
    auto npoints = read_32l(is);
    if (npoints_p)
      *npoints_p = npoints;
    vector<uint32_t> parts;
    for (int i = 0 ; i != nparts ; ++i)
      parts.push_back(read_32l(is));
    vector<pair<double, double> > points;
    auto w = width(area);
    for (int i = 0 ; i != npoints ; ++i) {
      auto x = read_double(is);
      auto y = read_double(is);
      auto p = make_pair(x, y);
      points.push_back(p);
      if (w) {
	if (!include(area, p))
	  continue;
      }
      if (all)
	cout << x << ' ' << y << '\n';		
      else {
	if (!(i % 16))
	  cout << x << ' ' << y << '\n';
      }
    }
    return true;
  }
  bool rd(istream& is, bool all, const rect& area) const override
  {
    return common(is, all, area, nullptr);
  }
};

struct PolyLineZ : PolyLine {
  PolyLineZ() : PolyLine(ShapeType::PolyLineZ) {}
  bool rd(istream& is, bool all, const rect& area) const override
  {
    uint32_t npoints;
    if (!PolyLine::common(is, all, area, &npoints))
      return false;
    auto zmin = read_double(is);
    auto zmax = read_double(is);
    vector<double> zz;
    for (int i = 0 ; i != npoints ; ++i) {
      auto z = read_double(is);
      zz.push_back(z);
    }
    auto mmin = read_double(is);
    auto mmax = read_double(is);
    vector<double> mm;
    for (int i = 0 ; i != npoints ; ++i) {
      auto m = read_double(is);
      mm.push_back(m);
    }
    return true;
  }
};

struct Polygon : Shape {
  Polygon(ShapeType id = ShapeType::Polygon) : Shape(id) {}
  bool
  common(istream& is, bool all, const rect& area, uint32_t* npoints_p) const
  {
    if (!Shape::rd(is, all, area))
      return false;
    double bounding_box[4];
    for (int i = 0 ; i != sizeof bounding_box/sizeof bounding_box[0] ; ++i)
      bounding_box[i] = read_double(is);
    auto nparts = read_32l(is);
    auto npoints = read_32l(is);
    if (npoints_p)
      *npoints_p = npoints;
    vector<uint32_t> parts;
    for (int i = 0 ; i != nparts ; ++i)
      parts.push_back(read_32l(is));
    vector<pair<double, double> > points;
    auto w = width(area);
    for (int i = 0 ; i != npoints ; ++i) {
      auto x = read_double(is);
      auto y = read_double(is);
      auto p = make_pair(x, y);
      points.push_back(p);
      if (w) {
	if (!include(area, p))
	  continue;
      }
      if (all)
	cout << x << ' ' << y << '\n';
      else {
	if (!(i % 16))
	  cout << x << ' ' << y << '\n';
      }
    }
    return true;
  }
  bool rd(istream& is, bool all, const rect& area) const override
  {
    return common(is, all, area, nullptr);
  }
};

struct PolygonZ : Polygon {
  PolygonZ() : Polygon(ShapeType::PolygonZ) {}
  bool rd(istream& is, bool all, const rect& area) const override
  {
    uint32_t npoints;
    if (!Polygon::common(is, all, area, &npoints))
      return false;
    auto zmin = read_double(is);
    auto zmax = read_double(is);
    vector<double> zz;
    for (int i = 0 ; i != npoints ; ++i) {
      auto z = read_double(is);
      zz.push_back(z);
    }
    auto mmin = read_double(is);
    auto mmax = read_double(is);
    vector<double> mm;
    for (int i = 0 ; i != npoints ; ++i) {
      auto m = read_double(is);
      mm.push_back(m);
    }
    return true;
  }
};

struct table_t : map<ShapeType, Shape*> {
  table_t()
  {
    (*this)[ShapeType::Point] = new Point;
    (*this)[ShapeType::PolyLine] = new PolyLine;
    (*this)[ShapeType::Polygon] = new Polygon;
    (*this)[ShapeType::PointZ] = new PointZ;
    (*this)[ShapeType::PolyLineZ] = new PolyLineZ;
    (*this)[ShapeType::PolygonZ] = new PolygonZ;
  }
} table;

void coord(const char* s, rect* r)
{
  istringstream ist(s);
  ist >> r->top_left.first;
  assert(ist.get() == ',');
  ist >> r->top_left.second;
  assert(ist.get() == ',');
  ist >> r->bottom_right.first;
  assert(ist.get() == ',');
  ist >> r->bottom_right.second;
}


int main(int argc, char** argv)
{
  bool all = true;
  rect area;
  for (int opt ; (opt = getopt(argc, argv, "pc:")) != -1 ; ) {
    switch (opt) {
    case 'p': all = false; break;
    case 'c': coord(optarg, &area); break;
    case '?':
    default:
      usage(argv[0]); return 1;
    }
  }
  
  if (argc-1 != optind) {
    usage(argv[0]);
    return 1;
  }
  
  ifstream ifs(argv[optind]);
  if (!ifs) {
    cerr << "Cannot open " << argv[1] << '\n';
    return 1;
  }

  FileHeader fh;
  rd(ifs, fh);
  
  auto p = table.find(fh.type);
  assert(p != table.end());
  auto ptr = p->second;

  while (!ifs.eof()) {
    RecordHeader rh;
    rd(ifs, rh);
    ptr->rd(ifs, all, area);
  }
  return 0;
}
