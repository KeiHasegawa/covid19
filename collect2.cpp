#include <unistd.h>
#include <signal.h>

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
};

inline bool capture(std::string wid, std::string place)
{
  using namespace std;
  ostringstream os;
  os << "xwd -id " << wid << " -out " << place << ".xwd -silent";
  auto status = system(os.str().c_str());
  if (status) {
    cerr << os.str() << " failed\n";
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
  sleep(25);
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
  struct sweeper {
    pid_t pid;
    sweeper(pid_t p) : pid{p} {}
    ~sweeper()
    {
      kill(pid, SIGTERM);
    }
  } sweeper(pid);
  return capture(wid, info.place);
}

int main()
{
  using namespace std;
  auto p = find_if(begin(data), end(data), subr);
  return end(data) - p;
}
