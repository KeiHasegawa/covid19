#include <unistd.h>

#include <map>
#include <vector>
#include <iostream>
#include <tuple>
#include <sstream>
#include <fstream>

using namespace std;

struct info_t {
  map<int, int> tm;
  vector<pair<int, int> > gn;
  tuple<int, int, int> pl;
};

map<pair<double, double>, info_t> g_crow_data;

map<int, vector<tuple<double, double, int> > > conv;

void build(const pair<double, double>& pt, const pair<int, int>& u)
{
  auto x = pt.first;
  auto y = pt.second;
  auto z = u.second;
  auto t = u.first;
  conv[t].push_back(make_tuple(y, x, z));
}

void build(const pair<pair<double, double>, info_t>& x)
{
  auto pt = x.first;
  for (const auto& y : x.second.tm)
    build(pt, y);
}

void out_data(ostream& out ,const tuple<double, double, int>& t)
{
  auto x = get<0>(t);
  auto y = get<1>(t);
  auto z = get<2>(t);
  out << x << ' ' << y << ' ' << z << '\n';
}

void out_map(ostream& os, const pair<double, double>& p)
{
  auto x = p.first;
  auto y = p.second;
  os << x << ' ' << y << ' ' << "0.0" << '\n';
}

void out_map(ostream& os, const vector<pair<double, double> >& v)
{
  for (const auto& p : v)
    out_map(os, p);
}

extern vector<pair<double, double> > okinawa;

const string map_nm = "kansai.map";

void out_map()
{
  ofstream ofs(map_nm);
  out_map(ofs, okinawa);
}

string onm(time_t t)
{
  auto tm = localtime(&t);
  auto ptr = asctime(tm);
  string s = ptr;
  auto pos = s.find_last_of('\n');
  if (pos != string::npos)
    s.erase(pos);
  for (string::size_type p = 0 ; ; ++p) {
    p = s.find_first_of(' ', p);
    if (p == string::npos)
      break;
    s[p] = '_';
  }
  return s;
}

void out_data(const pair<int, vector<tuple<double, double, int> > >& p)
{
  ostringstream os;
  os << onm(p.first);
  ofstream ofs(os.str());
  for (const auto& x : p.second)
    out_data(ofs, x);
}

void out_header()
{
  cout << "#! /usr/local/bin/gnuplot\n";
  cout << '\n';
  cout << "n=0\n";
}

void out_script1(int t, bool pause)
{
  cout << "set zrange [0:10000]\n";
  cout << "splot " << '"' << onm(t) << '"' << " with impulses, ";
  cout << '"' << map_nm << '"' << " with dots" << '\n';
  cout << "if (n) pause -1 \"Hit return to continue\"\n";
  cout << "reset\n";
}

void out_footer()
{
  cout << "pause -1 \"Hit return to continue\"\n";
}

void out_script(bool pause)
{
  out_header();
  for (const auto& x : conv)
    out_script1(x.first, pause);
  out_footer();
}

inline void usage(const char* prog)
{
  cerr << "usage % " << prog << "[-n]\n";
}

int main(int argc, char** argv)
{
  bool pause = true;
  for (int opt; (opt = getopt(argc, argv, "n")) != -1 ; ) {
    switch (opt) {
    case 'n' : pause = false; break;
    default: usage(argv[0]); return 1;
    }
  }

  if (optind != argc) {
    usage(argv[0]);
    return 1;
  }
  
  for (const auto& x : g_crow_data)
    build(x);

  for (const auto& x : conv)
    out_data(x);

  out_map();
  
  out_script(pause);
    
  return 0;
}
