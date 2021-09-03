#include <unistd.h>

#include <map>
#include <vector>
#include <iostream>
#include <tuple>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cassert>

using namespace std;

struct info_t {
  map<int, int> tm;
  vector<pair<int, int> > gn;
  tuple<int, int, int> pl;
};

map<string, map<pair<double, double>, info_t> > g_crow_data;

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

void build(const pair<string, map<pair<double, double>, info_t> >& p,
	   const vector<string>& prefs)
{
  auto s = p.first;
  if (find(begin(prefs), end(prefs), s) == end(prefs))
    return;
  for (const auto& x : p.second)
    build(x);
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

extern vector<pair<double, double> > gunma;
extern vector<pair<double, double> > tochigi;
extern vector<pair<double, double> > ibaraki;
extern vector<pair<double, double> > saitama;
extern vector<pair<double, double> > chiba;
extern vector<pair<double, double> > tokyo;
extern vector<pair<double, double> > kanagawa;
extern vector<pair<double, double> > osaka;
extern vector<pair<double, double> > hyougo;
extern vector<pair<double, double> > nara;
extern vector<pair<double, double> > kyoto;
extern vector<pair<double, double> > wakayama;
extern vector<pair<double, double> > shiga;
extern vector<pair<double, double> > okinawa;
extern vector<pair<double, double> > hokkaido;
extern vector<pair<double, double> > aichi;
extern vector<pair<double, double> > hukuoka;
extern vector<pair<double, double> > miyagi;
extern vector<pair<double, double> > shizuoka;
extern vector<pair<double, double> > hiroshima;
extern vector<pair<double, double> > aomori;
extern vector<pair<double, double> > iwate;
extern vector<pair<double, double> > akita;
extern vector<pair<double, double> > yamagata;
extern vector<pair<double, double> > hukushima;
extern vector<pair<double, double> > niigata;
extern vector<pair<double, double> > toyama;
extern vector<pair<double, double> > ishikawa;
extern vector<pair<double, double> > hukui;
extern vector<pair<double, double> > yamanashi;
extern vector<pair<double, double> > nagano;

struct map_map : map<string, vector<pair<double, double> >*> {
  map_map()
  {
    (*this)["Gunma"] = &gunma;
    (*this)["Tochigi"] = &tochigi;
    (*this)["Ibaraki"] = &ibaraki;
    (*this)["Saitama"] = &saitama;
    (*this)["Chiba"] = &chiba;
    (*this)["Tokyo"] = &tokyo;
    (*this)["Kanagawa"] = &kanagawa;
    (*this)["Osaka"] = &osaka;
    (*this)["Hyougo"] = &hyougo;
    (*this)["Nara"] = &nara;
    (*this)["Kyoto"] = &kyoto;
    (*this)["Wakayama"] = &wakayama;
    (*this)["Shiga"] = &shiga;
    (*this)["Okinawa"] = &okinawa;
    (*this)["Hokkaido"] = &hokkaido;
    (*this)["Aichi"] = &aichi;
    (*this)["Hukuoka"] = &hukuoka;
    (*this)["Miyagi"] = &miyagi;
    (*this)["Shizuoka"] = &shizuoka;
    (*this)["Hiroshima"] = &hiroshima;

    (*this)["Aomori"] = &aomori;
    (*this)["Iwate"] = &iwate;
    (*this)["Akita"] = &akita;
    (*this)["Yamagata"] = &yamagata;
    (*this)["Hukushima"] = &hukushima;
    (*this)["Niigata"] = &niigata;
    (*this)["Toyama"] = &toyama;
    (*this)["Ishikawa"] = &ishikawa;
    (*this)["Hukui"] = &hukui;
    (*this)["Yamanashi"] = &yamanashi;
    (*this)["Nagano"] = &nagano;
  }
} map_map;

const string map_nm = "area.map";

void out_map(const vector<string>& prefs)
{
  ofstream ofs(map_nm);
  for (const auto& x : prefs)
    out_map(ofs, *map_map[x]);
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

void out_script1(int t, bool pause, int range)
{
  cout << "set zrange [0:" << range << "]\n";
  cout << "splot " << '"' << onm(t) << '"' << " with impulses, ";
  cout << '"' << map_nm << '"' << " with dots" << '\n';
  cout << "if (n) pause -1 \"Hit return to continue\"\n";
  cout << "reset\n";
}

void out_footer()
{
  cout << "pause -1 \"Hit return to continue\"\n";
}

void out_script(bool pause, int range)
{
  out_header();
  for (const auto& x : conv)
    out_script1(x.first, pause, range);
  out_footer();
}

inline void usage(const char* prog)
{
  cerr << "usage % " << prog << "Tokyo [-n]\n";
}

bool chose(string area, vector<string>& prefs)
{
  auto p = map_map.find(area);
  if (p != map_map.end()) {
    prefs.push_back(area);
    return true;
  }

  if (area == "chikasato" || area == "Kanto") {
    prefs.push_back("Chiba");
    prefs.push_back("Kanagawa");
    prefs.push_back("Saitama");
    prefs.push_back("Tokyo");
    if (area == "chikasato")
      return true;
    prefs.push_back("Ibaraki");
    prefs.push_back("Tochigi");
    prefs.push_back("Gunma");
    return true;
  }

  if (area == "Kansai") {
    prefs.push_back("Osaka");
    prefs.push_back("Hyougo");
    prefs.push_back("Kyoto");
    prefs.push_back("Shiga");
    prefs.push_back("Nara");
    prefs.push_back("Wakayama");
    return true;
  }

  cerr << "Unknown area : `" << area << "'\n"; 
  return false;
}

struct range_data : map<string, int> {
  range_data()
  {
    (*this)["Gunma"] = 7500;
    (*this)["Tochigi"] = 4000;
    (*this)["Ibaraki"] = 4000;
    (*this)["Saitama"] = 40000;
    (*this)["Chiba"] = 15000;
    (*this)["Tokyo"] = 40000;
    (*this)["Kanagawa"] = 40000;
    (*this)["Osaka"] = 40000;
    (*this)["Hyougo"] = 10000;
    (*this)["Nara"] = 7500;
    (*this)["Kyoto"] = 7500;
    (*this)["Wakayama"] = 7500;
    (*this)["Shiga"] = 4000;
    (*this)["Okinawa"] = 10000;
    (*this)["Hokkaido"] = 30000;
    (*this)["Aichi"] = 30000;
    (*this)["Hukuoka"] = 30000;
    (*this)["Miyagi"] = 20000;
    (*this)["Shizuoka"] = 10000;
    (*this)["Hiroshima"] = 10000;
    (*this)["Aomori"] = 3000;
    (*this)["Iwate"] = 4000;
    (*this)["Akita"] = 3000;
    (*this)["Yamagata"] = 3000;
    (*this)["Hukushima"] = 3000;
    (*this)["Niigata"] = 5000;
    (*this)["Toyama"] = 5000;
    (*this)["Ishikawa"] = 5000;
    (*this)["Hukui"] = 5000;
    (*this)["Yamanashi"] = 3000;
    (*this)["Nagano"] = 5000;
  }
} range_data;

int get_range(string s)
{
  auto p = range_data.find(s);
  assert(p != range_data.end());
  return p->second;
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

  if (optind != argc-1) {
    usage(argv[0]);
    return 1;
  }

  string area = argv[optind];
  vector<string> prefs;
  if (!chose(area, prefs))
    return 1;
  
  for (const auto& x : g_crow_data)
    build(x, prefs);

  for (const auto& x : conv)
    out_data(x);

  out_map(prefs);

  vector<int> ranges;
  transform(begin(prefs), end(prefs), back_inserter(ranges), get_range);
  auto p = max_element(begin(ranges), end(ranges));
  assert(p != end(ranges));
  out_script(pause, *p);
    
  return 0;
}
