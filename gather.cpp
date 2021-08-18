#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <X11/X.h>
#include <X11/Xlib.h>

#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>

Window getWin1(Display* dpy, Window win)
{
  using namespace std;
  char* name;
  if (XFetchName(dpy, win, &name) && string("Firefox") == name)
    return win;
  Window *children, dummy;
  unsigned int n;
  auto status = XQueryTree(dpy, win, &dummy, &dummy, &children, &n);
  assert(status);
  auto p = find_if(&children[0], &children[n], bind1st(ptr_fun(getWin1), dpy));
  XFree(children);  
  if (p == &children[n])
    return 0;
  return *p;
}

inline Window getWin(Display* dpy, Window win)
{
  while (1) {
    if (auto ret = getWin1(dpy, win))
      return ret;
  }
}

inline bool pid_prop(Display* dpy, Atom atom)
{
  using namespace std;
  auto name = XGetAtomName(dpy, atom);
  bool ret = string("_NET_WM_PID") == name;
  XFree(name); 
  return ret;
}

void capture(pid_t pid)
{
  using namespace std;
  auto dpy = XOpenDisplay(nullptr);
  auto scr = XDefaultScreen(dpy);
  auto top = RootWindow(dpy, scr);
  Window win = getWin(dpy, top);
  int cnt;
  auto atoms = XListProperties(dpy, win, &cnt);
  auto p = find_if(&atoms[0], &atoms[cnt], bind1st(ptr_fun(pid_prop), dpy));
  assert(p != &atoms[cnt]);
  auto name = XGetAtomName(dpy, *p);
  auto atom = XInternAtom(dpy, name, true);
  Atom type;
  int format;
  unsigned long nitems;
  unsigned long bytes;
  unsigned char* prop;
  auto status = XGetWindowProperty(dpy, win, atom, 0, 4,
				   false, AnyPropertyType, &type,
				   &format, &nitems, &bytes,
				   &prop);
  assert(status == Success);
  assert(format == 32);
  assert(nitems == 1);
  assert(bytes == 0);
  auto x = *reinterpret_cast<int*>(prop);
  if (x != pid) {
    // `firefox' has been already running.
    asm("int3");
  }
  XFree(name);
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
	  "192.168.100.17:0.0",
	  nullptr);
    cerr << "exec failed\n";
    return 1;
  }
  capture(pid);
  kill(pid, SIGTERM);
  return 0;
}
