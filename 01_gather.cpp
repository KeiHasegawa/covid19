#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <iostream>

void capture()
{
  sleep(20);
}

int main()
{
  using namespace std;
  pid_t pid = fork();
  if (!pid) {
    execl("/usr/bin/firefox",
	  "firefox",
	  "https://tokyo.mobakumap.jp/",
	  "--display",
	  "192.168.100.17:0.0", 0);
    cerr << "exec failed\n";
    return 1;
  }
  capture();
  kill(pid, SIGTERM);
  return 0;
}
