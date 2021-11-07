#include <sys/stat.h>
#include <dlfcn.h>
#include <unistd.h>

#include <map>
#include <vector>
#include <iostream>
#include <tuple>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iterator>

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
extern vector<pair<double, double> > gihu;
extern vector<pair<double, double> > mie;
extern vector<pair<double, double> > tottori;
extern vector<pair<double, double> > shimane;
extern vector<pair<double, double> > okayama;
extern vector<pair<double, double> > yamaguchi;
extern vector<pair<double, double> > tokushima;
extern vector<pair<double, double> > kagawa;
extern vector<pair<double, double> > ehime;
extern vector<pair<double, double> > kouchi;
extern vector<pair<double, double> > saga;
extern vector<pair<double, double> > nagasaki;
extern vector<pair<double, double> > kumamoto;
extern vector<pair<double, double> > ooita;
extern vector<pair<double, double> > miyazaki;
extern vector<pair<double, double> > kagoshima;

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
    (*this)["Gihu"] = &gihu;
    (*this)["Mie"] = &mie;
    (*this)["Tottori"] = &tottori;
    (*this)["Shimane"] = &shimane;
    (*this)["Okayama"] = &okayama;
    (*this)["Yamaguchi"] = &yamaguchi;
    (*this)["Tokushima"] = &tokushima;
    (*this)["Kagawa"] = &kagawa;
    (*this)["Ehime"] = &ehime;
    (*this)["Kouchi"] = &kouchi;
    (*this)["Saga"] = &saga;
    (*this)["Nagasaki"] = &nagasaki;
    (*this)["Kumamoto"] = &kumamoto;
    (*this)["Ooita"] = &ooita;
    (*this)["Miyazaki"] = &miyazaki;
    (*this)["Kagoshima"] = &kagoshima;
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

void out_header(ostream& os)
{
  os << "#! /usr/local/bin/gnuplot\n";
  os << '\n';
  os << "n=0\n";
}

void out_script1(ostream& os, int t, bool pause, int range, time_t b, time_t e)
{
  if (b) {
    if (t < b)
      return;
  }
  if (e) {
    if (e <= t)
      return;
  }
  os << "set zrange [0:" << range << "]\n";
  os << "splot " << '"' << onm(t) << '"' << " with impulses, ";
  os << '"' << map_nm << '"' << " with dots" << '\n';
  os << "if (n) pause -1 \"Hit return to continue\"\n";
  os << "reset\n";
}

void out_footer(ostream& os)
{
  os << "pause -1 \"Hit return to continue\"\n";
}

void out_script(ostream& os, bool pause, int range, time_t b, time_t e)
{
  out_header(os);
  for (const auto& x : conv)
    out_script1(os, x.first, pause, range, b, e);
  out_footer(os);
}

inline void usage(const char* prog)
{
  cerr << "usage % " << prog << " Tokyo [-n][-b 2021.08.01][-e 2021.08.02]\n";
  cerr << "or\n";
  cerr << "usage % " << prog << " -s Nihonbashi\n";
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

  if (area == "Shikoku") {
    prefs.push_back("Tokushima");
    prefs.push_back("Kagawa");
    prefs.push_back("Ehime");
    prefs.push_back("Kouchi");
    return true;
  }

  if (area == "Kyushuu") {
    prefs.push_back("Hukuoka");
    prefs.push_back("Saga");
    prefs.push_back("Nagasaki");
    prefs.push_back("Kumamoto");
    prefs.push_back("Ooita");
    prefs.push_back("Miyazaki");
    prefs.push_back("Kagoshima");
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
    (*this)["Gihu"] = 7000;
    (*this)["Mie"] = 5000;
    (*this)["Tottori"] = 5000;
    (*this)["Shimane"] = 3000;
    (*this)["Okayama"] = 10000;
    (*this)["Yamaguchi"] = 3000;
    (*this)["Tokushima"] = 3000;
    (*this)["Kagawa"] = 4000;
    (*this)["Ehime"] = 7000;
    (*this)["Kouchi"] = 4000;
    (*this)["Saga"] = 4000;
    (*this)["Nagasaki"] = 15000;
    (*this)["Kumamoto"] = 4000;
    (*this)["Ooita"] = 4000;
    (*this)["Miyazaki"] = 3000;
    (*this)["Kagoshima"] = 7500;
  }
} range_data;

int get_range(string s)
{
  auto p = range_data.find(s);
  assert(p != range_data.end());
  return p->second;
}

time_t get_day(const char* s)
{
  istringstream ist(s);
  int y;
  ist >> y;
  assert(ist.get() == '.');
  int m;
  ist >> m;
  assert(ist.get() == '.');
  int d;
  ist >> d;
  tm buf = { .tm_mday = d, .tm_mon = m-1, .tm_year = y-1900 };
  return timelocal(&buf);
}

struct spots_t : map<string, pair<string, pair<double, double> > > {
  spots_t()
  {
    (*this)["Nihonbashi"] = {"Tokyo", {35.68123,139.774534}};
    (*this)["Marunouchi"] = {"Tokyo", {35.680478,139.765367}};
    (*this)["Ootemachi"] = {"Tokyo", {35.687438,139.764955}};
    (*this)["Ginza"] = {"Tokyo", {35.669626,139.765539}};
    (*this)["Shinbashi"] = {"Tokyo", {35.664917,139.757003}};
    (*this)["Toranomon"] = {"Tokyo", {35.665949,139.74625}};
    (*this)["Ochanomizu"] = {"Tokyo", {35.718733,139.731683}};
    (*this)["Ueno"] = {"Tokyo", {35.711622,139.775695}};
    (*this)["Asakusa"] = {"Tokyo", {35.717064,139.79875}};
    (*this)["Skytree"] = {"Tokyo", {35.710063,139.8107}};
    (*this)["Kinshicho"] = {"Tokyo", {35.698312,139.813998}};
    (*this)["Toyosu"] = {"Tokyo", {35.652026,139.788785}};
    (*this)["RaraportToyosu"] = {"Tokyo", {35.655735,139.792662}};
    (*this)["Roppongi"] = {"Tokyo", {35.662893,139.733651}};
    (*this)["Shibuya"] = {"Tokyo", {35.661633,139.702516}};
    (*this)["Centergai"] = {"Tokyo", {35.658034,139.701636}};
    (*this)["Kamiizumi"] = {"Tokyo", {35.65727,139.693623}};
    (*this)["Yoyogikouen"] = {"Tokyo", {35.671587,139.696703}};
    (*this)["ShinjukuNishi"] = {"Tokyo", {35.693292,139.699132}};
    (*this)["ShinjukuHigashi"] = {"Tokyo", {35.689607,139.700571}};
    (*this)["Kabukicho"] = {"Tokyo", {35.695543,139.703149}};
    (*this)["Ikebukuro"] = {"Tokyo", {35.736262,139.707009}};
    (*this)["Nakano"] = {"Tokyo", {35.70607,139.659262}};
    (*this)["Ohyamaeki"] = {"Tokyo", {35.748531,139.702286}};
    (*this)["Nippori"] = {"Tokyo", {35.728158,139.770641}};
    (*this)["Kitasenju"] = {"Tokyo", {35.753029,139.803752}};
    (*this)["Daiba"] = {"Tokyo", {35.61885,139.780188}};
    (*this)["Shinagawa"] = {"Tokyo", {35.628471,139.73876}};
    (*this)["Ohsaki"] = {"Tokyo", {35.619851,139.728189}};
    (*this)["Kamata"] = {"Tokyo", {35.562479,139.716073}};
    (*this)["Haneda"] = {"Tokyo", {35.549393,139.779839}};
    (*this)["Sangenchaya"] = {"Tokyo", {35.641285,139.667989,}};
    (*this)["Hachioji"] = {"Tokyo", {35.658566,139.295838}};
    (*this)["Takahatahudo"] = {"Tokyo", {35.662013,139.411074}};
    (*this)["Huchu"] = {"Tokyo", {35.673204,139.477815}};
    (*this)["Inagi"] = {"Tokyo", {35.628468,139.494632}};
    (*this)["Chohu"] = {"Tokyo", {35.660425,139.555081}};
    (*this)["Kitami"] = {"Tokyo", {35.636547,139.587245}};
    (*this)["Ogikubo"] = {"Tokyo", {35.697402,139.622517}};
    (*this)["Kichijoji"] = {"Tokyo", {35.703158,139.580115}};
    (*this)["Mitaka"] = {"Tokyo", {35.683546,139.559268}};
    (*this)["MusashiKoganei"] = {"Tokyo", {35.701123,139.506912}};
    (*this)["Kokubunji"] = {"Tokyo", {35.705538,139.460007}};
    (*this)["Tachikawa"] = {"Tokyo", {35.714188,139.399159}};
    (*this)["Akishima"] = {"Tokyo", {35.708829,139.364915}};
    (*this)["Akikawa"] = {"Tokyo", {35.728027,139.286749}};
    (*this)["Hinodecho"] = {"Tokyo", {35.742117,139.257405}};
    (*this)["Hussa"] = {"Tokyo", {35.742364,139.327865}};
    (*this)["Hakonesaki"] = {"Tokyo", {35.771312,139.346714}};
    (*this)["Kosaku"] = {"Tokyo", {35.777083,139.303125}};
    (*this)["Kawabe"] = {"Tokyo", {35.785417,139.284375}};
    (*this)["Kiyose"] = {"Tokyo", {35.784283,139.521967}};
    (*this)["Higashikurume"] = {"Tokyo", {35.753218,139.516371}};
    (*this)["Kumekawa"] = {"Tokyo", {35.750026,139.472007}};
    (*this)["Tanashi"] = {"Tokyo", {35.727083,139.540625}};
    (*this)["Hitotsubashigakuen"] = {"Tokyo", {35.72206,139.480039}};
    (*this)["Nerima"] = {"Tokyo", {35.735785,139.651776}};
    (*this)["Akabane"] = {"Tokyo", {35.783721,139.7217}};
    (*this)["Kameari"] = {"Tokyo", {35.761606,139.848806}};
    (*this)["Nishikasai"] = {"Tokyo", {35.664577,139.859203}};

    (*this)["Kawasaki"] = {"Kanagawa", {35.532988,139.700872}};
    (*this)["KeikyuKawasaki"] = {"Kanagawa", {35.531365,139.696889}};
    (*this)["Tsurumi"] = {"Kanagawa", {35.508036,139.676262}};
    (*this)["Shinyokohama"] = {"Kanagawa", {35.508043,139.614786}};
    (*this)["Kanagawaeki"] = {"Kanagawa", {35.471027,139.627114}};
    (*this)["Yokohama"] = {"Kanagawa", {35.465981,139.622062}};
    (*this)["NipponOhdouri"] = {"Kanagawa", {35.446456,139.642306}};
    (*this)["Hoshikawa"] = {"Kanagawa", {35.458875,139.589907}};
    (*this)["Yoshinocho"] = {"Kanagawa", {35.435417,139.615625}};
    (*this)["Kamiohoka"] = {"Kanagawa", {35.409122,139.596629}};
    (*this)["Kanazawabunko"] = {"Kanagawa", {35.343905,139.628711}};
    (*this)["Kamakura"] = {"Kanagawa", {35.319065,139.550412}};
    (*this)["Yokosukachuo"] = {"Kanagawa", {35.278699,139.67004}};
    (*this)["Miurakaiganeki"] = {"Kanagawa", {35.188364,139.653511}};
    (*this)["Shinzushi"] = {"Kanagawa", {35.295934,139.581199}};
    (*this)["Hayamacho"] = {"Kanagawa", {35.272094,139.586202}};
    (*this)["Hujisawa"] = {"Kanagawa", {35.338898,139.48747}};
    (*this)["Oohuna"] = {"Kanagawa", {35.354048,139.531299}};
    (*this)["Totsuka"] = {"Kanagawa", {35.400766,139.534204}};
    (*this)["Tateba"] = {"Kanagawa", {35.414484,139.500994}};
    (*this)["Samukawacho"] = {"Kanagawa", {35.37595,139.387012}};
    (*this)["Chigasaki"] = {"Kanagawa", {35.330303,139.406817}};
    (*this)["Hiratsuka"] = {"Kanagawa", {35.32783,139.350645}};
    (*this)["Ohiso"] = {"Kanagawa", {35.311435,139.313291}};
    (*this)["Ninomiya"] = {"Kanagawa", {35.298786,139.257598}};
    (*this)["Odawara"] = {"Kanagawa", {35.256445,139.155393}};
    (*this)["Tokaidaigaku"] = {"Kanagawa", {35.372872,139.270904}};
    (*this)["Isehara"] = {"Kanagawa", {35.396037,139.313594}};
    (*this)["Hon-atsugi"] = {"Kanagawa", {35.439408,139.364422}};
    (*this)["Ebina"] = {"Kanagawa", {35.454271,139.389335}};
    (*this)["Yamato"] = {"Kanagawa", {35.469831,139.461463}};
    (*this)["Seya"] = {"Kanagawa", {35.473081,139.475668}};
    (*this)["Ayase"] = {"Kanagawa", {35.437553,139.430111}};
    (*this)["OdakyuSagamihara"] = {"Kanagawa", {35.515191,139.422653}};
    (*this)["Sagamiohno"] = {"Kanagawa", {35.532641,139.433562}};
    (*this)["Machida"] = {"Kanagawa", {35.541994,139.445376}};
    (*this)["Tamapraza"] = {"Kanagawa", {35.577406,139.558528}};
    (*this)["CenterMinami"] = {"Kanagawa", {35.545583,139.57451}};
    (*this)["MusashiKosugi"] = {"Kanagawa", {35.576629,139.66}};
    (*this)["Miyazakidai"] = {"Kanagawa", {35.587217,139.591201}};
    (*this)["Mizonokuchi"] = {"Kanagawa", {35.599965,139.610623}};
    (*this)["Noborido"] = {"Kanagawa", {35.620766,139.570098}};
    (*this)["Shinyuri"] = {"Kanagawa", {35.603805,139.507605}};
    (*this)["Huchinobe"] = {"Kanagawa", {35.568734,139.3951}};
    (*this)["Hashimoto"] = {"Kanagawa", {35.594864,139.344922}};
    (*this)["Aikawacho"] = {"Kanagawa", {35.528821,139.321661}};
    (*this)["Tamacenter"] = {"Kanagawa", {35.623931,139.422853}};
    (*this)["Kaisei"] = {"Kanagawa", {35.326485,139.135806}};
    (*this)["FujiFilmMaeeki"] = {"Kanagawa", {35.317645,139.108928}};
    (*this)["Yamakitaeki"] = {"Kanagawa", {35.360937,139.080372}};
    (*this)["Shinmatsuda"] = {"Kanagawa", {35.344594,139.139444}};
    (*this)["SagamiKaneko"] = {"Kanagawa", {35.333867,139.150462}};
    (*this)["Manazuru"] = {"Kanagawa", {35.156809,139.13234}};
    (*this)["Yugawara"] = {"Kanagawa", {35.146087,139.102177}};
    (*this)["Hutamatagawa"] = {"Kanagawa", {35.463577,139.53231}};
    (*this)["Nakayama"] = {"Kanagawa", {35.514752,139.539181}};

    (*this)["Kawaguchi"] = {"Saitama", {35.833731,139.731689}};
    (*this)["Toda"] = {"Saitama", {35.801922,139.66835}};
    (*this)["Wakou"] = {"Saitama", {35.789853,139.62211}};
    (*this)["Niiza"] = {"Saitama", {35.803692,139.556495}};
    (*this)["Asakasumidai"] = {"Saitama", {35.814553,139.587081}};
    (*this)["Shigishi"] = {"Saitama", {35.839701,139.581411}};
    (*this)["Miyoshicho"] = {"Saitama", {35.833067,139.51686}};
    (*this)["Hujiminoshi"] = {"Saitama", {35.867403,139.509741}};
    (*this)["Kamihukuokaeki"] = {"Saitama", {35.873915,139.511741}};
    (*this)["Kawagoe"] = {"Saitama", {35.907116,139.482444}};
    (*this)["Sashiohgieki"] = {"Saitama", {35.91693,139.56494}};
    (*this)["Tokorozawa"] = {"Saitama", {35.786617,139.473225}};
    (*this)["MusashiMurayama"] = {"Saitama", {35.753403,139.384666}};
    (*this)["Sakurakaidoueki"] = {"Saitama", {35.738918,139.416682}};
    (*this)["MusashiHujisawa"] = {"Saitama", {35.820853,139.412763}};
    (*this)["Warabi"] = {"Saitama", {35.824611,139.686419}};
    (*this)["Souka"] = {"Saitama", {35.828478,139.803594}};
    (*this)["Yashio"] = {"Saitama", {35.807836,139.844826}};
    (*this)["Misato"] = {"Saitama", {35.825964,139.875843}};
    (*this)["Yoshikawa"] = {"Saitama", {35.876664,139.843224}};
    (*this)["Koshigaya"] = {"Saitama", {35.875611,139.789783}};
    (*this)["HigashiUrawa"] = {"Saitama", {35.864132,139.704639}};
    (*this)["Urawa"] = {"Saitama", {35.859044,139.657217}};
    (*this)["MusashiUrawa"] = {"Saitama", {35.845957,139.647629}};
    (*this)["NishiUrawa"] = {"Saitama", {35.844278,139.628025}};
    (*this)["Yono"] = {"Saitama", {35.89078,139.628681}};
    (*this)["Ohmiya"] = {"Saitama", {35.906449,139.623855}};
    (*this)["Miyaharaeki"] = {"Saitama", {35.940292,139.609571}};
    (*this)["HigashiOhmiya"] = {"Saitama", {35.948755,139.640286}};
    (*this)["Iwatsuki"] = {"Saitama", {35.96334,139.712229}};
    (*this)["Kasukabe"] = {"Saitama", {35.979918,139.752621}};
    (*this)["Hasuda"] = {"Saitama", {35.981286,139.653069}};
    (*this)["Ageo"] = {"Saitama", {35.973522,139.588818}};
    (*this)["Inachuo"] = {"Saitama", {35.999422,139.61721}};
    (*this)["Okegawa"] = {"Saitama", {35.998756,139.564032}};
    (*this)["Kitamoto"] = {"Saitama", {36.031574,139.534009}};
    (*this)["Kounosu"] = {"Saitama", {36.059241,139.509643}};
    (*this)["Yoshimicho"] = {"Saitama", {36.039853,139.45373}};
    (*this)["HigashiMatsuyama"] = {"Saitama", {36.034875,139.401776}};
    (*this)["ShinrinKoueneki"] = {"Saitama", {36.045234,139.374902}};
    (*this)["MusashiArashiyama"] = {"Saitama", {36.044381,139.32765}};
    (*this)["Meikakueki"] = {"Saitama", {36.003341,139.288854}};
    (*this)["Ogawachoeki"] = {"Saitama", {36.058417,139.261343}};
    (*this)["Yoriieki"] = {"Saitama", {36.117887,139.194537}};
    (*this)["Nogamieki"] = {"Saitama", {36.11159,139.111193}};
    (*this)["Oyahanaeki"] = {"Saitama", {36.077566,139.106306}};
    (*this)["Ohanabatakeeki"] = {"Saitama", {35.992492,139.083617}};
    (*this)["Yokose"] = {"Saitama", {35.968188,139.132708}};
    (*this)["Ogose"] = {"Saitama", {35.962165,139.299375}};
    (*this)["BushuNagaseeki"] = {"Saitama", {35.941979,139.325765}};
    (*this)["Wakabaeki"] = {"Saitama", {35.949105,139.40873}};
    (*this)["Kitasakado"] = {"Saitama", {35.971836,139.396702}};
    (*this)["Gyoda"] = {"Saitama", {36.113765,139.432249}};
    (*this)["Kumagaya"] = {"Saitama", {36.13939,139.390033}};
    (*this)["Hanyu"] = {"Saitama", {36.170361,139.534104}};
    (*this)["Hukaya"] = {"Saitama", {36.191419,139.281398}};
    (*this)["Honjyo"] = {"Saitama", {36.236164,139.188611}};
    (*this)["Jinbobara"] = {"Saitama", {36.253464,139.149407}};
    (*this)["Tansou"] = {"Saitama", {36.216661,139.102273}};
    (*this)["Hanasaki"] = {"Saitama", {36.109925,139.633523}};
    (*this)["Satte"] = {"Saitama", {36.074555,139.714949}};
    (*this)["Kuki"] = {"Saitama", {36.065958,139.677633}};
    (*this)["SugidoTakanodai"] = {"Saitama", {36.051502,139.714422}};
    (*this)["ToubuDoubutsuKouen"] = {"Saitama", {36.02495,139.7267}};
    (*this)["Shiraoka"] = {"Saitama", {36.017588,139.667094}};
    (*this)["Kawamataeki"] = {"Saitama", {36.208923,139.526515}};
    (*this)["Oganocho"] = {"Saitama", {36.01714,139.008604}};

    (*this)["DisneyLand"] = {"Chiba", {35.632896,139.880394}};
    (*this)["Honyawata"] = {"Chiba", {35.721091,139.927234}};
    (*this)["Hunabashi"] = {"Chiba", {35.701736,139.985382}};
    (*this)["Tsudanuma"] = {"Chiba", {35.691215,140.020407}};
    (*this)["KeiseiMakuhari"] = {"Chiba", {35.660444,140.056076}};
    (*this)["KaihinMakuhari"] = {"Chiba", {35.648476,140.041987}};
    (*this)["Inage"] = {"Chiba", {35.63717,140.09249}};
    (*this)["Tsuga"] = {"Chiba", {35.636095,140.149201}};
    (*this)["KeiseiChiba"] = {"Chiba", {35.611618,140.114267}};
    (*this)["Kamatori"] = {"Chiba", {35.562653,140.178736}};
    (*this)["Goieki"] = {"Chiba", {35.513028,140.089701}};
    (*this)["Sodegaura"] = {"Chiba", {35.432189,139.957829}};
    (*this)["Kisarazu"] = {"Chiba", {35.381579,139.926229}};
    (*this)["Kimitsu"] = {"Chiba", {35.333667,139.895042}};
    (*this)["Aobori"] = {"Chiba", {35.330531,139.858939}};
    (*this)["Katsuyama"] = {"Chiba", {35.114027,139.833394}};
    (*this)["Iwaieki"] = {"Chiba", {35.09328,139.849893}};
    (*this)["Tateyama"] = {"Chiba", {34.983579,139.846917}};
    (*this)["Kamogawa"] = {"Chiba", {35.120034,140.073334}};
    (*this)["Katsuura"] = {"Chiba", {35.152563,140.311936}};
    (*this)["Mishuku"] = {"Chiba", {35.18756,140.351431}};
    (*this)["Ohara"] = {"Chiba", {35.251221,140.391036}};
    (*this)["Ichinomiya"] = {"Chiba", {35.373089,140.369527}};
    (*this)["Shigehara"] = {"Chiba", {35.426874,140.304048}};
    (*this)["Ohami"] = {"Chiba", {35.452607,140.282762}};
    (*this)["Kujuukuri"] = {"Chiba", {35.522631,140.310999}};
    (*this)["Tougane"] = {"Chiba", {35.560158,140.363609}};
    (*this)["Naritou"] = {"Chiba", {35.608387,140.410859}};
    (*this)["Yokoshiba"] = {"Chiba", {35.661769,140.491232}};
    (*this)["Youkaichi"] = {"Chiba", {35.699286,140.552366}};
    (*this)["Shibayamacho"] = {"Chiba", {35.693126,140.414397}};
    (*this)["Yachimata"] = {"Chiba", {35.644488,140.301338}};
    (*this)["Yotsukaido"] = {"Chiba", {35.666465,140.175374}};
    (*this)["Katsutadai"] = {"Chiba", {35.715438,140.125972}};
    (*this)["Chikucentereki"] = {"Chiba", {35.725856,140.155287}};
    (*this)["Sakesakai"] = {"Chiba", {35.731664,140.275249}};
    (*this)["Miyazato"] = {"Chiba", {35.726649,140.346981}};
    (*this)["Takocho"] = {"Chiba", {35.74905,140.466227}};
    (*this)["Narita"] = {"Chiba", {35.771987,140.39285}};
    (*this)["Asahi"] = {"Chiba", {35.722009,140.654939}};
    (*this)["Choushi"] = {"Chiba", {35.751212,140.7845}};
    (*this)["ShimousaTachibana"] = {"Chiba", {35.780462,140.744675}};
    (*this)["Ajikieki"] = {"Chiba", {35.835707,140.242358}};
    (*this)["ChibaNewtown"] = {"Chiba", {35.800133,140.116274}};
    (*this)["Nishishiraieki"] = {"Chiba", {35.784402,140.031767}};
    (*this)["Kamagaya"] = {"Chiba", {35.779409,139.998398}};
    (*this)["Matsudo"] = {"Chiba", {35.7843,139.900661}};
    (*this)["Kashiwa"] = {"Chiba", {35.86215,139.970917}};
    (*this)["Abiko"] = {"Chiba", {35.872703,140.010794}};
    (*this)["Nagareyama"] = {"Chiba", {35.871905,139.925241}};
    (*this)["Atagoeki"] = {"Chiba", {35.950148,139.864819}};
    (*this)["Matsubushicho"] = {"Chiba", {35.922758,139.815748}};

  // Ibaraki
    (*this)["Kashima"] = {"Ibaraki", {35.968807,140.631517}};
    (*this)["Itako"] = {"Ibaraki", {35.937343,140.549606}};
    (*this)["Namekata"] = {"Ibaraki", {35.993244,140.482587}};
    (*this)["Inashiki"] = {"Ibaraki", {35.95472,140.326839}};
    (*this)["Sanuki"] = {"Ibaraki", {35.930066,140.138229}};
    (*this)["Toride"] = {"Ibaraki", {35.895699,140.062875}};
    (*this)["Moriya"] = {"Ibaraki", {35.95067,139.992268}};
    (*this)["Miraidaira"] = {"Ibaraki", {35.99375,140.040625}};
    (*this)["HitachinoUshiku"] = {"Ibaraki", {36.007352,140.158247}};
    (*this)["Amicho"] = {"Ibaraki", {36.030812,140.214808}};
    (*this)["Tsuchiura"] = {"Ibaraki", {36.078484,140.206212}};
    (*this)["Tsukuba"] = {"Ibaraki", {36.08251,140.11171}};
    (*this)["Mizukaidou"] = {"Ibaraki", {36.018325,139.991993}};
    (*this)["Bandoushi"] = {"Ibaraki", {36.048356,139.888837}};
    (*this)["Sakaicho"] = {"Ibaraki", {36.108485,139.794953}};
    (*this)["Shimotsuma"] = {"Ibaraki", {36.181994,139.96445}};
    (*this)["Yachiyocho"] = {"Ibaraki", {36.181684,139.891121}};
    (*this)["Yuuki"] = {"Ibaraki", {36.298223,139.872371}};
    (*this)["Shimodate"] = {"Ibaraki", {36.304147,139.978334}};
    (*this)["Iwase"] = {"Ibaraki", {36.359588,140.108271}};
    (*this)["Kasama"] = {"Ibaraki", {36.373302,140.246142}};
    (*this)["Shirosato"] = {"Ibaraki", {36.488544,140.307827}};
    (*this)["Uritura"] = {"Ibaraki", {36.498221,140.449424}};
    (*this)["HitachiOomiya"] = {"Ibaraki", {36.547132,140.412619}};
    (*this)["HitachOota"] = {"Ibaraki", {36.531528,140.527906}};
    (*this)["Toukaieki"] = {"Ibaraki", {36.465534,140.566054}};
    (*this)["Mito"] = {"Ibaraki", {36.370755,140.476308}};
    (*this)["Katsuta"] = {"Ibaraki", {36.39468,140.524589}};
    (*this)["Ooarai"] = {"Ibaraki", {36.31505,140.562942}};
    (*this)["Hatori"] = {"Ibaraki", {36.247523,140.286754}};
    (*this)["Ishioka"] = {"Ibaraki", {36.19095,140.28025}};
    (*this)["Hokota"] = {"Ibaraki", {36.152444,140.520298}};
    (*this)["Hitachi"] = {"Ibaraki", {36.590439,140.661847}};
    (*this)["Takahagi"] = {"Ibaraki", {36.714482,140.717003}};
    (*this)["HitachDaiko"] = {"Ibaraki", {36.77094,140.3508}};
    (*this)["Isohara"] = {"Ibaraki", {36.790502,140.746164}};
  
    (*this)["Koga"] = {"Tochigi", {36.194597,139.709555}};
    (*this)["Nogi"] = {"Tochigi", {36.229954,139.734718}};
    (*this)["Ashikaga"] = {"Tochigi", {36.331824,139.455877}};
    (*this)["Sano"] = {"Tochigi", {36.316738,139.578856}};
    (*this)["ShinOhirashita"] = {"Tochigi", {36.339024,139.701633}};
    (*this)["Koyama"] = {"Tochigi", {36.313121,139.806324}};
    (*this)["Jichiidaieki"] = {"Tochigi", {36.395411,139.854729}};
    (*this)["Kamimikawa"] = {"Tochigi", {36.43922,139.909927}};
    (*this)["Mouka"] = {"Tochigi", {36.439188,140.002576}};
    (*this)["Mashiko"] = {"Tochigi", {36.463321,140.088886}};
    (*this)["Mogi"] = {"Tochigi", {36.530794,140.181362}};
    (*this)["Hagacho"] = {"Tochigi", {36.548215,140.058199}};
    (*this)["Omochanomachi"] = {"Tochigi", {36.466668,139.829498}};
    (*this)["Kanuma"] = {"Tochigi", {36.557266,139.744969}};
    (*this)["Utsunomiya"] = {"Tochigi", {36.559023,139.898451}};
    (*this)["Takarazumidera"] = {"Tochigi", {36.631476,139.979498}};
    (*this)["Ujiie"] = {"Tochigi", {36.681632,139.962097}};
    (*this)["Kuroiso"] = {"Tochigi", {36.9699,140.059446}};
    (*this)["Nasucho"] = {"Tochigi", {37.01977,140.121006}};
    (*this)["Yaita"] = {"Tochigi", {36.806617,139.932955}};
    (*this)["Nikko"] = {"Tochigi", {36.720785,139.686834}};
    (*this)["KarasuyamaKeisatsu"] = {"Tochigi", {36.652108,140.158461}};
    (*this)["Itakura"] = {"Gunma", {36.222008,139.648559}};
    (*this)["Tatebayashi"] = {"Gunma", {36.245994,139.528202}};
    (*this)["Honnakanoeki"] = {"Gunma", {36.258552,139.469758}};
    (*this)["Nishikoizumi"] = {"Gunma", {36.25848,139.408457}};
    (*this)["Ohta"] = {"Gunma", {36.294137,139.378518}};
    (*this)["Kiryu"] = {"Gunma", {36.411145,139.333079}};
    (*this)["Akagi"] = {"Gunma", {36.425779,139.276292}};
    (*this)["Isezaki"] = {"Gunma", {36.326906,139.193895}};
    (*this)["Tamamuracho"] = {"Gunma", {36.304404,139.114992}};
    (*this)["Hujioka"] = {"Gunma", {36.250159,139.083324}};
    (*this)["Jyoshuhukushima"] = {"Gunma", {36.2563,138.929675}};
    (*this)["Higashitomioka"] = {"Gunma", {36.260842,138.901856}};
    (*this)["Shimonita"] = {"Gunma", {36.210588,138.786197}};
    (*this)["Takasaki"] = {"Gunma", {36.322827,139.012662}};
    (*this)["Maebashi"] = {"Gunma", {36.383184,139.073217}};
    (*this)["Yoshioka"] = {"Gunma", {36.447377,139.009948}};
    (*this)["Shibukawa"] = {"Gunma", {36.491322,139.008798}};
    (*this)["Nakanojyo"] = {"Gunma", {36.58539,138.851446}};
    (*this)["Gunmabara"] = {"Gunma", {36.571722,138.824408}};
    (*this)["Numata"] = {"Gunma", {36.6425,139.035623}};

    (*this)["Umeda"] = {"Osaka", {34.705027,135.498427}};
    (*this)["Higobashi"] = {"Osaka", {34.691661,135.496227}};
    (*this)["Nakanoshima"] = {"Osaka", {34.69055,135.486616}};
    (*this)["Nishikujyou"] = {"Osaka", {34.682143,135.466149}};
    (*this)["Bentencho"] = {"Osaka", {34.669179,135.462577}};
    (*this)["Taisho"] = {"Osaka", {34.665782,135.479248}};
    (*this)["Doutonbori"] = {"Osaka", {34.668723,135.501297}};
    (*this)["Nanba"] = {"Osaka", {34.664987,135.503656}};
    (*this)["Shinimamiya"] = {"Osaka", {34.649793,135.501548}};
    (*this)["Tennouji"] = {"Osaka", {34.648435,135.518454}};
    (*this)["Anobebashi"] = {"Osaka", {34.646071,135.513477}};
    (*this)["Minamitanabe"] = {"Osaka", {34.625587,135.520574}};
    (*this)["Tamaide"] = {"Osaka", {34.623669,135.490285}};
    (*this)["Kireurewari"] = {"Osaka", {34.609227,135.552141}};
    (*this)["Abikoeki"] = {"Osaka", {34.599061,135.512784}};
    (*this)["Sakaihigashi"] = {"Osaka", {34.575378,135.484796}};
    (*this)["Nakamozu"] = {"Osaka", {34.556315,135.504258}};
    (*this)["KawauchiMatsubara"] = {"Osaka", {34.575533,135.557137}};
    (*this)["Eganosou"] = {"Osaka", {34.574946,135.573021}};
    (*this)["Hijiidera"] = {"Osaka", {34.571533,135.594449}};
    (*this)["Miharaku"] = {"Osaka", {34.538543,135.559896}};
    (*this)["Kitanoda"] = {"Osaka", {34.523181,135.543034}};
    (*this)["Izumigaoka"] = {"Osaka", {34.497191,135.511808}};
    (*this)["Kingou"] = {"Osaka", {34.495268,135.559422}};
    (*this)["Tomitabayashi"] = {"Osaka", {34.50452,135.601271}};
    (*this)["Kanancho"] = {"Osaka", {34.491608,135.629687}};
    (*this)["Kawauchinagano"] = {"Osaka", {34.451086,135.573088}};
    (*this)["Ootori"] = {"Osaka", {34.531989,135.458916}};
    (*this)["Takaishi"] = {"Osaka", {34.521535,135.432981}};
    (*this)["Izumiootsu"] = {"Osaka", {34.50336,135.40667}};
    (*this)["Izumihutyuu"] = {"Osaka", {34.48796,135.423879}};
    (*this)["Tadaoka"] = {"Osaka", {34.488332,135.397436}};
    (*this)["Higashikishiwada"] = {"Osaka", {34.448716,135.385171}};
    (*this)["Kaiduka"] = {"Osaka", {34.445467,135.357532}};
    (*this)["Izumisano"] = {"Osaka", {34.411261,135.317282}};
    (*this)["Kansaiairport"] = {"Osaka", {34.432002,135.230394}};
    (*this)["Taruieki"] = {"Osaka", {34.374342,135.261701}};
    (*this)["Ozakieki"] = {"Osaka", {34.361544,135.240697}};
    (*this)["Hukahicho"] = {"Osaka", {34.31842,135.148884}};
    (*this)["Taishicho"] = {"Osaka", {34.519223,135.648978}};
    (*this)["Juudou"] = {"Osaka", {34.706219,135.621383}};
    (*this)["Yokotsutsumi"] = {"Osaka", {34.703467,135.572192}};
    (*this)["Morinomiya"] = {"Osaka", {34.681731,135.533356}};
    (*this)["Huse"] = {"Osaka", {34.664082,135.563416}};
    (*this)["Kitatatsumi"] = {"Osaka", {34.652941,135.554986}};
    (*this)["Yaoeki"] = {"Osaka", {34.617357,135.596782}};
    (*this)["Shinobugaoka"] = {"Osaka", {34.746047,135.645545}};
    (*this)["Monma"] = {"Osaka", {34.738046,135.582928}};
    (*this)["Moriguchi"] = {"Osaka", {34.73518,135.56504}};
    (*this)["Noe"] = {"Osaka", {34.707131,135.543387}};
    (*this)["Kyoubashi"] = {"Osaka", {34.69669,135.533912}};
    (*this)["Himejima"] = {"Osaka", {34.704402,135.458175}};
    (*this)["Shinoosaka"] = {"Osaka", {34.733466,135.500255}};
    (*this)["Amagasaki"] = {"Osaka", {34.718524,135.417286}};
    (*this)["Itami"] = {"Osaka", {34.780732,135.421674}};
    (*this)["Esaka"] = {"Osaka", {34.758653,135.49703}};
    (*this)["Kamisinjyo"] = {"Osaka", {34.750327,135.533098}};
    (*this)["Kouno"] = {"Osaka", {34.786988,135.675541}};
    (*this)["Karien"] = {"Osaka", {34.784627,135.630978}};
    (*this)["Settsu"] = {"Osaka", {34.78364,135.556586}};
    (*this)["Ibaraki"] = {"Osaka", {34.815463,135.562399}};
    (*this)["Chisato"] = {"Osaka", {34.807469,135.495255}};
    (*this)["Minoo"] = {"Osaka", {34.834477,135.468419}};
    (*this)["Ikeda"] = {"Osaka", {34.821589,135.425534}};
    (*this)["Takatsuki"] = {"Osaka", {34.85167,135.617739}};
    (*this)["Minase"] = {"Osaka", {34.877838,135.667816}};

    (*this)["Nishinomiya"] = {"Hyougo", {34.738958,135.348654}};
    (*this)["Sumoto"] = {"Hyougo", {34.342832,134.895363}};
    (*this)["Ashiya"] = {"Hyougo", {34.734243,135.30707}};
    (*this)["HyougoSettsu"] = {"Hyougo", {34.726544,135.276543}};
    (*this)["Rokkoudou"] = {"Hyougo", {34.714976,135.238545}};
    (*this)["Daimaru"] = {"Hyougo", {34.693849,135.196045}};
    (*this)["Shinkaichi"] = {"Hyougo", {34.676572,135.169034}};
    (*this)["Shinnagata"] = {"Hyougo", {34.657692,135.145465}};
    (*this)["Itashuku"] = {"Hyougo", {34.660017,135.133204}};
    (*this)["Sanyoutarumizu"] = {"Hyougo", {34.629538,135.053661}};
    (*this)["Akashi"] = {"Hyougo", {34.649036,134.992696}};
    (*this)["Harima"] = {"Hyougo", {34.716644,134.868086}};
    (*this)["Kakogawa"] = {"Hyougo", {34.767637,134.839365}};
    (*this)["Takaraden"] = {"Hyougo", {34.784718,134.812117}};
    (*this)["Himejie"] = {"Hyougo", {34.826797,134.690533}};
    (*this)["HyougoTaishicho"] = {"Hyougo", {34.83327,134.593739}};
    (*this)["Tatsuno"] = {"Hyougo", {34.825484,134.522363}};
    (*this)["Nishiaise"] = {"Hyougo", {34.801375,134.450759}};
    (*this)["Akaho"] = {"Hyougo", {34.756601,134.393266}};
    (*this)["Kamikoori"] = {"Hyougo", {34.866004,134.353599}};
    (*this)["Sayou"] = {"Hyougo", {35.004076,134.356878}};
    (*this)["Hamasaka"] = {"Hyougo", {35.62053,134.452843}};
    (*this)["Kasumi"] = {"Hyougo", {35.635605,134.622973}};
    (*this)["Toyooka"] = {"Hyougo", {35.543992,134.813341}};
    (*this)["Wadayama"] = {"Hyougo", {35.34117,134.851888}};
    (*this)["Takacho"] = {"Hyougo", {35.050346,134.923561}};
    (*this)["Nishiwaki"] = {"Hyougo", {34.971867,134.96893}};
    (*this)["Takieki"] = {"Hyougo", {34.948705,134.962436}};
    (*this)["Houjyoucho"] = {"Hyougo", {34.930791,134.835821}};
    (*this)["Hukuzaki"] = {"Hyougo", {34.960752,134.750755}};
    (*this)["Amachi"] = {"Hyougo", {34.987879,134.758851}};
    (*this)["Teramae"] = {"Hyougo", {35.065462,134.743169}};
    (*this)["Shishikuri"] = {"Hyougo", {35.004386,134.549438}};
    (*this)["Ono"] = {"Hyougo", {34.843227,134.934328}};
    (*this)["Shisome"] = {"Hyougo", {34.782473,135.007572}};
    (*this)["Kitasuzuran"] = {"Hyougo", {34.739441,135.151946}};
    (*this)["Nishikami"] = {"Hyougo", {34.719417,135.017416}};
    (*this)["Inami"] = {"Hyougo", {34.748381,134.913248}};
    (*this)["Mita"] = {"Hyougo", {34.888442,135.229983}};
    (*this)["Shinoyamaguchi"] = {"Hyougo", {35.05621,135.17767}};
    (*this)["Kashiwabara"] = {"Hyougo", {35.127226,135.077328}};
  
    (*this)["Toriimae"] = {"Nara", {34.692351,135.696117}};
    (*this)["YamatoNishioodera"] = {"Nara", {34.693779,135.782786}};
    (*this)["Tatsutagawa"] = {"Osaka", {34.617396,135.704627}};
    (*this)["Seino"] = {"Nara", {34.606015,135.700726}};
    (*this)["Shinoodera"] = {"Nara", {34.597672,135.702482}};
    (*this)["Samida"] = {"Nara", {34.585169,135.731091}};
    (*this)["Uemaki"] = {"Nara", {34.562729,135.716671}};
    (*this)["KintetsuShimoda"] = {"Nara", {34.541405,135.70413}};
    (*this)["Yamatotakada"] = {"Nara", {34.519714,135.742516}};
    (*this)["Yamatoshinjyo"] = {"Nara", {34.488576,135.73583}};
    (*this)["KintetsuGosho"] = {"Nara", {34.46472,135.732352}};
    (*this)["Tubosakayama"] = {"Nara", {34.449727,135.794925}};
    (*this)["Asuka"] = {"Nara", {34.464897,135.798264}};
    (*this)["Hukujin"] = {"Nara", {34.395195,135.750787}};
    (*this)["Yamatohutami"] = {"Nara", {34.346037,135.684536}};
    (*this)["Takanoguchi"] = {"Nara", {34.30625,135.559375}};
    (*this)["Haibara"] = {"Nara", {34.529746,135.954386}};
    (*this)["Sakurai"] = {"Nara", {34.51349,135.846276}};
    (*this)["Tenri"] = {"Nara", {34.601151,135.830145}};
    (*this)["Yuizaki"] = {"Nara", {34.584263,135.78471}};
    (*this)["Nishidawara"] = {"Nara", {34.553645,135.789673}};
    (*this)["Ishimi"] = {"Nara", {34.571904,135.785879}};
    (*this)["Hashio"] = {"Nara", {34.570138,135.751481}};
    (*this)["Ancho"] = {"Nara", {34.606445,135.756949}};
    (*this)["Houryuuji"] = {"Nara", {34.601645,135.739033}};
    (*this)["Tsutsui"] = {"Nara", {34.620257,135.7807}};
    (*this)["Katashita"] = {"Nara", {34.588565,135.627274}};

    (*this)["Ayabe"] = {"Kyoto", {35.302141,135.251866}};
    (*this)["Kitsu"] = {"Kyoto", {34.735977,135.824927}};
    (*this)["Iwazono"] = {"Kyoto", {34.759883,135.792022}};
    (*this)["Wachi"] = {"Kyoto", {35.26101,135.399021}};
    (*this)["Higashimaizuru"] = {"Kyoto", {35.468545,135.394886}};
    (*this)["Hukuchiyama"] = {"Kyoto", {35.295979,135.118425}};
    (*this)["Kitaouji"] = {"Kyoto", {35.045172,135.758704}};
    (*this)["Imadegawa"] = {"Kyoto", {35.029822,135.759359}};
    (*this)["Sanjyou"] = {"Kyoto", {35.009443,135.772303}};
    (*this)["Gion"] = {"Kyoto", {35.003971,135.772093}};
    (*this)["Karasumaru"] = {"Kyoto", {35.009992,135.759609}};
    (*this)["Yamanouchi"] = {"Kyoto", {35.008304,135.72337}};
    (*this)["Kyotoeki"] = {"Kyoto", {34.985849,135.758767}};
    (*this)["Higashidera"] = {"Kyoto", {34.979945,135.752636}};
    (*this)["Kamikatsura"] = {"Kyoto", {34.990528,135.695827}};
    (*this)["Higashimukou"] = {"Kyoto", {34.953942,135.70456}};
    (*this)["Hushimimomoyama"] = {"Kyoto", {34.932622,135.764301}};
    (*this)["Rokujizou"] = {"Kyoto", {34.932007,135.79335}};
    (*this)["Nagaokakyo"] = {"Kyoto", {34.924353,135.680006}};
    (*this)["Yamasaki"] = {"Kyoto", {34.892199,135.679878}};
    (*this)["KyotoHashimoto"] = {"Kyoto", {34.881949,135.684204}};
    (*this)["Kuonyama"] = {"Kyoto", {34.881534,135.732697}};
    (*this)["Terada"] = {"Kyoto", {34.853295,135.772111}};
    (*this)["Ujitawara"] = {"Kyoto", {34.852718,135.856891}};
    (*this)["Yamashirotaga"] = {"Kyoto", {34.817515,135.806251}};
    (*this)["Nittabe"] = {"Kyoto", {34.820653,135.772809}};

    (*this)["Yoshinojingu"] = {"Wakayama", {34.390266,135.847992}};
    (*this)["Kasada"] = {"Wakayama", {34.292202,135.480245}};
    (*this)["Wakayama"] = {"Wakayama", {34.23218,135.191792}};
    (*this)["Kainan"] = {"Wakayama", {34.1544,135.214347}};
    (*this)["Iwade"] = {"Wakayama", {34.254862,135.321072}};
    (*this)["Uchida"] = {"Wakayama", {34.26529,135.364091}};
    (*this)["Kiminocho"] = {"Wakayama", {34.167194,135.307575}};
    (*this)["Minoshima"] = {"Wakayama", {34.085997,135.124575}};
    (*this)["Hujinami"] = {"Wakayama", {34.057197,135.196615}};
    (*this)["Yuasa"] = {"Wakayama", {34.031938,135.17942}};
    (*this)["Kiiuchibara"] = {"Wakayama", {33.925983,135.145135}};
    (*this)["Mihamacho"] = {"Wakayama", {33.893806,135.133262}};
    (*this)["Kiigobou"] = {"Wakayama", {33.89432,135.154851}};
    (*this)["Innan"] = {"Wakayama", {33.818423,135.219705}};
    (*this)["Minabe"] = {"Wakayama", {33.767125,135.324648}};
    (*this)["Ikitanabe"] = {"Wakayama", {33.733047,135.384142}};
    (*this)["Asaki"] = {"Wakayama", {33.69629,135.417663}};
    (*this)["Shirahama"] = {"Wakayama", {33.675803,135.387177}};
    (*this)["Shuusanken"] = {"Wakayama", {33.546824,135.495525}};
    (*this)["Kushimoto"] = {"Wakayama", {33.475527,135.781603}};
    (*this)["Kiikatsuura"] = {"Wakayama", {33.628152,135.941418}};
    (*this)["Shinguu"] = {"Wakayama", {33.725151,135.994147}};
    (*this)["Uden"] = {"Wakayama", {33.737114,136.015908}};
    (*this)["Adawa"] = {"Wakayama", {33.805305,136.04298}};
    (*this)["Kumano"] = {"Wakayama", {33.889638,136.09886}};

    (*this)["Nagahama"] = {"Shiga", {35.378545,136.264941}};
    (*this)["Yonehara"] = {"Shiga", {35.31477,136.289845}};
    (*this)["Hikone"] = {"Shiga", {35.272213,136.263354}};
    (*this)["Konoetakashima"] = {"Shiga", {35.292688,136.010133}};
    (*this)["Tagataisha"] = {"Shiga", {35.226452,136.284083}};
    (*this)["Hougou"] = {"Shiga", {35.197898,136.230922}};
    (*this)["Aichikawa"] = {"Shiga", {35.176123,136.213369}};
    (*this)["ShigaYoukaichi"] = {"Shiga", {35.114526,136.19479,}};
    (*this)["Konoeyawata"] = {"Shiga", {35.122855,136.102788}};
    (*this)["Yasu"] = {"Shiga", {35.068353,136.022584}};
    (*this)["Moriyama"] = {"Shiga", {35.050604,135.99642}};
    (*this)["Kurihigashi"] = {"Shiga", {35.037417,135.979962}};
    (*this)["Kusatsu"] = {"Shiga", {35.022884,135.962202}};
    (*this)["Kouzai"] = {"Shiga", {35.000612,136.082331}};
    (*this)["Mizuguchijyounan"] = {"Shiga", {34.96809,136.165547}};
    (*this)["Ohtsu"] = {"Shiga", {35.003051,135.864572}};
    (*this)["Yamashina"] = {"Shiga", {34.992374,135.817157}};

    (*this)["OkinawaKentyou"] = {"Okinawa", {26.214395,127.679337}};
    (*this)["Toyomijyou"] = {"Okinawa", {26.177104,127.681291}};
    (*this)["Itoman"] = {"Okinawa", {26.123542,127.665856}};
    (*this)["Yaesecho"] = {"Okinawa", {26.123528,127.742226}};
    (*this)["Nanpubara"] = {"Okinawa", {26.193297,127.728236}};
    (*this)["Urazoe"] = {"Okinawa", {26.245875,127.721865}};
    (*this)["Nanjyo"] = {"Okinawa", {26.146106,127.769519}};
    (*this)["Yonabaracho"] = {"Okinawa", {26.199558,127.755468}};
    (*this)["Saibaracho"] = {"Okinawa", {26.222837,127.758824}};
    (*this)["Nakajyomura"] = {"Okinawa", {26.262176,127.789834}};
    (*this)["Ginowan"] = {"Okinawa", {26.281497,127.778435}};
    (*this)["Kitanakajyo"] = {"Okinawa", {26.301052,127.793063}};
    (*this)["OkinawaCity"] = {"Okinawa", {26.334248,127.80547}};
    (*this)["Kadenacho"] = {"Okinawa", {26.361372,127.755332}};
    (*this)["Uruma"] = {"Okinawa", {26.378871,127.857378}};
    (*this)["Kanatakecho"] = {"Okinawa", {26.456123,127.926107}};
    (*this)["Ginoza"] = {"Okinawa", {26.481576,127.97558}};
    (*this)["Nago"] = {"Okinawa", {26.591555,127.977475}};
    (*this)["Iemura"] = {"Okinawa", {26.713491,127.807017}};
    (*this)["Miyakojima"] = {"Okinawa", {24.846095,125.301883}};
    (*this)["Ishigaki"] = {"Okinawa", {24.471136,124.205}};
  
    (*this)["Gakuenmae"] = {"Hokkaido", {43.047499,141.369021}};
    (*this)["Tokeidai"] = {"Hokkaido", {43.06579,141.352372}};
    (*this)["YozemiSapporo"] = {"Hokkaido", {43.069678,141.352732}};
    (*this)["Higashikuyakusho"] = {"Hokkaido", {43.076165,141.363593}};
    (*this)["Siroishieki"] = {"Hokkaido", {43.046343,141.395505}};
    (*this)["Kotonieki"] = {"Hokkaido", {43.081541,141.307393}};
    (*this)["Kiyota"] = {"Hokkaido", {42.999588,141.44385}};
    (*this)["ShinSapporoeki"] = {"Hokkaido", {43.038692,141.472363}};
    (*this)["Kitahiroshima"] = {"Hokkaido", {42.979328,141.563105}};
    (*this)["Nohoro"] = {"Hokkaido", {43.092147,141.529351}};
    (*this)["Nanhorocho"] = {"Hokkaido", {43.063734,141.650416}};
    (*this)["Naganumacho"] = {"Hokkaido", {43.010334,141.695238}};
    (*this)["Kuriyamaeki"] = {"Hokkaido", {43.058431,141.775886}};
    (*this)["Yuujineki"] = {"Hokkaido", {43.012276,141.785916}};
    (*this)["Oibuneki"] = {"Hokkaido", {42.87385,141.810805}};
    (*this)["Eniwa"] = {"Hokkaido", {42.882703,141.586795}};
    (*this)["Minamishimizuzawa"] = {"Hokkaido", {42.98562,142.006925}};
    (*this)["Ishikari"] = {"Hokkaido", {43.171364,141.315654}};
    (*this)["Teina"] = {"Hokkaido", {43.12023,141.243665}};
    (*this)["Otaru"] = {"Hokkaido", {43.197698,140.993691}};
    (*this)["Yoichi"] = {"Hokkaido", {43.186929,140.794593}};
    (*this)["Kodaira"] = {"Hokkaido", {43.265352,140.638922}};
    (*this)["Iwauchi"] = {"Hokkaido", {42.950828,140.457851}};
    (*this)["Guchian"] = {"Hokkaido", {42.918032,140.770852}};
    (*this)["Ranetsu"] = {"Hokkaido", {42.804538,140.528961}};
    (*this)["Kuromatsunai"] = {"Hokkaido", {42.669798,140.305601}};
    (*this)["Oshamanbe"] = {"Hokkaido", {42.512791,140.375103}};
    (*this)["Konkincho"] = {"Hokkaido", {42.429422,140.009203}};
    (*this)["Yagumoeki"] = {"Hokkaido", {42.253486,140.272988}};
    (*this)["Morieki"] = {"Hokkaido", {42.10893,140.573914}};
    (*this)["Kabecho"] = {"Hokkaido", {42.038376,140.816636}};
    (*this)["Goryoukaku"] = {"Hokkaido", {41.789259,140.752283}};
    (*this)["Nanaehama"] = {"Hokkaido", {41.817275,140.709057}};
    (*this)["Dainakayama"] = {"Hokkaido", {41.864741,140.713442}};
    (*this)["Kikonai"] = {"Hokkaido", {41.677713,140.43396}};
    (*this)["Hukushimacho"] = {"Hokkaido", {41.483786,140.251318}};
    (*this)["Matsumaecho"] = {"Hokkaido", {41.430053,140.110412}};
    (*this)["Uenokunicho"] = {"Hokkaido", {41.801093,140.121346}};
    (*this)["Esashicho"] = {"Hokkaido", {41.869167,140.1275}};
    (*this)["Atsusawabe"] = {"Hokkaido", {41.920898,140.225472}};
    (*this)["Otobecho"] = {"Hokkaido", {41.968357,140.136139}};
    (*this)["Toyoura"] = {"Hokkaido", {42.579842,140.715274}};
    (*this)["Touyako"] = {"Hokkaido", {42.550546,140.763622}};
    (*this)["Datemonbetsu"] = {"Hokkaido", {42.469365,140.856181}};
    (*this)["Higashimuroran"] = {"Hokkaido", {42.349026,141.025831}};
    (*this)["Noboribetsu"] = {"Hokkaido", {42.452047,141.180894}};
    (*this)["Oginoeki"] = {"Hokkaido", {42.521152,141.305988}};
    (*this)["Tomakomai"] = {"Hokkaido", {42.639739,141.596789}};
    (*this)["Atsumacho"] = {"Hokkaido", {42.723698,141.878022}};
    (*this)["Mukawaeki"] = {"Hokkaido", {42.578817,141.923677}};
    (*this)["Hidakamonbetsu"] = {"Hokkaido", {42.481211,142.072588}};
    (*this)["Shinkaneki"] = {"Hokkaido", {42.360761,142.312741}};
    (*this)["Shizuuchi"] = {"Hokkaido", {42.336516,142.360349}};
    (*this)["Higashmachieki"] = {"Hokkaido", {42.156897,142.788593}};
    (*this)["Samanieki"] = {"Hokkaido", {42.127949,142.936087}};
    (*this)["Erimocho"] = {"Hokkaido", {42.016236,143.148553}};
    (*this)["Nakahudauchi"] = {"Hokkaido", {42.698005,143.134159}};
    (*this)["Urahoro"] = {"Hokkaido", {42.810447,143.651454}};
    (*this)["Ikedaeki"] = {"Hokkaido", {42.921448,143.45325}};
    (*this)["Hudauchi"] = {"Hokkaido", {42.912643,143.256177}};
    (*this)["Obihiro"] = {"Hokkaido", {42.917948,143.20205}};
    (*this)["Otosaracho"] = {"Hokkaido", {42.994176,143.197923}};
    (*this)["Memuroeki"] = {"Hokkaido", {42.91003,143.048335}};
    (*this)["Tokachishimizu"] = {"Hokkaido", {43.013738,142.879793}};
    (*this)["Shintoku"] = {"Hokkaido", {43.082511,142.832569}};
    (*this)["Hurano"] = {"Hokkaido", {43.347089,142.391256}};
    (*this)["Nakahurano"] = {"Hokkaido", {43.405833,142.420972}};
    (*this)["Kamihurano"] = {"Hokkaido", {43.463967,142.469325}};
    (*this)["Ashibetsu"] = {"Hokkaido", {43.516506,142.184264}};
    (*this)["Akahiraeki"] = {"Hokkaido", {43.554802,142.048524}};
    (*this)["Takigawaeki"] = {"Hokkaido", {43.55517,141.901245}};
    (*this)["Shintotsukawa"] = {"Hokkaido", {43.545836,141.874376}};
    (*this)["Sunagawa"] = {"Hokkaido", {43.492941,141.90917}};
    (*this)["Miutaeki"] = {"Hokkaido", {43.330976,141.862046}};
    (*this)["Mikasa"] = {"Hokkaido", {43.245532,141.875289}};
    (*this)["Iwamizawa"] = {"Hokkaido", {43.204014,141.759718}};
    (*this)["Shinshinotsu"] = {"Hokkaido", {43.22531,141.649353}};
    (*this)["Shiranuka"] = {"Hokkaido", {42.956195,144.076746}};
    (*this)["Kushiro"] = {"Hokkaido", {42.990412,144.381878}};
    (*this)["Atsugisi"] = {"Hokkaido", {43.056181,144.841165}};
    (*this)["Sanai"] = {"Hokkaido", {43.129346,145.027922}};
    (*this)["Nemuro"] = {"Hokkaido", {43.32368,145.597201}};
    (*this)["Betsukaicho"] = {"Hokkaido", {43.393791,145.117546}};
    (*this)["Montyaeki"] = {"Hokkaido", {43.298465,144.608167}};
    (*this)["Nakahyoutsu"] = {"Hokkaido", {43.555221,144.971426}};
    (*this)["Hyoutsu"] = {"Hokkaido", {43.661375,145.131422}};
    (*this)["Rausu"] = {"Hokkaido", {44.021867,145.189673}};
    (*this)["Shiretokosharieki"] = {"Hokkaido", {43.910994,144.661526}};
    (*this)["Koshimizu"] = {"Hokkaido", {43.85666,144.462174}};
    (*this)["Katsuradai"] = {"Hokkaido", {44.017034,144.273315}};
    (*this)["Omanbetsu"] = {"Hokkaido", {43.91606,144.171346}};
    (*this)["Mihoro"] = {"Hokkaido", {43.836597,144.106304}};
    (*this)["HokkaidoKitami"] = {"Hokkaido", {43.804867,143.89722}};
    (*this)["Tsubetsu"] = {"Hokkaido", {43.706356,144.025018}};
    (*this)["Kunshihucho"] = {"Hokkaido", {43.725349,143.741719}};
    (*this)["Saromacho"] = {"Hokkaido", {44.017858,143.774644}};
    (*this)["Enkei"] = {"Hokkaido", {44.059921,143.520633}};
    (*this)["Monbetsu"] = {"Hokkaido", {44.356353,143.354406}};
    (*this)["Shimokawacho"] = {"Hokkaido", {44.302631,142.63541}};
    (*this)["Nayori"] = {"Hokkaido", {44.349383,142.465274}};
    (*this)["Shibetsu"] = {"Hokkaido", {44.17254,142.388257}};
    (*this)["Wakan"] = {"Hokkaido", {44.027174,142.415321}};
    (*this)["Takasucho"] = {"Hokkaido", {43.843388,142.354501}};
    (*this)["Touma"] = {"Hokkaido", {43.825452,142.516769}};
    (*this)["Asahikawa"] = {"Hokkaido", {43.762762,142.358511}};
    (*this)["Higashishinraku"] = {"Hokkaido", {43.696632,142.451467}};
    (*this)["Biei"] = {"Hokkaido", {43.59114,142.46175}};
    (*this)["Otakecho"] = {"Hokkaido", {44.582563,142.962028}};
    (*this)["Mishincho"] = {"Hokkaido", {44.482965,142.35039}};
    (*this)["Shisachicho"] = {"Hokkaido", {44.938695,142.581442}};
    (*this)["Tenshiocho"] = {"Hokkaido", {44.888285,141.745144}};
    (*this)["Houhu"] = {"Hokkaido", {45.104569,141.772491}};
    (*this)["Sarubarai"] = {"Hokkaido", {45.33065,142.109133}};
    (*this)["Wakkanai"] = {"Hokkaido", {45.398145,141.683072}};

    (*this)["Nagoyaeki"] = {"Aichi", {35.170915,136.881537}};
    (*this)["Sakaecho"] = {"Aichi", {35.170529,136.908809}};
    (*this)["Kuyaoodouri"] = {"Aichi", {35.173741,136.907777}};
    (*this)["Sasasima"] = {"Aichi", {35.161868,136.881793}};
    (*this)["Jyoushin"] = {"Aichi", {35.192207,136.890837}};
    (*this)["Hutatsuiri"] = {"Aichi", {35.194692,136.859229}};
    (*this)["Jinmokudera"] = {"Aichi", {35.195969,136.825482}};
    (*this)["Daichicho"] = {"Aichi", {35.175095,136.8201}};
    (*this)["Kintetsukanie"] = {"Aichi", {35.129734,136.794151}};
    (*this)["Kintetsuyatomi"] = {"Aichi", {35.113605,136.727575}};
    (*this)["Asukamura"] = {"Aichi", {35.078861,136.791252}};
    (*this)["Ohtagawa"] = {"Aichi", {35.020489,136.892837}};
    (*this)["Asakura"] = {"Aichi", {34.99361,136.863111}};
    (*this)["Kyouwa"] = {"Aichi", {35.035379,136.954532}};
    (*this)["Ogawaeki"] = {"Aichi", {34.981247,136.971893}};
    (*this)["Mikawatakahama"] = {"Aichi", {34.930513,136.990046}};
    (*this)["Aominami"] = {"Aichi", {34.887203,136.989655}};
    (*this)["Nishio"] = {"Aichi", {34.863822,137.057908}};
    (*this)["Kouda"] = {"Aichi", {34.859944,137.164655}};
    (*this)["Gamagouri"] = {"Aichi", {34.82292,137.226053}};
    (*this)["Kokuhu"] = {"Aichi", {34.837608,137.328123}};
    (*this)["Ekimaeoodouri"] = {"Aichi", {34.763115,137.385865}};
    (*this)["Mikawatawara"] = {"Aichi", {34.666866,137.268739}};
    (*this)["Shinshiro"] = {"Aichi", {34.90113,137.493018}};
    (*this)["Toyota"] = {"Aichi", {35.055469,137.150706}};
    (*this)["Miyoshigaoka"] = {"Aichi", {35.126928,137.111098}};
    (*this)["Nagakude"] = {"Aichi", {35.171534,137.049736}};
    (*this)["Owariseto"] = {"Aichi", {35.225197,137.097309}};
    (*this)["Takakuradera"] = {"Aichi", {35.264438,137.043071}};
    (*this)["Owariasahi"] = {"Aichi", {35.216888,137.03599}};
    (*this)["Komakiguchi"] = {"Aichi", {35.281767,136.927636}};
    (*this)["Inuyama"] = {"Aichi", {35.38032,136.945692}};
    (*this)["Hukuwa"] = {"Aichi", {35.359675,136.916051}};
    (*this)["Kashimori"] = {"Aichi", {35.344872,136.90045}};
    (*this)["Enan"] = {"Aichi", {35.335113,136.872086}};
    (*this)["Owariichinomiya"] = {"Aichi", {35.30218,136.797338}};
    (*this)["Tsushima"] = {"Aichi", {35.177619,136.730825}};
    (*this)["Hibino"] = {"Aichi", {35.163637,136.728547}};
    (*this)["Denmacho"] = {"Aichi", {35.120775,136.910384}};
    (*this)["Toyotahoncho"] = {"Aichi", {35.113647,136.910783}};
    (*this)["Minatokuyakusho"] = {"Aichi", {35.106081,136.884808}};

    (*this)["Hakata"] = {"Hukuoka", {33.589728,130.420727}};
    (*this)["Tenjin"] = {"Hukuoka", {33.588689,130.399966}};
    (*this)["Takamiya"] = {"Hukuoka", {33.56699,130.41477}};
    (*this)["Nishishineki"] = {"Hukuoka", {33.583521,130.359206}};
    (*this)["Hukudaimae"] = {"Hukuoka", {33.547478,130.36222}};
    (*this)["Meihama"] = {"Hukuoka", {33.583748,130.325073}};
    (*this)["Chikuzenmaehara"] = {"Hukuoka", {33.557077,130.199326}};
    (*this)["Yoshitomi"] = {"Hukuoka", {33.604845,131.173822}};
    (*this)["Ushimaeki"] = {"Hukuoka", {33.621218,131.126315}};
    (*this)["Chikujyoueki"] = {"Hukuoka", {33.673149,131.03773}};
    (*this)["Yukihashi"] = {"Hukuoka", {33.728814,130.970099}};
    (*this)["Saigawa"] = {"Hukuoka", {33.650516,130.939303}};
    (*this)["Konamisenishikoudai"] = {"Hukuoka", {33.752989,130.971985}};
    (*this)["Keibajyoumae"] = {"Hukuoka", {33.842926,130.87655}};
    (*this)["Idemitsubijutsukan"] = {"Hukuoka", {33.886968,130.882576}};
    (*this)["Oguraeki"] = {"Hukuoka", {33.947606,130.965246}};
    (*this)["Tohataeki"] = {"Hukuoka", {33.897208,130.82164}};
    (*this)["Hijinoki"] = {"Hukuoka", {33.893374,130.781894}};
    (*this)["Yawataeki"] = {"Hukuoka", {33.869238,130.795365}};
    (*this)["Kurosakieki"] = {"Hukuoka", {33.866787,130.766278}};
    (*this)["Tsuuyaeki"] = {"Hukuoka", {33.822631,130.726123}};
    (*this)["Ashiyacho"] = {"Hukuoka", {33.893854,130.663884}};
    (*this)["Mizumakieki"] = {"Hukuoka", {33.852349,130.695375}};
    (*this)["Chikuhoutyokuhou"] = {"Hukuoka", {33.753389,130.726069}};
    (*this)["Ebitsu"] = {"Hukuoka", {33.840127,130.623882}};
    (*this)["Wakamiya"] = {"Hukuoka", {33.723867,130.667488}};
    (*this)["Akama"] = {"Hukuoka", {33.80813,130.569887}};
    (*this)["Hukuma"] = {"Hukuoka", {33.763596,130.487004}};
    (*this)["Kogaeki"] = {"Hukuoka", {33.732335,130.466642}};
    (*this)["Shinguchuoh"] = {"Hukuoka", {33.711777,130.449262}};
    (*this)["Hukukoudaimae"] = {"Hukuoka", {33.698445,130.440624}};
    (*this)["Hisayamacho"] = {"Hukuoka", {33.646728,130.499881}};
    (*this)["Shinokurieki"] = {"Hukuoka", {33.623916,130.524816}};
    (*this)["Yuzusu"] = {"Hukuoka", {33.613316,130.444654}};
    (*this)["Shimencho"] = {"Hukuoka", {33.591404,130.47973}};
    (*this)["Sukeityuoh"] = {"Hukuoka", {33.586959,130.505094}};
    (*this)["Umieki"] = {"Hukuoka", {33.569142,130.513276}};
    (*this)["Dazaihu"] = {"Hukuoka", {33.519042,130.531392}};
    (*this)["Kasugaeki"] = {"Hukuoka", {33.535362,130.468545}};
    (*this)["Kasugaharaeki"] = {"Hukuoka", {33.537964,130.473126}};
    (*this)["Hakataminami"] = {"Hukuoka", {33.517855,130.436852}};
    (*this)["Tenpaisan"] = {"Hukuoka", {33.482291,130.529984}};
    (*this)["Soeda"] = {"Hukuoka", {33.567274,130.85659}};
    (*this)["Chikugoyoshii"] = {"Hukuoka", {33.340909,130.753134}};
    (*this)["Amaki"] = {"Hukuoka", {33.419218,130.653588}};
    (*this)["Tachiarai"] = {"Hukuoka", {33.413898,130.618894}};
    (*this)["Nishitetsukogouri"] = {"Hukuoka", {33.396121,130.553567}};
    (*this)["Imaguma"] = {"Hukuoka", {33.403821,130.593985}};
    (*this)["Ohmuta"] = {"Hukuoka", {33.029659,130.44409}};
    (*this)["Ookawa"] = {"Hukuoka", {33.206618,130.384004}};
    (*this)["Kurume"] = {"Hukuoka", {33.312436,130.521461}};  
  
    (*this)["Kesennuma"] = {"Miyagi", {38.89852,141.562502}};
    (*this)["Aobadoori"] = {"Miyagi", {38.260683,140.878116}};
    (*this)["Sendaieki"] = {"Miyagi", {38.260132,140.882437}};
    (*this)["Miyaginodoori"] = {"Miyagi", {38.258472,140.885965}};
    (*this)["Nagamachiminami"] = {"Miyagi", {38.22462,140.87656}};
    (*this)["Morisekinoshita"] = {"Miyagi", {38.165349,140.896144}};
    (*this)["Iwanuma"] = {"Miyagi", {38.111908,140.864159}};
    (*this)["Watarieki"] = {"Miyagi", {38.039891,140.861264}};
    (*this)["Muratacho"] = {"Miyagi", {38.118539,140.722405}};
    (*this)["Kawasakicho"] = {"Miyagi", {38.177756,140.64316}};
    (*this)["Hunaokaeki"] = {"Miyagi", {38.05928,140.768335}};
    (*this)["Kakutaeki"] = {"Miyagi", {37.979284,140.772442}};
    (*this)["Shiroishi"] = {"Miyagi", {38.00359,140.626246}};
    (*this)["Oogawara"] = {"Miyagi", {38.047775,140.740608}};
    (*this)["Tagajyo"] = {"Miyagi", {38.291807,141.005809}};
    (*this)["Shiogama"] = {"Miyagi", {38.311919,141.018321}};
    (*this)["Rihu"] = {"Miyagi", {38.329472,140.98474}};
    (*this)["Izumi"] = {"Miyagi", {38.323359,140.880805}};
    (*this)["Matsushima"] = {"Miyagi", {38.382774,141.073535}};
    (*this)["Oosatocho"] = {"Miyagi", {38.424289,141.004491}};
    (*this)["Rikuzenakai"] = {"Miyagi", {38.432523,141.238991}};
    (*this)["Taiwacho"] = {"Miyagi", {38.437381,140.886333}};
    (*this)["Ishinomaki"] = {"Miyagi", {38.435358,141.303485}};
    (*this)["Oushida"] = {"Miyagi", {38.541502,141.063707}};
    (*this)["Hurukawa"] = {"Miyagi", {38.57061,140.96773}};
    (*this)["Shikimacho"] = {"Miyagi", {38.548929,140.849908}};
    (*this)["Kamicho"] = {"Miyagi", {38.571763,140.854793}};

    (*this)["Atami"] = {"Shizuoka", {35.103842,139.077884}};
    (*this)["Ito"] = {"Shizuoka", {34.97461,139.092218}};
    (*this)["Izu"] = {"Shizuoka", {34.774544,139.037391}};
    (*this)["Kawazu"] = {"Shizuoka", {34.747407,138.995923}};
    (*this)["Shimoda"] = {"Shizuoka", {34.67912,138.944444}};
    (*this)["Matsuzakicho"] = {"Shizuoka", {34.752722,138.778838}};
    (*this)["Nishiizu"] = {"Shizuoka", {34.771693,138.775334}};
    (*this)["Shuuzenji"] = {"Shizuoka", {34.979241,138.950974}};
    (*this)["Izunagaoka"] = {"Shizuoka", {35.039818,138.9475}};
    (*this)["Izunita"] = {"Shizuoka", {35.079111,138.941606}};
    (*this)["Shimizucho"] = {"Shizuoka", {35.099033,138.902749}};
    (*this)["Mishima"] = {"Shizuoka", {35.119335,138.911166}};
    (*this)["Shimodokari"] = {"Shizuoka", {35.129525,138.895277}};
    (*this)["Susono"] = {"Shizuoka", {35.171742,138.909466}};
    (*this)["Gotenba"] = {"Shizuoka", {35.300123,138.934056}};
    (*this)["Surugakoyama"] = {"Shizuoka", {35.358706,138.998844}};
    (*this)["Numazu"] = {"Shizuoka", {35.102649,138.859801}};
    (*this)["Yuzukieki"] = {"Shizuoka", {35.157333,138.639207}};
    (*this)["Hujinomiya"] = {"Shizuoka", {35.221205,138.615215}};
    (*this)["Kusanagi"] = {"Shizuoka", {35.002586,138.441433}};
    (*this)["Higashishizuoka"] = {"Shizuoka", {34.984763,138.413538}};
    (*this)["Shizuokaeki"] = {"Shizuoka", {34.972187,138.3889}};
    (*this)["Yaizu"] = {"Shizuoka", {34.872459,138.318504}};
    (*this)["Hujieda"] = {"Shizuoka", {34.849182,138.252038}};
    (*this)["Yoshidacho"] = {"Shizuoka", {34.770963,138.252077}};
    (*this)["Makinohara"] = {"Shizuoka", {34.740001,138.224625}};
    (*this)["Shimada"] = {"Shizuoka", {34.830155,138.173407}};
    (*this)["Omaezaki"] = {"Shizuoka", {34.637974,138.128162}};
    (*this)["Kikukawa"] = {"Shizuoka", {34.761665,138.085343}};
    (*this)["Kakegawa"] = {"Shizuoka", {34.77039,137.999797}};
    (*this)["Ainoeki"] = {"Shizuoka", {34.752465,137.961651}};
    (*this)["Tomen"] = {"Shizuoka", {34.83139,137.930775}};
    (*this)["Iwata"] = {"Shizuoka", {34.710188,137.852327}};
    (*this)["Hutamatahoncho"] = {"Shizuoka", {34.859614,137.812714}};
    (*this)["Enshukomatsu"] = {"Shizuoka", {34.784639,137.778099}};
    (*this)["Jidoushagakkoumae"] = {"Shizuoka", {34.747681,137.751862}};
    (*this)["Daiichidoori"] = {"Shizuoka", {34.707268,137.732676}};
    (*this)["Takatsuka"] = {"Shizuoka", {34.690575,137.681954}};
    (*this)["Kansanji"] = {"Shizuoka", {34.763764,137.61731}};
    (*this)["Higashitsuzuki"] = {"Shizuoka", {34.790238,137.586723}};
    (*this)["Washizu"] = {"Shizuoka", {34.716707,137.546326}};

    (*this)["Hukuyama"] = {"Hiroshima", {34.488944,133.362542}};
    (*this)["Takagi"] = {"Hiroshima", {34.562959,133.253346}};
    (*this)["Bigoshouhara"] = {"Hiroshima", {34.862336,133.016474}};
    (*this)["Onomichi"] = {"Hiroshima", {34.404865,133.193159}};
    (*this)["Ueshimacho"] = {"Hiroshima", {34.257467,133.204492}};
    (*this)["Miharaeki"] = {"Hiroshima", {34.400708,133.083197}};
    (*this)["Mitsugi"] = {"Hiroshima", {34.802645,132.856152}};
    (*this)["Mukoubara"] = {"Hiroshima", {34.615053,132.720031}};
    (*this)["Saijyoueki"] = {"Hiroshima", {34.431407,132.743896}};
    (*this)["Takeharaeki"] = {"Hiroshima", {34.339477,132.910661}};
    (*this)["Kumanocho"] = {"Hiroshima", {34.335791,132.584506}};
    (*this)["Kure"] = {"Hiroshima", {34.244647,132.557585}};
    (*this)["Yanoeki"] = {"Hiroshima", {34.352111,132.531952}};
    (*this)["Kaidacho"] = {"Hiroshima", {34.372264,132.53609}};
    (*this)["Sakaeki"] = {"Hiroshima", {34.338752,132.510788}};
    (*this)["Kouyoueki"] = {"Hiroshima", {34.376325,132.506446}};
    (*this)["Kumuraeki"] = {"Hiroshima", {34.482091,132.508082}};
    (*this)["Hiroshimaeki"] = {"Hiroshima", {34.397667,132.475379}};
    (*this)["Inaricho"] = {"Hiroshima", {34.392666,132.47123}};
    (*this)["Kamiyacho"] = {"Hiroshima", {34.3955,132.456854}};
    (*this)["Yokogawaeki"] = {"Hiroshima", {34.40996,132.450602}};
    (*this)["Saibaraeki"] = {"Hiroshima", {34.443331,132.474793}};
    (*this)["Kitahiroshimacho"] = {"Hiroshima", {34.674644,132.538386}};
    (*this)["Rakurakuen"] = {"Hiroshima", {34.364296,132.351961}};
    (*this)["JAHiroshima"] = {"Hiroshima", {34.343936,132.322436}};
    (*this)["Akiootacho"] = {"Hiroshima", {34.576781,132.227171}};
    (*this)["Ootake"] = {"Hiroshima", {34.217754,132.223365}};

    (*this)["Simokitaeki"] = {"Aomori", {41.282743,141.189904}};
    (*this)["Mutsuyokohama"] = {"Aomori", {41.086601,141.249659}};
    (*this)["Rokkasho"] = {"Aomori", {40.967402,141.374211}};
    (*this)["Noheji"] = {"Aomori", {40.85518,141.119545}};
    (*this)["Aomorieki"] = {"Aomori", {40.828675,140.734745}};
    (*this)["Misawa"] = {"Aomori", {40.669446,141.353717}};
    (*this)["Towada"] = {"Aomori", {40.612571,141.205468}};
    (*this)["Hachinohe"] = {"Aomori", {40.516288,141.488974}};
    (*this)["Tagocho"] = {"Aomori", {40.340033,141.152283}};
    (*this)["Goshogawara"] = {"Aomori", {40.808915,140.447774}};
    (*this)["Ajigasawa"] = {"Aomori", {40.775218,140.220741}};
    (*this)["Tsuruta"] = {"Aomori", {40.757977,140.435356}};
    (*this)["Itayanagi"] = {"Aomori", {40.697207,140.461723}};
    (*this)["Kuroishi"] = {"Aomori", {40.648188,140.59183}};
    (*this)["Kawabecho"] = {"Aomori", {40.646628,140.52091}};
    (*this)["Hujisaki"] = {"Aomori", {40.653574,140.500028}};
    (*this)["Hirosaki"] = {"Aomori", {40.599151,140.48522}};
    (*this)["Hiraka"] = {"Aomori", {40.584973,140.561026}};
    (*this)["Oowani"] = {"Aomori", {40.521981,140.566695}};

    (*this)["Taneichi"] = {"Iwate", {40.410363,141.715099}};
    (*this)["Tome"] = {"Iwate", {40.285586,141.290782}};
    (*this)["Kuji"] = {"Iwate", {40.190585,141.770773}};
    (*this)["Iwatemiyauchi"] = {"Iwate", {39.960917,141.217574}};
    (*this)["Oozara"] = {"Iwate", {39.913756,141.100825}};
    (*this)["Takisawa"] = {"Iwate", {39.798806,141.149737}};
    (*this)["Morioka"] = {"Iwate", {39.701437,141.136723}};
    (*this)["Shizukuishi"] = {"Iwate", {39.689203,140.974947}};
    (*this)["Yahaba"] = {"Iwate", {39.613189,141.148107}};
    (*this)["Shiba"] = {"Iwate", {39.554835,141.159859}};
    (*this)["Miyakoeki"] = {"Iwate", {39.640271,141.94658}};
    (*this)["Hanamaki"] = {"Iwate", {39.393164,141.110713}};
    (*this)["Toono"] = {"Iwate", {39.332455,141.530755}};
    (*this)["Iwatehunakosi"] = {"Iwate", {39.43118,141.974017}};
    (*this)["Kirikiri"] = {"Iwate", {39.369714,141.938884}};
    (*this)["Kamaishi"] = {"Iwate", {39.272941,141.872798}};
    (*this)["Kitakami"] = {"Iwate", {39.282201,141.122612}};
    (*this)["Hottoyuda"] = {"Iwate", {39.314649,140.776066}};
    (*this)["Kanegasaki"] = {"Iwate", {39.199875,141.112714}};
    (*this)["Mizusawa"] = {"Iwate", {39.138941,141.146238}};
    (*this)["Hiraizumi"] = {"Iwate", {38.988122,141.11778}};
    (*this)["Ichinoseki"] = {"Iwate", {38.926292,141.137575}};
    (*this)["Oohunato"] = {"Iwate", {39.085517,141.710807}};

    (*this)["Oodate"] = {"Akita", {40.266672,140.554575}};
    (*this)["Takanosu"] = {"Akita", {40.232064,140.369089}};
    (*this)["Hanawa"] = {"Akita", {40.189509,140.785771}};
    (*this)["Noshiro"] = {"Akita", {40.206307,140.033065}};
    (*this)["Hachirougata"] = {"Akita", {39.947839,140.078463}};
    (*this)["Gojyoumoku"] = {"Akita", {39.943897,140.111309}};
    (*this)["Igawasakura"] = {"Akita", {39.911982,140.075993}};
    (*this)["Ookuboeki"] = {"Akita", {39.870904,140.062996}};
    (*this)["Oga"] = {"Akita", {39.883618,139.848292}};
    (*this)["Akitaeki"] = {"Akita", {39.716884,140.129853}};
    (*this)["Kakudate"] = {"Akita", {39.591716,140.571064}};
    (*this)["Oomagari"] = {"Akita", {39.465628,140.479806}};
    (*this)["Nanegohonjyou"] = {"Akita", {39.386609,140.057298}};
    (*this)["Nikaho"] = {"Akita", {39.289847,139.963931}};
    (*this)["Yokote"] = {"Akita", {39.31029,140.560646}};
    (*this)["Yuzawa"] = {"Akita", {39.163777,140.486993}};

    (*this)["Yuusa"] = {"Yamagata", {39.015999,139.905427}};
    (*this)["Sakata"] = {"Yamagata", {38.922231,139.845895}};
    (*this)["Yomoku"] = {"Yamagata", {38.844242,139.911448}};
    (*this)["Mamurogawa"] = {"Yamagata", {38.858278,140.254834}};
    (*this)["Shinjyo"] = {"Yamagata", {38.762011,140.306147}};
    (*this)["Mogami"] = {"Yamagata", {38.755881,140.517594}};
    (*this)["Tsuruoka"] = {"Yamagata", {38.740141,139.835488}};
    (*this)["Ooishida"] = {"Yamagata", {38.595784,140.375336}};
    (*this)["Murayama"] = {"Yamagata", {38.477076,140.386396}};
    (*this)["Sakuranbohigashine"] = {"Yamagata", {38.428415,140.380816}};
    (*this)["Kahokucho"] = {"Yamagata", {38.426307,140.314309}};
    (*this)["Hidarisawa"] = {"Yamagata", {38.382165,140.208055}};
    (*this)["Sagae"] = {"Yamagata", {38.372057,140.274633}};
    (*this)["Tendou"] = {"Yamagata", {38.341621,140.365648}};
    (*this)["Hanemaenagasaki"] = {"Yamagata", {38.333589,140.273324}};
    (*this)["Hanemaeyamabe"] = {"Yamagata", {38.294566,140.271554}};
    (*this)["Yamagataeki"] = {"Yamagata", {38.248926,140.327303}};
    (*this)["Kaminoyama"] = {"Yamagata", {38.152194,140.278615}};
    (*this)["Ayamekouen"] = {"Yamagata", {38.114303,140.032666}};
    (*this)["Miyauchieki"] = {"Yamagata", {38.070866,140.135354}};
    (*this)["Hanemaekomatsu"] = {"Yamagata", {38.00476,140.048531}};
    (*this)["Yonezawa"] = {"Yamagata", {37.909638,140.128107}};
  
    (*this)["Hujitaeki"] = {"Hukushima", {37.8789,140.539466}};
    (*this)["Kuwaori"] = {"Hukushima", {37.855228,140.517555}};
    (*this)["Hohara"] = {"Hukushima", {37.814735,140.556271}};
    (*this)["Hukushimaeki"] = {"Hukushima", {37.754212,140.459216}};
    (*this)["Souma"] = {"Hukushima", {37.802531,140.925714}};
    (*this)["Haranomachi"] = {"Hukushima", {37.638134,140.970968}};
    (*this)["Kawamatacho"] = {"Hukushima", {37.664994,140.598313}};
    (*this)["Nihonmatsu"] = {"Hukushima", {37.589603,140.435427}};
    (*this)["Ootamamura"] = {"Hukushima", {37.534388,140.371189}};
    (*this)["Motomiya"] = {"Hukushima", {37.514146,140.399542}};
    (*this)["Inawashiro"] = {"Hukushima", {37.546452,140.103088}};
    (*this)["Nishiwakamatsu"] = {"Hukushima", {37.485955,139.914094}};
    (*this)["Aizusakashita"] = {"Hukushima", {37.55675,139.821515}};
    (*this)["Aizutakada"] = {"Hukushima", {37.470899,139.841323}};
    (*this)["Kooriyama"] = {"Hukushima", {37.398196,140.388129}};
    (*this)["Sukagawa"] = {"Hukushima", {37.300306,140.372098}};
    (*this)["Onoshinmachi"] = {"Hukushima", {37.275204,140.636783}};
    (*this)["Hirono"] = {"Hukushima", {37.211628,140.998652}};
    (*this)["Banjyouishikawa"] = {"Hukushima", {37.140759,140.44398}};
    (*this)["Banjyouasakawa"] = {"Hukushima", {37.079849,140.414402}};
    (*this)["Tyuuhou"] = {"Hukushima", {37.022494,140.393267}};
    (*this)["Banjyouhanawa"] = {"Hukushima", {36.958696,140.412046}};
    (*this)["Shinsirakawa"] = {"Hukushima", {37.122914,140.188107}};
    (*this)["Shirakawa"] = {"Hukushima", {37.130199,140.21275}};
    (*this)["Izumisaki"] = {"Hukushima", {37.158087,140.298972}};
    (*this)["Yabuki"] = {"Hukushima", {37.205325,140.328165}};
    (*this)["Kagamiishi"] = {"Hukushima", {37.250605,140.346789}};
    (*this)["Iwaki"] = {"Hukushima", {37.058216,140.892236}};

    (*this)["Murakami"] = {"Niigata", {38.220318,139.463574}};
    (*this)["Shinhotta"] = {"Niigata", {37.944053,139.335096}};
    (*this)["Houei"] = {"Niigata", {37.920108,139.215913}};
    (*this)["Niigataeki"] = {"Niigata", {37.912039,139.061775}};
    (*this)["Echigoishiyama"] = {"Niigata", {37.896357,139.095397}};
    (*this)["Aoyamaeki"] = {"Niigata", {37.898759,139.001779}};
    (*this)["Kameda"] = {"Niigata", {37.877391,139.108173}};
    (*this)["Mizuhara"] = {"Niigata", {37.83648,139.21725}};
    (*this)["Niizu"] = {"Niigata", {37.800452,139.121149}};
    (*this)["Goizumi"] = {"Niigata", {37.734406,139.179786}};
    (*this)["Minamikuyakusho"] = {"Niigata", {37.765826,139.019133}};
    (*this)["Maki"] = {"Niigata", {37.756701,138.889477}};
    (*this)["Hanyuuda"] = {"Niigata", {37.693473,139.060738}};
    (*this)["Kamo"] = {"Niigata", {37.658883,139.049023}};
    (*this)["Higashisanjyou"] = {"Niigata", {37.62841,138.974305}};
    (*this)["Yoshidaeki"] = {"Niigata", {37.687125,138.878675}};
    (*this)["Izumosaki"] = {"Niigata", {37.531928,138.716222}};
    (*this)["Mitsukeeki"] = {"Niigata", {37.540171,138.904735}};
    (*this)["Nagaoka"] = {"Niigata", {37.448014,138.854047}};
    (*this)["Kashiwazaki"] = {"Niigata", {37.372959,138.565466}};
    (*this)["Kochitani"] = {"Niigata", {37.309639,138.81353}};
    (*this)["Echigohorinouchi"] = {"Niigata", {37.238928,138.928218}};
    (*this)["Tookamachi"] = {"Niigata", {37.1349,138.75671}};
    (*this)["Takadaeki"] = {"Niigata", {37.115157,138.242226}};
    (*this)["Shiosawa"] = {"Niigata", {37.041398,138.848529}};
    (*this)["Araieki"] = {"Niigata", {37.02674,138.255591}};
    (*this)["Itoigawa"] = {"Niigata", {37.043542,137.861613}};
    (*this)["Sado"] = {"Niigata", {38.067872,138.389126}};

    (*this)["Tomarieki"] = {"Toyama", {36.951953,137.555961}};
    (*this)["Iriyoshi"] = {"Toyama", {36.94139,137.499484}};
    (*this)["Kurobe"] = {"Toyama", {36.873946,137.444367}};
    (*this)["Uotsu"] = {"Toyama", {36.815242,137.400481}};
    (*this)["Namekawa"] = {"Toyama", {36.769384,137.348611}};
    (*this)["Kamiichi"] = {"Toyama", {36.704422,137.357708}};
    (*this)["Ghyakugoku"] = {"Toyama", {36.665341,137.3143}};
    (*this)["Toyamaeki"] = {"Toyama", {36.700806,137.214002}};
    (*this)["ToyamaKosugi"] = {"Toyama", {36.720745,137.09265}};
    (*this)["ToyamaSuehirocho"] = {"Toyama", {36.743813,137.012622}};
    (*this)["Ishidoueki"] = {"Toyama", {36.672439,136.865561}};
    (*this)["Himieki"] = {"Toyama", {36.849492,136.990693}};
    (*this)["Tonami"] = {"Toyama", {36.636555,136.953693}};
    (*this)["Hukuno"] = {"Toyama", {36.58855,136.923185}};

    (*this)["Wajima"] = {"Ishikawa", {37.390552,136.899096}};
    (*this)["Notocho"] = {"Ishikawa", {37.310334,137.147694}};
    (*this)["Anamizu"] = {"Ishikawa", {37.227904,136.904591}};
    (*this)["Nanao"] = {"Ishikawa", {37.042416,136.963985}};
    (*this)["Shigacho"] = {"Ishikawa", {37.006167,136.778012}};
    (*this)["Notobe"] = {"Ishikawa", {36.961389,136.869612}};
    (*this)["Hanesaku"] = {"Ishikawa", {36.89664,136.78326}};
    (*this)["Unoki"] = {"Ishikawa", {36.722624,136.702879}};
    (*this)["Uchinada"] = {"Ishikawa", {36.633381,136.634268}};
    (*this)["Kanazawa"] = {"Ishikawa", {36.578044,136.648171}};
    (*this)["Oshino"] = {"Ishikawa", {36.541865,136.622088,}};
    (*this)["Mattou"] = {"Ishikawa", {36.52681,136.566371}};
    (*this)["Nominegami"] = {"Ishikawa", {36.452119,136.45954}};
    (*this)["Komatsu"] = {"Ishikawa", {36.40271,136.452831}};
    (*this)["Kaga"] = {"Ishikawa", {36.32055,136.350315}};

    (*this)["Ashiwara"] = {"Hukui", {36.214555,136.235015}};
    (*this)["Maruoka"] = {"Hukui", {36.162344,136.233498}};
    (*this)["Matsuoka"] = {"Hukui", {36.094031,136.301845}};
    (*this)["Hukuieki"] = {"Hukui", {36.06165,136.223546}};
    (*this)["Echizenoono"] = {"Hukui", {35.983176,136.496954}};
    (*this)["Kitasabae"] = {"Hukui", {35.971301,136.198583}};
    (*this)["Echizencho"] = {"Hukui", {35.974312,136.129734}};
    (*this)["HukuiTakeo"] = {"Hukui", {35.903455,136.170902}};
    (*this)["HukuiNanjyo"] = {"Hukui", {35.832307,136.193395}};
    (*this)["Suruga"] = {"Hukui", {35.644827,136.076326}};
    (*this)["Obama"] = {"Hukui", {35.485188,135.781118}};
    (*this)["Wakasahongou"] = {"Hukui", {35.482623,135.619313}};
    (*this)["Wakasatakahama"] = {"Hukui", {35.486407,135.547584}};

    (*this)["Nagasaka"] = {"Yamanashi", {35.826908,138.366269}};
    (*this)["Nirasaki"] = {"Yamanashi", {35.709951,138.451155}};
    (*this)["Shioyama"] = {"Yamanashi", {35.705404,138.734381}};
    (*this)["Ootsuki"] = {"Yamanashi", {35.60942,138.938089}};
    (*this)["Uenohara"] = {"Yamanashi", {35.618479,139.115463}};
    (*this)["Tanimuracho"] = {"Yamanashi", {35.550561,138.904672}};
    (*this)["Mitsutouge"] = {"Yamanashi", {35.524288,138.845517}};
    (*this)["Kawaguchiko"] = {"Yamanashi", {35.498236,138.768841}};
    (*this)["Hujisaneki"] = {"Yamanashi", {35.483549,138.795685}};
    (*this)["Yamanashieki"] = {"Yamanashi", {35.684988,138.682858}};
    (*this)["Ishiwaonsen"] = {"Yamanashi", {35.657664,138.635272}};
    (*this)["Kouhueki"] = {"Yamanashi", {35.666674,138.568785}};
    (*this)["Ryuuoueki"] = {"Yamanashi", {35.668708,138.519373}};
    (*this)["Tsunenaga"] = {"Yamanashi", {35.617075,138.533096}};
    (*this)["Minamialps"] = {"Yamanashi", {35.608395,138.464814}};
    (*this)["Ichikawadaimon"] = {"Yamanashi", {35.560469,138.493379}};
    (*this)["Hujikawacho"] = {"Yamanashi", {35.561175,138.461397}};

    (*this)["Kitaiiyama"] = {"Nagano", {36.859037,138.363932}};
    (*this)["Shinshunakano"] = {"Nagano", {36.744772,138.364902}};
    (*this)["Yudanaka"] = {"Nagano", {36.741638,138.414728}};
    (*this)["Kohuse"] = {"Nagano", {36.698941,138.312862}};
    (*this)["Suzaka"] = {"Nagano", {36.678393,138.308684}};
    (*this)["Naganoeki"] = {"Nagano", {36.643124,138.188644}};
    (*this)["Yashiro"] = {"Nagano", {36.531993,138.128097}};
    (*this)["Sakashiro"] = {"Nagano", {36.462421,138.181245}};
    (*this)["Ikedacho"] = {"Nagano", {36.421403,137.874571}};
    (*this)["Shinanomatsukawa"] = {"Nagano", {36.425287,137.858278}};
    (*this)["Shinanooomachi"] = {"Nagano", {36.49992,137.861261}};
    (*this)["Uedaeki"] = {"Nagano", {36.396487,138.249638}};
    (*this)["Aokimura"] = {"Nagano", {36.370077,138.128514}};
    (*this)["Toyoshina"] = {"Nagano", {36.30025,137.90097}};
    (*this)["Matsumoto"] = {"Nagano", {36.230815,137.964355}};
    (*this)["Hirooka"] = {"Nagano", {36.148217,137.949559  }};
    (*this)["Shimosuwa"] = {"Nagano", {36.071984,138.085061}};
    (*this)["Okaya"] = {"Nagano", {36.056985,138.045399}};
    (*this)["Miyaki"] = {"Nagano", {35.976407,137.990649}};
    (*this)["Kayanoeki"] = {"Nagano", {35.9948,138.152503}};
    (*this)["Haramura"] = {"Nagano", {35.958031,138.272589}};
    (*this)["Inamatsushima"] = {"Nagano", {35.913805,137.988631}};
    (*this)["Kitadono"] = {"Nagano", {35.879531,137.984022}};
    (*this)["Hujimieki"] = {"Nagano", {35.912228,138.23786}};
    (*this)["Inaeki"] = {"Nagano", {35.838369,137.959165}};
    (*this)["Miyataeki"] = {"Nagano", {35.767269,137.938944}};
    (*this)["Komagane"] = {"Nagano", {35.736296,137.936782}};
    (*this)["Iijima"] = {"Nagano", {35.678021,137.928799}};
    (*this)["Uematsu"] = {"Nagano", {35.78409,137.693273}};
    (*this)["Kisohukushima"] = {"Nagano", {35.843778,137.69341}};
    (*this)["Inaooshima"] = {"Nagano", {35.595784,137.913261}};
    (*this)["NaganoToyooka"] = {"Nagano", {35.551373,137.896088}};
    (*this)["Ichita"] = {"Nagano", {35.549344,137.886543}};
    (*this)["Iida"] = {"Nagano", {35.519564,137.821249}};

    (*this)["Minoshiratori"] = {"Gihu", {35.884914,136.860593}};
    (*this)["Takayama"] = {"Gihu", {36.141076,137.251365}};
    (*this)["Hidahurukawa"] = {"Gihu", {36.236726,137.189603}};
    (*this)["Gero"] = {"Gihu", {35.921587,137.465382}};
    (*this)["Kamiasou"] = {"Gihu", {35.541425,137.118725}};
    (*this)["Nakatsugawa"] = {"Gihu", {35.500502,137.503153}};
    (*this)["Ena"] = {"Gihu", {35.455097,137.40817}};
    (*this)["Mizunami"] = {"Gihu", {35.36907,137.252033}};
    (*this)["Toki"] = {"Gihu", {35.359764,137.182195}};
    (*this)["Yamozu"] = {"Gihu", {35.476007,137.14143}};
    (*this)["Odaka"] = {"Gihu", {35.429718,137.128229}};
    (*this)["Tajimi"] = {"Gihu", {35.334979,137.121042}};
    (*this)["Nakakawabe"] = {"Gihu", {35.487542,137.065359}};
    (*this)["Imawatarieki"] = {"Gihu", {35.432315,137.037186}};
    (*this)["Minooota"] = {"Gihu", {35.445588,137.019416}};
    (*this)["Sakaiwa"] = {"Gihu", {35.426338,136.976865}};
    (*this)["Toka"] = {"Gihu", {35.47531,136.969319}};
    (*this)["Umeyama"] = {"Gihu", {35.548709,136.917939}};
    (*this)["Hamonokaikan"] = {"Gihu", {35.483542,136.914116}};
    (*this)["Nakaeki"] = {"Gihu", {35.400514,136.835804}};
    (*this)["Kasamatsu"] = {"Gihu", {35.374073,136.764287}};
    (*this)["Ginan"] = {"Gihu", {35.389779,136.769229}};
    (*this)["Gihueki"] = {"Gihu", {35.409528,136.756466}};
    (*this)["Moreragihu"] = {"Gihu", {35.455406,136.670048}};
    (*this)["Kitakatacho"] = {"Gihu", {35.435774,136.684343}};
    (*this)["Hozumi"] = {"Gihu", {35.396082,136.693097}};
    (*this)["Anpachicho"] = {"Gihu", {35.335418,136.665415}};
    (*this)["Shinhatori"] = {"Gihu", {35.315747,136.686397}};
    (*this)["Oonocho"] = {"Gihu", {35.470708,136.627665}};
    (*this)["Ibieki"] = {"Gihu", {35.470237,136.572521}};
    (*this)["Kitaikeno"] = {"Gihu", {35.443434,136.573661}};
    (*this)["Hirokoube"] = {"Gihu", {35.419827,136.602104}};
    (*this)["Oogaki"] = {"Gihu", {35.366778,136.617826}};
    (*this)["Tarui"] = {"Gihu", {35.369692,136.531084}};
    (*this)["Sekigahara"] = {"Gihu", {35.363802,136.470368}};
    (*this)["Minotakada"] = {"Gihu", {35.309061,136.563584}};
    (*this)["Komano"] = {"Gihu", {35.223682,136.603583}};

    (*this)["Nishikuwana"] = {"Mie", {35.06573,136.683999}};
    (*this)["Asahieki"] = {"Mie", {35.033733,136.657974}};
    (*this)["Kwagoetomisubara"] = {"Mie", {35.016682,136.660154}};
    (*this)["Yokkaichi"] = {"Mie", {34.966323,136.618286}};
    (*this)["Suzuka"] = {"Mie", {34.884064,136.58238}};
    (*this)["Taianeki"] = {"Mie", {35.091982,136.545357}};
    (*this)["Komono"] = {"Mie", {35.008732,136.517376}};
    (*this)["Idagawa"] = {"Mie", {34.86822,136.49255}};
    (*this)["Tsueki"] = {"Mie", {34.733993,136.510243}};
    (*this)["Uenoshieki"] = {"Mie", {34.76755,136.129955}};
    (*this)["Meibari"] = {"Mie", {34.621773,136.095609}};
    (*this)["Matsuzaka"] = {"Mie", {34.576881,136.535564}};
    (*this)["Saimiya"] = {"Mie", {34.537871,136.615218}};
    (*this)["Aikaeki"] = {"Mie", {34.502624,136.545447}};
    (*this)["Tamaru"] = {"Mie", {34.488556,136.634089}};
    (*this)["Ujiyamada"] = {"Mie", {34.488268,136.713961}};
    (*this)["Toba"] = {"Mie", {34.486767,136.843126}};
    (*this)["Ukataeki"] = {"Mie", {34.329317,136.825901}};
    (*this)["Minamiiki"] = {"Mie", {34.352059,136.70365}};
    (*this)["Miseyaeki"] = {"Mie", {34.39477,136.408528}};
    (*this)["Aiga"] = {"Mie", {34.111582,136.227184}};
    (*this)["Owase"] = {"Mie", {34.074725,136.190312}};

    (*this)["Tottorieki"] = {"Tottori", {35.493999,134.225896}};
    (*this)["Matsuzaki"] = {"Tottori", {35.46871,133.902042}};
    (*this)["Gunke"] = {"Tottori", {35.413228,134.251365}};
    (*this)["Titou"] = {"Tottori", {35.26526,134.225534}};
    (*this)["Kurayoshi"] = {"Tottori", {35.454752,133.849479}};
    (*this)["Urayasueki"] = {"Tottori", {35.499611,133.693193}};
    (*this)["Hiyoshizu"] = {"Tottori", {35.440182,133.380808}};
    (*this)["Yonago"] = {"Tottori", {35.423417,133.336672}};
    (*this)["Babasaki"] = {"Tottori", {35.538684,133.22641}};
  
    (*this)["Arajima"] = {"Shimane", {35.431774,133.2071}};
    (*this)["Shinjiko"] = {"Shimane", {35.467363,133.046042}};
    (*this)["Kamonaka"] = {"Shimane", {35.344584,132.911241}};
    (*this)["Izumo"] = {"Shimane", {35.361195,132.758592}};
    (*this)["ShimaneOota"] = {"Shimane", {35.200935,132.499685}};
    (*this)["Kouzueki"] = {"Shimane", {35.012746,132.223147}};
    (*this)["Hamadaeki"] = {"Shimane", {34.902571,132.088873}};
    (*this)["Masudaeki"] = {"Shimane", {34.678277,131.839025}};

    (*this)["Nishikatagami"] = {"Okayama", {34.745208,134.184257}};
    (*this)["Wakieki"] = {"Okayama", {34.797285,134.152814}};
    (*this)["Okueki"] = {"Okayama", {34.730723,134.152814}};
    (*this)["Nishiooderaeki"] = {"Okayama", {34.6618,134.037254}};
    (*this)["Kadotayashiki"] = {"Okayama", {34.656158,133.938948}};
    (*this)["Nishikawamidori"] = {"Okayama", {34.665556,133.92312}};
    (*this)["Bizennishi"] = {"Okayama", {34.631919,133.900493}};
    (*this)["Unoeki"] = {"Okayama", {34.494458,133.953868}};
    (*this)["Hayajima"] = {"Okayama", {34.602212,133.833257}};
    (*this)["Kurashiki"] = {"Okayama", {34.60196,133.765753}};
    (*this)["Sousha"] = {"Okayama", {34.67429,133.738077}};
    (*this)["Bityuutakahari"] = {"Okayama", {34.788489,133.616078}};
    (*this)["Kanemitsu"] = {"Okayama", {34.540941,133.620814}};
    (*this)["Satoshoueki"] = {"Okayama", {34.507749,133.550516}};
    (*this)["Kasaoka"] = {"Okayama", {34.504804,133.504464}};
    (*this)["Ihara"] = {"Okayama", {34.592821,133.469103}};
    (*this)["Tyugokukatsuyama"] = {"Okayama", {35.080576,133.694679}};
    (*this)["Kikkoueki"] = {"Okayama", {34.998619,133.959102}};
    (*this)["Higashitsuyama"] = {"Okayama", {35.058669,134.031816}};
    (*this)["Katsumata"] = {"Okayama", {35.035785,134.118809}};
    (*this)["Nagicho"] = {"Okayama", {35.123024,134.177426}};

    (*this)["Wagicho"] = {"Yamaguchi", {34.202432,132.220288}};
    (*this)["Iwakuni"] = {"Yamaguchi", {34.171957,132.225028}};
    (*this)["Subouooshima"] = {"Yamaguchi", {33.927631,132.19532}};
    (*this)["Yanagii"] = {"Yamaguchi", {33.965853,132.106398}};
    (*this)["Heiseicho"] = {"Yamaguchi", {33.938056,132.073056}};
    (*this)["Tahusecho"] = {"Yamaguchi", {33.958725,132.043834}};
    (*this)["Hikarieki"] = {"Yamaguchi", {33.973943,131.914817}};
    (*this)["Shimomatsu"] = {"Yamaguchi", {34.008728,131.868056}};
    (*this)["Tokuyamaeki"] = {"Yamaguchi", {34.051162,131.802991}};
    (*this)["Bouhu"] = {"Yamaguchi", {34.053399,131.568457}};
    (*this)["Yamaguchieki"] = {"Yamaguchi", {34.176454,131.474183}};
    (*this)["Kotoshiba"] = {"Yamaguchi", {33.952654,131.252433}};
    (*this)["Onoda"] = {"Yamaguchi", {34.007813,131.185548}};
    (*this)["Shimonoseki"] = {"Yamaguchi", {33.950577,130.922101}};
    (*this)["Miroku"] = {"Yamaguchi", {34.169198,131.204445}};
    (*this)["Nagato"] = {"Yamaguchi", {34.375324,131.185052}};
    (*this)["Higashihagi"] = {"Yamaguchi", {34.417019,131.410366}};

    (*this)["Karatsu"] = {"Saga", {33.445938,129.968507}};
    (*this)["Imari"] = {"Saga", {33.271873,129.876298}};
    (*this)["Nakataku"] = {"Saga", {33.28332,130.112221}};
    (*this)["Keyakidaieki"] = {"Saga", {33.434116,130.533401}};
    (*this)["Tashiro"] = {"Saga", {33.383989,130.524512}};
    (*this)["Hirokawacho"] = {"Saga", {33.241698,130.551147}};
    (*this)["Yame"] = {"Saga", {33.211939,130.557874}};
    (*this)["Hainuzuka"] = {"Saga", {33.209947,130.497604}};
    (*this)["Setaka"] = {"Saga", {33.157147,130.485385}};
    (*this)["Yakabe"] = {"Saga", {33.173889,130.415682}};
    (*this)["Hattyoumuta"] = {"Saga", {33.208918,130.437582}};
    (*this)["Bizenkashima"] = {"Saga", {33.114459,130.097808}};
    (*this)["Ureshino"] = {"Saga", {33.100892,129.987055}};
    (*this)["Takeo"] = {"Saga", {33.19647,130.023086}};  
    (*this)["Oomachichoeki"] = {"Saga", {33.212412,130.106473}};
    (*this)["Oomachichoyakuba"] = {"Saga", {33.213759,130.1161}};
    (*this)["Bizenyamaguchi"] = {"Saga", {33.219393,130.160758}};
    (*this)["Ushitsu"] = {"Saga", {33.247826,130.201547}};
    (*this)["Sagaeki"] = {"Saga", {33.264176,130.297397}};
    (*this)["Kamisaki"] = {"Saga", {33.315766,130.374474}};
    (*this)["Nakaharaeki"] = {"Saga", {33.346342,130.440411}};
    (*this)["Yoshinosato"] = {"Saga", {33.324845,130.399378}};

    (*this)["Ichiki"] = {"Nagasaki", {33.749967,129.691357}};
    (*this)["Matsuura"] = {"Nagasaki", {33.34425,129.707839}};
    (*this)["Tabirahirado"] = {"Nagasaki", {33.362607,129.582711}};
    (*this)["Sasaeki"] = {"Nagasaki", {33.236734,129.646875}};
    (*this)["Sasebo"] = {"Nagasaki", {33.170937,129.720537}};
    (*this)["Hasamicho"] = {"Nagasaki", {33.137893,129.895548}};
    (*this)["Kawadana"] = {"Nagasaki", {33.06846,129.863442}};
    (*this)["Oomura"] = {"Nagasaki", {32.910748,129.962203}};
    (*this)["Isahaya"] = {"Nagasaki", {32.852064,130.041238}};
    (*this)["Tokitsucho"] = {"Nagasaki", {32.828751,129.848546}};
    (*this)["Michinoo"] = {"Nagasaki", {32.804386,129.852857}};
    (*this)["Kankoudoorieki"] = {"Nagasaki", {32.743298,129.878013}};
    (*this)["NagasakiAinoeki"] = {"Nagasaki", {32.818944,130.156049}};
    (*this)["Shimabara"] = {"Nagasaki", {32.790237,130.370656}};
    (*this)["Minamishimabara"] = {"Nagasaki", {32.659796,130.297847}};

    (*this)["Nankancho"] = {"Kumamoto", {33.061605,130.540972}};
    (*this)["Arao"] = {"Kumamoto", {32.994287,130.434236}};
    (*this)["Nagasu"] = {"Kumamoto", {32.935617,130.45432}};
    (*this)["Tamana"] = {"Kumamoto", {32.926161,130.549355}};
    (*this)["Koppa"] = {"Kumamoto", {32.916344,130.626295}};
    (*this)["Yamashika"] = {"Kumamoto", {33.017499,130.691216}};
    (*this)["Ogunicho"] = {"Kumamoto", {33.121582,131.068152}};
    (*this)["Miyajieki"] = {"Kumamoto", {32.937259,131.117548}};
    (*this)["Higoootsu"] = {"Kumamoto", {32.877436,130.866191}};
    (*this)["Misatoki"] = {"Kumamoto", {32.861787,130.797045}};
    (*this)["Hikarinomori"] = {"Kumamoto", {32.857687,130.786755}};
    (*this)["Mitsuishi"] = {"Kumamoto", {32.864157,130.738342}};
    (*this)["Nishihara"] = {"Kumamoto", {32.834814,130.903007}};
    (*this)["Takamori"] = {"Kumamoto", {32.819336,131.122476}};
    (*this)["Tsuuchosuji"] = {"Kumamoto", {32.803275,130.70968}};
    (*this)["Kumamotoeki"] = {"Kumamoto", {32.790193,130.689915}};
    (*this)["Masujyoucho"] = {"Kumamoto", {32.791403,130.81637}};
    (*this)["Kenguncho"] = {"Kumamoto", {32.77831,130.76082}};
    (*this)["Nishikumamotoeki"] = {"Kumamoto", {32.762557,130.682961}};
    (*this)["Ohunacho"] = {"Kumamoto", {32.714554,130.801936}};
    (*this)["Matsuhashi"] = {"Kumamoto", {32.652458,130.670409}};
    (*this)["Kousa"] = {"Kumamoto", {32.65122,130.81129}};
    (*this)["KumamotoMisatocho"] = {"Kumamoto", {32.6397,130.788901}};
    (*this)["Hikawacho"] = {"Kumamoto", {32.582453,130.673737}};
    (*this)["Kamiamakusa"] = {"Kumamoto", {32.587382,130.430457}};
    (*this)["Amakusa"] = {"Kumamoto", {32.458457,130.193344}};
    (*this)["Bigotakada"] = {"Kumamoto", {32.475116,130.612364}};
    (*this)["Minamata"] = {"Kumamoto", {32.204948,130.396084}};
    (*this)["Hitoyoshi"] = {"Kumamoto", {32.21612,130.753719}};
    (*this)["Asagiri"] = {"Kumamoto", {32.236259,130.893817}};
    (*this)["Taraki"] = {"Kumamoto", {32.262812,130.933174}};

    (*this)["Nagashimacho"] = {"Kagoshima", {32.199343,130.176784}};  
    (*this)["Nishiidemitzu"] = {"Kagoshima", {32.075406,130.339231}};
    (*this)["Akune"] = {"Kagoshima", {32.022947,130.196237}};
    (*this)["Isa"] = {"Kagoshima", {32.057195,130.613066}};
    (*this)["Kurino"] = {"Kagoshima", {31.950538,130.723311}};
    (*this)["Sendai"] = {"Kagoshima", {31.813716,130.312237}};
    (*this)["Kushikino"] = {"Kagoshima", {31.721334,130.274188}};
    (*this)["Ijuuin"] = {"Kagoshima", {31.630235,130.395793}};
    (*this)["Tenmonkantsu"] = {"Kagoshima", {31.590658,130.555058}};
    (*this)["Minamisatsuma"] = {"Kagoshima", {31.416601,130.323485}};
    (*this)["Makurazaki"] = {"Kagoshima", {31.272014,130.299539}};
    (*this)["Eiookawa"] = {"Kagoshima", {31.257887,130.4133}};
    (*this)["Ibusuki"] = {"Kagoshima", {31.236949,130.642586}};
    (*this)["Tyousa"] = {"Kagoshima", {31.72695,130.63277}};
    (*this)["Kokubun"] = {"Kagoshima", {31.743599,130.763391}};
    (*this)["Tarumizu"] = {"Kagoshima", {31.492862,130.700797}};
    (*this)["Shikaya"] = {"Kagoshima", {31.378205,130.852177}};
    (*this)["Kimotsuke"] = {"Kagoshima", {31.344364,130.945223}};
    (*this)["Nishikie"] = {"Kagoshima", {31.243572,130.787615}};
    (*this)["Minamioosumi"] = {"Kagoshima", {31.217288,130.768172}};
    (*this)["Shihushi"] = {"Kagoshima", {31.473098,131.098346}};

    (*this)["Kushima"] = {"Miyazaki", {31.462963,131.230557}};
    (*this)["Yutsu"] = {"Miyazaki", {31.586785,131.395984}};
    (*this)["Nishitojyou"] = {"Miyazaki", {31.723542,131.05701}};
    (*this)["Mimata"] = {"Miyazaki", {31.733792,131.119476}};
    (*this)["Minamimiyazaki"] = {"Miyazaki", {31.895116,131.422359}};
    (*this)["Kobayashi"] = {"Miyazaki", {31.990594,130.976149}};
    (*this)["Kokutomicho"] = {"Miyazaki", {31.990649,131.323535}};
    (*this)["Hyuugashintomi"] = {"Miyazaki", {32.072511,131.501906}};
    (*this)["Nishimiyako"] = {"Miyazaki", {32.1078,131.400992}};
    (*this)["Takanabe"] = {"Miyazaki", {32.122263,131.533494}};
    (*this)["Kyoumachionsen"] = {"Miyazaki", {32.045396,130.767668}};
    (*this)["Tonoueki"] = {"Miyazaki", {32.250864,131.568088}};
    (*this)["Hyuugashieki"] = {"Miyazaki", {32.425792,131.627937}};
    (*this)["Kadokawaeki"] = {"Miyazaki", {32.477353,131.653841}};
    (*this)["Nobeoka"] = {"Miyazaki", {32.589956,131.672405}};
    (*this)["Takachiho"] = {"Miyazaki", {32.711738,131.307797}};


    (*this)["Kamioka"] = {"Ooita", {32.95628,131.861628}};
    (*this)["Miecho"] = {"Ooita", {32.983603,131.584366}};
    (*this)["Bungotakeda"] = {"Ooita", {32.970797,131.389726}};
    (*this)["Tsukumi"] = {"Ooita", {33.072933,131.863708}};
    (*this)["Usuki"] = {"Ooita", {33.118594,131.807767}};
    (*this)["Mukounohara"] = {"Ooita", {33.196801,131.513986}};
    (*this)["Ooitaeki"] = {"Ooita", {33.23316,131.606392}};
    (*this)["Beppu"] = {"Ooita", {33.279584,131.500607}};
    (*this)["Bunngomorieki"] = {"Ooita", {33.282656,131.155453}};
    (*this)["Hidaeki"] = {"Ooita", {33.317021,130.938733}};
    (*this)["Youkoku"] = {"Ooita", {33.370115,131.530563}};
    (*this)["Nakayamakaori"] = {"Ooita", {33.44854,131.505751}};
    (*this)["Nakatsueki"] = {"Ooita", {33.599166,131.190782}};
    (*this)["Bungonagasu"] = {"Ooita", {33.564868,131.382876}};
    (*this)["Bungotakada"] = {"Ooita", {33.556173,131.447046}};
    (*this)["Kokutou"] = {"Ooita", {33.563269,131.732218}};

    (*this)["Tyokutoucho"] = {"Kagawa", {34.459796,133.995634}};  
    (*this)["Doshoucho"] = {"Kagawa", {34.486783,134.188298}};  
    (*this)["Kawaracho"] = {"Kagawa", {34.338961,134.052558}};
    (*this)["Kotodenshido"] = {"Kagawa", {34.322537,134.172956}};
    (*this)["Sakaide"] = {"Kagawa", {34.313167,133.856717}};
    (*this)["Utatsu"] = {"Kagawa", {34.30636,133.813896}};
    (*this)["Marugame"] = {"Kagawa", {34.291974,133.792917}};
    (*this)["Tadotsu"] = {"Kagawa", {34.271102,133.75673}};
    (*this)["Takimiya"] = {"Kagawa", {34.248146,133.922165}};
    (*this)["Gakuendoorieki"] = {"Kagawa", {34.270573,134.136917}};
    (*this)["Sanbonmatsu"] = {"Kagawa", {34.251568,134.334466}};
    (*this)["Zentsuuji"] = {"Kagawa", {34.229953,133.789225}};
    (*this)["Kotodenkotohira"] = {"Kagawa", {34.190891,133.819243}};
    (*this)["Takaseeki"] = {"Kagawa", {34.184074,133.71142}};
    (*this)["Kannonji"] = {"Kagawa", {34.124436,133.655514}};
  
    (*this)["Naruto"] = {"Tokushima", {34.179227,134.608584}};
    (*this)["Itano"] = {"Tokushima", {34.142188,134.465922}};
    (*this)["Matsushigecho"] = {"Tokushima", {34.133784,134.580563}};
    (*this)["Kitajimacho"] = {"Tokushima", {34.12558,134.547007}};
    (*this)["Katsuho"] = {"Tokushima", {34.128655,134.528264}};
    (*this)["Kamiita"] = {"Tokushima", {34.121453,134.404929}};
    (*this)["Tokushimaeki"] = {"Tokushima", {34.074235,134.551158}};
    (*this)["Ishiieki"] = {"Tokushima", {34.070212,134.44431}};
    (*this)["Kamoshima"] = {"Tokushima", {34.073617,134.356501}};
    (*this)["Awa"] = {"Tokushima", {34.089293,134.234111}};
    (*this)["Sadamitsu"] = {"Tokushima", {34.039368,134.058787}};
    (*this)["Awakamo"] = {"Tokushima", {34.037064,133.926485}};
    (*this)["Awaikeda"] = {"Tokushima", {34.027107,133.804717}};
    (*this)["Shishikui"] = {"Tokushima", {33.566734,134.30059}};  

    (*this)["Imabari"] = {"Ehime", {34.064339,132.99378}};
    (*this)["Niihama"] = {"Ehime", {33.948045,133.294363}};
    (*this)["Iyomishima"] = {"Ehime", {33.979575,133.541997}};
    (*this)["Iyosaijyou"] = {"Ehime", {33.912501,133.187561}};
    (*this)["Matsuyama"] = {"Ehime", {33.835615,132.762051}};
    (*this)["Yokogawara"] = {"Ehime", {33.803336,132.884283}};
    (*this)["Jizoucho"] = {"Ehime", {33.779537,132.70421}};
    (*this)["Gunnakaminato"] = {"Ehime", {33.756066,132.702129}};
    (*this)["Tobecho"] = {"Ehime", {33.74926,132.792233}};
    (*this)["Kumankougen"] = {"Ehime", {33.655721,132.901523}};
    (*this)["Naishi"] = {"Ehime", {33.548928,132.646304}};
    (*this)["Iyooosu"] = {"Ehime", {33.51848,132.544802}};
    (*this)["Yawatahama"] = {"Ehime", {33.458164,132.436012}};
    (*this)["Unocho"] = {"Ehime", {33.363196,132.509904}};
    (*this)["Chikanaga"] = {"Ehime", {33.255706,132.67635}};
    (*this)["Uwajima"] = {"Ehime", {33.226069,132.567642}};
    (*this)["Ainancho"] = {"Ehime", {32.962517,132.58342}};

    (*this)["Akieki"] = {"Kouchi", {33.504424,133.906399}};
    (*this)["Nahanri"] = {"Kouchi", {33.42503,134.018081}};
    (*this)["Muroto"] = {"Kouchi", {33.289854,134.15205}};
    (*this)["Tosayamada"] = {"Kouchi", {33.607105,133.684643}};
    (*this)["Noichi"] = {"Kouchi", {33.561828,133.698055}};
    (*this)["Gomenhigashi"] = {"Kouchi", {33.574533,133.647874}};
    (*this)["Kouchijyou"] = {"Kouchi", {33.558518,133.534223}};
    (*this)["Inoeki"] = {"Kouchi", {33.547505,133.430098}};
    (*this)["Tosa"] = {"Kouchi", {33.494482,133.424274}};
    (*this)["Echicho"] = {"Kouchi", {33.532862,133.252108}};
    (*this)["Sagawaeki"] = {"Kouchi", {33.500101,133.292518}};
    (*this)["Tanogou"] = {"Kouchi", {33.410417,133.296875}};
    (*this)["Tosakurei"] = {"Kouchi", {33.329312,133.226799}};
    (*this)["Tubokawa"] = {"Kouchi", {33.212328,133.137357}};
    (*this)["Nakamuraeki"] = {"Kouchi", {32.984576,132.943976}};
    (*this)["Higashishukumou"] = {"Kouchi", {32.933605,132.728663}};
    (*this)["Tosashimizu"] = {"Kouchi", {32.781463,132.954834}};
  }
} spots_tbl;

inline bool near(const pair<double, double>& a, const pair<double, double>& b)
{
  auto x1 = a.first;
  auto x2 = b.first;
  auto y1 = a.second;
  auto y2 = b.second;
  constexpr double delta = 0.001;
  return (fabs(x1 - x2) < delta) && (fabs(y1 - y2) < delta);
}

inline void out_data(ostream& os, int x, int y, int nth)
{
  if (nth < 0)
    os << x << ' ' << y << '\n';
  else
    os << x << ' ' << nth << ' ' << y << '\n';
}

inline void out_data(string fn, const map<int, int>& tm, bool three, int nth)
{
  ofstream ofs(fn);
  if (!ofs) {
    cerr << "cannot open `" << fn << "'\n";
    return;
  }

  for (const auto& x : tm)
    out_data(ofs, x.first, x.second, nth);
}

string time2str(time_t t)
{
  auto ptr_tm = localtime(&t);
  auto ptr_c = asctime(ptr_tm);
  string s = ptr_c;
  for (size_t p = 0 ; p != string::npos ; ) { 
    p = s.find_first_of(' ', p);
    if (p == string::npos)
      break;
    s[p] = '_';
  }

  s.erase(s.length()-1);
  string ss = "00:00:00_";
  auto p = s.length()-ss.length()-4;
  auto len = ss.length();
  // assert(s.substr(p, len) == ss) will fail
  s.erase(p, len);
  return s;
}

inline time_t new_file(pair<ofstream*, time_t>* curr, time_t t)
{
  if (!curr->first) {
    tm buf;
    localtime_r(&t, &buf);
    auto debug = asctime(&buf);
    assert(!buf.tm_sec);
    assert(!buf.tm_min);
    buf.tm_hour = 0;
    if (buf.tm_wday) {
      buf.tm_mday -= buf.tm_wday;
      buf.tm_wday = 0;
      auto debug = asctime(&buf);      
    }
    return timelocal(&buf);
  }
  auto ptr = localtime(&t);
  int wday = ptr->tm_wday;
  static int prev;
  bool ret = (prev != wday && !wday);
  prev = wday;
  return ret ? t : 0;
}

inline void split_out(ostream& os, pair<ofstream*, time_t>* curr, time_t t,
		      int v, bool three, int nth)
{
  if (auto t0 = new_file(curr, t)) {
    string fn = time2str(t);
    if (three)
      fn += ".3";
    fn += ".dat";
    delete curr->first;
    curr->first = new ofstream(fn);
    if (!curr->first) {
      cerr << "cannot open `" << fn << "'\n";
      return;
    }
    curr->second = t0;
    os << '"' << fn << '"';
    if (three)
      os << " using 1:2:3 with impuls, \\\n";
    else
      os << " using 1:2 with line, \\\n";
  }

  ofstream& ofs = *curr->first;
  auto t0 = curr->second;
  out_data(ofs, t-t0, v, nth);
}

void just(ostream& os, string spot, bool split, bool three, int nth)
{
  auto p = spots_tbl.find(spot);
  if (p == spots_tbl.end()) {
    cerr << "unknown `" << spot << '\n';
    return;
  }
  const auto& x = p->second;
  auto k1 = x.first;
  auto q = g_crow_data.find(k1);
  assert(q != g_crow_data.end());
  const auto& tbl = q->second;
  auto k2 = x.second;
  auto r = find_if(begin(tbl), end(tbl),
		   [k2](const pair<pair<double, double>, info_t>& x)
		   { return near(x.first, k2); });
  assert(r != tbl.end());
  const auto& info = r->second;
  const auto& tm = info.tm;

  if (!split) {
    string data_fn = spot;
    if (three)
      data_fn += ".3";
    data_fn += ".data";
    os << '"' << data_fn << '"';
    if (three)
      os << " using 1:2:3 with impuls, \\\n";
    else
      os << " using 1:2 with line, \\\n";
    out_data(data_fn, tm, three, nth);
    return;
  }

  pair<ofstream*, time_t> curr;
  nth = three ? tm.size()-1 : -1;
  for (const auto& x : tm) {
    split_out(os, &curr, x.first, x.second, three, nth);
    if (three)
      --nth;
  }
  delete curr.first;
}

void time_series(const vector<string>& spots, bool split, bool three)
{
  string fn = "display.";
  ostringstream os;
  copy(begin(spots), end(spots), ostream_iterator<string>(os, "."));
  fn += os.str();
  if (split)
    fn += "split.";
  if (three)
    fn += "3.";
  fn += "gp";
  ofstream ofs(fn);
  if (!ofs) {
    cerr << "cannot open `" << fn << "'\n";
    return;
  }
  if (chmod(fn.c_str(), 0755) < 0) {
    cerr << "chmod failed\n";
    return;
  }
  cout << "./" << fn << '\n';
  
  ofs << "#! /usr/local/bin/gnuplot -p\n\n";
  if (split) {
    if (three)
      ofs << "set view 60,10\n";
    ofs << "set xtics (";
    vector<string> days = { "Sun", "Mon", "Tue", "Wed", "Thr", "Fri", "Sat" };
    int t = 0;
    for (auto d : days) {
      if (t)
	ofs << ", ";
      ofs << '"' << d << '"' << ' ' << t ;
      t += 86400;
    }
    ofs << ")\n";
  }
  else {
    ofs << "set xdata time\n";
    ofs << "set timefmt " << '"' << "%s" << '"' << '\n';
  }

  if (three)
    ofs << 's';
  ofs << "plot \\\n";
  int nth = three ? spots.size()-1 : -1;
  for (auto spot : spots) {
    just(ofs, spot, split, three, nth);
    if (three)
      --nth;
  }
}

void copy3(map<int, int>& dst, const map<int, int>& src)
{
  copy(begin(src), end(src), inserter(dst, begin(dst)));
}

void copy2(info_t& dst, const info_t& src)
{
  copy3(dst.tm, src.tm);
  dst.gn = src.gn;
  dst.pl = src.pl;
}

void copy1(map<pair<double, double>, info_t>& dst,
	  const map<pair<double, double>, info_t>& src)
{
  for (const auto x : src) {
    auto& dst2 = dst[x.first];
    const auto& src2 = x.second;
    copy2(dst2, src2);
  }
}

bool read_dll1(string s)
{
  void* hdl = dlopen(s.c_str(), RTLD_LAZY);
  if (!hdl) {
    cerr << "dlopen(" << '"' << s << '"' << ") failed\n";
    cerr << dlerror() << '\n';
    return true;
  }
  struct sweeper {
    void* hdl;
    sweeper(void* p) : hdl{p} {}
    ~sweeper(){ dlclose(hdl); }
  } sweeper(hdl);

  void* addr = dlsym(hdl, "_Z11g_crow_dataB5cxx11");
  if (!addr) {
    cerr << "dlsym failed\n";
    return true;
  }

  typedef decltype(g_crow_data) T;
  auto ptr = reinterpret_cast<T*>(addr);
  for (const auto& x : *ptr) {
    auto& dst = g_crow_data[x.first];
    const auto& src = x.second;
    copy1(dst, src);
  }
  return false; // ok
}

int read_dll()
{
  vector<string> dll = {
    "../2021.09.21.18/2021_09_21_18",
    "../2021.09.22.18/2021_09_22_18",
    "../2021.09.23.18/2021_09_23_18",
    "../2021.09.24.18/2021_09_24_18",
    "../2021.09.25.18/2021_09_25_18",
    "../2021.09.26.18/2021_09_26_18",
    "../2021.09.27.18/2021_09_27_18",
    "../2021.09.28.18/2021_09_28_18",
    "../2021.09.29.18/2021_09_29_18",
    "../2021.09.30.18/2021_09_30_18",
    "../2021.10.01.18/2021_10_01_18",
    "../2021.10.02.18/2021_10_02_18",
    "../2021.10.03.18/2021_10_03_18",
    "../2021.10.04.18/2021_10_04_18",
    "../2021.10.05.18/2021_10_05_18",
    "../2021.10.06.18/2021_10_06_18",
    "../2021.10.07.18/2021_10_07_18",
    "../2021.10.08.18/2021_10_08_18",
    "../2021.10.09.18/2021_10_09_18",
    "../2021.10.10.18/2021_10_10_18",
    "../2021.10.11.18/2021_10_11_18",
    "../2021.10.12.18/2021_10_12_18",
    "../2021.10.13.18/2021_10_13_18",
    "../2021.10.14.18/2021_10_14_18",
    "../2021.10.15.18/2021_10_15_18",
    "../2021.10.16.18/2021_10_16_18",
    "../2021.10.17.18/2021_10_17_18",
    "../2021.10.18.18/2021_10_18_18",
    "../2021.10.19.18/2021_10_19_18",
    "../2021.10.20.18/2021_10_20_18",
    "../2021.10.21.18/2021_10_21_18",
    "../2021.10.22.18/2021_10_22_18",
    "../2021.10.23.18/2021_10_23_18",
    "../2021.10.24.18/2021_10_24_18",
    "../2021.10.25.18/2021_10_25_18",
    "../2021.10.26.18/2021_10_26_18",
    "../2021.10.27.18/2021_10_27_18",
    "../2021.10.28.18/2021_10_28_18",
    "../2021.10.29.18/2021_10_29_18",
    "../2021.10.30.18/2021_10_30_18",
    "../2021.10.31.18/2021_10_31_18",
    "../2021.11.01.18/2021_11_01_18",
    "../2021.11.02.18/2021_11_02_18",
    "../2021.11.03.18/2021_11_03_18",
    "../2021.11.04.18/2021_11_04_18",
    "../2021.11.05.18/2021_11_05_18",
    "../2021.11.06.18/2021_11_06_18",
  };
  auto p = find_if(begin(dll), end(dll), read_dll1);
  return p - end(dll);
}

int main(int argc, char** argv)
{
  bool pause = true;
  time_t b = 0, e = 0;
  vector<string> spots;
  bool split = true;
  bool three = false;
  for (int opt; (opt = getopt(argc, argv, "nb:e:s:c3")) != -1 ; ) {
    switch (opt) {
    case 'n' : pause = false; break;
    case 'b' : b = get_day(optarg); break;
    case 'e' : e = get_day(optarg); break;
    case 's' : spots.push_back(optarg); break;
    case 'c' : split = false; break;
    case '3' : three = true; break;
    default: usage(argv[0]); return 1;
    }
  }

  if (read_dll() < 0)
    return 1;

  if (optind == argc && !spots.empty()) {
    time_series(spots, split, three);
    return 0;
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

  string fn = "display";
  fn += "." + area;
  fn += ".gp";
  ofstream ofs(fn);
  if (!ofs) {
    cerr << "cannot open `" << fn << "'\n";
    return 1;
  }
  if (chmod(fn.c_str(), 0755) < 0) {
    cerr << "chmod failed\n";
    return 1;
  }
  cout << "./" << fn << '\n';
  
  out_script(ofs, pause, *p, b, e);
  return 0;
}
