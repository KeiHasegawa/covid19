#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

inline void skip_header(istream& is)
{
  int n = 0;
  string item;
  while (!is.eof()) {
    int c = is.get();
    if (c == '\n') {
      assert(n == 6);
      return;
    }
    if (c == ',') {
      ++n;
      item.clear();
      continue;
    }
    item += (char)c;
  }
}

struct info_t {
  int positive;
  int death;
};

map<time_t, map<int, info_t> > table;

struct pref_t {
  string name;
  string name2;
  pair<double, double> pos;
  int population;
  int gdp;
  vector<pair<double, double> >* map;
};

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

struct prefs_t : map<int, pref_t> {
  prefs_t()
  {
    (*this)[1] = {"北海道", "Hokkaido", {43.047499,141.369021}, 5201524,
      2682000, &hokkaido
    };
    (*this)[2] = {"青森県", "Aomori", {40.828675,140.734745}, 215680,
      2443000, &aomori
    };
    (*this)[3] = {"岩手県", "Iwate", {39.701437,141.136723}, 1198692,
      2420000, &iwate
    };
    (*this)[4] = {"宮城県", "Miyagi", {38.260132,140.882437}, 2282142,
      2945000, &miyagi
    };
    (*this)[5] = {"秋田県", "Akita", {35.360937,139.080372}, 939268,
      2319000, &akita
    };
    (*this)[6] = {"山形県", "Yamagata", {38.248926,140.327303}, 1068696,
      2403000, &yamagata
    };
    (*this)[7] = {"福島県", "Hukushima", {37.754212,140.459216}, 1834198,
      2324000, &hukushima
    };
    (*this)[8] = {"茨城県", "Ibaraki", {36.370755,140.476308}, 2868554,
      3044000, &ibaraki
    };
    (*this)[9] = {"栃木県", "Tochigi", {36.559023,139.898451}, 1934016,
      2955000, &tochigi
    };
    (*this)[10]= {"群馬県", "Gunma", {36.383184,139.073217},  1940333,
      2890000, &gunma
    };
    (*this)[11]= {"埼玉県", "Saitama", {35.859044,139.657217}, 7346836,
      2785000, &saitama
    };
    (*this)[12]= {"千葉県", "Chiba", {35.611618,140.114267}, 6287034,
      2820000, &chiba
    };
    (*this)[13]= {"東京都", "Tokyo", {35.68123,139.774534}, 14064696,
      4373000, &tokyo
    };
    (*this)[14]= {"神奈川県", "Kanagawa", {35.465981,139.622062}, 9240411,
      2926000, &kanagawa
    };
    (*this)[15]= {"新潟県", "Niigata", {37.912039,139.061775}, 2202358,
      2668000, &niigata
    };
    (*this)[16]= {"富山県", "Toyama", {36.700806,137.214002}, 1035612 ,
      3055000, &toyama
    };
    (*this)[17]= {"石川県", "Ishikawa", {36.578044,136.648171}, 1133294,
      2744000, &ishikawa
    };
    (*this)[18]= {"福井県", "Hukui", {36.06165,136.223546}, 767433,
      2841000, &hukui
    };
    (*this)[19]= {"山梨県", "Yamanashi", {35.666674,138.568785}, 810427,
      2779000, &yamanashi
    };
    (*this)[20]= {"長野県", "Nagano", {36.643124,138.188644}, 2049683,
      2730000, &nagano
    };
    (*this)[21]= {"岐阜県", "Gihu", {35.409528,136.756466}, 1979781,
      2657000, &gihu
    };
    (*this)[22]= {"静岡県", "Shizuoka", {34.972187,138.3889}, 3635220,
      3162000, &shizuoka
    };
    (*this)[23]= {"愛知県", "Aichi", {35.170915,136.881537}, 7546192,
      3105000, &aichi
    };
    (*this)[24]= {"三重県", "Mie", {34.733993,136.510243}, 1771440,
      2735000, &mie,
    };
    (*this)[25]= {"滋賀県", "Shiga", {35.003051,135.864572}, 1414248 ,
      3072, &shiga
    };
    (*this)[26]= {"京都府", "Kyoto", {34.985849,135.758767}, 2579921,
      2865000, &kyoto
    };
    (*this)[27]= {"大阪府", "Osaka", {34.705027,135.498427}, 8842523,
      2920000, &osaka
    };
    (*this)[28]= {"兵庫県", "Hyougo", {34.826797,134.690533}, 5469184,
      2585000, &hyougo
    };
    (*this)[29]= {"奈良県", "Nara", {34.601151,135.830145}, 1325437,
      2388000, &nara
    };
    (*this)[30]= {"和歌山県", "Wakayama", {34.23218,135.191792}, 923033,
      2655000, &wakayama
    };
    (*this)[31]= {"鳥取県", "Tottori", {35.493999,134.225896}, 553847,
      2232000, &tottori
    };
    (*this)[32]= {"島根県", "Shimane", {35.200935,132.499685}, 671602,
      2382000, &shimane
    };
    (*this)[33]= {"岡山県", "Okayama", {34.60196,133.765753}, 1889607,
      2693000, &okayama
    };
    (*this)[34]= {"広島県", "Hiroshima", {34.397667,132.475379}, 2801388,
      3030000, &hiroshima
    };
    (*this)[35]= {"山口県", "Yamaguchi", {34.176454,131.474183}, 1342987,
      2864000, &yamaguchi
    };
    (*this)[36]= {"徳島県", "Tokushima", {34.074235,134.551158}, 719704,
      2698000, &tokushima
    };
    (*this)[37]= {"香川県", "Kagawa", {34.270573,134.136917}, 951049,
      2790000, &kagawa
    };
    (*this)[38]= {"愛媛県", "Ehime", {33.835615,132.762051}, 1335694,
      2673000, &ehime
    };
    (*this)[39]= {"高知県", "Kouchi", {33.558518,133.534223}, 692065,
      2199000, &kouchi
    };
    (*this)[40]= {"福岡県", "Hukuoka", {33.589728,130.420727}, 5138891,
      2778000, &hukuoka
    };
    (*this)[41]= {"佐賀県", "Saga", {33.264176,130.297397}, 812013,
      2399000, &saga
    };
    (*this)[42]= {"長崎県", "Nagasaki", {32.818944,130.156049}, 1313103,
      2351000, &nagasaki
    };
    (*this)[43]= {"熊本県", "Kumamoto", {32.790193,130.689915}, 1739211,
      2399000, &kumamoto
    };
    (*this)[44]= {"大分県", "Ooita", {33.23316,131.606392}, 1124597,
      2488000, &ooita
    };
    (*this)[45]= {"宮崎県", "Miyazaki", {31.895116,131.422359}, 1070213,
      2208000, &miyazaki
    };
    (*this)[46]= {"鹿児島県", "Kagoshima", {31.416601,130.323485}, 1589206,
      2431000, &kagoshima
    };
    (*this)[47]= {"沖縄県", "Okinawa", {26.214395,127.679337}, 1468410,
      2018000, &okinawa
    };
  }
} prefs;

inline void handle(int n, string item,
		   map<int, info_t>** curr_m, info_t** curr_i)
{
  if (n == 0) {
    // 日付
    istringstream ist(item);
    int y;
    ist >> y;
    assert(ist.get() == '/');
    int m;
    ist >> m;
    assert(ist.get() == '/');
    int d;
    ist >> d;
    tm buf = { .tm_mday = d, .tm_mon = m-1, .tm_year = y-1900 };
    auto t = timelocal(&buf);
    *curr_m = &table[t];
    return;
  }
  if (n == 1) {
    // 都道府県コード
    istringstream ist(item);
    int id;
    ist >> id;
    auto p = prefs.find(id);
    assert(p != end(prefs));
    *curr_i = &(**curr_m)[id];
    return;
  }
  if (n == 2) {
    // 都道府県名
    (void)item;
    return;
  }
  if (n == 3) {
    // 各地の感染者数_1日ごとの発表数
    istringstream ist(item);
    int positive;
    ist >> positive;
    (*curr_i)->positive = positive;
    return;
  }
  if (n == 4) {
    // 各地の感染者数_累計
    istringstream ist(item);
    int total;
    ist >> total;
    (void)total;
    return;
  }
  if (n == 5) {
    // 各地の死者数_1日ごとの発表数
    istringstream ist(item);
    int death;
    ist >> death;
    (*curr_i)->death = death;
    return;
  }

  assert(n == 6);
  // 各地の死者数_累計
  istringstream ist(item);
  int total;
  ist >> total;
  (void)total;
}

inline void get_entry(istream& is)
{
  int n = 0;
  string item;
  map<int, info_t>* curr_m = nullptr;
  info_t* curr_i = nullptr;
  while (!is.eof()) {
    int c = is.get();
    if (c == '\n')
      return handle(n, item, &curr_m, &curr_i);
    if (c == ',') {
      handle(n, item, &curr_m, &curr_i);
      ++n;
      item.clear();
      continue;
    }
    item += (char)c;
  }
}

inline void out_data1(ostream& os, const pair<int, info_t>& p, bool raitio,
		      const info_t& disp, const vector<string>& chosen)
{
  auto id = p.first;
  auto it = prefs.find(id);
  assert(it != prefs.end());
  const auto& pref = it->second;
  if (!chosen.empty()) {
    auto name = pref.name2;
    auto it = find(begin(chosen), end(chosen), name);
    if (it == end(chosen))
      return;
  }
  auto pos = pref.pos;
  auto x = pos.second;
  auto y = pos.first;
  const auto& info = p.second;
  assert(disp.positive^disp.death);
  double z = disp.positive ? info.positive : info.death;
  if (raitio) {
    z /= pref.population;
    z *= 100000;
  }
  os << x << ' ' << ' ' << y << ' ' << z << '\n';
}

string conv(const vector<string>& chosen)
{
  string ret;
  for (auto s : chosen)
    ret += "." + s;
  return ret;
}

inline bool comp(pair<int, pref_t> x, string name)
{
  const auto& pref = x.second;
  return pref.name2 == name;
}

inline void out_map(ostream& os, string name)
{
  auto p = find_if(begin(prefs), end(prefs), bind2nd(ptr_fun(comp), name));
  if (p == end(prefs)) {
    cerr << "unknown `" << name << "'\n";
    return;
  }
  const auto& pref = p->second;
  auto& v = *pref.map;
  for (const auto& p : v) {
    auto x = p.first;
    auto y = p.second;
    os << x << ' ' << y << ' ' << 0 << '\n';
  }
}

inline void out_map(string map_fn, const vector<string>& chosen)
{
  ofstream ofs(map_fn);
  if (!ofs) {
    cerr << "cannot open `" << map_fn << "'\n";
    return;
  }
  for (auto s : chosen)
    out_map(ofs, s);
}

inline void
out_data(ostream& os, time_t t, const map<int, info_t>& tbl, int zrange,
	 bool raitio, const info_t& disp, const vector<string>& chosen)
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
  assert(s.substr(p, len) == ss);
  s.erase(p, len);
  if (raitio)
    s += ".raitio";

  ofstream ofs(s);
  if (!ofs) {
    cerr << "cannot open " << s << '\n';
    return;
  }

  for (const auto& x : tbl)
    out_data1(ofs, x, raitio, disp, chosen);

  os << "set zrange [0:" << zrange << "]\n";
  os << "set view 60,10\n";
  os << "splot " << '"' << s << '"' << " with impuls, \\\n";
  if (chosen.empty()) {
    os << '"' << "japan.dat" << '"' << " with dots\n";
    return;
  }
  string map_fn = "map_of" + conv(chosen);
  os << '"' << map_fn << '"' << " with dots\n";
  out_map(map_fn, chosen);
}

inline void
out_data1(ostream& os, time_t t, const info_t& info, bool raitio,
	  const pref_t& pref, int info_t::*pm, int nth, int scale)
{
  double v = info.*pm;
  v *= scale;
  if (raitio) {
    v /= pref.population;
    v *= 100000;
  }
  os << t << ' ';
  if (nth >= 0)
    os << nth << ' ';
  os << v << '\n';
}

inline void out_data2(ostream& os, bool raitio, string fn, int id,
		      const pref_t& pref, bool just_one, const info_t& disp,
		      int info_t::*pm, bool three, int nth, int scale)
{
  if (raitio)
    fn += ".raitio";
  if (three)
    fn += ".3";
  fn += ".dat";
  ofstream ofs(fn);
  if (!ofs) {
    cerr << "cannot open `" << fn << "'\n";
    return;
  }

  if (three)
    os << '"' << fn << '"' << " using 1:2:3 with impuls";
  else {
    os << '"' << fn << '"' << " using 1:2";
    if (just_one && disp.positive^disp.death)
      os << " with impuls";
    else {
      os << " with line";
      if (pm == &info_t::death)
	os << " axes x1y2";      
    }
  }
  os << ", \\\n";

  for (const auto& x : table) {
    auto t = x.first;
    const auto& tbl = x.second;
    auto q = tbl.find(id);
    assert(q != tbl.end());
    const auto& info = q->second;
    out_data1(ofs, t, info, raitio, pref, pm, nth, scale);
  }
}

inline void out_data(ostream& os, bool raitio, string name, bool just_one,
		     const info_t& disp, bool three, int nth, int scale)
{
  auto p = find_if(begin(prefs), end(prefs), bind2nd(ptr_fun(comp), name));
  if (p == end(prefs)) {
    cerr << "unknown `" << name << "'\n";
    return;
  }
  auto id = p->first;
  const auto& pref = p->second;

  if (disp.death) {
    string fn = name;
    if (scale != 1)
      fn += "." + to_string(scale);
    fn += ".death";
    int nth1 = nth < 0 ? -1 : nth+1;
    out_data2(os, raitio, fn, id, pref, just_one, disp, &info_t::death,
	      three, nth1, scale);
  }

  if (disp.positive) {
    string fn = name + ".positive";
    out_data2(os, raitio, fn, id, pref, just_one, disp, &info_t::positive,
	      three, nth, 1);
  }
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
  assert(s.substr(p, len) == ss);
  s.erase(p, len);
  return s;
}

inline void usage(const char* prog)
{
  cerr << "usage % " << prog << " [-c Tokyo][-z 100][-d][-p][-r][-b 2021.08.01][-e 2021.08.31][-3][-s 100][-m]\n";
}

int main(int argc, char** argv)
{
  vector<string> chosen;
  int zrange = -1;
  bool raitio = false;
  info_t disp = { .positive = 1 };
  time_t b = 0, e = 0;
  bool three = false;
  int scale = 1;
  bool use_map = false;
  for (int opt; (opt = getopt(argc, argv, "c:z:rdpb:e:3s:m")) != -1; ){
    switch (opt) {
    case 'c': chosen.push_back(optarg); break;
    case 'z': zrange = atoi(optarg); break;
    case 'r': raitio = true; break;
    case 'd': disp.positive = 0; disp.death = 1; break;
    case 'p': disp.positive = 1; break;
    case 'b': b = get_day(optarg); break;
    case 'e': e = get_day(optarg); break;
    case '3': three = true; break;
    case 's': disp.death = 1; scale = atoi(optarg); break;
    case 'm': use_map = true; break;
    case '?':
    default:  usage(argv[0]); return 1;
    }
  }
 
  if (argc != optind) {
    usage(argv[0]);
    return 1;
  }
  
  string fn = "nhk_news_covid19_prefectures_daily_data.csv";
  ifstream ifs(fn);
  if (!ifs) {
    cerr << "cannot open `" << fn << "'\n";
    return 1;
  }

  skip_header(ifs);
  while (!ifs.eof())
    get_entry(ifs);

  string gp = fn + conv(chosen);
  if (disp.positive)
    gp += ".positive";
  if (disp.death) {
    if (scale != 1)
      gp += "." + to_string(scale);
    gp += ".death";
  }
  if (raitio)
    gp += ".raitio";
  if (three)
    gp += ".3";
  if (zrange >= 0)
    gp += "." + to_string(zrange);
  if (b)
    gp += "." + time2str(b);
  if (e)
    gp += "." + time2str(e);
  if (use_map)
    gp += ".map";
  gp += ".gp";
  ofstream ofs(gp);
  if (!ofs) {
    cerr << "cannot open `" << gp << "'\n";
    return 1; 
  }
  if (chmod(gp.c_str(), 0755) < 0) {
    cerr << "chmod failed\n";
    return 1;
  }
  cerr << "./" << gp << '\n';

  ofs << "#! /usr/local/bin/gnuplot -p\n\n";

  if (zrange < 0) {
    if (disp.positive)
      zrange = raitio ? 30 : 400;
    else
      zrange = raitio ? 1 : 40;
  }

  if (chosen.empty() || use_map) {
    if (disp.positive && disp.death) {
      cerr << "Both positive and death are specified\n";
      return 1;
    }
    for (const auto& p : table) {
      auto t = p.first;
      if (b && t < b)
	continue;
      if (e && e <= t)
	continue;
      out_data(ofs, t, p.second, zrange, raitio, disp, chosen);
    }
    return 0;
  }

  ofs << "set xdata time\n";
  ofs << "set timefmt " << '"' << "%s" << '"' << '\n';
  if (disp.positive && disp.death && !three) {
    ofs << "set ytics nomirror\n";
    ofs << "set y2tics nomirror\n";
  }
  if (three)
    ofs << 's';
  ofs << "plot \\\n";
  auto sz = chosen.size();
  int nth = three ? 2*sz : -1;
  for (auto p = rbegin(chosen) ; p != rend(chosen) ; ++p) {
    auto s = *p;
    out_data(ofs, raitio, s, sz==1, disp, three, nth, scale);
    if (three)
      nth -= 2;
  }
  
  return 0;
}
