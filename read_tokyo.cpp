#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

inline void skip_header(istream& is, int N)
{
  string item;
  int n = 0;
  while (!is.eof()) {
    int c = is.get();
    if (c == '\n') {
      assert(n == N);
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
  int hospital;
  int medium;
  int serious;
  int hotel;
  int home;
  int wait;
  int death;
  int recover;
  int demand;
  int no_carry;
  int test;
};

bool has_data(int y, int m, int d, int* demand, int* no_carry)
{
  if (y == 2021 && m == 7 && 12 <= d && d <= 18) {
    // 2021/07/12 - 2021/07/18
    *demand = 233/7;
    *no_carry = 61/7;
    return true;
  }
  if (y == 2021 && m == 7 && 19 <= d && d <= 25) {
    // 2021/07/19 - 2021/07/25
    *demand = 412/7;
    *no_carry = 153/7;
    return true;
  }
  if (y == 2021 && (m == 7 && 26 <= d || m ==8 && d == 1)) {
    // 2021/07/26 - 2021/08/01
    *demand = 1022/7;
    *no_carry = 519/7;
    return true;
  }
  if (y == 2021 && m == 8 && 2 <= d && d <= 8) {
    // 2021/08/02 - 2021/08/08
    *demand = 1670/7;
    *no_carry = 959/7;
    return true;
  }
  if (y == 2021 && m == 8 && 9 <= d && d <= 15) {
    // 2021/08/09 - 2021/08/15
    *demand = 2259/7;
    *no_carry = 1414/7;
    return true;
  }
  if (y == 2021 && m == 8 && 16 <= d && d <= 22) {
    // 2021/08/16 - 2021/08/22
    *demand = 1983/7;
    *no_carry = 1160/7;
    return true;
  }
  if (y == 2021 && m == 8 && 23 <= d && d <= 29) {
    // 2021/08/23 - 2021/08/29
    *demand = 1466/7;
    *no_carry = 726/7;
    return true;
  }
  if (y == 2021 && (m == 8 && 30 <= d && d <= 31 || m == 9 && d <= 5 )) {
    // 2021/08/30 - 2021/09/05
    *demand = 795/7;
    *no_carry = 262/7;
    return true;
  }
  if (y == 2021 && m == 9 && 6 <= d && d <= 12) {
    // 2021/09/06 - 2021/09/12
    *demand = 330/7;
    *no_carry = 83/7;
    return true;
  }
  if (y == 2021 && m == 9 && 13 <= d && d <= 19) {
    // 2021/09/13 - 2021/09/19
    *demand = 159/7;
    *no_carry = 23/7;
    return true;
  }
  if (y == 2021 && m == 9 && 20 <= d && d <= 26) {
    // 2021/09/20 - 2021/09/26
    *demand = 74/7;
    *no_carry = 12/7;
    return true;
  }
  
  return false;
}

map<time_t, info_t> table;

inline void handle(int n, string item, info_t** curr)
{
  if (n == 0) {
    // 全国地方公共団体コード
    assert(item == "130001");
    return;
  }
  if (n == 1) {
    // 都道府県名
    assert(item == "東京都");
    return;
  }
  if (n == 2) {
    // 市区町村名
    assert(item.empty());
    return;
  }
  if (n == 3) {
    // 公表_年月日
    auto p = item.find_first_of('-');
    assert(p != string::npos);
    auto q = item.find_first_of('-', p+1);
    assert(q != string::npos);
    item[p] = ' ';
    item[q] = ' ';
    istringstream ist(item);
    int y;
    ist >> y;
    int m;
    ist >> m;
    int d;
    ist >> d;
    tm buf = { .tm_mday = d, .tm_mon = m-1, .tm_year = y-1900 };
    auto t = timelocal(&buf);
    *curr = &table[t];
    int demand, no_carry;
    if (has_data(y, m, d, &demand, &no_carry)) {
      (*curr)->demand = demand;
      (*curr)->no_carry = no_carry;
    }
    else
      (*curr)->demand = (*curr)->no_carry = 0;
    return;
  }
  if (n == 4) {
    // 陽性者数（累計）
    istringstream ist(item);
    int positive;
    ist >> positive;
    (*curr)->positive = positive;
    return;
  }
  if (n == 5) {
    // 入院中
    istringstream ist(item);
    int hospital;
    ist >> hospital;
    (*curr)->hospital = hospital;
    return;
  }
  if (n == 6) {
    // 軽症・中等症
    istringstream ist(item);
    int medium;
    ist >> medium;
    (*curr)->medium = medium;
    return;
  }
  if (n == 7) {
    // 重症
    istringstream ist(item);
    int serious;
    ist >> serious;
    (*curr)->serious = serious;
    return;
  }
  if (n == 8) {
    // 宿泊療養
    if (item.empty()) {
      (*curr)->hotel = 0;
      return;
    }
    istringstream ist(item);
    int hotel;
    ist >> hotel;
    (*curr)->hotel = hotel;
    return;
  }
  if (n == 9) {
    // 自宅療養
    if (item.empty()) {
      (*curr)->home = 0;
      return;
    }
    istringstream ist(item);
    int home;
    ist >> home;
    (*curr)->home = home;
    return;
  }
  if (n == 10) {
    // 調整中
    if (item.empty()) {
      (*curr)->wait = 0;
      return;
    }
    istringstream ist(item);
    int wait;
    ist >> wait;
    (*curr)->wait = wait;
    return;
  }
  if (n == 11) {
    // 死亡
    istringstream ist(item);
    int death;
    ist >> death;
    (*curr)->death = death;
    return;
  }
  if (n == 12) {
    istringstream ist(item);
    int recover;
    ist >> recover;
    (*curr)->recover = recover;
    *curr = 0;
    return;
  }

  // 総検査実施件数
  assert(n == 13);
  istringstream ist(item);
  int test;
  ist >> test;
  (*curr)->test = test;
  *curr = 0;
}

inline void get_entry(istream& is)
{
  int n = 0;
  string item;
  info_t* curr = 0;
  while (!is.eof()) {
    int c = is.get();
    if (c == '\n')
      return handle(n, item, &curr);
    if (c == ',') {
      handle(n, item, &curr);
      ++n;
      item.clear();
      continue;
    }
    item += (char)c;
  }
}

inline void get_entry2(istream& is)
{
  int n = 0;
  string item;
  info_t* curr = 0;
  while (!is.eof()) {
    int c = is.get();
    if (c == '\n')
      return;
    if (c == ',') {
      if (n <= 4) {
	int nn = n == 4 ? 13 : n ;
	handle(nn, item, &curr);
      }
      ++n;
      item.clear();
      continue;
    }
    item += (char)c;
  }
}

inline void out_data(ostream& os, time_t t, int v, int ng, int nth, bool three,
		     time_t b, time_t e)
{
  if (b) {
    if (t < b)
      return;
  }
  if (e) {
    if (e <= t)
      return;
  }
  
  if (ng <= 2 && !three) {
    os << t << ' ' << v << '\n';
    return;
  }

  os << t << ' ' << nth << ' ' << v << '\n';
}


int n_graph(const info_t& info)
{
  return info.positive + info.hospital + info.medium + info.serious
    + info.hotel + info.home + info.wait + info.death + info.recover
    + info.demand + info.no_carry + info.test;
}

void subr(ostream& os, string cvs, string postfix, int info_t::*pm,
	  int ng, int nth, bool diff, bool three, time_t b, time_t e, int scale)
{
  string fn = cvs + postfix;
  if (scale != 1) {
    ostringstream os;
    os << fn << '.' << scale;
    fn = os.str();
  }
  os << '"' << fn << '"' << " using 1:2";
  if (ng > 2 || three)
    os << ":3";
  if (ng == 1 || ng > 2 || three)
    os << " with impuls, \\\n";
  else {
    os << " with line";
    if (ng == 2 && nth)
      os << " axes x1y2";
    os << ", \\\n";
  }
  ofstream dat(fn);
  if (!dat) {
    cerr << "cannot open `" << fn << "'\n";
    return;
  }
  int prev = 0;
  for (const auto& p : table) {
    auto v = p.second.*pm;
    auto vv = diff ? v-prev : v;
    vv *= scale;
    out_data(dat, p.first, vv, ng, nth, three, b, e);
    prev = v;
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
  cerr << prog << " [-d][-h][-n][-m][-s][-H][-j][-w][-r][-D][-N]";
  cerr << "[-b 2021.08.16][-e 2021.09.13][-S 100]\n";
}

int main(int argc, char** argv)
{
  info_t disp = { .positive = 1 };
  time_t b = 0, e = 0;
  bool three = false;
  int death_scale = 1;
  int demand_scale = 1;
  for (int opt ; (opt = getopt(argc, argv, "dhnmsHjwrDN3b:e:S:tT:")) != -1 ; ) {
    switch (opt) {
    case 'd': disp.death = 1; break;
    case 'h': disp.hospital = 1; break;
    case 'n': disp.positive = 0; break;
    case 'm': disp.medium = 1; break;
    case 's': disp.serious = 1; break;
    case 'H': disp.hotel = 1; break;
    case 'j': disp.home = 1; break;
    case 'w': disp.wait = 1; break;
    case 'r': disp.recover = 1; break;
    case 'D': disp.demand = 1; break;
    case 'N': disp.no_carry = 1; break;
    case 't': disp.test = 1; break;
    case '3': three = true; break;
    case 'b': b = get_day(optarg); break;
    case 'e': e = get_day(optarg); break;
    case 'S': death_scale = atoi(optarg); disp.death = 1; break;
    case 'T': demand_scale = atoi(optarg); disp.demand = disp.no_carry = 1;
      break;
    case '?':
    default:   usage(argv[0]); return 1;
    }
  }

  if (optind != argc) {
    usage(argv[0]);
    return 1;
  }

  auto ng = n_graph(disp);
  if (!ng) {
    cerr << "no graph is output.\n";
    return 1;
  }
  
  string cvs = "130001_tokyo_covid19_details_testing_positive_cases.csv";
  ifstream ifs(cvs);
  if (!ifs) {
    cerr << "cannot open `" << cvs << "'\n";
    return 1;
  }

  skip_header(ifs, 12);
  while (!ifs.eof())
    get_entry(ifs);

  if (disp.test) {
    string cvs = "130001_tokyo_covid19_tests_conducted.csv";
    ifstream ifs(cvs);
    if (!ifs) {
      cerr << "cannot open `" << cvs << "'\n";
      return 1;
    }
    skip_header(ifs, 6);
    while (!ifs.eof())
      get_entry2(ifs);
  }

  string gp = cvs;
  if (disp.positive)
    gp += ".p";
  if (disp.death) {
    if (death_scale != 1)
      gp += "." + to_string(death_scale);
    gp += ".d";
  }
  if (disp.hospital)
    gp += ".h";
  if (disp.medium)
    gp += ".m";
  if (disp.serious)
    gp += ".s";
  if (disp.home)
    gp += ".j";
  if (disp.wait)
    gp += ".w";
  if (disp.recover)
    gp += ".r";
  if (disp.demand)
    gp += ".D";
  if (disp.no_carry)
    gp += ".N";
  if (disp.test)
    gp += ".t";
  if (b)
    gp += "." + time2str(b);
  if (e)
    gp += "." + time2str(e);
  if (three)
    gp += ".3";
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
  ofs << "set xdata time\n";
  ofs << "set timefmt " << '"' << "%s" << '"' << '\n';
  if (ng == 2 && !three) {
    ofs << "set ytics nomirror\n";
    ofs << "set y2tics nomirror\n";
  }
  if (ng > 2 || three)
    ofs << 's';
  ofs << "plot \\\n";      

  int nth = 0;
  if (disp.positive)
    subr(ofs, cvs, ".positive", &info_t::positive, ng, nth++, true, three,
	 b, e, 1);

  if (disp.death)
    subr(ofs, cvs, ".death", &info_t::death, ng, nth++, true, three, b, e,
	 death_scale);

  if (disp.hospital)
    subr(ofs, cvs, ".hospital", &info_t::hospital, ng, nth++, false, three,
	 b, e, 1);

  if (disp.medium)
    subr(ofs, cvs, ".medium", &info_t::medium, ng, nth++, false, three, b, e,
	 1);

  if (disp.serious)
    subr(ofs, cvs, ".serious", &info_t::serious, ng, nth++, false, three,
	 b, e, 1);
  
  if (disp.hotel)
    subr(ofs, cvs, ".hotel", &info_t::hotel, ng, nth++, false, three, b, e, 1);

  if (disp.home)
    subr(ofs, cvs, ".home", &info_t::home, ng, nth++, false, three, b, e, 1);

  if (disp.wait)
    subr(ofs, cvs, ".wait", &info_t::wait, ng, nth++, false, three, b, e, 1);

  if (disp.recover)
    subr(ofs, cvs, ".recover", &info_t::recover, ng, nth++, true, three, b, e,
	 1);

  if (disp.demand)
    subr(ofs, cvs, ".demand", &info_t::demand, ng, nth++, false, three, b, e,
	 demand_scale);

  if (disp.no_carry)
    subr(ofs, cvs, ".no_carry", &info_t::no_carry, ng, nth++, false, three,
	 b, e, demand_scale);

  if (disp.test)
    subr(ofs, cvs, ".test", &info_t::test, ng, nth++, false, three,
	 b, e, 1);
  
  ofs << '\n';
  return 0;
}
