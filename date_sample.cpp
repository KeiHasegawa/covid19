#include <sys/time.h>
#include <time.h>

int main()
{
  timeval res;
  gettimeofday(&res, nullptr);
  auto tm = localtime(&res.tv_sec);
  auto p = asctime(tm);
  auto copied = *tm;
  copied.tm_sec = 0;
  copied.tm_min = 0;
  copied.tm_hour -= 2;
  auto q = asctime(&copied);
  auto t = res.tv_sec;
  t -= tm->tm_sec;
  t -= tm->tm_min * 60;
  t -= 2 * 3600;
  auto tm2 = localtime(&t);
  auto r = asctime(tm2);
  return 0;
}
