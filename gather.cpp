#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

bool comp(Display* dpy, Window win)
{
  using namespace std;
  char* name;
  if (!XFetchName(dpy, win, &name))
    return false;
  bool ret = string("Firefox") == name;
  XFree(name);
  return ret;
}

Window getWin1(Display* dpy, Window top)
{
  using namespace std;
  Window* children, dummy;
  unsigned int n;
  auto status = XQueryTree(dpy, top, &dummy, &dummy, &children, &n);
  struct sweeper {
    Window* ptr;
    sweeper(Window* p) : ptr{p} {}
    ~sweeper(){ XFree(ptr); }
  }  sweeper(children);
  assert(status);
  auto x = count_if(&children[0], &children[n], bind1st(ptr_fun(comp), dpy));
  if (x)
    cout << "x = " << x << '\n';
  auto p = find_if(&children[0], &children[n], bind1st(ptr_fun(comp), dpy));
  assert(p != &children[n]);
  return *p;
}

inline Window getWin(Display* dpy, Window top)
{
  sleep(30);
  return getWin1(dpy, top);    
}

inline bool pid_prop(Display* dpy, Atom atom)
{
  using namespace std;
  auto name = XGetAtomName(dpy, atom);
  bool ret = string("_NET_WM_PID") == name;
  XFree(name); 
  return ret;
}

inline int Image_Size(XImage *image)
{
  if (image->format != ZPixmap)
    return(image->bytes_per_line * image->height * image->depth);

  return(image->bytes_per_line * image->height);
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
  XFree(name);
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
  auto xpid = *reinterpret_cast<int*>(prop);
  if (pid != xpid) {
    // `firefox' has been already running.
    // just ignore.
  }
  XWindowAttributes info;
  if(!XGetWindowAttributes(dpy, win, &info)) {
    cerr << "XGetWindowAttributes failed\n";
    return;
  }
  assert(info.x >= 0 && info.y >= 0);
  int absx, absy;
  Window dummy;
  if (!XTranslateCoordinates(dpy, win, top, 0, 0,
			      &absx, &absy, &dummy)) {
    cerr << "XTranslateCoordinates failed\n";
    return;
  }
  info.x = absx;
  info.y = absy;
  auto width = info.width;
  auto height = info.height;

  // No boarder
  absx -= info.border_width;
  absy -= info.border_width;
  width += 2 * info.border_width;
  height += 2 * info.border_width;
  auto dwidth = DisplayWidth(dpy, scr);
  auto dheight = DisplayHeight(dpy, scr);

  /* clip to window */
  if (absx < 0)
    width += absx, absx = 0;
  if (absy < 0)
    height += absy, absy = 0;
  if (absx + width > dwidth)
    width = dwidth - absx;
  if (absy + height > dheight)
    height = dheight - absy;

  auto x = absx - info.x;
  auto y = absy - info.y;

  auto image = XGetImage(dpy, win, x, y, width, height, AllPlanes, ZPixmap);
  if (!image) {
    cerr << "XGetImage failed\n";
    return;
  }
  XDestroyImage(image);
}

int main()
{
  using namespace std;
  pid_t pid = fork();
  if (!pid) {
    execl("/usr/bin/firefox",
	  "firefox",
	  "https://tokyo.mobakumap.jp/#35.681236,139.767125,13z",
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
