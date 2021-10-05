#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <map>
#include <vector>
#include <iterator>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

void skip_header(istream& is, int* id, int* id2, int* lat, int* n)
{
  *id = *lat = *n = 0;
  *id2 = -1;
  string s;
  for (int c ; (c = is.get()) != -1 ; ) {
    if (c == ',') {
      ++*n;
      if (s == "Country/Region" || s == "Admin2")
	*id = *n;
      if (s == "Province_State")
	*id2 = *n;
      if (s == "Lat")
	*lat = *n;
      s.clear();
      if (is.peek() == '1')
	break;
    }
    else
      s += (char)c;
  }
}

time_t get_day(istream& is)
{
  string s;
  while (!is.eof()) {
    char c = is.get();
    if (c == '\n')
      return 0;
    if (c == ',')
      break;
    s += c;
  }

  istringstream ist(s);
  int m;
  ist >> m;
  assert(ist.get() == '/');
  int d;
  ist >> d;
  assert(ist.get() == '/');
  int y;
  ist >> y;
  y += 2000;
  y -= 1900;

  tm buf = { .tm_mday = d, .tm_mon = m-1, .tm_year = y };
  return timelocal(&buf);
}

inline double get_double(string s)
{
  istringstream ist(s);
  double d;
  ist >> d;
  return d;
}

inline bool eoi(int c, string s)
{
  if (s.empty())
    return c == ',';
  if (s[0] != '"')
    return c == ',';
  auto len = s.length();
  if (len == 1)
    return false;
  if (s[len-1] != '"')
    return false;
  return c == ',';
}

struct info_t {
  vector<int> val;
  string name;
  string name2;
};

void get_entry(istream& is, int id, int id2, int lat, int n,
	       map<pair<double, double>, info_t>& tbl)
{
  string s;
  string name, name2;
  pair<double, double> pos;
  int r = 0;
  for (int c ; (c = is.get()) != -1 ; ) {
    if (eoi(c, s)) {
      ++r;
      if (r == id)
	name = s;
      if (r == id2)
	name2 = s;
      if (r == lat)
	pos.first = get_double(s);
      if (r == lat+1)
	pos.second = get_double(s);
      if (r == n)
	break;
      s.clear();
    }
    else
      s += char(c);
  }

  if (0) {
    static set<pair<string,string> > x;
    if (name == "Unassigned") {
      assert(!pos.first && !pos.second);
    }
    else {
      auto y = make_pair(name,name2);
      assert(x.find(y) == x.end());
      x.insert(y);
    }
  }

  auto p = tbl.find(pos);
  if (p != tbl.end()) {
    auto& info = p->second;
    auto& val = info.val;
    val.clear();
  }

  auto& info = tbl[pos];

  if (!name.empty()) {
    if (name[0] == '"') {
      auto len = name.length();
      assert(name[len-1] == '"');
      name.erase(len-1);
      name.erase(0,1);
    }
  }
  info.name = name;
  info.name2 = name2;
  auto& val = info.val;

  while (!is.eof()) {
    int v;
    is >> v;
    val.push_back(v);
    int c = is.get();
    if (c == '\n')
      break;
    assert(c == ',');
  }
}

void rd_data(istream& is,
	     vector<time_t>& vt,
	     map<pair<double, double>, info_t>& tbl)
{
  int id, id2, lat, n;
  skip_header(is, &id, &id2, &lat, &n);
  while (auto t = get_day(is))
    vt.push_back(t);

  while (!is.eof())
    get_entry(is, id, id2, lat, n, tbl);

  tbl.erase(make_pair(0.0,0.0));

  for (const auto& x : tbl) {
    const auto& info = x.second;
    const auto& val = info.val;
    assert(val.size() == vt.size()+1);
  }      
}

void debug(const pair<double, double>& p)
{
  cerr << p.first << ' ' << p.second;
}

void debug(const vector<int>& vi)
{
  copy(begin(vi), end(vi), ostream_iterator<int>(cerr, ","));
}

void debug(const info_t& info)
{
  const auto& val = info.val;
  debug(val);
  cerr << info.name << ' ' << info.name2 << '\n';
}

void debug(const pair<pair<double, double>, info_t>& p)
{
  debug(p.first);
  cerr << ' ';
  debug(p.second);
  cerr << '\n';
}

void debug(const map<pair<double, double>, info_t>& tbl)
{
  for (const auto& x : tbl)
    debug(x);
}

struct rect {
  pair<double, double> top_left;
  pair<double, double> bottom_right;
};

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

struct prop_t {
  int population;
  int gdp;            //  GDP(PPP) per a persion
};

struct props_t : map<string, prop_t> {
  props_t()
  {
    (*this)["Afghanistan"]              = {  37466414,  2073 };
    (*this)["Albania"]                  = {   3011405, 10596 };
    (*this)["Algeria"]                  = {  44700000,  6698 };
    (*this)["Andorra"]                  = {     77543, 32575 };
    (*this)["Angola"]                   = {  24383301,  6331 };
    (*this)["Antigua and Barbuda"]      = {     97000, 29298 };
    (*this)["Argentina"]                = {  40760000, 22363 };
    (*this)["Armenia"]                  = {   2900000,  7034 };
    (*this)["Australia"]                = {  25681000, 54799 };
    (*this)["Austria"]                  = {   8930000, 39634 };
    (*this)["Azerbaijan"]               = {   9872765, 18030 };
    (*this)["Bahamas"]                  = {    351461, 27394 };
    (*this)["Bahrain"]                  = {   1501635, 52129 };
    (*this)["Bangladesh"]               = { 159400000,  2080 };
    (*this)["Barbados"]                 = {    301865, 14568 };
    (*this)["Belarus"]                  = {   9410000, 19940 };
    (*this)["Belgium"]                  = {  11589623, 48224 };
    (*this)["Belize"]                   = {    419199,  9576 };
    (*this)["Benin"]                    = {  11733059,  2552 };
    (*this)["Bhutan"]                   = {    697000,  6370 };
    (*this)["Bolivia"]                  = {  10800882,  6500 };
    (*this)["Bosnia and Herzegovina"]   = {   3301000,  9563 };
    (*this)["Botswana"]                 = {   2030000, 17021 };
    (*this)["Brazil"]                   = { 211050000, 14987 };
    (*this)["Brunei"]                   = {    400000, 50116 };
    (*this)["Bulgaria"]                 = {   7101859, 22831 };
    (*this)["Burkina Faso"]             = {  21510181,  2207 };
    (*this)["Burma"]                    = {  53582855,  4830 };
    (*this)["Burundi"]                  = {  11865821,   727 };
    (*this)["Cabo Verde"]               = {    543767,  7728 };
    (*this)["Cambodia"]                 = {  16486542,  4583 };
    (*this)["Cameroon"]                 = {  25876400,  2152 };
    (*this)["Canada"]                   = {  37590000, 47569 };
    (*this)["Central African Republic"] = {   4745200,   600 };
    (*this)["Chad"]                     = {  16244513,  2428 };
    (*this)["Chile"]                    = {  18952000, 25700 };
    (*this)["China"]                    = {1443490000, 17206 };
    (*this)["Colombia"]                 = {  50500000, 14936 };
    (*this)["Comoros"]                  = {    850886,  2799 };
    (*this)["Congo (Brazzaville)"]      = {   4200000,  3912 };
    (*this)["Congo (Kinshasa)"]         = {  86790567,  1106 };
    (*this)["Costa Rica"]               = {   4890400, 14343 };
    (*this)["Cote d'Ivoire"]            = {  28088455,  5360 };
    (*this)["Croatia"]                  = {   4130300, 20222 };
    (*this)["Cuba"]                     = {  11338000,  9500 };
    (*this)["Cyprus"]                   = {   1189265, 41572 };
    (*this)["Czechia"]                  = {  10701777, 40585 };
    (*this)["Denmark"]                  = {   5822763, 37265 };
    (*this)["Djibouti"]                 = {    921804,  3788 };
    (*this)["Dominica"]                 = {     67757,  5400 };
    (*this)["Dominican Republic"]       = {  10780000, 12173 };
    (*this)["Ecuador"]                  = {  13625000, 10908 };
    (*this)["Egypt"]                    = { 100388100, 13358 };
    (*this)["El Salvador"]              = {   6163000,  7551 };
    (*this)["Equatorial Guinea"]        = {   1454789, 21442 };
    (*this)["Eritrea"]                  = {    604945,  1820 };
    (*this)["Estonia"]                  = {   1323824, 34096 };
    (*this)["Eswatini"]                 = {   1160164,  9186 };
    (*this)["Ethiopia"]                 = { 108113150,  1427 };
    (*this)["Fiji"]                     = {    858038,  4185 };
    (*this)["Finland"]                  = {   5326000, 36217 };
    (*this)["France"]                   = {  62814233, 45454 };
    (*this)["Gabon"]                    = {   2119275, 18647 };
    (*this)["Gambia"]                   = {   2173999,  2240 };
    (*this)["Georgia"]                  = {   3728573, 12409 };
    (*this)["Germany"]                  = {  83000000, 53571 };
    (*this)["Ghana"]                    = {  30420000,  2200 };
    (*this)["Greece"]                   = {  10815197, 18168 };
    (*this)["Grenada"]                  = {    111454, 16604 };
    (*this)["Guatemala"]                = {  14027000,  7290 };
    (*this)["Guinea"]                   = {  12771200,  1002 };
    (*this)["Guinea-Bissau"]            = {   1874303,  1951 };
    (*this)["Guyana"]                   = {    743700, 23258 };
    (*this)["Haiti"]                    = {  10033000,  1703 };
    (*this)["Holy See"]                 = {       809,     0 };
    (*this)["Honduras"]                 = {   7466000,  4592 };
    (*this)["Hungary"]                  = {   9800000, 31913 };
    (*this)["Iceland"]                  = {    355620, 55941 };
    (*this)["India"]                    = {1352610000,  4060 };
    (*this)["Indonesia"]                = { 264162000, 13234 };
    (*this)["Iran"]                     = {  80000000, 12264 };
    (*this)["Iraq"]                     = {  40222503, 17708 };
    (*this)["Ireland"]                  = {   4921500, 86988 };
    (*this)["Israel"]                   = {   8797900, 40661 };
    (*this)["Italy"]                    = {  60550100, 40066 };
    (*this)["Jamaica"]                  = {   2719000,  8487 };
    (*this)["Japan"]                    = { 125360000, 44585 };
    (*this)["Jordan"]                   = {   9710752, 11639 };
    (*this)["Kazakhstan"]               = {  18200000, 26306 };
    (*this)["Kenya"]                    = {  45010056,  1800 };
    (*this)["Kiribati"]                 = {    119940,  2135 };
    (*this)["Korea, South"]             = {  51845612, 44292 };
    (*this)["Kosovo"]                   = {   1847708, 11664 };
    (*this)["Kuwait"]                   = {   4207100, 39849 };
    (*this)["Kyrgyzstan"]               = {   5900000,  3361 };
    (*this)["Laos"]                     = {   6911544,  3068 };
    (*this)["Latvia"]                   = {   2014000, 27702 };
    (*this)["Lebanon"]                  = {   6859408, 17326 };
    (*this)["Lesotho"]                  = {   2108328,  3868 };
    (*this)["Liberia"]                  = {   4200000,   887 };
    (*this)["Libya"]                    = {   6653210, 14520 };
    (*this)["Liechtenstein"]            = {     38896, 98432 };
    (*this)["Lithuania"]                = {   2794184, 25373 };
    (*this)["Luxembourg"]               = {    512353,112045 };
    (*this)["Madagascar"]               = {  26969300,  1507 };
    (*this)["Malawi"]                   = {  15910000,   834 };
    (*this)["Malaysia"]                 = {  31786000, 17747 };
    (*this)["Maldives"]                 = {    396334,  9173 };
    (*this)["Mali"]                     = {  16300000,  2380 };
    (*this)["Malta"]                    = {    409000, 23760 };
    (*this)["Marshall Islands"]         = {     58413,  3789 };
    (*this)["Mauritania"]               = {   4525700,  4335 };
    (*this)["Mauritius"]                = {   1265475, 25029 };
    (*this)["Mexico"]                   = { 120632000, 17390 };
    (*this)["Micronesia"]               = {    104463,  3534 };
    (*this)["Moldova"]                  = {   4030000,  4666 };
    (*this)["Monaco"]                   = {     36371,168000 };
    (*this)["Mongolia"]                 = {   3238479, 13451 };
    (*this)["Montenegro"]               = {    624000, 14666 };
    (*this)["Morocco"]                  = {  37112080,  4349 };
    (*this)["Mozambique"]               = {  23920000,  1290 };
    (*this)["Namibia"]                  = {   2260000,  6577 };
    (*this)["Nepal"]                    = {  30424878,  3581 };
    (*this)["Netherlands"]              = {  17308133, 59693 };
    (*this)["New Zealand"]              = {   5005882, 40266 };
    (*this)["Nicaragua"]                = {   6528000,  5289 };
    (*this)["Niger"]                    = {  24112753,  1213 };
    (*this)["Nigeria"]                  = { 296241700,  5746 };
    (*this)["North Macedonia"]          = {   2077132, 16253 };
    (*this)["Norway"]                   = {   5391369, 72058 };
    (*this)["Oman"]                     = {   4480000, 24153 };
    (*this)["Pakistan"]                 = { 220998678,  8000 };
    (*this)["Palau"]                    = {     18094, 15005 };
    (*this)["Panama"]                   = {   4246400, 19080 };
    (*this)["Papua New Guinea"]         = {   6732000,  2833 };
    (*this)["Paraguay"]                 = {   7152503,  4778 };
    (*this)["Peru"]                     = {  33109000, 11557 };
    (*this)["Philippines"]              = { 100981437,  4681 };
    (*this)["Poland"]                   = {  38268000, 35957 };
    (*this)["Portugal"]                 = {  10347892, 36079 };
    (*this)["Qatar"]                    = {   2795484,138910 };
    (*this)["Romania"]                  = {  19186201, 32950 };
    (*this)["Russia"]                   = { 146171015, 29485 };
    (*this)["Rwanda"]                   = {  12374397,  2641 };
    (*this)["Saint Kitts and Nevis"]    = {     52441, 31095 };
    (*this)["Saint Lucia"]              = {    184401, 13708 };
    (*this)["Saint Vincent and the Grenadines"]
                                        = {    100455, 12431 };
    (*this)["Samoa"]                    = {    202506,  5962 };
    (*this)["San Marino"]               = {     33600, 60651 };
    (*this)["Sao Tome and Principe"]    = {     71868,     0 };
    (*this)["Saudi Arabia"]             = {  34218169, 56817 };
    (*this)["Senegal"]                  = {  15854323,  3675 };
    (*this)["Serbia"]                   = {   6926705, 18840 };
    (*this)["Seychelles"]               = {     98462, 30486 };
    (*this)["Sierra Leone"]             = {   8059155,  1608 };
    (*this)["Singapore"]                = {   5685800,102742 };
    (*this)["Slovakia"]                 = {   5464060, 34815 };        
    (*this)["Slovenia"]                 = {   2108977, 40343 };
    (*this)["Solomon Islands"]          = {    652857,  2307 };
    (*this)["Somalia"]                  = {  15893219,   888 };
    (*this)["South Africa"]             = {  60142978, 12351 };
    (*this)["South Sudan"]              = {  12778250,  1420 };
    (*this)["Spain"]                    = {  47450795, 41736 };
    (*this)["Sri Lanka"]                = {  21919000, 13909 };
    (*this)["Sudan"]                    = {  44909353,  4232 };
    (*this)["Suriname"]                 = {    575990, 15845 };
    (*this)["Sweden"]                   = {  10402070, 52477 };
    (*this)["Switzerland"]              = {   8570146, 67557 };
    (*this)["Syria"]                    = {  17500657,  2900 };
    (*this)["Taiwan*"]                  = {  23568378, 56959 };
    (*this)["Tajikistan"]               = {   9537645,  3354 };
    (*this)["Tanzania"]                 = {  61193226,  3574 };
    (*this)["Thailand"]                 = {  69950850, 19169 };
    (*this)["Timor-Leste"]              = {   1340513,  4031 };
    (*this)["Togo"]                     = {   8608444,  1821 };
    (*this)["Trinidad and Tobago"]      = {   1366725, 32684 };
    (*this)["Tunisia"]                  = {  11708370, 13417 };
    (*this)["Turkey"]                   = {  83614362, 32278 };
    (*this)["US"]                       = { 331449281, 68309 };
    (*this)["Uganda"]                   = {  42729036,  2566 };
    (*this)["Ukraine"]                  = {  41383182, 10310 };
    (*this)["United Arab Emirates"]     = {   9800000, 69901 };
    (*this)["United Kingdom"]           = {  67886004, 47089 };
    (*this)["Uruguay"]                  = {   3518552, 24516 };
    (*this)["Uzbekistan"]               = {  35011180,  9595 };
    (*this)["Vanuatu"]                  = {    307815,  2850 };
    (*this)["Venezuela"]                = {  28887118,  7344 };
    (*this)["Vietnam"]                  = {  96208984, 10755 };
    (*this)["Washington"]               = {   7705281, 70979 };
    (*this)["West Bank and Gaza"]       = {    734547,  6220 };
    (*this)["Yemen"]                    = {  30491000,  2380 };
    (*this)["Zambia"]                   = {  17351708,  4148 };
    (*this)["Zimbabwe"]                 = {  15092171,  2621 };

    (*this)["Alabama"]                  = { 5024279, 48123 };
    (*this)["Alaska"]                   = { 736081,  73181 };
    (*this)["American Samoa"]           = {  46366,  11200 };
    (*this)["Arizona"]                  = { 7151502, 56581 };
    (*this)["Arkansas"]                 = { 3013756, 45869 };
    (*this)["California"]               = {39538223, 71228 };
    (*this)["Colorado"]                 = { 5773714, 69117 };
    (*this)["Connecticut"]              = { 3605944, 76106 };
    (*this)["Delaware"]                 = {  990837, 62852 };
    (*this)["District of Columbia"]     = {  689545, 77649 };
    (*this)["Florida"]                  = {21538187, 53267 };
    (*this)["Georgia"]                  = {10711908, 56183 };
    (*this)["Guam"]                     = {  168801, 35600 };
    (*this)["Hawaii"]                   = { 1455271, 77765 };
    (*this)["Idaho"]                    = { 1839106, 52225 };
    (*this)["Illinois"]                 = {12812508, 65030 };
    (*this)["Indiana"]                  = { 6785528, 54181 };
    (*this)["Iowa"]                     = { 3190369, 61691 };
    (*this)["Kansas"]                   = { 2940865, 56422 };
    (*this)["Kentucky"]                 = { 4509342, 52295 };
    (*this)["Louisiana"]                = { 4661468, 49973 };
    (*this)["Maine"]                    = { 1344212, 56277 };
    (*this)["Maryland"]                 = { 6185278, 80776 };
    (*this)["Massachusetts"]            = { 7033469, 77385 };
    (*this)["Michigan"]                 = {10077331, 54909 };
    (*this)["Minnesota"]                = { 5706494, 68388 };
    (*this)["Mississippi"]              = { 2963914, 43567 };
    (*this)["Missouri"]                 = { 6160281, 53578 };
    (*this)["Montana"]                  = { 1085407, 53386 };
    (*this)["Nebraska"]                 = { 1961504, 59970 };
    (*this)["Nevada"]                   = { 3104614, 60365 };
    (*this)["New Hampshire"]            = { 1377529, 73381 };
    (*this)["New Jersey"]               = { 9288994, 82545 };
    (*this)["New Mexico"]               = { 2120220, 46744 };
    (*this)["New York"]                 = {20215751, 64894 };
    (*this)["North Carolina"]           = {10453948, 52752 };
    (*this)["North Dakota"]             = {  779094, 61843 };
    (*this)["Northern Mariana Islands"] = {   51659, 24500 };
    (*this)["Ohio"]                     = {11799448, 54021 };
    (*this)["Oklahoma"]                 = { 3963516, 50051 };
    (*this)["Oregon"]                   = { 4237256, 60212 };
    (*this)["Pennsylvania"]             = {13011844, 59195 };
    (*this)["Puerto Rico"]              = { 3285874, 35943 };
    (*this)["Rhode Island"]             = { 1098163, 63870 };
    (*this)["South Carolina"]           = { 5124712, 50570 };
    (*this)["South Dakota"]             = {  886667, 56521 };
    (*this)["Tennessee"]                = { 6916897, 53320 };
    (*this)["Texas"]                    = {29183290, 64034 };
    (*this)["Utah"]                     = { 3271616, 60365 };
    (*this)["Vermont"]                  = {  643503, 57513 };
    (*this)["Virgin Islands"]           = {  105870, 36350 };
    (*this)["Virginia"]                 = { 8654542, 71535 };
    (*this)["West Virginia"]            = { 1793716, 43469 };
    (*this)["Wisconsin"]                = { 5893718, 59305 };
    (*this)["Wyoming"]                  = {  576851, 62268 };
  }
} props;

struct props2_t  : map<pair<string, string>, prop_t>  {
  props2_t()
  {
    {
      int gdp = 29411;
      string state = "Alabama";
      (*this)[make_pair("Autauga", state)] = {  58805, gdp };
      (*this)[make_pair("Baldwin", state)] = { 231767, gdp };
      (*this)[make_pair("Barbour", state)] = {  25223, gdp };
      (*this)[make_pair("Bibb",    state)] = {  22293, gdp };
      (*this)[make_pair("Blount",  state)] = {  59134, gdp };
      (*this)[make_pair("Bullock", state)] = {  10357, gdp };
      (*this)[make_pair("Butler",  state)] = {   1721, gdp };
      (*this)[make_pair("Calhoun", state)] = { 116441, gdp };
      (*this)[make_pair("Chambers",state)] = {  34772, gdp };
      (*this)[make_pair("Cherokee",state)] = {   1048, gdp };
      (*this)[make_pair("Chilton", state)] = {  45014, gdp };
      (*this)[make_pair("Choctaw", state)] = {  12665, gdp };
      (*this)[make_pair("Clarke",  state)] = {  23087, gdp };
      (*this)[make_pair("Clay",    state)] = {   9923, gdp };
      (*this)[make_pair("Cleburne",state)] = {  15056, gdp };
      (*this)[make_pair("Coffee",  state)] = {  53465, gdp };
      (*this)[make_pair("Colbert", state)] = {  57227, gdp };
      (*this)[make_pair("Conecuh", state)] = {  11597, gdp };
      (*this)[make_pair("Coosa",   state)] = {  10387, gdp };
      (*this)[make_pair("Covington", state)] = {37570, gdp };
      (*this)[make_pair("Crenshaw",state)] = {  13194, gdp };
      (*this)[make_pair("Cullman", state)] = {  87866, gdp };
      (*this)[make_pair("Dale", state)]    = {  49326, gdp };
      (*this)[make_pair("Dallas",  state)] = {  38462, gdp };
      (*this)[make_pair("DeKalb",  state)] = {  71608, gdp };
      (*this)[make_pair("Elmore",  state)] = {  87977, gdp };
      (*this)[make_pair("Escambia",state)] = {  36757, gdp };
      (*this)[make_pair("Etowah", state)]  = { 103436, gdp };
      (*this)[make_pair("Fayette", state)] = {  16321, gdp };
      (*this)[make_pair("Franklin", state)] = { 32113, gdp };
      (*this)[make_pair("Geneva", state)]  = { 26659, gdp };
      (*this)[make_pair("Greene", state)]  = {   7730, gdp };
      (*this)[make_pair("Hale", state)]    = {  14785, gdp };
      (*this)[make_pair("Henry", state)]   = {  17146, gdp };
      (*this)[make_pair("Houston", state)] = { 107202, gdp };
      (*this)[make_pair("Jackson", state)] = {  52579, gdp };
      (*this)[make_pair("Jefferson", state)] = {674721, gdp };
      (*this)[make_pair("Lamar", state)]   = {  13972, gdp };
      (*this)[make_pair("Lauderdale", state)] = {93564, gdp };
      (*this)[make_pair("Lawrence", state)] = {  33073, gdp };
      (*this)[make_pair("Lee", state)] =     {  174241, gdp };
      (*this)[make_pair("Limestone", state)] = {103570, gdp };
      (*this)[make_pair("Lowndes", state)] = { 10311, gdp };
      (*this)[make_pair("Macon", state)] = { 19532, gdp };
      (*this)[make_pair("Madison", state)] = { 388153, gdp };
      (*this)[make_pair("Marengo", state)] = { 19323, gdp };
      
      /*
	(*this)[make_pair("", state)] = {  , gdp };
	https://en.wikipedia.org/wiki/Marengo_County,_Alabama
      */
    }
  }
} props2;

double zmax;

bool is_errata(string name, int i, int z)
{
  if (name == "Turkey" && i == 322 && z > 800000)
    return true;
  if (name == "Ecuador" && i == 544 && z == 8786)
    return true;
  return false;
}

inline void out_data1(int i, ostream& os,
		      const pair<pair<double, double>, info_t>& p,
		      bool trunc, bool raitio, bool comp_name2)
{
  auto pos = p.first;
  auto x = pos.second;
  auto y = pos.first;
  const auto& info = p.second;
  const auto& val = info.val;
  assert(i+1 < val.size());
  auto z1 = val[i];
  auto z2 = val[i+1];
  double z = z2 - z1;
  auto name = info.name;
  if (is_errata(name, i, z)) {
    z1 = val[i-1];
    z2 = val[i];
    z = z2 - z1;
  }
  if (z < 0)
    z = 0;
  if (raitio) {
    if (name == "Summer Olympics 2020")
      return;
    auto nm = comp_name2 ? info.name2 : name;
    auto p = props.find(nm);
    assert(p != props.end());
    auto prop = p->second;
    z /= prop.population;
    z *= 100000;
  }
  zmax = max(zmax, z);
  if (trunc) {
    constexpr rect area = {{-179.745,72.9202},{-60.9756,23.5209}};
    if (!include(area, make_pair(x,y)))
      return;
  }
  os << x << ' ' << y << ' ' << z << '\n';
}

string erase_comma(string s)
{
  for (auto p = s.find_first_of(',') ; p != string::npos ; 
       p = s.find_first_of(',', p) ) {
    s.erase(p, 1);
  }
  return s;
}

string conv(string s)
{
  s = erase_comma(s);
  for (auto p = s.find_first_of(' '); p != string::npos ;
       p = s.find_first_of(' ',p) ) {
    s[p] = '_';
  }
  return s;
}

string conv(const vector<string>& chosen)
{
  string ret;
  for (auto s : chosen)
    ret += "." + conv(s);
  return ret;
}

bool near1(pair<double, double> p, pair<double, double> q)
{
  auto x1 = p.first;
  auto x2 = q.first;
  auto y1 = p.second;
  auto y2 = q.second;
  return fabs(x1 - y2) < 10 && fabs(y1 - x2) < 10;
}

bool near(const vector<pair<double, double> >& coords,
	  const pair<double, double>& pt)
{
  
  auto p = find_if(begin(coords), end(coords), bind2nd(ptr_fun(near1), pt));
  return p != end(coords);
}

bool comp(pair<pair<double, double>, info_t> p, string name)
{
  auto info = p.second;
  return info.name == name;
}

bool comp2(pair<pair<double, double>, info_t> p, string name)
{
  auto info = p.second;
  return info.name2 == name;
}

void get_coords(const map<pair<double, double>, info_t>& tbl,
		const vector<string>& chosen,
		vector<pair<double, double> >& res,
		bool comp_name2,
		bool trunc)
{
  auto pf = comp_name2 ? comp2 : comp;
  for (auto name : chosen) {
    auto p = find_if(begin(tbl), end(tbl), bind2nd(ptr_fun(pf), name));
    if (p == end(tbl)) {
      cerr << "unknown `" << name << "'\n";
      return;
    }
    auto pt = p->first;
    res.push_back(pt);
  }
}

void shurink(const map<pair<double, double>, info_t>& tbl,
	     string map_fn, const vector<string>& chosen, string new_map,
	     bool trunc)
{
  ifstream ifs(map_fn);
  if (!ifs) {
    cerr << "cannot open " << map_fn << '\n';
    return;
  }
  ofstream ofs(new_map);
  if (!ofs) {
    cerr << "cannot open " << new_map << '\n';
    return;
  }

  vector<pair<double, double> > coords;
  get_coords(tbl, chosen, coords, map_fn != "world.dat", trunc);
  
  while (!ifs.eof()) {
    double x;
    ifs >> x;
    double y;
    ifs >> y;
    double z;
    ifs >> z;
    assert(!z);
    if (near(coords, make_pair(x,y)))
      ofs << x << ' ' << y << ' ' << z << '\n';
  }
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

void out_data(int i, time_t t,
	      ostream& os,
	      const map<pair<double, double>, info_t>& tbl,
	      string map_fn,
	      int zrange,
	      bool trunc,
	      string postfix,
	      const vector<string>& chosen,
	      bool raitio,
	      bool comp_name2)
{
  string s = time2str(t);
  s += postfix;
  s += conv(chosen);
  if (raitio)
    s += ".raitio";
  ofstream ofs(s);
  if (!ofs) {
    cerr << "cannot open " << s << '\n';
    return;
  }

  for (const auto& x : tbl)
    out_data1(i, ofs, x, trunc, raitio, comp_name2);

  os << "set view 60,10\n";
  os << "set zrange [0:" << zrange << "]\n";  
  os << "splot " << '"' << s << '"' << " with impuls, \\\n";
  if (chosen.empty())
    os << '"' << map_fn << '"' << " with dots" << '\n';
  else {
    string new_map = map_fn + conv(chosen);
    static bool done;
    if (!done) {
      shurink(tbl, map_fn, chosen, new_map, trunc);
      done = true;
    }
    os << '"' << new_map << '"' << " with dots" << '\n';    
  }
  os << "reset\n";
}

bool on_map(const pair<pair<double, double>, info_t>& p)
{
  auto info = p.second;
  auto name = info.name;
  auto pos = p.first;
  if (name == "France")
    return near1(pos, make_pair(2.2137, 46.2276));
  if (name == "United Kingdom")
    return near1(pos, make_pair(-3.436, 55.3781));
  return true;
}

bool chose(string name, const map<pair<double, double>, info_t>& tbl,
	   map<pair<double, double>, info_t>& res, bool comp_name2)
{
  map<pair<double, double>, info_t> tmp;
  auto pf = comp_name2 ? comp2 : comp;
  copy_if(begin(tbl), end(tbl), inserter(tmp, begin(tmp)),
	  bind2nd(ptr_fun(pf), name));
  if (tmp.empty()) {
    cerr << "unknown `" << name << "'\n";
    return true;
  }
  copy_if(begin(tmp), end(tmp), inserter(res, begin(res)), on_map);
  return false;
}

void rd_and_out(string fn, ostream& os, string map_fn, int zrange,
		bool trunc, string  postfix, const vector<string>& chosen,
		bool raitio, bool comp_name2, time_t b, time_t e)
{
  ifstream ifs(fn);
  if (!ifs) {
    cerr << "cannot open " << fn << '\n';
    return;
  }
  vector<time_t> vt;
  map<pair<double, double>, info_t> tbl;
  rd_data(ifs, vt, tbl);

  if (!chosen.empty()) {
    map<pair<double, double>, info_t> tmp;    
    for (const auto& name : chosen) {
      if (chose(name, tbl, tmp, map_fn != "world.dat"))
	return;
    }
    tbl = tmp;
  }

  os << "#! /usr/local/bin/gnuplot -p\n\n";
  for (int i = 0 ; i != vt.size() ; ++i) {
    auto t = vt[i];
    if (b && t < b)
      continue;
    if (e && e <= t)
      continue;
    out_data(i, t, os, tbl, map_fn, zrange, trunc, postfix, chosen,
	     raitio, comp_name2);
  }
}

inline void gen_gp(string fn, string map_fn, int zrange, bool print_zmax,
		   bool trunc, string postfix, const vector<string>& chosen,
		   bool raitio, bool comp_name2, time_t b, time_t e)
{
  zmax = 0;
  string gp = fn;
  if (!chosen.empty()) {
    gp += conv(chosen);
    gp += ".map";
  }
  if (raitio)
    gp += ".raitio";
  if (b)
    gp += '.' + time2str(b);
  if (e)
    gp += '.' + time2str(e);
  gp += ".gp";
  ofstream ofs(gp);
  if (!ofs) {
    cerr << "cannot open " << gp << '\n';
    return;
  }
  if (chmod(gp.c_str(), 0755) < 0) {
    cerr << "chmod failed\n";
    return;
  }
  cout << "./" << gp << '\n';
  
  rd_and_out(fn, ofs, map_fn, zrange, trunc, postfix, chosen, raitio,
	     comp_name2, b, e);
  if (print_zmax)
    cerr << zmax << '\n';
}

void gen_gps(bool trunc, bool print_zmax, bool just_us,
	     const vector<string>& chosen, int z, bool raitio,
	     time_t b, time_t e)
{
  if (just_us) {
    string map_fn = trunc ?
      "cb_2020_us_state_20m.shp.dat2" : "cb_2020_us_state_20m.shp.dat";
    auto z1 = raitio ? 100 : 10000;
    z1 = z < 0 ? z1 : z;
    gen_gp("time_series_covid19_confirmed_US.csv",
	   map_fn, z1, print_zmax, trunc, ".conf.US", chosen, raitio, true,
	   b, e);
    auto z2 = raitio ? 10 : 1000;
    z2 = z < 0 ? z2 : z;
    gen_gp("time_series_covid19_deaths_US.csv",
	   map_fn, z2,  print_zmax, trunc, ".death.US", chosen, raitio, true,
	   b, e);
    return;
  }
  auto z1 = raitio ? 400 : 40000;
  z1 = z < 0 ? z1 : z;
  gen_gp("time_series_covid19_confirmed_global.csv", "world.dat",
	 z1, print_zmax, false, ".conf.global", chosen, raitio, false,
	 b, e);
  auto z2 = raitio ? 4 : 4000;
  z2 = z < 0 ? z2 : z;
  gen_gp("time_series_covid19_deaths_global.csv", "world.dat",
	 z2, print_zmax, false, ".death.global", chosen, raitio, false,
	 b, e);
}

bool should_skip(string name, string name2, string chosen, bool comp_name2)
{
  if (comp_name2)
    return name2 != chosen;
  return name != chosen;
}

void get_entry(istream& is, int id, int id2, int n, string chosen,
	       vector<int>& res, bool comp_name2)
{
  string s;
  string name, name2;
  pair<double, double> pos;
  int r = 0;
  for (int c ; (c = is.get()) != -1 ; ) {
    if (eoi(c, s)) {
      ++r;
      if (r == id)
	name = s;
      if (r == id2)
	name2 = s;
      if (r == n)
	break;
      s.clear();
    }
    else
      s += char(c);
  }

  if (name.empty()) {
    // invalid chosen is specified or reached to EOF
    return;
  }
  
  auto len = name.length();  
  if (name[0] == '"') {
    assert(name[len-1] == '"');
    name.erase(len-1);
    name.erase(0,1);
  }
  if (name[len-1] == '*')
    name.erase(len-1);

  if (should_skip(name, name2, chosen, comp_name2)) {
    while (is.get() != '\n')
      ;
    return;
  }

  bool e = res.empty();

  for (int i = 0 ; !is.eof() ; ++i) {
    int v;
    is >> v;
    if (e)
      res.push_back(v);
    else {
      assert(i < res.size());
      res[i] += v;
    }
    int c = is.get();
    if (c == '\n')
      break;
    assert(c == ',');
  }
}

void rd_and_out(string ifn, string chosen, bool raitio, string ofn,
		bool comp_name2, int nth, int scale, bool print_zmax)
{
  ifstream ifs(ifn);
  if (!ifs) {
    cerr << "cannot open " << ifn << '\n';
    return;
  }

  int id, id2, dummy, n;
  skip_header(ifs, &id, &id2, &dummy, &n);

  vector<time_t> vt;
  while (auto t = get_day(ifs))
    vt.push_back(t);

  vector<int> vi;
  while (!ifs.eof())
    get_entry(ifs, id, id2, n, chosen, vi, comp_name2);

  if (vi.empty()) {
    assert(!chosen.empty());
    // nothing may be chosen
    cerr << "unknown `" << chosen << "'\n";
    return;
  }

  ofstream ofs(ofn);
  if (!ofs) {
    cerr << "cannot open " << ofn << '\n';
    return;
  }

  double population = 0;
  if (raitio) {
    auto p = props.find(chosen);
    assert(p != props.end());
    auto prop = p->second;
    population = prop.population;
  }

  int zmax = 0;
  assert(vt.size()+1 == vi.size());
  for (int i = 0 ; i != vt.size() ; ++i) {
    auto t = vt[i];
    auto y1 = vi[i];
    auto y2 = vi[i+1];
    auto v = y2 - y1;
    if (is_errata(chosen, i, v)) {
      y1 = vi[i-1];
      y2 = vi[i];
      v = y2 - y1;
    }
    zmax = max(zmax, v);
    v *= scale;
    if (v < 0)
      v = 0;
    ofs << t << ' ';
    if (nth >= 0)
      ofs << nth << ' ';
    if (raitio)
      ofs << v/population * 100000;
    else
      ofs << v;
    ofs << '\n';
  }

  if (print_zmax)
    cout << "max : " << zmax << '\n';
}

inline void gen_gp1(string fn, string name, ostream& os, bool raitio,
		    bool just_one, bool comp_name2, int nth, int scale,
		    bool print_zmax)
{
  string ofn = fn + "." + conv(name);
  if (raitio)
    ofn += ".raitio";
  if (nth >= 0)
    ofn += ".3";
  if (scale != 1) {
    ostringstream os;
    os << '.' << scale;
    ofn += os.str();
  }
  ofn += ".dat";
  rd_and_out(fn, name, raitio, ofn, comp_name2, nth, scale, print_zmax);

  if (nth < 0) {
    // -3 option not specified    
    if (just_one)
      os << '"' << ofn << '"' << " using 1:2 with impuls\n";
    else
      os << '"' << ofn << '"' << " using 1:2 with line, \\\n";
    return;
  }

  os << '"' << ofn << '"' << " using 1:2:3 with impuls\n";
}

void gen_gp(string fn, const vector<string>& chosen, bool raitio,
	    bool comp_name2, bool three, int start, int scale, bool print_zmax)
{
  string s = fn + conv(chosen);
  if (raitio)
    s += ".raitio";
  if (three)
    s += ".3";
  if (scale != 1) {
    ostringstream os;
    os << '.' << scale;
    s += os.str();
  }
  string gp = s + ".gp";
  ofstream ofs(gp);
  if (!ofs) {
    cerr << "cannot open " << gp << '\n';
    return;
  }
  if (chmod(gp.c_str(), 0755) < 0) {
    cerr << "chmod failed\n";
    return;
  }
  cout << "./" << gp << '\n';
    
  ofs << "#! /usr/local/bin/gnuplot -p\n\n";
  ofs << "set xdata time\n";
  ofs << "set timefmt " << '"' << "%s" << '"' << '\n';
  if (three)
    ofs << 's';
  ofs << "plot \\\n";

  bool just_one = (chosen.size() == 1);
  int nth = three ? start : -1;
  for (auto name : chosen) {
    gen_gp1(fn, name, ofs, raitio, just_one, comp_name2, nth, scale,
	    print_zmax);
    if (three)
      nth += chosen.size();
  }
}

void gen_both_gp1(ostream& os, string fn, string name, bool raitio, bool y2,
		  bool three, int scale)
{
  string s = fn + '.' + conv(name);
  if (raitio)
    s += ".raitio";
  if (three)
    s += ".3";
  if (scale != 1) {
    ostringstream os;
    os << '.' << scale;
    s += os.str();
  }
  s += ".dat";

  if (three)
    os << '"' << s << '"' << " using 1:2:3 with impuls";
  else {
    os << '"' << s << '"' << " using 1:2 with line";
    if (y2)
      os << " axes x1y2";
  }
  os << ", \\\n";
}

void gen_both_gp(string fn1, string fn2, const vector<string>& chosen,
		 bool raitio, double y, bool three, int scale)
{
  string gp = fn1 + '.' + fn2 + conv(chosen);
  if (raitio)
    gp += ".raitio";
  if (three)
    gp += ".3";
  if (scale != 1) {
    ostringstream os;
    os << '.' << scale;
    gp += os.str();
  }
  gp += ".gp";
  ofstream ofs(gp);
  if (!ofs) {
    cerr << "cannot open " << gp << '\n';
    return;
  }
  if (chmod(gp.c_str(), 0755) < 0) {
    cerr << "chmod failed\n";
    return;
  }
  cout << "./" << gp << '\n';

  ofs << "#! /usr/local/bin/gnuplot -p\n\n";
  ofs << "set xdata time\n";
  ofs << "set timefmt \"%s\"\n";
  if (three)
    ofs << 's';
  else {
    ofs << "set ytics nomirror\n";
    ofs << "set y2tics nomirror\n";
  }
  ofs << "plot \\\n";

#if 0  
  for (auto s : chosen)
    gen_both_gp1(ofs, fn1, s, raitio, false, three, 1);

  for (auto s : chosen)
    gen_both_gp1(ofs, fn2, s, raitio, true, three, scale);
#else

  for (auto p = rbegin(chosen) ; p != rend(chosen) ; ++p) {
    auto s = *p;
    gen_both_gp1(ofs, fn2, s, raitio, true, three, scale);
  }

  for (auto p = rbegin(chosen) ; p != rend(chosen) ; ++p) {
    auto s = *p;
    gen_both_gp1(ofs, fn1, s, raitio, false, three, 1);
  }  
#endif 
}

void gen_gps(const vector<string>& chosen, bool just_us, bool raitio,
	     bool three, int scale, bool print_zmax)
{
  auto y = raitio ? 1.4 : 14000;  
  if (just_us) {
    string fn1 = "time_series_covid19_confirmed_US.csv";
    string fn2 = "time_series_covid19_deaths_US.csv";
    gen_gp(fn1, chosen, raitio, true, three, 0, 1, print_zmax);
    gen_gp(fn2, chosen, raitio, true, three, 1, scale, print_zmax);
    gen_both_gp(fn1, fn2, chosen, raitio, y, three, scale);
    return;
  }
  string fn1 = "time_series_covid19_confirmed_global.csv";
  string fn2 = "time_series_covid19_deaths_global.csv";
  gen_gp(fn1, chosen, raitio, false, three, 0, 1, print_zmax);
  gen_gp(fn2, chosen, raitio, false, three, 1, scale, print_zmax);
  gen_both_gp(fn1, fn2, chosen, raitio, y, three, scale);
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

inline void usage(const char* prog)
{
  cerr << "usage % " << prog << " [-p][-a][-c Japan][-m][-u][-z 2000][-r]";
  cerr << '\n';
}

int main(int argc, char** argv)
{
  bool print_zmax = false;
  bool trunc = true;
  bool just_us = false;
  bool use_map = true;
  int zrange = -1;
  bool raitio = false;
  vector<string> chosen;
  bool three = false;
  int scale = 1;
  time_t b = 0, e = 0;
  for (int opt; (opt = getopt(argc, argv, "pac:umz:r3s:b:e:")) != -1 ; ) {
    switch (opt) {
    case 'p': print_zmax = true; break;
    case 'a': trunc = false; break;
    case 'c': chosen.push_back(optarg); use_map = false; break;
    case 'u': just_us = true; break;
    case 'm': use_map = true; break;
    case 'z': zrange = atoi(optarg); break;
    case 'r': raitio = true; break;
    case '3': three = true; break;
    case 's': scale = atoi(optarg); break;
    case 'b': b = get_day(optarg); break;
    case 'e': e = get_day(optarg); break;
    default:
    case '?': usage(argv[0]); return 1;
    }
  }

  if (optind != argc) {
    usage(argv[0]);
    return 1;
  }

  if (use_map) {
    gen_gps(trunc, print_zmax, just_us, chosen, zrange, raitio, b, e);
    return 0;
  }

  gen_gps(chosen, just_us, raitio, three, scale, print_zmax);
  return 0;
}
