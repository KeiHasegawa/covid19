#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

struct info_t {
  int id;
  std::string place;
};

std::vector<info_t> data = {
  {533946114, "Nihonbashi"},
  {533946113, "Marunouchi"},
#if 0  
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
  ostringstream os;
  os << "xwd -id " << wid << " -out " << name << " -silent";
  auto z = system(os.str().c_str());
  if (z) {
    cerr << os.str() << " failed\n";
    return true;
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
  static bool first = true;
  if (first) {
    sleep(20);
    first = false;
  }
  else
    sleep(10);
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
