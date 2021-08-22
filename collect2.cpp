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
};

std::vector<info_t> data = {
  {533946114, "Nihonbashi"},
  {533946113, "Marunouchi"},
#if 1
  {533946211, "Ootemachi"},
  {533946013, "Ginza"},
  {533936904, "Shinbashi"},
  {533946001, "Toranomon"},
  {533946411, "Ochanomizu"},
  {533946521, "Ueno"},
  {533946532, "Asakusa"},
  {533946542, "Skytree"},
  {533946353, "Kinshicho"},
  {533936834, "Toyosu"},
  {533936833, "Raraport"},
  {533935981, "Roppongi"},
  {533935961, "Shibuya"},
  {533935952, "Centergai"},
  {533935853, "Kamiizumi"},
  {533945052, "Yoyogi"},
  {533945254, "Shinjuku"},
  {533945263, "ShinjukuHigashi"},
  {533945361, "Kabukicho"},
  {533945764, "Ikebukuro"},
  {533945433, "Nakano"},
  {533945963, "Ohyama"},
  {533946712, "Nippori"},
  {533946943, "Kitasenju"},
  {533936521, "Daiba"},
  {533935591, "Shinagawa"},
  {533935481, "Ohsaki"},
  {533925771, "Kamata"},
  {533926524, "Haneda"},
  {533925354, "Kawasaki"},
  {533925363, "KeikyuKawasaki"},
  {533935732, "Sangenchaya"},
  {533932873, "Hachioji"},
  {533933931, "Takahatahudo"},
  {533943083, "Huchu"},
  {533934601, "Inagi"},
  {533934832, "Chohu"},
  {533934662, "Kitami"},
  {533944494, "Ogikubo"},
  {533944461, "Kichijoji"},
  {533944442, "Mitaka"},
  {533944402, "MusashiKoganei"},
  {533943481, "Kokubunji"},
  {533943333, "Tachikawa"},
  {533942584, "Akishima"},
  {533942722, "Akikawa"},
  {533942902, "Hinodecho"},
  {533942961, "Hussa"},
  {533952274, "Hakonesaki"},
  {533952341, "Kosaku"},
  {533952422, "Kawabe"},
  {533954214, "Kiyose"},
  {533954122, "Higashikurume"},
  {533943974, "Kumekawa"},
  {533944731, "Tanashi"},
  {533943683, "Hitotsubashigakuen"},
  {533945821, "Nerima"},
  {533955372, "Akabane"},

  {533925141, "Tsurumi"},
  {533924191, "Shinyokohama"},
  {533915603, "Kanagawaeki"},
  {533914594, "Yokohama"},
  {533915313, "NipponOhdouri"},
  {533914474, "Hoshikawa"},
  {533914291, "Yoshinocho"},
  {533904972, "Kamiohoka"},
  {533904192, "Kanazawabunko"},
  {523974841, "Kamakura"},
  {523975332, "Yokosukachuo"},
  {523974561, "Shinzushi"},
  {523974264, "Hayamacho"},
  {533903084, "Hujisawa"},
  {533903084, "Oohuna"},
  {533904822, "Totsuka"},
  {533904903, "Tateba"},
  {533903402, "Samukawacho"},
  {523973924, "Chigasaki"},
  {523972972, "Hiratsuka"},
  {523972751, "Ohiso"},
  {523972504, "Ninomiya"},
  {523971023, "Odawara"},
  {533902414, "Tokaidaigaku"},
  {533902753, "Isehara"},
  {533912293, "Honatsugi"},
  {533913411, "Ebina"},
  {533913662, "Yamato"},
  {533913682, "Seya"},
  {533913241, "Ayase"},
  {533923134, "OdakyuSagamihara"},
  {533923353, "Sagamiohno"},
  {533923552, "Machida"},
  {533924942, "Tamapraza"},
  {533924552, "CenterMinami"},
  {533925922, "MusashiKosugi"},
  {533934071, "Miyazakidai"},
  {533934184, "Mizonokuchi"},
  {533934452, "Noborido"},
  {533934202, "Shinyuri"},
  {533923812, "Huchinobe"},
  {533932172, "Hashimoto"},
  {533922352, "Aikawacho"},
  {533933434, "Tamacenter"},
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

inline bool capture(std::string wid, std::string name, kind_t kind)
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
 label:  
  ostringstream osz;
  osz << "xwd -id " << wid << " -out " << name << " -silent";
  auto z = system(osz.str().c_str());
  if (z) {
    cerr << osz.str() << " failed\n";
    return true;
  }

  if (kind == time_s) {
    ostringstream osu;
    osu << "tdata -in " << name << " > " << name << ".dat";
    auto u = system(osu.str().c_str());
    if (u) {
      static set<string> retry;
      if (retry.find(name) != retry.end()) {
	cerr << osu.str() << " failed\n";
	return true;
      }
      retry.insert(name);
      sleep(5);
      goto label;
    }
#if 0    
    unlink(name.c_str());
#endif    
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
  if (capture(wid, info.place + ".time", time_s))
    return true;
  if (capture(wid, info.place + ".gen", generation))
    return true;
  if (capture(wid, info.place + ".place", place))
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
