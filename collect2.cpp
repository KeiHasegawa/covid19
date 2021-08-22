#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <set>

struct info_t {
  int id;
  std::string place;
  std::pair<double, double> coord;
};

std::vector<info_t> data = {
  {533946114, "Nihonbashi", {35.68123,139.774534}},
#if 1
  {533946113, "Marunouchi", {35.680478,139.765367}},
  {533946211, "Ootemachi", {35.687438,139.764955}},
  {533946013, "Ginza", {35.669626,139.765539}},
  {533936904, "Shinbashi", {35.664917,139.757003}},
  {533946001, "Toranomon", {35.665949,139.74625}},
  {533946411, "Ochanomizu", {35.718733,139.731683}},
  {533946521, "Ueno", {35.711622,139.775695}},
  {533946532, "Asakusa", {35.717064,139.79875}},
  {533946542, "Skytree", {35.710063,139.8107}},
  {533946353, "Kinshicho", {35.698312,139.813998}},
  {533936834, "Toyosu", {35.652026,139.788785}},
  {533936833, "RaraportToyosu", {35.655735,139.792662}},
  {533935981, "Roppongi", {35.662893,139.733651}},
  {533935961, "Shibuya", {35.658034,139.701636}},
  {533935952, "Centergai", {35.658034,139.701636}},
  {533935853, "Kamiizumi", {35.65727,139.693623}},
  {533945052, "Yoyogikouen", {35.671587,139.696703}},
  {533945254, "ShinjukuNishi", {35.693292,139.699132}},
  {533945263, "ShinjukuHigashi", {35.689607,139.700571}},
  {533945361, "Kabukicho", {35.695543,139.703149}},
  {533945764, "Ikebukuro", {35.736262,139.707009}},
  {533945433, "Nakano", {35.70607,139.659262}},
  {533945963, "Ohyamaeki", {35.748531,139.702286}},
  {533946712, "Nippori", {35.728158,139.770641}},
  {533946943, "Kitasenju", {35.753029,139.803752}},
  {533936521, "Daiba", {35.61885,139.780188}},
  {533935591, "Shinagawa", {35.628471,139.73876}},
  {533935481, "Ohsaki", {35.619851,139.728189}},
  {533925771, "Kamata", {35.562479,139.716073}},
  {533926524, "Haneda", {35.549393,139.779839}},
  {533935732, "Sangenchaya", {35.641285,139.667989,}},
  {533932873, "Hachioji", {35.658566,139.295838}},
  {533933931, "Takahatahudo", {35.662013,139.411074}},
  {533943083, "Huchu", {35.673204,139.477815}},
  {533934601, "Inagi", {35.628468,139.494632}},
  {533934832, "Chohu", {35.660425,139.555081}},
  {533934662, "Kitami", {35.636547,139.587245}},
  {533944494, "Ogikubo", {35.697402,139.622517}},
  {533944461, "Kichijoji", {35.703158,139.580115}},
  {533944442, "Mitaka", {35.683546,139.559268}},
  {533944402, "MusashiKoganei", {35.701123,139.506912}},
  {533943481, "Kokubunji", {35.705538,139.460007}},
  {533943333, "Tachikawa", {35.714188,139.399159}},
  {533942584, "Akishima", {35.708829,139.364915}},
  {533942722, "Akikawa", {35.728027,139.286749}},
  {533942902, "Hinodecho", {35.742117,139.257405}},
  {533942961, "Hussa", {35.742364,139.327865}},
  {533952274, "Hakonesaki", {35.771312,139.346714}},
  {533952341, "Kosaku", {35.777083,139.303125}},
  {533952422, "Kawabe", {35.785417,139.284375}},
  {533954214, "Kiyose", {35.784283,139.521967}},
  {533954122, "Higashikurume", {35.753218,139.516371}},
  {533943974, "Kumekawa", {35.750026,139.472007}},
  {533944731, "Tanashi", {35.727083,139.540625}},
  {533943683, "Hitotsubashigakuen", {35.72206,139.480039}},
  {533945821, "Nerima", {35.735785,139.651776}},
  {533955372, "Akabane", {35.783721,139.7217}},

  {533925354, "Kawasaki", {35.531365,139.696889}},
  {533925363, "KeikyuKawasaki", {35.531365,139.696889}},
  {533925141, "Tsurumi", {35.508036,139.676262}},
  {533924191, "Shinyokohama", {35.508043,139.614786}},
  {533915603, "Kanagawaeki", {35.471027,139.627114}},
  {533914594, "Yokohama", {35.465981,139.622062}},
  {533915313, "NipponOhdouri", {35.446456,139.642306}},
  {533914474, "Hoshikawa", {35.458875,139.589907}},
  {533914291, "Yoshinocho", {35.435417,139.615625}},
  {533904972, "Kamiohoka", {35.409122,139.596629}},
  {533904192, "Kanazawabunko", {35.343905,139.628711}},
  {523974841, "Kamakura", {35.319065,139.550412}},
  {523975332, "Yokosukachuo", {35.278699,139.67004}},
  {523974561, "Shinzushi", {35.295934,139.581199}},
  {523974264, "Hayamacho", {35.272094,139.586202}},
  {533903084, "Hujisawa", {35.338898,139.48747}},
  {533903084, "Oohuna", {35.354048,139.531299}},
  {533904822, "Totsuka", {35.400766,139.534204}},
  {533904903, "Tateba", {35.414484,139.500994}},
  {533903402, "Samukawacho", {35.37595,139.387012}},
  {523973924, "Chigasaki", {35.330303,139.406817}},
  {523972972, "Hiratsuka", {35.32783,139.350645}},
  {523972751, "Ohiso", {35.311435,139.313291}},
  {523972504, "Ninomiya", {35.298786,139.257598}},
  {523971023, "Odawara", {35.256445,139.155393}},
  {533902414, "Tokaidaigaku", {35.372872,139.270904}},
  {533902753, "Isehara", {35.396037,139.313594}},
  {533912293, "Hon-atsugi", {35.439408,139.364422}},
  {533913411, "Ebina", {35.454271,139.389335}},
  {533913662, "Yamato", {35.469831,139.461463}},
  {533913682, "Seya", {35.473081,139.475668}},
  {533913241, "Ayase", {35.437553,139.430111}},
  {533923134, "OdakyuSagamihara", {35.515191,139.422653}},
  {533923353, "Sagamiohno", {35.532641,139.433562}},
  {533923552, "Machida", {35.541994,139.445376}},
  {533924942, "Tamapraza", {35.577406,139.558528}},
  {533924552, "CenterMinami", {35.545583,139.57451}},
  {533925922, "MusashiKosugi", {35.576629,139.66}},
  {533934071, "Miyazakidai", {35.587217,139.591201}},
  {533934184, "Mizonokuchi", {35.599965,139.610623}},
  {533934452, "Noborido", {35.620766,139.570098}},
  {533934202, "Shinyuri", {35.603805,139.507605}},
  {533923812, "Huchinobe", {35.568734,139.3951}},
  {533932172, "Hashimoto", {35.594864,139.344922}},
  {533922352, "Aikawacho", {35.528821,139.321661}},
  {533933434, "Tamacenter", {35.623931,139.422853}},
#endif  
};

enum kind_t { time_s, generation, place };

inline int pos(kind_t kind)
{
  switch (kind) {
  case time_s:
    return 350;
  case generation:
    return 480;
  case place:
  default:
    return 610;
  }
}

inline std::string dump_file(std::string base, kind_t kind)
{
  switch (kind) {
  case time_s:
    return base + ".time";
  case generation:
    return base + ".gen";
  case place:
  default:
    return base + ".gen";
  }
}

inline bool capture(std::string wid, const info_t& info, kind_t kind)
{
  using namespace std;
  if (kind != time_s) {
    ostringstream os;
    os << "xdotool mousemove --window " << wid << ' ';
    os << pos(kind) << ' ' << 490;
    auto x = system(os.str().c_str());
    if (x) {
      cerr << os.str() << " failed\n";
      return true;
    }
    const char* cmd = "xdotool click 1";
    auto y = system(cmd);
    if (y) {
      cerr << cmd << " failed\n";
      return true;
    }
  }
  string fn = dump_file(info.place, kind);
 label:
  ostringstream osz;
  osz << "xwd -id " << wid << " -out " << fn << " -silent";
  auto z = system(osz.str().c_str());
  if (z) {
    cerr << osz.str() << " failed\n";
    return true;
  }

  if (kind == time_s) {
    ostringstream os;
    auto c = info.coord;
    os << "tdata -in " << fn;
    os << " -x " << c.first;
    os << " -y " << c.second;
    os << " > " << fn << ".cpp";
    auto u = system(os.str().c_str());
    if (u) {
      static set<string> retry;
      if (retry.find(fn) != retry.end()) {
	cerr << os.str() << " failed\n";
	return true;
      }
      retry.insert(fn);
      sleep(5);
      goto label;
    }
    unlink(fn.c_str());
  }
  return false;
}

inline bool close_tab(std::string wid)
{
  using namespace std;
  ostringstream os;
  os << "xdotool mousemove --window " << wid << " 210 10";
  auto x = system(os.str().c_str());
  if (x) {
    cerr << os.str() << " failed\n";
    return true;
  }
  const char* cmd = "xdotool click 1";
  auto y = system(cmd);
  if (y) {
    cerr << cmd << " failed\n";
    return true;
  }
  return false;
}

inline bool subr(const info_t& info)
{
  using namespace std;
  pid_t pid = fork();
  if (!pid) {
    ostringstream os;
    os << "https://tokyo.mobakumap.jp/#" << info.id;
    execl("/usr/bin/firefox", "firefox", os.str().c_str(), nullptr);
    cerr << "execl failed\n";
    return 1;
  }
  sleep(15);
  ostringstream os;
  os << "w."<< pid;
  string log = os.str();
  string cmd = "xwininfo -root -tree | grep 'モバイル空間統計' | awk '{print $1}'";
  cmd += "> ";
  cmd += log;
  auto y = system(cmd.c_str());
  if (y) {
    cerr << cmd << " failed\n";
    return true;
  }
  ifstream ifs(log);
  string wid;
  ifs >> wid;
  unlink(log.c_str());  
  if (wid.empty()) {
    // no firefox mobakumap page
    return true;
  }
  if (capture(wid, info, time_s))
    return true;
  if (capture(wid, info, generation))
    return true;
  if (capture(wid, info, place))
    return true;
  return close_tab(wid);
}

int main()
{
  using namespace std;
  pid_t pid = fork();
  if (!pid) {
    ostringstream os;
    execl("/usr/bin/firefox", "firefox",
	  "https://tokyo.mobakumap.jp/", nullptr);
    cerr << "execl failed\n";
    return 1;
  }
  sleep(30);
  auto p = find_if(begin(data), end(data), subr);
  return end(data) - p;
}
