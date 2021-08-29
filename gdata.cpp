/*

Copyright 1985, 1986, 1988, 1998  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall
not be used in advertising or otherwise to promote the sale, use or
other dealings in this Software without prior written authorization
from The Open Group.

*/

/* xwud - marginally useful raster image undumper */


#include <X11/Xos.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <stdio.h>
#include <X11/XWDFile.h>
#define  XK_LATIN1
#include <X11/keysymdef.h>
#include <errno.h>
#include <stdlib.h>

#include <iostream>
#include <map>
#include <cassert>
#include <algorithm>
#include <sstream>

namespace mine {
  using namespace std;
  const int sky_blue = 5749684;
  inline bool found(int x, int y, XImage* in_image)
  {
    int end = x + 130;
    for ( ; x != end ; ++x) {
      if (XGetPixel(in_image, x, y) != sky_blue)
	return false;
    }
    return true;
  }
  pair<int, int> gen_button;
  void find_gen_button(XImage* in_image)
  {
    int X = 460;
    int Y = 480;
    for (int x = X-100 ; x != X+100 ; ++x) {
      for (int y = Y-50 ; y != Y+50 ; ++y) {
	if (found(x, y, in_image)) {
	  gen_button = make_pair(x, y);
	  return;
	}
      }
    }
    asm("int3");
  }
  void out(pair<int, int> k, int v)
  {
    auto x = k.first;
    auto y = k.second;
    cout << "      ";
    cout << "(*this)[make_pair(" << x << ", " << y << ")] = " << v << ";\n";
  }
  // "40%" data
  //  ^^
  struct table40_t : map<pair<int,int>, int> {
    table40_t()
    {
      (*this)[make_pair(673, 420)] = 16777215;
      (*this)[make_pair(673, 421)] = 16777215;
      (*this)[make_pair(673, 422)] = 16777215;
      (*this)[make_pair(673, 423)] = 16777215;
      (*this)[make_pair(673, 424)] = 16711422;
      (*this)[make_pair(673, 425)] = 12171705;
      (*this)[make_pair(673, 426)] = 9737364;
      (*this)[make_pair(673, 427)] = 9539985;
      (*this)[make_pair(673, 428)] = 15658734;
      (*this)[make_pair(673, 429)] = 16777215;
      (*this)[make_pair(673, 430)] = 16777215;
      (*this)[make_pair(673, 431)] = 16777215;
      (*this)[make_pair(673, 432)] = 16777215;
      (*this)[make_pair(674, 420)] = 16777215;
      (*this)[make_pair(674, 421)] = 16777215;
      (*this)[make_pair(674, 422)] = 16777215;
      (*this)[make_pair(674, 423)] = 15592941;
      (*this)[make_pair(674, 424)] = 9605778;
      (*this)[make_pair(674, 425)] = 12434877;
      (*this)[make_pair(674, 426)] = 16711422;
      (*this)[make_pair(674, 427)] = 10461087;
      (*this)[make_pair(674, 428)] = 15658734;
      (*this)[make_pair(674, 429)] = 16777215;
      (*this)[make_pair(674, 430)] = 16777215;
      (*this)[make_pair(674, 431)] = 16777215;
      (*this)[make_pair(674, 432)] = 16777215;
      (*this)[make_pair(675, 420)] = 16777215;
      (*this)[make_pair(675, 421)] = 16777215;
      (*this)[make_pair(675, 422)] = 13158600;
      (*this)[make_pair(675, 423)] = 9342606;
      (*this)[make_pair(675, 424)] = 15132390;
      (*this)[make_pair(675, 425)] = 16777215;
      (*this)[make_pair(675, 426)] = 16777215;
      (*this)[make_pair(675, 427)] = 10461087;
      (*this)[make_pair(675, 428)] = 15658734;
      (*this)[make_pair(675, 429)] = 16777215;
      (*this)[make_pair(675, 430)] = 16777215;
      (*this)[make_pair(675, 431)] = 16777215;
      (*this)[make_pair(675, 432)] = 16777215;
      (*this)[make_pair(676, 420)] = 16777215;
      (*this)[make_pair(676, 421)] = 15461355;
      (*this)[make_pair(676, 422)] = 6974058;
      (*this)[make_pair(676, 423)] = 7763574;
      (*this)[make_pair(676, 424)] = 7960953;
      (*this)[make_pair(676, 425)] = 7960953;
      (*this)[make_pair(676, 426)] = 7960953;
      (*this)[make_pair(676, 427)] = 7171437;
      (*this)[make_pair(676, 428)] = 7829367;
      (*this)[make_pair(676, 429)] = 7960953;
      (*this)[make_pair(676, 430)] = 16777215;
      (*this)[make_pair(676, 431)] = 16777215;
      (*this)[make_pair(676, 432)] = 16777215;
      (*this)[make_pair(677, 420)] = 16777215;
      (*this)[make_pair(677, 421)] = 16777215;
      (*this)[make_pair(677, 422)] = 16777215;
      (*this)[make_pair(677, 423)] = 16777215;
      (*this)[make_pair(677, 424)] = 16777215;
      (*this)[make_pair(677, 425)] = 16777215;
      (*this)[make_pair(677, 426)] = 16777215;
      (*this)[make_pair(677, 427)] = 10461087;
      (*this)[make_pair(677, 428)] = 15658734;
      (*this)[make_pair(677, 429)] = 16777215;
      (*this)[make_pair(677, 430)] = 16777215;
      (*this)[make_pair(677, 431)] = 16777215;
      (*this)[make_pair(677, 432)] = 16777215;
      (*this)[make_pair(678, 420)] = 16777215;
      (*this)[make_pair(678, 421)] = 16777215;
      (*this)[make_pair(678, 422)] = 16777215;
      (*this)[make_pair(678, 423)] = 16777215;
      (*this)[make_pair(678, 424)] = 16777215;
      (*this)[make_pair(678, 425)] = 16777215;
      (*this)[make_pair(678, 426)] = 16777215;
      (*this)[make_pair(678, 427)] = 14737632;
      (*this)[make_pair(678, 428)] = 16448250;
      (*this)[make_pair(678, 429)] = 16777215;
      (*this)[make_pair(678, 430)] = 16777215;
      (*this)[make_pair(678, 431)] = 16777215;
      (*this)[make_pair(678, 432)] = 16777215;
      (*this)[make_pair(679, 420)] = 16777215;
      (*this)[make_pair(679, 421)] = 16777215;
      (*this)[make_pair(679, 422)] = 16777215;
      (*this)[make_pair(679, 423)] = 16448250;
      (*this)[make_pair(679, 424)] = 14211288;
      (*this)[make_pair(679, 425)] = 13158600;
      (*this)[make_pair(679, 426)] = 13158600;
      (*this)[make_pair(679, 427)] = 14211288;
      (*this)[make_pair(679, 428)] = 16448250;
      (*this)[make_pair(679, 429)] = 16777215;
      (*this)[make_pair(679, 430)] = 16777215;
      (*this)[make_pair(679, 431)] = 16777215;
      (*this)[make_pair(679, 432)] = 16777215;
      (*this)[make_pair(680, 420)] = 16777215;
      (*this)[make_pair(680, 421)] = 16777215;
      (*this)[make_pair(680, 422)] = 14606046;
      (*this)[make_pair(680, 423)] = 8026746;
      (*this)[make_pair(680, 424)] = 9211020;
      (*this)[make_pair(680, 425)] = 11119017;
      (*this)[make_pair(680, 426)] = 11119017;
      (*this)[make_pair(680, 427)] = 9145227;
      (*this)[make_pair(680, 428)] = 8092539;
      (*this)[make_pair(680, 429)] = 14737632;
      (*this)[make_pair(680, 430)] = 16777215;
      (*this)[make_pair(680, 431)] = 16777215;
      (*this)[make_pair(680, 432)] = 16777215;
      (*this)[make_pair(681, 420)] = 16777215;
      (*this)[make_pair(681, 421)] = 16777215;
      (*this)[make_pair(681, 422)] = 10000536;
      (*this)[make_pair(681, 423)] = 15461355;
      (*this)[make_pair(681, 424)] = 16777215;
      (*this)[make_pair(681, 425)] = 16777215;
      (*this)[make_pair(681, 426)] = 16777215;
      (*this)[make_pair(681, 427)] = 16777215;
      (*this)[make_pair(681, 428)] = 15329769;
      (*this)[make_pair(681, 429)] = 10197915;
      (*this)[make_pair(681, 430)] = 16777215;
      (*this)[make_pair(681, 431)] = 16777215;
      (*this)[make_pair(681, 432)] = 16777215;
      (*this)[make_pair(682, 420)] = 16777215;
      (*this)[make_pair(682, 421)] = 16316664;
      (*this)[make_pair(682, 422)] = 9737364;
      (*this)[make_pair(682, 423)] = 16777215;
      (*this)[make_pair(682, 424)] = 16777215;
      (*this)[make_pair(682, 425)] = 16777215;
      (*this)[make_pair(682, 426)] = 16777215;
      (*this)[make_pair(682, 427)] = 16777215;
      (*this)[make_pair(682, 428)] = 16777215;
      (*this)[make_pair(682, 429)] = 9605778;
      (*this)[make_pair(682, 430)] = 16514043;
      (*this)[make_pair(682, 431)] = 16777215;
      (*this)[make_pair(682, 432)] = 16777215;
      (*this)[make_pair(683, 420)] = 16777215;
      (*this)[make_pair(683, 421)] = 16777215;
      (*this)[make_pair(683, 422)] = 10197915;
      (*this)[make_pair(683, 423)] = 15329769;
      (*this)[make_pair(683, 424)] = 16777215;
      (*this)[make_pair(683, 425)] = 16777215;
      (*this)[make_pair(683, 426)] = 16777215;
      (*this)[make_pair(683, 427)] = 16777215;
      (*this)[make_pair(683, 428)] = 15198183;
      (*this)[make_pair(683, 429)] = 10329501;
      (*this)[make_pair(683, 430)] = 16777215;
      (*this)[make_pair(683, 431)] = 16777215;
      (*this)[make_pair(683, 432)] = 16777215;
      (*this)[make_pair(684, 420)] = 16777215;
      (*this)[make_pair(684, 421)] = 16777215;
      (*this)[make_pair(684, 422)] = 14869218;
      (*this)[make_pair(684, 423)] = 8158332;
      (*this)[make_pair(684, 424)] = 8816262;
      (*this)[make_pair(684, 425)] = 10790052;
      (*this)[make_pair(684, 426)] = 10724259;
      (*this)[make_pair(684, 427)] = 8816262;
      (*this)[make_pair(684, 428)] = 8158332;
      (*this)[make_pair(684, 429)] = 14935011;
      (*this)[make_pair(684, 430)] = 16777215;
      (*this)[make_pair(684, 431)] = 16777215;
      (*this)[make_pair(684, 432)] = 16777215;
      (*this)[make_pair(685, 420)] = 16777215;
      (*this)[make_pair(685, 421)] = 16777215;
      (*this)[make_pair(685, 422)] = 16777215;
      (*this)[make_pair(685, 423)] = 16579836;
      (*this)[make_pair(685, 424)] = 14540253;
      (*this)[make_pair(685, 425)] = 13487565;
      (*this)[make_pair(685, 426)] = 13487565;
      (*this)[make_pair(685, 427)] = 14540253;
      (*this)[make_pair(685, 428)] = 16579836;
      (*this)[make_pair(685, 429)] = 16777215;
      (*this)[make_pair(685, 430)] = 16777215;
      (*this)[make_pair(685, 431)] = 16777215;
      (*this)[make_pair(685, 432)] = 16777215;
    }
  } s40;
  map<pair<int, int>, int> table40;
  void update_table40()
  {
    for (const auto& x : s40) {
      auto pos = x.first;
      pos.first += gen_button.first - 450;
      pos.second += gen_button.second - 480;
      table40[pos] = x.second;
    }
  }
  // "100%" data
  //  ^^
  struct table100_t : map<pair<int,int>, int> {
    table100_t()
    {
      (*this)[make_pair(673, 420)] = 16777215;
      (*this)[make_pair(673, 421)] = 16777215;
      (*this)[make_pair(673, 422)] = 16777215;
      (*this)[make_pair(673, 423)] = 16777215;
      (*this)[make_pair(673, 424)] = 16777215;
      (*this)[make_pair(673, 425)] = 16777215;
      (*this)[make_pair(673, 426)] = 16777215;
      (*this)[make_pair(673, 427)] = 16777215;
      (*this)[make_pair(673, 428)] = 16777215;
      (*this)[make_pair(673, 429)] = 16777215;
      (*this)[make_pair(673, 430)] = 16777215;
      (*this)[make_pair(673, 431)] = 16777215;
      (*this)[make_pair(673, 432)] = 16777215;
      (*this)[make_pair(674, 420)] = 16777215;
      (*this)[make_pair(674, 421)] = 16777215;
      (*this)[make_pair(674, 422)] = 16777215;
      (*this)[make_pair(674, 423)] = 16777215;
      (*this)[make_pair(674, 424)] = 16777215;
      (*this)[make_pair(674, 425)] = 16777215;
      (*this)[make_pair(674, 426)] = 16777215;
      (*this)[make_pair(674, 427)] = 16777215;
      (*this)[make_pair(674, 428)] = 16777215;
      (*this)[make_pair(674, 429)] = 16777215;
      (*this)[make_pair(674, 430)] = 16777215;
      (*this)[make_pair(674, 431)] = 16777215;
      (*this)[make_pair(674, 432)] = 16777215;
      (*this)[make_pair(675, 420)] = 16777215;
      (*this)[make_pair(675, 421)] = 16777215;
      (*this)[make_pair(675, 422)] = 16777215;
      (*this)[make_pair(675, 423)] = 16448250;
      (*this)[make_pair(675, 424)] = 14211288;
      (*this)[make_pair(675, 425)] = 13158600;
      (*this)[make_pair(675, 426)] = 13158600;
      (*this)[make_pair(675, 427)] = 14211288;
      (*this)[make_pair(675, 428)] = 16448250;
      (*this)[make_pair(675, 429)] = 16777215;
      (*this)[make_pair(675, 430)] = 16777215;
      (*this)[make_pair(675, 431)] = 16777215;
      (*this)[make_pair(675, 432)] = 16777215;
      (*this)[make_pair(676, 420)] = 16777215;
      (*this)[make_pair(676, 421)] = 16777215;
      (*this)[make_pair(676, 422)] = 14606046;
      (*this)[make_pair(676, 423)] = 8026746;
      (*this)[make_pair(676, 424)] = 9211020;
      (*this)[make_pair(676, 425)] = 11119017;
      (*this)[make_pair(676, 426)] = 11119017;
      (*this)[make_pair(676, 427)] = 9145227;
      (*this)[make_pair(676, 428)] = 8092539;
      (*this)[make_pair(676, 429)] = 14737632;
      (*this)[make_pair(676, 430)] = 16777215;
      (*this)[make_pair(676, 431)] = 16777215;
      (*this)[make_pair(676, 432)] = 16777215;
      (*this)[make_pair(677, 420)] = 16777215;
      (*this)[make_pair(677, 421)] = 16777215;
      (*this)[make_pair(677, 422)] = 10000536;
      (*this)[make_pair(677, 423)] = 15461355;
      (*this)[make_pair(677, 424)] = 16777215;
      (*this)[make_pair(677, 425)] = 16777215;
      (*this)[make_pair(677, 426)] = 16777215;
      (*this)[make_pair(677, 427)] = 16777215;
      (*this)[make_pair(677, 428)] = 15329769;
      (*this)[make_pair(677, 429)] = 10197915;
      (*this)[make_pair(677, 430)] = 16777215;
      (*this)[make_pair(677, 431)] = 16777215;
      (*this)[make_pair(677, 432)] = 16777215;
      (*this)[make_pair(678, 420)] = 16777215;
      (*this)[make_pair(678, 421)] = 16316664;
      (*this)[make_pair(678, 422)] = 9737364;
      (*this)[make_pair(678, 423)] = 16777215;
      (*this)[make_pair(678, 424)] = 16777215;
      (*this)[make_pair(678, 425)] = 16777215;
      (*this)[make_pair(678, 426)] = 16777215;
      (*this)[make_pair(678, 427)] = 16777215;
      (*this)[make_pair(678, 428)] = 16777215;
      (*this)[make_pair(678, 429)] = 9605778;
      (*this)[make_pair(678, 430)] = 16514043;
      (*this)[make_pair(678, 431)] = 16777215;
      (*this)[make_pair(678, 432)] = 16777215;
      (*this)[make_pair(679, 420)] = 16777215;
      (*this)[make_pair(679, 421)] = 16777215;
      (*this)[make_pair(679, 422)] = 10197915;
      (*this)[make_pair(679, 423)] = 15329769;
      (*this)[make_pair(679, 424)] = 16777215;
      (*this)[make_pair(679, 425)] = 16777215;
      (*this)[make_pair(679, 426)] = 16777215;
      (*this)[make_pair(679, 427)] = 16777215;
      (*this)[make_pair(679, 428)] = 15198183;
      (*this)[make_pair(679, 429)] = 10329501;
      (*this)[make_pair(679, 430)] = 16777215;
      (*this)[make_pair(679, 431)] = 16777215;
      (*this)[make_pair(679, 432)] = 16777215;
      (*this)[make_pair(680, 420)] = 16777215;
      (*this)[make_pair(680, 421)] = 16777215;
      (*this)[make_pair(680, 422)] = 14869218;
      (*this)[make_pair(680, 423)] = 8158332;
      (*this)[make_pair(680, 424)] = 8816262;
      (*this)[make_pair(680, 425)] = 10790052;
      (*this)[make_pair(680, 426)] = 10724259;
      (*this)[make_pair(680, 427)] = 8816262;
      (*this)[make_pair(680, 428)] = 8158332;
      (*this)[make_pair(680, 429)] = 14935011;
      (*this)[make_pair(680, 430)] = 16777215;
      (*this)[make_pair(680, 431)] = 16777215;
      (*this)[make_pair(680, 432)] = 16777215;
      (*this)[make_pair(681, 420)] = 16777215;
      (*this)[make_pair(681, 421)] = 16777215;
      (*this)[make_pair(681, 422)] = 16777215;
      (*this)[make_pair(681, 423)] = 16579836;
      (*this)[make_pair(681, 424)] = 14540253;
      (*this)[make_pair(681, 425)] = 13487565;
      (*this)[make_pair(681, 426)] = 13487565;
      (*this)[make_pair(681, 427)] = 14540253;
      (*this)[make_pair(681, 428)] = 16579836;
      (*this)[make_pair(681, 429)] = 16777215;
      (*this)[make_pair(681, 430)] = 16777215;
      (*this)[make_pair(681, 431)] = 16777215;
      (*this)[make_pair(681, 432)] = 16777215;
      (*this)[make_pair(682, 420)] = 16777215;
      (*this)[make_pair(682, 421)] = 16777215;
      (*this)[make_pair(682, 422)] = 16777215;
      (*this)[make_pair(682, 423)] = 16448250;
      (*this)[make_pair(682, 424)] = 14211288;
      (*this)[make_pair(682, 425)] = 13158600;
      (*this)[make_pair(682, 426)] = 13158600;
      (*this)[make_pair(682, 427)] = 14211288;
      (*this)[make_pair(682, 428)] = 16448250;
      (*this)[make_pair(682, 429)] = 16777215;
      (*this)[make_pair(682, 430)] = 16777215;
      (*this)[make_pair(682, 431)] = 16777215;
      (*this)[make_pair(682, 432)] = 16777215;
      (*this)[make_pair(683, 420)] = 16777215;
      (*this)[make_pair(683, 421)] = 16777215;
      (*this)[make_pair(683, 422)] = 14606046;
      (*this)[make_pair(683, 423)] = 8026746;
      (*this)[make_pair(683, 424)] = 9211020;
      (*this)[make_pair(683, 425)] = 11119017;
      (*this)[make_pair(683, 426)] = 11119017;
      (*this)[make_pair(683, 427)] = 9145227;
      (*this)[make_pair(683, 428)] = 8092539;
      (*this)[make_pair(683, 429)] = 14737632;
      (*this)[make_pair(683, 430)] = 16777215;
      (*this)[make_pair(683, 431)] = 16777215;
      (*this)[make_pair(683, 432)] = 16777215;
      (*this)[make_pair(684, 420)] = 16777215;
      (*this)[make_pair(684, 421)] = 16777215;
      (*this)[make_pair(684, 422)] = 10000536;
      (*this)[make_pair(684, 423)] = 15461355;
      (*this)[make_pair(684, 424)] = 16777215;
      (*this)[make_pair(684, 425)] = 16777215;
      (*this)[make_pair(684, 426)] = 16777215;
      (*this)[make_pair(684, 427)] = 16777215;
      (*this)[make_pair(684, 428)] = 15329769;
      (*this)[make_pair(684, 429)] = 10197915;
      (*this)[make_pair(684, 430)] = 16777215;
      (*this)[make_pair(684, 431)] = 16777215;
      (*this)[make_pair(684, 432)] = 16777215;
      (*this)[make_pair(685, 420)] = 16777215;
      (*this)[make_pair(685, 421)] = 16316664;
      (*this)[make_pair(685, 422)] = 9737364;
      (*this)[make_pair(685, 423)] = 16777215;
      (*this)[make_pair(685, 424)] = 16777215;
      (*this)[make_pair(685, 425)] = 16777215;
      (*this)[make_pair(685, 426)] = 16777215;
      (*this)[make_pair(685, 427)] = 16777215;
      (*this)[make_pair(685, 428)] = 16777215;
      (*this)[make_pair(685, 429)] = 9605778;
      (*this)[make_pair(685, 430)] = 16514043;
      (*this)[make_pair(685, 431)] = 16777215;
      (*this)[make_pair(685, 432)] = 16777215;
    }
  } s100;
  map<pair<int, int>, int> table100;
  void update_table100()
  {
    for (const auto& x : s100) {
      auto pos = x.first;
      pos.first += gen_button.first - 450;
      pos.second += gen_button.second - 480;
      table100[pos] = x.second;
    }
  }
  // "10%" data
  //  ^^
  struct table10_t : map<pair<int,int>, int> {
    table10_t()
    {
      (*this)[make_pair(673, 420)] = 16777215;
      (*this)[make_pair(673, 421)] = 16777215;
      (*this)[make_pair(673, 422)] = 16777215;
      (*this)[make_pair(673, 423)] = 12632256;
      (*this)[make_pair(673, 424)] = 13816530;
      (*this)[make_pair(673, 425)] = 16777215;
      (*this)[make_pair(673, 426)] = 16777215;
      (*this)[make_pair(673, 427)] = 16777215;
      (*this)[make_pair(673, 428)] = 16777215;
      (*this)[make_pair(673, 429)] = 16777215;
      (*this)[make_pair(673, 430)] = 16777215;
      (*this)[make_pair(673, 431)] = 16777215;
      (*this)[make_pair(673, 432)] = 16777215;
      (*this)[make_pair(674, 420)] = 16777215;
      (*this)[make_pair(674, 421)] = 16777215;
      (*this)[make_pair(674, 422)] = 13882323;
      (*this)[make_pair(674, 423)] = 9868950;
      (*this)[make_pair(674, 424)] = 16711422;
      (*this)[make_pair(674, 425)] = 16777215;
      (*this)[make_pair(674, 426)] = 16777215;
      (*this)[make_pair(674, 427)] = 16777215;
      (*this)[make_pair(674, 428)] = 16777215;
      (*this)[make_pair(674, 429)] = 16777215;
      (*this)[make_pair(674, 430)] = 16777215;
      (*this)[make_pair(674, 431)] = 16777215;
      (*this)[make_pair(674, 432)] = 16777215;
      (*this)[make_pair(675, 420)] = 16777215;
      (*this)[make_pair(675, 421)] = 16053492;
      (*this)[make_pair(675, 422)] = 7500402;
      (*this)[make_pair(675, 423)] = 11842740;
      (*this)[make_pair(675, 424)] = 12369084;
      (*this)[make_pair(675, 425)] = 12369084;
      (*this)[make_pair(675, 426)] = 12369084;
      (*this)[make_pair(675, 427)] = 12369084;
      (*this)[make_pair(675, 428)] = 12369084;
      (*this)[make_pair(675, 429)] = 12369084;
      (*this)[make_pair(675, 430)] = 16777215;
      (*this)[make_pair(675, 431)] = 16777215;
      (*this)[make_pair(675, 432)] = 16777215;
      (*this)[make_pair(676, 420)] = 16777215;
      (*this)[make_pair(676, 421)] = 16185078;
      (*this)[make_pair(676, 422)] = 12369084;
      (*this)[make_pair(676, 423)] = 12369084;
      (*this)[make_pair(676, 424)] = 12369084;
      (*this)[make_pair(676, 425)] = 12369084;
      (*this)[make_pair(676, 426)] = 12369084;
      (*this)[make_pair(676, 427)] = 12369084;
      (*this)[make_pair(676, 428)] = 12369084;
      (*this)[make_pair(676, 429)] = 12369084;
      (*this)[make_pair(676, 430)] = 16777215;
      (*this)[make_pair(676, 431)] = 16777215;
      (*this)[make_pair(676, 432)] = 16777215;
      (*this)[make_pair(677, 420)] = 16777215;
      (*this)[make_pair(677, 421)] = 16777215;
      (*this)[make_pair(677, 422)] = 16777215;
      (*this)[make_pair(677, 423)] = 16777215;
      (*this)[make_pair(677, 424)] = 16777215;
      (*this)[make_pair(677, 425)] = 16777215;
      (*this)[make_pair(677, 426)] = 16777215;
      (*this)[make_pair(677, 427)] = 16777215;
      (*this)[make_pair(677, 428)] = 16777215;
      (*this)[make_pair(677, 429)] = 16777215;
      (*this)[make_pair(677, 430)] = 16777215;
      (*this)[make_pair(677, 431)] = 16777215;
      (*this)[make_pair(677, 432)] = 16777215;
      (*this)[make_pair(678, 420)] = 16777215;
      (*this)[make_pair(678, 421)] = 16777215;
      (*this)[make_pair(678, 422)] = 16777215;
      (*this)[make_pair(678, 423)] = 16777215;
      (*this)[make_pair(678, 424)] = 16777215;
      (*this)[make_pair(678, 425)] = 16777215;
      (*this)[make_pair(678, 426)] = 16777215;
      (*this)[make_pair(678, 427)] = 16777215;
      (*this)[make_pair(678, 428)] = 16777215;
      (*this)[make_pair(678, 429)] = 16777215;
      (*this)[make_pair(678, 430)] = 16777215;
      (*this)[make_pair(678, 431)] = 16777215;
      (*this)[make_pair(678, 432)] = 16777215;
      (*this)[make_pair(679, 420)] = 16777215;
      (*this)[make_pair(679, 421)] = 16777215;
      (*this)[make_pair(679, 422)] = 16777215;
      (*this)[make_pair(679, 423)] = 16448250;
      (*this)[make_pair(679, 424)] = 14211288;
      (*this)[make_pair(679, 425)] = 13158600;
      (*this)[make_pair(679, 426)] = 13158600;
      (*this)[make_pair(679, 427)] = 14211288;
      (*this)[make_pair(679, 428)] = 16448250;
      (*this)[make_pair(679, 429)] = 16777215;
      (*this)[make_pair(679, 430)] = 16777215;
      (*this)[make_pair(679, 431)] = 16777215;
      (*this)[make_pair(679, 432)] = 16777215;
      (*this)[make_pair(680, 420)] = 16777215;
      (*this)[make_pair(680, 421)] = 16777215;
      (*this)[make_pair(680, 422)] = 14606046;
      (*this)[make_pair(680, 423)] = 8026746;
      (*this)[make_pair(680, 424)] = 9211020;
      (*this)[make_pair(680, 425)] = 11119017;
      (*this)[make_pair(680, 426)] = 11119017;
      (*this)[make_pair(680, 427)] = 9145227;
      (*this)[make_pair(680, 428)] = 8092539;
      (*this)[make_pair(680, 429)] = 14737632;
      (*this)[make_pair(680, 430)] = 16777215;
      (*this)[make_pair(680, 431)] = 16777215;
      (*this)[make_pair(680, 432)] = 16777215;
      (*this)[make_pair(681, 420)] = 16777215;
      (*this)[make_pair(681, 421)] = 16777215;
      (*this)[make_pair(681, 422)] = 10000536;
      (*this)[make_pair(681, 423)] = 15461355;
      (*this)[make_pair(681, 424)] = 16777215;
      (*this)[make_pair(681, 425)] = 16777215;
      (*this)[make_pair(681, 426)] = 16777215;
      (*this)[make_pair(681, 427)] = 16777215;
      (*this)[make_pair(681, 428)] = 15329769;
      (*this)[make_pair(681, 429)] = 10197915;
      (*this)[make_pair(681, 430)] = 16777215;
      (*this)[make_pair(681, 431)] = 16777215;
      (*this)[make_pair(681, 432)] = 16777215;
      (*this)[make_pair(682, 420)] = 16777215;
      (*this)[make_pair(682, 421)] = 16316664;
      (*this)[make_pair(682, 422)] = 9737364;
      (*this)[make_pair(682, 423)] = 16777215;
      (*this)[make_pair(682, 424)] = 16777215;
      (*this)[make_pair(682, 425)] = 16777215;
      (*this)[make_pair(682, 426)] = 16777215;
      (*this)[make_pair(682, 427)] = 16777215;
      (*this)[make_pair(682, 428)] = 16777215;
      (*this)[make_pair(682, 429)] = 9605778;
      (*this)[make_pair(682, 430)] = 16514043;
      (*this)[make_pair(682, 431)] = 16777215;
      (*this)[make_pair(682, 432)] = 16777215;
      (*this)[make_pair(683, 420)] = 16777215;
      (*this)[make_pair(683, 421)] = 16777215;
      (*this)[make_pair(683, 422)] = 10197915;
      (*this)[make_pair(683, 423)] = 15329769;
      (*this)[make_pair(683, 424)] = 16777215;
      (*this)[make_pair(683, 425)] = 16777215;
      (*this)[make_pair(683, 426)] = 16777215;
      (*this)[make_pair(683, 427)] = 16777215;
      (*this)[make_pair(683, 428)] = 15198183;
      (*this)[make_pair(683, 429)] = 10329501;
      (*this)[make_pair(683, 430)] = 16777215;
      (*this)[make_pair(683, 431)] = 16777215;
      (*this)[make_pair(683, 432)] = 16777215;
      (*this)[make_pair(684, 420)] = 16777215;
      (*this)[make_pair(684, 421)] = 16777215;
      (*this)[make_pair(684, 422)] = 14869218;
      (*this)[make_pair(684, 423)] = 8158332;
      (*this)[make_pair(684, 424)] = 8816262;
      (*this)[make_pair(684, 425)] = 10790052;
      (*this)[make_pair(684, 426)] = 10724259;
      (*this)[make_pair(684, 427)] = 8816262;
      (*this)[make_pair(684, 428)] = 8158332;
      (*this)[make_pair(684, 429)] = 14935011;
      (*this)[make_pair(684, 430)] = 16777215;
      (*this)[make_pair(684, 431)] = 16777215;
      (*this)[make_pair(684, 432)] = 16777215;
      (*this)[make_pair(685, 420)] = 16777215;
      (*this)[make_pair(685, 421)] = 16777215;
      (*this)[make_pair(685, 422)] = 16777215;
      (*this)[make_pair(685, 423)] = 16579836;
      (*this)[make_pair(685, 424)] = 14540253;
      (*this)[make_pair(685, 425)] = 13487565;
      (*this)[make_pair(685, 426)] = 13487565;
      (*this)[make_pair(685, 427)] = 14540253;
      (*this)[make_pair(685, 428)] = 16579836;
      (*this)[make_pair(685, 429)] = 16777215;
      (*this)[make_pair(685, 430)] = 16777215;
      (*this)[make_pair(685, 431)] = 16777215;
      (*this)[make_pair(685, 432)] = 16777215;
    }
  } s10;
  map<pair<int, int>, int> table10;
  void update_table10()
  {
    for (const auto& x : s10) {
      auto pos = x.first;
      pos.first += gen_button.first - 450;
      pos.second += gen_button.second - 480;
      table10[pos] = x.second;
    }
  }
  // "20%" data
  //  ^^
  struct table20_t : map<pair<int,int>, int> {
    table20_t()
    {
      (*this)[make_pair(673, 420)] = 16777215;
      (*this)[make_pair(673, 421)] = 16777215;
      (*this)[make_pair(673, 422)] = 10790052;
      (*this)[make_pair(673, 423)] = 15724527;
      (*this)[make_pair(673, 424)] = 16777215;
      (*this)[make_pair(673, 425)] = 16777215;
      (*this)[make_pair(673, 426)] = 16777215;
      (*this)[make_pair(673, 427)] = 16777215;
      (*this)[make_pair(673, 428)] = 14540253;
      (*this)[make_pair(673, 429)] = 7039851;
      (*this)[make_pair(673, 430)] = 16777215;
      (*this)[make_pair(673, 431)] = 16777215;
      (*this)[make_pair(673, 432)] = 16777215;
      (*this)[make_pair(674, 420)] = 16777215;
      (*this)[make_pair(674, 421)] = 16777215;
      (*this)[make_pair(674, 422)] = 9013641;
      (*this)[make_pair(674, 423)] = 16777215;
      (*this)[make_pair(674, 424)] = 16777215;
      (*this)[make_pair(674, 425)] = 16777215;
      (*this)[make_pair(674, 426)] = 16777215;
      (*this)[make_pair(674, 427)] = 15329769;
      (*this)[make_pair(674, 428)] = 8816262;
      (*this)[make_pair(674, 429)] = 8553090;
      (*this)[make_pair(674, 430)] = 16777215;
      (*this)[make_pair(674, 431)] = 16777215;
      (*this)[make_pair(674, 432)] = 16777215;
      (*this)[make_pair(675, 420)] = 16777215;
      (*this)[make_pair(675, 421)] = 16119285;
      (*this)[make_pair(675, 422)] = 9737364;
      (*this)[make_pair(675, 423)] = 16777215;
      (*this)[make_pair(675, 424)] = 16777215;
      (*this)[make_pair(675, 425)] = 16777215;
      (*this)[make_pair(675, 426)] = 15198183;
      (*this)[make_pair(675, 427)] = 8684676;
      (*this)[make_pair(675, 428)] = 15329769;
      (*this)[make_pair(675, 429)] = 9342606;
      (*this)[make_pair(675, 430)] = 16777215;
      (*this)[make_pair(675, 431)] = 16777215;
      (*this)[make_pair(675, 432)] = 16777215;
      (*this)[make_pair(676, 420)] = 16777215;
      (*this)[make_pair(676, 421)] = 16777215;
      (*this)[make_pair(676, 422)] = 9276813;
      (*this)[make_pair(676, 423)] = 14145495;
      (*this)[make_pair(676, 424)] = 15395562;
      (*this)[make_pair(676, 425)] = 11382189;
      (*this)[make_pair(676, 426)] = 8618883;
      (*this)[make_pair(676, 427)] = 15132390;
      (*this)[make_pair(676, 428)] = 16777215;
      (*this)[make_pair(676, 429)] = 9342606;
      (*this)[make_pair(676, 430)] = 16777215;
      (*this)[make_pair(676, 431)] = 16777215;
      (*this)[make_pair(676, 432)] = 16777215;
      (*this)[make_pair(677, 420)] = 16777215;
      (*this)[make_pair(677, 421)] = 16777215;
      (*this)[make_pair(677, 422)] = 14803425;
      (*this)[make_pair(677, 423)] = 10197915;
      (*this)[make_pair(677, 424)] = 9013641;
      (*this)[make_pair(677, 425)] = 12566463;
      (*this)[make_pair(677, 426)] = 16119285;
      (*this)[make_pair(677, 427)] = 16777215;
      (*this)[make_pair(677, 428)] = 16777215;
      (*this)[make_pair(677, 429)] = 9803157;
      (*this)[make_pair(677, 430)] = 16777215;
      (*this)[make_pair(677, 431)] = 16777215;
      (*this)[make_pair(677, 432)] = 16777215;
      (*this)[make_pair(678, 420)] = 16777215;
      (*this)[make_pair(678, 421)] = 16777215;
      (*this)[make_pair(678, 422)] = 16777215;
      (*this)[make_pair(678, 423)] = 16777215;
      (*this)[make_pair(678, 424)] = 16777215;
      (*this)[make_pair(678, 425)] = 16777215;
      (*this)[make_pair(678, 426)] = 16777215;
      (*this)[make_pair(678, 427)] = 16777215;
      (*this)[make_pair(678, 428)] = 16777215;
      (*this)[make_pair(678, 429)] = 16777215;
      (*this)[make_pair(678, 430)] = 16777215;
      (*this)[make_pair(678, 431)] = 16777215;
      (*this)[make_pair(678, 432)] = 16777215;
      (*this)[make_pair(679, 420)] = 16777215;
      (*this)[make_pair(679, 421)] = 16777215;
      (*this)[make_pair(679, 422)] = 16777215;
      (*this)[make_pair(679, 423)] = 16448250;
      (*this)[make_pair(679, 424)] = 14211288;
      (*this)[make_pair(679, 425)] = 13158600;
      (*this)[make_pair(679, 426)] = 13158600;
      (*this)[make_pair(679, 427)] = 14211288;
      (*this)[make_pair(679, 428)] = 16448250;
      (*this)[make_pair(679, 429)] = 16777215;
      (*this)[make_pair(679, 430)] = 16777215;
      (*this)[make_pair(679, 431)] = 16777215;
      (*this)[make_pair(679, 432)] = 16777215;
      (*this)[make_pair(680, 420)] = 16777215;
      (*this)[make_pair(680, 421)] = 16777215;
      (*this)[make_pair(680, 422)] = 14606046;
      (*this)[make_pair(680, 423)] = 8026746;
      (*this)[make_pair(680, 424)] = 9211020;
      (*this)[make_pair(680, 425)] = 11119017;
      (*this)[make_pair(680, 426)] = 11119017;
      (*this)[make_pair(680, 427)] = 9145227;
      (*this)[make_pair(680, 428)] = 8092539;
      (*this)[make_pair(680, 429)] = 14737632;
      (*this)[make_pair(680, 430)] = 16777215;
      (*this)[make_pair(680, 431)] = 16777215;
      (*this)[make_pair(680, 432)] = 16777215;
      (*this)[make_pair(681, 420)] = 16777215;
      (*this)[make_pair(681, 421)] = 16777215;
      (*this)[make_pair(681, 422)] = 10000536;
      (*this)[make_pair(681, 423)] = 15461355;
      (*this)[make_pair(681, 424)] = 16777215;
      (*this)[make_pair(681, 425)] = 16777215;
      (*this)[make_pair(681, 426)] = 16777215;
      (*this)[make_pair(681, 427)] = 16777215;
      (*this)[make_pair(681, 428)] = 15329769;
      (*this)[make_pair(681, 429)] = 10197915;
      (*this)[make_pair(681, 430)] = 16777215;
      (*this)[make_pair(681, 431)] = 16777215;
      (*this)[make_pair(681, 432)] = 16777215;
      (*this)[make_pair(682, 420)] = 16777215;
      (*this)[make_pair(682, 421)] = 16316664;
      (*this)[make_pair(682, 422)] = 9737364;
      (*this)[make_pair(682, 423)] = 16777215;
      (*this)[make_pair(682, 424)] = 16777215;
      (*this)[make_pair(682, 425)] = 16777215;
      (*this)[make_pair(682, 426)] = 16777215;
      (*this)[make_pair(682, 427)] = 16777215;
      (*this)[make_pair(682, 428)] = 16777215;
      (*this)[make_pair(682, 429)] = 9605778;
      (*this)[make_pair(682, 430)] = 16514043;
      (*this)[make_pair(682, 431)] = 16777215;
      (*this)[make_pair(682, 432)] = 16777215;
      (*this)[make_pair(683, 420)] = 16777215;
      (*this)[make_pair(683, 421)] = 16777215;
      (*this)[make_pair(683, 422)] = 10197915;
      (*this)[make_pair(683, 423)] = 15329769;
      (*this)[make_pair(683, 424)] = 16777215;
      (*this)[make_pair(683, 425)] = 16777215;
      (*this)[make_pair(683, 426)] = 16777215;
      (*this)[make_pair(683, 427)] = 16777215;
      (*this)[make_pair(683, 428)] = 15198183;
      (*this)[make_pair(683, 429)] = 10329501;
      (*this)[make_pair(683, 430)] = 16777215;
      (*this)[make_pair(683, 431)] = 16777215;
      (*this)[make_pair(683, 432)] = 16777215;
      (*this)[make_pair(684, 420)] = 16777215;
      (*this)[make_pair(684, 421)] = 16777215;
      (*this)[make_pair(684, 422)] = 14869218;
      (*this)[make_pair(684, 423)] = 8158332;
      (*this)[make_pair(684, 424)] = 8816262;
      (*this)[make_pair(684, 425)] = 10790052;
      (*this)[make_pair(684, 426)] = 10724259;
      (*this)[make_pair(684, 427)] = 8816262;
      (*this)[make_pair(684, 428)] = 8158332;
      (*this)[make_pair(684, 429)] = 14935011;
      (*this)[make_pair(684, 430)] = 16777215;
      (*this)[make_pair(684, 431)] = 16777215;
      (*this)[make_pair(684, 432)] = 16777215;
      (*this)[make_pair(685, 420)] = 16777215;
      (*this)[make_pair(685, 421)] = 16777215;
      (*this)[make_pair(685, 422)] = 16777215;
      (*this)[make_pair(685, 423)] = 16579836;
      (*this)[make_pair(685, 424)] = 14540253;
      (*this)[make_pair(685, 425)] = 13487565;
      (*this)[make_pair(685, 426)] = 13487565;
      (*this)[make_pair(685, 427)] = 14540253;
      (*this)[make_pair(685, 428)] = 16579836;
      (*this)[make_pair(685, 429)] = 16777215;
      (*this)[make_pair(685, 430)] = 16777215;
      (*this)[make_pair(685, 431)] = 16777215;
      (*this)[make_pair(685, 432)] = 16777215;
    }
  } s20;
  map<pair<int, int>, int> table20;
  void update_table20()
  {
    for (const auto& x : s20) {
      auto pos = x.first;
      pos.first += gen_button.first - 450;
      pos.second += gen_button.second - 480;
      table20[pos] = x.second;
    }
  }
  // "15-79" data
  //  ^^^^^
  struct table1579_t : map<pair<int,int>, int> {
    table1579_t()
    {
      (*this)[make_pair(305, 320)] = 16777215;
      (*this)[make_pair(305, 321)] = 16777215;
      (*this)[make_pair(305, 322)] = 12632256;
      (*this)[make_pair(305, 323)] = 13816530;
      (*this)[make_pair(305, 324)] = 16777215;
      (*this)[make_pair(305, 325)] = 16777215;
      (*this)[make_pair(305, 326)] = 16777215;
      (*this)[make_pair(305, 327)] = 16777215;
      (*this)[make_pair(305, 328)] = 16777215;
      (*this)[make_pair(305, 329)] = 16777215;
      (*this)[make_pair(306, 320)] = 16777215;
      (*this)[make_pair(306, 321)] = 13882323;
      (*this)[make_pair(306, 322)] = 9868950;
      (*this)[make_pair(306, 323)] = 16711422;
      (*this)[make_pair(306, 324)] = 16777215;
      (*this)[make_pair(306, 325)] = 16777215;
      (*this)[make_pair(306, 326)] = 16777215;
      (*this)[make_pair(306, 327)] = 16777215;
      (*this)[make_pair(306, 328)] = 16777215;
      (*this)[make_pair(306, 329)] = 16777215;
      (*this)[make_pair(307, 320)] = 16053492;
      (*this)[make_pair(307, 321)] = 7500402;
      (*this)[make_pair(307, 322)] = 11842740;
      (*this)[make_pair(307, 323)] = 12369084;
      (*this)[make_pair(307, 324)] = 12369084;
      (*this)[make_pair(307, 325)] = 12369084;
      (*this)[make_pair(307, 326)] = 12369084;
      (*this)[make_pair(307, 327)] = 12369084;
      (*this)[make_pair(307, 328)] = 12369084;
      (*this)[make_pair(307, 329)] = 16777215;
      (*this)[make_pair(308, 320)] = 16185078;
      (*this)[make_pair(308, 321)] = 12369084;
      (*this)[make_pair(308, 322)] = 12369084;
      (*this)[make_pair(308, 323)] = 12369084;
      (*this)[make_pair(308, 324)] = 12369084;
      (*this)[make_pair(308, 325)] = 12369084;
      (*this)[make_pair(308, 326)] = 12369084;
      (*this)[make_pair(308, 327)] = 12369084;
      (*this)[make_pair(308, 328)] = 12369084;
      (*this)[make_pair(308, 329)] = 16777215;
      (*this)[make_pair(309, 320)] = 16777215;
      (*this)[make_pair(309, 321)] = 16777215;
      (*this)[make_pair(309, 322)] = 16777215;
      (*this)[make_pair(309, 323)] = 16777215;
      (*this)[make_pair(309, 324)] = 16777215;
      (*this)[make_pair(309, 325)] = 16777215;
      (*this)[make_pair(309, 326)] = 16777215;
      (*this)[make_pair(309, 327)] = 16777215;
      (*this)[make_pair(309, 328)] = 16777215;
      (*this)[make_pair(309, 329)] = 16777215;
      (*this)[make_pair(310, 320)] = 16777215;
      (*this)[make_pair(310, 321)] = 16777215;
      (*this)[make_pair(310, 322)] = 16777215;
      (*this)[make_pair(310, 323)] = 16777215;
      (*this)[make_pair(310, 324)] = 16777215;
      (*this)[make_pair(310, 325)] = 16777215;
      (*this)[make_pair(310, 326)] = 16777215;
      (*this)[make_pair(310, 327)] = 16777215;
      (*this)[make_pair(310, 328)] = 16777215;
      (*this)[make_pair(310, 329)] = 16777215;
      (*this)[make_pair(311, 320)] = 16777215;
      (*this)[make_pair(311, 321)] = 16777215;
      (*this)[make_pair(311, 322)] = 16777215;
      (*this)[make_pair(311, 323)] = 16777215;
      (*this)[make_pair(311, 324)] = 16777215;
      (*this)[make_pair(311, 325)] = 16777215;
      (*this)[make_pair(311, 326)] = 16777215;
      (*this)[make_pair(311, 327)] = 16777215;
      (*this)[make_pair(311, 328)] = 16777215;
      (*this)[make_pair(311, 329)] = 16777215;
      (*this)[make_pair(312, 320)] = 15987699;
      (*this)[make_pair(312, 321)] = 10724259;
      (*this)[make_pair(312, 322)] = 10132122;
      (*this)[make_pair(312, 323)] = 9605778;
      (*this)[make_pair(312, 324)] = 9013641;
      (*this)[make_pair(312, 325)] = 16185078;
      (*this)[make_pair(312, 326)] = 16777215;
      (*this)[make_pair(312, 327)] = 16316664;
      (*this)[make_pair(312, 328)] = 10000536;
      (*this)[make_pair(312, 329)] = 16777215;
      (*this)[make_pair(313, 320)] = 15329769;
      (*this)[make_pair(313, 321)] = 9737364;
      (*this)[make_pair(313, 322)] = 14935011;
      (*this)[make_pair(313, 323)] = 15592941;
      (*this)[make_pair(313, 324)] = 9013641;
      (*this)[make_pair(313, 325)] = 16711422;
      (*this)[make_pair(313, 326)] = 16777215;
      (*this)[make_pair(313, 327)] = 16777215;
      (*this)[make_pair(313, 328)] = 9145227;
      (*this)[make_pair(313, 329)] = 16579836;
      (*this)[make_pair(314, 320)] = 15329769;
      (*this)[make_pair(314, 321)] = 10592673;
      (*this)[make_pair(314, 322)] = 16777215;
      (*this)[make_pair(314, 323)] = 16119285;
      (*this)[make_pair(314, 324)] = 10197915;
      (*this)[make_pair(314, 325)] = 16777215;
      (*this)[make_pair(314, 326)] = 16777215;
      (*this)[make_pair(314, 327)] = 16777215;
      (*this)[make_pair(314, 328)] = 9474192;
      (*this)[make_pair(314, 329)] = 16514043;
      (*this)[make_pair(315, 320)] = 15329769;
      (*this)[make_pair(315, 321)] = 10592673;
      (*this)[make_pair(315, 322)] = 16777215;
      (*this)[make_pair(315, 323)] = 16777215;
      (*this)[make_pair(315, 324)] = 9408399;
      (*this)[make_pair(315, 325)] = 15461355;
      (*this)[make_pair(315, 326)] = 16711422;
      (*this)[make_pair(315, 327)] = 14013909;
      (*this)[make_pair(315, 328)] = 10197915;
      (*this)[make_pair(315, 329)] = 16777215;
      (*this)[make_pair(316, 320)] = 15790320;
      (*this)[make_pair(316, 321)] = 12500670;
      (*this)[make_pair(316, 322)] = 16777215;
      (*this)[make_pair(316, 323)] = 16777215;
      (*this)[make_pair(316, 324)] = 14211288;
      (*this)[make_pair(316, 325)] = 9408399;
      (*this)[make_pair(316, 326)] = 8158332;
      (*this)[make_pair(316, 327)] = 10658466;
      (*this)[make_pair(316, 328)] = 15198183;
      (*this)[make_pair(316, 329)] = 16777215;
      (*this)[make_pair(317, 320)] = 16777215;
      (*this)[make_pair(317, 321)] = 16777215;
      (*this)[make_pair(317, 322)] = 16777215;
      (*this)[make_pair(317, 323)] = 16777215;
      (*this)[make_pair(317, 324)] = 16777215;
      (*this)[make_pair(317, 325)] = 16777215;
      (*this)[make_pair(317, 326)] = 16777215;
      (*this)[make_pair(317, 327)] = 16777215;
      (*this)[make_pair(317, 328)] = 16777215;
      (*this)[make_pair(317, 329)] = 16777215;
      (*this)[make_pair(318, 320)] = 16777215;
      (*this)[make_pair(318, 321)] = 16777215;
      (*this)[make_pair(318, 322)] = 16777215;
      (*this)[make_pair(318, 323)] = 16777215;
      (*this)[make_pair(318, 324)] = 16777215;
      (*this)[make_pair(318, 325)] = 16316664;
      (*this)[make_pair(318, 326)] = 16645629;
      (*this)[make_pair(318, 327)] = 16777215;
      (*this)[make_pair(318, 328)] = 16777215;
      (*this)[make_pair(318, 329)] = 16777215;
      (*this)[make_pair(319, 320)] = 16777215;
      (*this)[make_pair(319, 321)] = 16777215;
      (*this)[make_pair(319, 322)] = 16777215;
      (*this)[make_pair(319, 323)] = 16777215;
      (*this)[make_pair(319, 324)] = 16777215;
      (*this)[make_pair(319, 325)] = 11711154;
      (*this)[make_pair(319, 326)] = 14869218;
      (*this)[make_pair(319, 327)] = 16777215;
      (*this)[make_pair(319, 328)] = 16777215;
      (*this)[make_pair(319, 329)] = 16777215;
      (*this)[make_pair(320, 320)] = 16777215;
      (*this)[make_pair(320, 321)] = 16777215;
      (*this)[make_pair(320, 322)] = 16777215;
      (*this)[make_pair(320, 323)] = 16777215;
      (*this)[make_pair(320, 324)] = 16777215;
      (*this)[make_pair(320, 325)] = 11711154;
      (*this)[make_pair(320, 326)] = 14869218;
      (*this)[make_pair(320, 327)] = 16777215;
      (*this)[make_pair(320, 328)] = 16777215;
      (*this)[make_pair(320, 329)] = 16777215;
      (*this)[make_pair(321, 320)] = 16777215;
      (*this)[make_pair(321, 321)] = 16777215;
      (*this)[make_pair(321, 322)] = 16777215;
      (*this)[make_pair(321, 323)] = 16777215;
      (*this)[make_pair(321, 324)] = 16777215;
      (*this)[make_pair(321, 325)] = 11711154;
      (*this)[make_pair(321, 326)] = 14869218;
      (*this)[make_pair(321, 327)] = 16777215;
      (*this)[make_pair(321, 328)] = 16777215;
      (*this)[make_pair(321, 329)] = 16777215;
      (*this)[make_pair(322, 320)] = 16777215;
      (*this)[make_pair(322, 321)] = 16777215;
      (*this)[make_pair(322, 322)] = 16777215;
      (*this)[make_pair(322, 323)] = 16777215;
      (*this)[make_pair(322, 324)] = 16777215;
      (*this)[make_pair(322, 325)] = 15329769;
      (*this)[make_pair(322, 326)] = 16250871;
      (*this)[make_pair(322, 327)] = 16777215;
      (*this)[make_pair(322, 328)] = 16777215;
      (*this)[make_pair(322, 329)] = 16777215;
      (*this)[make_pair(323, 320)] = 16711422;
      (*this)[make_pair(323, 321)] = 16448250;
      (*this)[make_pair(323, 322)] = 16777215;
      (*this)[make_pair(323, 323)] = 16777215;
      (*this)[make_pair(323, 324)] = 16777215;
      (*this)[make_pair(323, 325)] = 16777215;
      (*this)[make_pair(323, 326)] = 16777215;
      (*this)[make_pair(323, 327)] = 16777215;
      (*this)[make_pair(323, 328)] = 16777215;
      (*this)[make_pair(323, 329)] = 16777215;
      (*this)[make_pair(324, 320)] = 15329769;
      (*this)[make_pair(324, 321)] = 10592673;
      (*this)[make_pair(324, 322)] = 16777215;
      (*this)[make_pair(324, 323)] = 16777215;
      (*this)[make_pair(324, 324)] = 16777215;
      (*this)[make_pair(324, 325)] = 16777215;
      (*this)[make_pair(324, 326)] = 16777215;
      (*this)[make_pair(324, 327)] = 16777215;
      (*this)[make_pair(324, 328)] = 16777215;
      (*this)[make_pair(324, 329)] = 16777215;
      (*this)[make_pair(325, 320)] = 15329769;
      (*this)[make_pair(325, 321)] = 10592673;
      (*this)[make_pair(325, 322)] = 16777215;
      (*this)[make_pair(325, 323)] = 16777215;
      (*this)[make_pair(325, 324)] = 16777215;
      (*this)[make_pair(325, 325)] = 16777215;
      (*this)[make_pair(325, 326)] = 16645629;
      (*this)[make_pair(325, 327)] = 13355979;
      (*this)[make_pair(325, 328)] = 9013641;
      (*this)[make_pair(325, 329)] = 16777215;
      (*this)[make_pair(326, 320)] = 15329769;
      (*this)[make_pair(326, 321)] = 10592673;
      (*this)[make_pair(326, 322)] = 16777215;
      (*this)[make_pair(326, 323)] = 16777215;
      (*this)[make_pair(326, 324)] = 16185078;
      (*this)[make_pair(326, 325)] = 12237498;
      (*this)[make_pair(326, 326)] = 8487297;
      (*this)[make_pair(326, 327)] = 11053224;
      (*this)[make_pair(326, 328)] = 15329769;
      (*this)[make_pair(326, 329)] = 16777215;
      (*this)[make_pair(327, 320)] = 15329769;
      (*this)[make_pair(327, 321)] = 10592673;
      (*this)[make_pair(327, 322)] = 15461355;
      (*this)[make_pair(327, 323)] = 11053224;
      (*this)[make_pair(327, 324)] = 8684676;
      (*this)[make_pair(327, 325)] = 12434877;
      (*this)[make_pair(327, 326)] = 16250871;
      (*this)[make_pair(327, 327)] = 16777215;
      (*this)[make_pair(327, 328)] = 16777215;
      (*this)[make_pair(327, 329)] = 16777215;
      (*this)[make_pair(328, 320)] = 15329769;
      (*this)[make_pair(328, 321)] = 7434609;
      (*this)[make_pair(328, 322)] = 9605778;
      (*this)[make_pair(328, 323)] = 13816530;
      (*this)[make_pair(328, 324)] = 16711422;
      (*this)[make_pair(328, 325)] = 16777215;
      (*this)[make_pair(328, 326)] = 16777215;
      (*this)[make_pair(328, 327)] = 16777215;
      (*this)[make_pair(328, 328)] = 16777215;
      (*this)[make_pair(328, 329)] = 16777215;
      (*this)[make_pair(329, 320)] = 16645629;
      (*this)[make_pair(329, 321)] = 15987699;
      (*this)[make_pair(329, 322)] = 16777215;
      (*this)[make_pair(329, 323)] = 16777215;
      (*this)[make_pair(329, 324)] = 16777215;
      (*this)[make_pair(329, 325)] = 16777215;
      (*this)[make_pair(329, 326)] = 16777215;
      (*this)[make_pair(329, 327)] = 16777215;
      (*this)[make_pair(329, 328)] = 16777215;
      (*this)[make_pair(329, 329)] = 16777215;
      (*this)[make_pair(330, 320)] = 16777215;
      (*this)[make_pair(330, 321)] = 16777215;
      (*this)[make_pair(330, 322)] = 16448250;
      (*this)[make_pair(330, 323)] = 13816530;
      (*this)[make_pair(330, 324)] = 15921906;
      (*this)[make_pair(330, 325)] = 16777215;
      (*this)[make_pair(330, 326)] = 16777215;
      (*this)[make_pair(330, 327)] = 16777215;
      (*this)[make_pair(330, 328)] = 16777215;
      (*this)[make_pair(330, 329)] = 16777215;
      (*this)[make_pair(331, 320)] = 16777215;
      (*this)[make_pair(331, 321)] = 13290186;
      (*this)[make_pair(331, 322)] = 8618883;
      (*this)[make_pair(331, 323)] = 10987431;
      (*this)[make_pair(331, 324)] = 8947848;
      (*this)[make_pair(331, 325)] = 11119017;
      (*this)[make_pair(331, 326)] = 16777215;
      (*this)[make_pair(331, 327)] = 16777215;
      (*this)[make_pair(331, 328)] = 11184810;
      (*this)[make_pair(331, 329)] = 16777215;
      (*this)[make_pair(332, 320)] = 16777215;
      (*this)[make_pair(332, 321)] = 9474192;
      (*this)[make_pair(332, 322)] = 16579836;
      (*this)[make_pair(332, 323)] = 16777215;
      (*this)[make_pair(332, 324)] = 16777215;
      (*this)[make_pair(332, 325)] = 9868950;
      (*this)[make_pair(332, 326)] = 15987699;
      (*this)[make_pair(332, 327)] = 16777215;
      (*this)[make_pair(332, 328)] = 9671571;
      (*this)[make_pair(332, 329)] = 16382457;
      (*this)[make_pair(333, 320)] = 16250871;
      (*this)[make_pair(333, 321)] = 10197915;
      (*this)[make_pair(333, 322)] = 16777215;
      (*this)[make_pair(333, 323)] = 16777215;
      (*this)[make_pair(333, 324)] = 16777215;
      (*this)[make_pair(333, 325)] = 12171705;
      (*this)[make_pair(333, 326)] = 14935011;
      (*this)[make_pair(333, 327)] = 16711422;
      (*this)[make_pair(333, 328)] = 8553090;
      (*this)[make_pair(333, 329)] = 16514043;
      (*this)[make_pair(334, 320)] = 16777215;
      (*this)[make_pair(334, 321)] = 10790052;
      (*this)[make_pair(334, 322)] = 15921906;
      (*this)[make_pair(334, 323)] = 16777215;
      (*this)[make_pair(334, 324)] = 16514043;
      (*this)[make_pair(334, 325)] = 11382189;
      (*this)[make_pair(334, 326)] = 16579836;
      (*this)[make_pair(334, 327)] = 12763842;
      (*this)[make_pair(334, 328)] = 9605778;
      (*this)[make_pair(334, 329)] = 16777215;
    }
  } s1579;
  map<pair<int, int>, int> table1579;
  void update_table1579()
  {
    for (const auto& x : s1579) {
      auto pos = x.first;
      pos.first += gen_button.first - 450;
      pos.second += gen_button.second - 480;
      table1579[pos] = x.second;
    }
  }
  // "15-39" data
  //  ^^^^^
  struct table1539_t : map<pair<int,int>, int> {
    table1539_t()
    {
      (*this)[make_pair(305, 380)] = 16777215;
      (*this)[make_pair(305, 381)] = 12632256;
      (*this)[make_pair(305, 382)] = 13816530;
      (*this)[make_pair(305, 383)] = 16777215;
      (*this)[make_pair(305, 384)] = 16777215;
      (*this)[make_pair(305, 385)] = 16777215;
      (*this)[make_pair(305, 386)] = 16777215;
      (*this)[make_pair(305, 387)] = 16777215;
      (*this)[make_pair(305, 388)] = 16777215;
      (*this)[make_pair(305, 389)] = 16777215;
      (*this)[make_pair(306, 380)] = 13882323;
      (*this)[make_pair(306, 381)] = 9868950;
      (*this)[make_pair(306, 382)] = 16711422;
      (*this)[make_pair(306, 383)] = 16777215;
      (*this)[make_pair(306, 384)] = 16777215;
      (*this)[make_pair(306, 385)] = 16777215;
      (*this)[make_pair(306, 386)] = 16777215;
      (*this)[make_pair(306, 387)] = 16777215;
      (*this)[make_pair(306, 388)] = 16777215;
      (*this)[make_pair(306, 389)] = 16777215;
      (*this)[make_pair(307, 380)] = 7500402;
      (*this)[make_pair(307, 381)] = 11842740;
      (*this)[make_pair(307, 382)] = 12369084;
      (*this)[make_pair(307, 383)] = 12369084;
      (*this)[make_pair(307, 384)] = 12369084;
      (*this)[make_pair(307, 385)] = 12369084;
      (*this)[make_pair(307, 386)] = 12369084;
      (*this)[make_pair(307, 387)] = 12369084;
      (*this)[make_pair(307, 388)] = 16777215;
      (*this)[make_pair(307, 389)] = 16777215;
      (*this)[make_pair(308, 380)] = 12369084;
      (*this)[make_pair(308, 381)] = 12369084;
      (*this)[make_pair(308, 382)] = 12369084;
      (*this)[make_pair(308, 383)] = 12369084;
      (*this)[make_pair(308, 384)] = 12369084;
      (*this)[make_pair(308, 385)] = 12369084;
      (*this)[make_pair(308, 386)] = 12369084;
      (*this)[make_pair(308, 387)] = 12369084;
      (*this)[make_pair(308, 388)] = 16777215;
      (*this)[make_pair(308, 389)] = 16777215;
      (*this)[make_pair(309, 380)] = 16777215;
      (*this)[make_pair(309, 381)] = 16777215;
      (*this)[make_pair(309, 382)] = 16777215;
      (*this)[make_pair(309, 383)] = 16777215;
      (*this)[make_pair(309, 384)] = 16777215;
      (*this)[make_pair(309, 385)] = 16777215;
      (*this)[make_pair(309, 386)] = 16777215;
      (*this)[make_pair(309, 387)] = 16777215;
      (*this)[make_pair(309, 388)] = 16777215;
      (*this)[make_pair(309, 389)] = 16777215;
      (*this)[make_pair(310, 380)] = 16777215;
      (*this)[make_pair(310, 381)] = 16777215;
      (*this)[make_pair(310, 382)] = 16777215;
      (*this)[make_pair(310, 383)] = 16777215;
      (*this)[make_pair(310, 384)] = 16777215;
      (*this)[make_pair(310, 385)] = 16777215;
      (*this)[make_pair(310, 386)] = 16777215;
      (*this)[make_pair(310, 387)] = 16777215;
      (*this)[make_pair(310, 388)] = 16777215;
      (*this)[make_pair(310, 389)] = 16777215;
      (*this)[make_pair(311, 380)] = 16777215;
      (*this)[make_pair(311, 381)] = 16777215;
      (*this)[make_pair(311, 382)] = 16777215;
      (*this)[make_pair(311, 383)] = 16777215;
      (*this)[make_pair(311, 384)] = 16777215;
      (*this)[make_pair(311, 385)] = 16777215;
      (*this)[make_pair(311, 386)] = 16777215;
      (*this)[make_pair(311, 387)] = 16777215;
      (*this)[make_pair(311, 388)] = 16777215;
      (*this)[make_pair(311, 389)] = 16777215;
      (*this)[make_pair(312, 380)] = 10724259;
      (*this)[make_pair(312, 381)] = 10132122;
      (*this)[make_pair(312, 382)] = 9605778;
      (*this)[make_pair(312, 383)] = 9013641;
      (*this)[make_pair(312, 384)] = 16185078;
      (*this)[make_pair(312, 385)] = 16777215;
      (*this)[make_pair(312, 386)] = 16316664;
      (*this)[make_pair(312, 387)] = 10000536;
      (*this)[make_pair(312, 388)] = 16777215;
      (*this)[make_pair(312, 389)] = 16777215;
      (*this)[make_pair(313, 380)] = 9737364;
      (*this)[make_pair(313, 381)] = 14935011;
      (*this)[make_pair(313, 382)] = 15592941;
      (*this)[make_pair(313, 383)] = 9013641;
      (*this)[make_pair(313, 384)] = 16711422;
      (*this)[make_pair(313, 385)] = 16777215;
      (*this)[make_pair(313, 386)] = 16777215;
      (*this)[make_pair(313, 387)] = 9145227;
      (*this)[make_pair(313, 388)] = 16579836;
      (*this)[make_pair(313, 389)] = 16777215;
      (*this)[make_pair(314, 380)] = 10592673;
      (*this)[make_pair(314, 381)] = 16777215;
      (*this)[make_pair(314, 382)] = 16119285;
      (*this)[make_pair(314, 383)] = 10197915;
      (*this)[make_pair(314, 384)] = 16777215;
      (*this)[make_pair(314, 385)] = 16777215;
      (*this)[make_pair(314, 386)] = 16777215;
      (*this)[make_pair(314, 387)] = 9474192;
      (*this)[make_pair(314, 388)] = 16514043;
      (*this)[make_pair(314, 389)] = 16777215;
      (*this)[make_pair(315, 380)] = 10592673;
      (*this)[make_pair(315, 381)] = 16777215;
      (*this)[make_pair(315, 382)] = 16777215;
      (*this)[make_pair(315, 383)] = 9408399;
      (*this)[make_pair(315, 384)] = 15461355;
      (*this)[make_pair(315, 385)] = 16711422;
      (*this)[make_pair(315, 386)] = 14013909;
      (*this)[make_pair(315, 387)] = 10197915;
      (*this)[make_pair(315, 388)] = 16777215;
      (*this)[make_pair(315, 389)] = 16777215;
      (*this)[make_pair(316, 380)] = 12500670;
      (*this)[make_pair(316, 381)] = 16777215;
      (*this)[make_pair(316, 382)] = 16777215;
      (*this)[make_pair(316, 383)] = 14211288;
      (*this)[make_pair(316, 384)] = 9408399;
      (*this)[make_pair(316, 385)] = 8158332;
      (*this)[make_pair(316, 386)] = 10658466;
      (*this)[make_pair(316, 387)] = 15198183;
      (*this)[make_pair(316, 388)] = 16777215;
      (*this)[make_pair(316, 389)] = 16777215;
      (*this)[make_pair(317, 380)] = 16777215;
      (*this)[make_pair(317, 381)] = 16777215;
      (*this)[make_pair(317, 382)] = 16777215;
      (*this)[make_pair(317, 383)] = 16777215;
      (*this)[make_pair(317, 384)] = 16777215;
      (*this)[make_pair(317, 385)] = 16777215;
      (*this)[make_pair(317, 386)] = 16777215;
      (*this)[make_pair(317, 387)] = 16777215;
      (*this)[make_pair(317, 388)] = 16777215;
      (*this)[make_pair(317, 389)] = 16777215;
      (*this)[make_pair(318, 380)] = 16777215;
      (*this)[make_pair(318, 381)] = 16777215;
      (*this)[make_pair(318, 382)] = 16777215;
      (*this)[make_pair(318, 383)] = 16777215;
      (*this)[make_pair(318, 384)] = 16316664;
      (*this)[make_pair(318, 385)] = 16645629;
      (*this)[make_pair(318, 386)] = 16777215;
      (*this)[make_pair(318, 387)] = 16777215;
      (*this)[make_pair(318, 388)] = 16777215;
      (*this)[make_pair(318, 389)] = 16777215;
      (*this)[make_pair(319, 380)] = 16777215;
      (*this)[make_pair(319, 381)] = 16777215;
      (*this)[make_pair(319, 382)] = 16777215;
      (*this)[make_pair(319, 383)] = 16777215;
      (*this)[make_pair(319, 384)] = 11711154;
      (*this)[make_pair(319, 385)] = 14869218;
      (*this)[make_pair(319, 386)] = 16777215;
      (*this)[make_pair(319, 387)] = 16777215;
      (*this)[make_pair(319, 388)] = 16777215;
      (*this)[make_pair(319, 389)] = 16777215;
      (*this)[make_pair(320, 380)] = 16777215;
      (*this)[make_pair(320, 381)] = 16777215;
      (*this)[make_pair(320, 382)] = 16777215;
      (*this)[make_pair(320, 383)] = 16777215;
      (*this)[make_pair(320, 384)] = 11711154;
      (*this)[make_pair(320, 385)] = 14869218;
      (*this)[make_pair(320, 386)] = 16777215;
      (*this)[make_pair(320, 387)] = 16777215;
      (*this)[make_pair(320, 388)] = 16777215;
      (*this)[make_pair(320, 389)] = 16777215;
      (*this)[make_pair(321, 380)] = 16777215;
      (*this)[make_pair(321, 381)] = 16777215;
      (*this)[make_pair(321, 382)] = 16777215;
      (*this)[make_pair(321, 383)] = 16777215;
      (*this)[make_pair(321, 384)] = 11711154;
      (*this)[make_pair(321, 385)] = 14869218;
      (*this)[make_pair(321, 386)] = 16777215;
      (*this)[make_pair(321, 387)] = 16777215;
      (*this)[make_pair(321, 388)] = 16777215;
      (*this)[make_pair(321, 389)] = 16777215;
      (*this)[make_pair(322, 380)] = 16777215;
      (*this)[make_pair(322, 381)] = 16777215;
      (*this)[make_pair(322, 382)] = 16777215;
      (*this)[make_pair(322, 383)] = 16777215;
      (*this)[make_pair(322, 384)] = 15329769;
      (*this)[make_pair(322, 385)] = 16250871;
      (*this)[make_pair(322, 386)] = 16777215;
      (*this)[make_pair(322, 387)] = 16777215;
      (*this)[make_pair(322, 388)] = 16777215;
      (*this)[make_pair(322, 389)] = 16777215;
      (*this)[make_pair(323, 380)] = 16777215;
      (*this)[make_pair(323, 381)] = 16777215;
      (*this)[make_pair(323, 382)] = 16777215;
      (*this)[make_pair(323, 383)] = 16777215;
      (*this)[make_pair(323, 384)] = 16777215;
      (*this)[make_pair(323, 385)] = 16777215;
      (*this)[make_pair(323, 386)] = 16777215;
      (*this)[make_pair(323, 387)] = 16777215;
      (*this)[make_pair(323, 388)] = 16777215;
      (*this)[make_pair(323, 389)] = 16777215;
      (*this)[make_pair(324, 380)] = 10724259;
      (*this)[make_pair(324, 381)] = 16777215;
      (*this)[make_pair(324, 382)] = 16777215;
      (*this)[make_pair(324, 383)] = 16777215;
      (*this)[make_pair(324, 384)] = 16777215;
      (*this)[make_pair(324, 385)] = 16777215;
      (*this)[make_pair(324, 386)] = 16250871;
      (*this)[make_pair(324, 387)] = 9737364;
      (*this)[make_pair(324, 388)] = 16777215;
      (*this)[make_pair(324, 389)] = 16777215;
      (*this)[make_pair(325, 380)] = 10592673;
      (*this)[make_pair(325, 381)] = 16777215;
      (*this)[make_pair(325, 382)] = 14277081;
      (*this)[make_pair(325, 383)] = 8421504;
      (*this)[make_pair(325, 384)] = 16777215;
      (*this)[make_pair(325, 385)] = 16777215;
      (*this)[make_pair(325, 386)] = 16777215;
      (*this)[make_pair(325, 387)] = 9145227;
      (*this)[make_pair(325, 388)] = 16579836;
      (*this)[make_pair(325, 389)] = 16777215;
      (*this)[make_pair(326, 380)] = 10592673;
      (*this)[make_pair(326, 381)] = 14342874;
      (*this)[make_pair(326, 382)] = 8816262;
      (*this)[make_pair(326, 383)] = 8882055;
      (*this)[make_pair(326, 384)] = 16119285;
      (*this)[make_pair(326, 385)] = 16777215;
      (*this)[make_pair(326, 386)] = 16777215;
      (*this)[make_pair(326, 387)] = 9474192;
      (*this)[make_pair(326, 388)] = 16514043;
      (*this)[make_pair(326, 389)] = 16777215;
      (*this)[make_pair(327, 380)] = 8750469;
      (*this)[make_pair(327, 381)] = 8816262;
      (*this)[make_pair(327, 382)] = 15856113;
      (*this)[make_pair(327, 383)] = 12303291;
      (*this)[make_pair(327, 384)] = 11908533;
      (*this)[make_pair(327, 385)] = 16316664;
      (*this)[make_pair(327, 386)] = 13487565;
      (*this)[make_pair(327, 387)] = 10197915;
      (*this)[make_pair(327, 388)] = 16777215;
      (*this)[make_pair(327, 389)] = 16777215;
      (*this)[make_pair(328, 380)] = 9211020;
      (*this)[make_pair(328, 381)] = 15856113;
      (*this)[make_pair(328, 382)] = 16777215;
      (*this)[make_pair(328, 383)] = 15987699;
      (*this)[make_pair(328, 384)] = 10987431;
      (*this)[make_pair(328, 385)] = 8355711;
      (*this)[make_pair(328, 386)] = 11184810;
      (*this)[make_pair(328, 387)] = 15461355;
      (*this)[make_pair(328, 388)] = 16777215;
      (*this)[make_pair(328, 389)] = 16777215;
      (*this)[make_pair(329, 380)] = 16777215;
      (*this)[make_pair(329, 381)] = 16777215;
      (*this)[make_pair(329, 382)] = 16777215;
      (*this)[make_pair(329, 383)] = 16777215;
      (*this)[make_pair(329, 384)] = 16777215;
      (*this)[make_pair(329, 385)] = 16777215;
      (*this)[make_pair(329, 386)] = 16777215;
      (*this)[make_pair(329, 387)] = 16777215;
      (*this)[make_pair(329, 388)] = 16777215;
      (*this)[make_pair(329, 389)] = 16777215;
      (*this)[make_pair(330, 380)] = 16777215;
      (*this)[make_pair(330, 381)] = 16448250;
      (*this)[make_pair(330, 382)] = 13816530;
      (*this)[make_pair(330, 383)] = 15921906;
      (*this)[make_pair(330, 384)] = 16777215;
      (*this)[make_pair(330, 385)] = 16777215;
      (*this)[make_pair(330, 386)] = 16777215;
      (*this)[make_pair(330, 387)] = 16777215;
      (*this)[make_pair(330, 388)] = 16777215;
      (*this)[make_pair(330, 389)] = 16777215;
      (*this)[make_pair(331, 380)] = 13290186;
      (*this)[make_pair(331, 381)] = 8618883;
      (*this)[make_pair(331, 382)] = 10987431;
      (*this)[make_pair(331, 383)] = 8947848;
      (*this)[make_pair(331, 384)] = 11119017;
      (*this)[make_pair(331, 385)] = 16777215;
      (*this)[make_pair(331, 386)] = 16777215;
      (*this)[make_pair(331, 387)] = 11184810;
      (*this)[make_pair(331, 388)] = 16777215;
      (*this)[make_pair(331, 389)] = 16777215;
      (*this)[make_pair(332, 380)] = 9474192;
      (*this)[make_pair(332, 381)] = 16579836;
      (*this)[make_pair(332, 382)] = 16777215;
      (*this)[make_pair(332, 383)] = 16777215;
      (*this)[make_pair(332, 384)] = 9868950;
      (*this)[make_pair(332, 385)] = 15987699;
      (*this)[make_pair(332, 386)] = 16777215;
      (*this)[make_pair(332, 387)] = 9671571;
      (*this)[make_pair(332, 388)] = 16382457;
      (*this)[make_pair(332, 389)] = 16777215;
      (*this)[make_pair(333, 380)] = 10197915;
      (*this)[make_pair(333, 381)] = 16777215;
      (*this)[make_pair(333, 382)] = 16777215;
      (*this)[make_pair(333, 383)] = 16777215;
      (*this)[make_pair(333, 384)] = 12171705;
      (*this)[make_pair(333, 385)] = 14935011;
      (*this)[make_pair(333, 386)] = 16711422;
      (*this)[make_pair(333, 387)] = 8553090;
      (*this)[make_pair(333, 388)] = 16514043;
      (*this)[make_pair(333, 389)] = 16777215;
      (*this)[make_pair(334, 380)] = 10790052;
      (*this)[make_pair(334, 381)] = 15921906;
      (*this)[make_pair(334, 382)] = 16777215;
      (*this)[make_pair(334, 383)] = 16514043;
      (*this)[make_pair(334, 384)] = 11382189;
      (*this)[make_pair(334, 385)] = 16579836;
      (*this)[make_pair(334, 386)] = 12763842;
      (*this)[make_pair(334, 387)] = 9605778;
      (*this)[make_pair(334, 388)] = 16777215;
      (*this)[make_pair(334, 389)] = 16777215;
    }
  } s1539;
  map<pair<int, int>, int> table1539;
  void update_table1539()
  {
    for (const auto& x : s1539) {
      auto pos = x.first;
      pos.first += gen_button.first - 450;
      pos.second += gen_button.second - 480;
      table1539[pos] = x.second;
    }
  }
  // "15-49" data
  //  ^^^^^
  struct table1549_t : map<pair<int,int>, int> {
    table1549_t()
    {
      (*this)[make_pair(305, 365)] = 16777215;
      (*this)[make_pair(305, 366)] = 12632256;
      (*this)[make_pair(305, 367)] = 13816530;
      (*this)[make_pair(305, 368)] = 16777215;
      (*this)[make_pair(305, 369)] = 16777215;
      (*this)[make_pair(305, 370)] = 16777215;
      (*this)[make_pair(305, 371)] = 16777215;
      (*this)[make_pair(305, 372)] = 16777215;
      (*this)[make_pair(305, 373)] = 16777215;
      (*this)[make_pair(305, 374)] = 16777215;
      (*this)[make_pair(306, 365)] = 13882323;
      (*this)[make_pair(306, 366)] = 9868950;
      (*this)[make_pair(306, 367)] = 16711422;
      (*this)[make_pair(306, 368)] = 16777215;
      (*this)[make_pair(306, 369)] = 16777215;
      (*this)[make_pair(306, 370)] = 16777215;
      (*this)[make_pair(306, 371)] = 16777215;
      (*this)[make_pair(306, 372)] = 16777215;
      (*this)[make_pair(306, 373)] = 16777215;
      (*this)[make_pair(306, 374)] = 16777215;
      (*this)[make_pair(307, 365)] = 7500402;
      (*this)[make_pair(307, 366)] = 11842740;
      (*this)[make_pair(307, 367)] = 12369084;
      (*this)[make_pair(307, 368)] = 12369084;
      (*this)[make_pair(307, 369)] = 12369084;
      (*this)[make_pair(307, 370)] = 12369084;
      (*this)[make_pair(307, 371)] = 12369084;
      (*this)[make_pair(307, 372)] = 12369084;
      (*this)[make_pair(307, 373)] = 16777215;
      (*this)[make_pair(307, 374)] = 16777215;
      (*this)[make_pair(308, 365)] = 12369084;
      (*this)[make_pair(308, 366)] = 12369084;
      (*this)[make_pair(308, 367)] = 12369084;
      (*this)[make_pair(308, 368)] = 12369084;
      (*this)[make_pair(308, 369)] = 12369084;
      (*this)[make_pair(308, 370)] = 12369084;
      (*this)[make_pair(308, 371)] = 12369084;
      (*this)[make_pair(308, 372)] = 12369084;
      (*this)[make_pair(308, 373)] = 16777215;
      (*this)[make_pair(308, 374)] = 16777215;
      (*this)[make_pair(309, 365)] = 16777215;
      (*this)[make_pair(309, 366)] = 16777215;
      (*this)[make_pair(309, 367)] = 16777215;
      (*this)[make_pair(309, 368)] = 16777215;
      (*this)[make_pair(309, 369)] = 16777215;
      (*this)[make_pair(309, 370)] = 16777215;
      (*this)[make_pair(309, 371)] = 16777215;
      (*this)[make_pair(309, 372)] = 16777215;
      (*this)[make_pair(309, 373)] = 16777215;
      (*this)[make_pair(309, 374)] = 16777215;
      (*this)[make_pair(310, 365)] = 16777215;
      (*this)[make_pair(310, 366)] = 16777215;
      (*this)[make_pair(310, 367)] = 16777215;
      (*this)[make_pair(310, 368)] = 16777215;
      (*this)[make_pair(310, 369)] = 16777215;
      (*this)[make_pair(310, 370)] = 16777215;
      (*this)[make_pair(310, 371)] = 16777215;
      (*this)[make_pair(310, 372)] = 16777215;
      (*this)[make_pair(310, 373)] = 16777215;
      (*this)[make_pair(310, 374)] = 16777215;
      (*this)[make_pair(311, 365)] = 16777215;
      (*this)[make_pair(311, 366)] = 16777215;
      (*this)[make_pair(311, 367)] = 16777215;
      (*this)[make_pair(311, 368)] = 16777215;
      (*this)[make_pair(311, 369)] = 16777215;
      (*this)[make_pair(311, 370)] = 16777215;
      (*this)[make_pair(311, 371)] = 16777215;
      (*this)[make_pair(311, 372)] = 16777215;
      (*this)[make_pair(311, 373)] = 16777215;
      (*this)[make_pair(311, 374)] = 16777215;
      (*this)[make_pair(312, 365)] = 10724259;
      (*this)[make_pair(312, 366)] = 10132122;
      (*this)[make_pair(312, 367)] = 9605778;
      (*this)[make_pair(312, 368)] = 9013641;
      (*this)[make_pair(312, 369)] = 16185078;
      (*this)[make_pair(312, 370)] = 16777215;
      (*this)[make_pair(312, 371)] = 16316664;
      (*this)[make_pair(312, 372)] = 10000536;
      (*this)[make_pair(312, 373)] = 16777215;
      (*this)[make_pair(312, 374)] = 16777215;
      (*this)[make_pair(313, 365)] = 9737364;
      (*this)[make_pair(313, 366)] = 14935011;
      (*this)[make_pair(313, 367)] = 15592941;
      (*this)[make_pair(313, 368)] = 9013641;
      (*this)[make_pair(313, 369)] = 16711422;
      (*this)[make_pair(313, 370)] = 16777215;
      (*this)[make_pair(313, 371)] = 16777215;
      (*this)[make_pair(313, 372)] = 9145227;
      (*this)[make_pair(313, 373)] = 16579836;
      (*this)[make_pair(313, 374)] = 16777215;
      (*this)[make_pair(314, 365)] = 10592673;
      (*this)[make_pair(314, 366)] = 16777215;
      (*this)[make_pair(314, 367)] = 16119285;
      (*this)[make_pair(314, 368)] = 10197915;
      (*this)[make_pair(314, 369)] = 16777215;
      (*this)[make_pair(314, 370)] = 16777215;
      (*this)[make_pair(314, 371)] = 16777215;
      (*this)[make_pair(314, 372)] = 9474192;
      (*this)[make_pair(314, 373)] = 16514043;
      (*this)[make_pair(314, 374)] = 16777215;
      (*this)[make_pair(315, 365)] = 10592673;
      (*this)[make_pair(315, 366)] = 16777215;
      (*this)[make_pair(315, 367)] = 16777215;
      (*this)[make_pair(315, 368)] = 9408399;
      (*this)[make_pair(315, 369)] = 15461355;
      (*this)[make_pair(315, 370)] = 16711422;
      (*this)[make_pair(315, 371)] = 14013909;
      (*this)[make_pair(315, 372)] = 10197915;
      (*this)[make_pair(315, 373)] = 16777215;
      (*this)[make_pair(315, 374)] = 16777215;
      (*this)[make_pair(316, 365)] = 12500670;
      (*this)[make_pair(316, 366)] = 16777215;
      (*this)[make_pair(316, 367)] = 16777215;
      (*this)[make_pair(316, 368)] = 14211288;
      (*this)[make_pair(316, 369)] = 9408399;
      (*this)[make_pair(316, 370)] = 8158332;
      (*this)[make_pair(316, 371)] = 10658466;
      (*this)[make_pair(316, 372)] = 15198183;
      (*this)[make_pair(316, 373)] = 16777215;
      (*this)[make_pair(316, 374)] = 16777215;
      (*this)[make_pair(317, 365)] = 16777215;
      (*this)[make_pair(317, 366)] = 16777215;
      (*this)[make_pair(317, 367)] = 16777215;
      (*this)[make_pair(317, 368)] = 16777215;
      (*this)[make_pair(317, 369)] = 16777215;
      (*this)[make_pair(317, 370)] = 16777215;
      (*this)[make_pair(317, 371)] = 16777215;
      (*this)[make_pair(317, 372)] = 16777215;
      (*this)[make_pair(317, 373)] = 16777215;
      (*this)[make_pair(317, 374)] = 16777215;
      (*this)[make_pair(318, 365)] = 16777215;
      (*this)[make_pair(318, 366)] = 16777215;
      (*this)[make_pair(318, 367)] = 16777215;
      (*this)[make_pair(318, 368)] = 16777215;
      (*this)[make_pair(318, 369)] = 16316664;
      (*this)[make_pair(318, 370)] = 16645629;
      (*this)[make_pair(318, 371)] = 16777215;
      (*this)[make_pair(318, 372)] = 16777215;
      (*this)[make_pair(318, 373)] = 16777215;
      (*this)[make_pair(318, 374)] = 16777215;
      (*this)[make_pair(319, 365)] = 16777215;
      (*this)[make_pair(319, 366)] = 16777215;
      (*this)[make_pair(319, 367)] = 16777215;
      (*this)[make_pair(319, 368)] = 16777215;
      (*this)[make_pair(319, 369)] = 11711154;
      (*this)[make_pair(319, 370)] = 14869218;
      (*this)[make_pair(319, 371)] = 16777215;
      (*this)[make_pair(319, 372)] = 16777215;
      (*this)[make_pair(319, 373)] = 16777215;
      (*this)[make_pair(319, 374)] = 16777215;
      (*this)[make_pair(320, 365)] = 16777215;
      (*this)[make_pair(320, 366)] = 16777215;
      (*this)[make_pair(320, 367)] = 16777215;
      (*this)[make_pair(320, 368)] = 16777215;
      (*this)[make_pair(320, 369)] = 11711154;
      (*this)[make_pair(320, 370)] = 14869218;
      (*this)[make_pair(320, 371)] = 16777215;
      (*this)[make_pair(320, 372)] = 16777215;
      (*this)[make_pair(320, 373)] = 16777215;
      (*this)[make_pair(320, 374)] = 16777215;
      (*this)[make_pair(321, 365)] = 16777215;
      (*this)[make_pair(321, 366)] = 16777215;
      (*this)[make_pair(321, 367)] = 16777215;
      (*this)[make_pair(321, 368)] = 16777215;
      (*this)[make_pair(321, 369)] = 11711154;
      (*this)[make_pair(321, 370)] = 14869218;
      (*this)[make_pair(321, 371)] = 16777215;
      (*this)[make_pair(321, 372)] = 16777215;
      (*this)[make_pair(321, 373)] = 16777215;
      (*this)[make_pair(321, 374)] = 16777215;
      (*this)[make_pair(322, 365)] = 16777215;
      (*this)[make_pair(322, 366)] = 16777215;
      (*this)[make_pair(322, 367)] = 16777215;
      (*this)[make_pair(322, 368)] = 16777215;
      (*this)[make_pair(322, 369)] = 15329769;
      (*this)[make_pair(322, 370)] = 16250871;
      (*this)[make_pair(322, 371)] = 16777215;
      (*this)[make_pair(322, 372)] = 16777215;
      (*this)[make_pair(322, 373)] = 16777215;
      (*this)[make_pair(322, 374)] = 16777215;
      (*this)[make_pair(323, 365)] = 16777215;
      (*this)[make_pair(323, 366)] = 16777215;
      (*this)[make_pair(323, 367)] = 16777215;
      (*this)[make_pair(323, 368)] = 16777215;
      (*this)[make_pair(323, 369)] = 14935011;
      (*this)[make_pair(323, 370)] = 9539985;
      (*this)[make_pair(323, 371)] = 15921906;
      (*this)[make_pair(323, 372)] = 16777215;
      (*this)[make_pair(323, 373)] = 16777215;
      (*this)[make_pair(323, 374)] = 16777215;
      (*this)[make_pair(324, 365)] = 16777215;
      (*this)[make_pair(324, 366)] = 16777215;
      (*this)[make_pair(324, 367)] = 16711422;
      (*this)[make_pair(324, 368)] = 12171705;
      (*this)[make_pair(324, 369)] = 9737364;
      (*this)[make_pair(324, 370)] = 9539985;
      (*this)[make_pair(324, 371)] = 15658734;
      (*this)[make_pair(324, 372)] = 16777215;
      (*this)[make_pair(324, 373)] = 16777215;
      (*this)[make_pair(324, 374)] = 16777215;
      (*this)[make_pair(325, 365)] = 16777215;
      (*this)[make_pair(325, 366)] = 15592941;
      (*this)[make_pair(325, 367)] = 9605778;
      (*this)[make_pair(325, 368)] = 12434877;
      (*this)[make_pair(325, 369)] = 16711422;
      (*this)[make_pair(325, 370)] = 10461087;
      (*this)[make_pair(325, 371)] = 15658734;
      (*this)[make_pair(325, 372)] = 16777215;
      (*this)[make_pair(325, 373)] = 16777215;
      (*this)[make_pair(325, 374)] = 16777215;
      (*this)[make_pair(326, 365)] = 13158600;
      (*this)[make_pair(326, 366)] = 9342606;
      (*this)[make_pair(326, 367)] = 15132390;
      (*this)[make_pair(326, 368)] = 16777215;
      (*this)[make_pair(326, 369)] = 16777215;
      (*this)[make_pair(326, 370)] = 10461087;
      (*this)[make_pair(326, 371)] = 15658734;
      (*this)[make_pair(326, 372)] = 16777215;
      (*this)[make_pair(326, 373)] = 16777215;
      (*this)[make_pair(326, 374)] = 16777215;
      (*this)[make_pair(327, 365)] = 6974058;
      (*this)[make_pair(327, 366)] = 7763574;
      (*this)[make_pair(327, 367)] = 7960953;
      (*this)[make_pair(327, 368)] = 7960953;
      (*this)[make_pair(327, 369)] = 7960953;
      (*this)[make_pair(327, 370)] = 7171437;
      (*this)[make_pair(327, 371)] = 7829367;
      (*this)[make_pair(327, 372)] = 7960953;
      (*this)[make_pair(327, 373)] = 16777215;
      (*this)[make_pair(327, 374)] = 16777215;
      (*this)[make_pair(328, 365)] = 16777215;
      (*this)[make_pair(328, 366)] = 16777215;
      (*this)[make_pair(328, 367)] = 16777215;
      (*this)[make_pair(328, 368)] = 16777215;
      (*this)[make_pair(328, 369)] = 16777215;
      (*this)[make_pair(328, 370)] = 10461087;
      (*this)[make_pair(328, 371)] = 15658734;
      (*this)[make_pair(328, 372)] = 16777215;
      (*this)[make_pair(328, 373)] = 16777215;
      (*this)[make_pair(328, 374)] = 16777215;
      (*this)[make_pair(329, 365)] = 16777215;
      (*this)[make_pair(329, 366)] = 16777215;
      (*this)[make_pair(329, 367)] = 16777215;
      (*this)[make_pair(329, 368)] = 16777215;
      (*this)[make_pair(329, 369)] = 16777215;
      (*this)[make_pair(329, 370)] = 14737632;
      (*this)[make_pair(329, 371)] = 16448250;
      (*this)[make_pair(329, 372)] = 16777215;
      (*this)[make_pair(329, 373)] = 16777215;
      (*this)[make_pair(329, 374)] = 16777215;
      (*this)[make_pair(330, 365)] = 16777215;
      (*this)[make_pair(330, 366)] = 16448250;
      (*this)[make_pair(330, 367)] = 13816530;
      (*this)[make_pair(330, 368)] = 15921906;
      (*this)[make_pair(330, 369)] = 16777215;
      (*this)[make_pair(330, 370)] = 16777215;
      (*this)[make_pair(330, 371)] = 16777215;
      (*this)[make_pair(330, 372)] = 16777215;
      (*this)[make_pair(330, 373)] = 16777215;
      (*this)[make_pair(330, 374)] = 16777215;
      (*this)[make_pair(331, 365)] = 13290186;
      (*this)[make_pair(331, 366)] = 8618883;
      (*this)[make_pair(331, 367)] = 10987431;
      (*this)[make_pair(331, 368)] = 8947848;
      (*this)[make_pair(331, 369)] = 11119017;
      (*this)[make_pair(331, 370)] = 16777215;
      (*this)[make_pair(331, 371)] = 16777215;
      (*this)[make_pair(331, 372)] = 11184810;
      (*this)[make_pair(331, 373)] = 16777215;
      (*this)[make_pair(331, 374)] = 16777215;
      (*this)[make_pair(332, 365)] = 9474192;
      (*this)[make_pair(332, 366)] = 16579836;
      (*this)[make_pair(332, 367)] = 16777215;
      (*this)[make_pair(332, 368)] = 16777215;
      (*this)[make_pair(332, 369)] = 9868950;
      (*this)[make_pair(332, 370)] = 15987699;
      (*this)[make_pair(332, 371)] = 16777215;
      (*this)[make_pair(332, 372)] = 9671571;
      (*this)[make_pair(332, 373)] = 16382457;
      (*this)[make_pair(332, 374)] = 16777215;
      (*this)[make_pair(333, 365)] = 10197915;
      (*this)[make_pair(333, 366)] = 16777215;
      (*this)[make_pair(333, 367)] = 16777215;
      (*this)[make_pair(333, 368)] = 16777215;
      (*this)[make_pair(333, 369)] = 12171705;
      (*this)[make_pair(333, 370)] = 14935011;
      (*this)[make_pair(333, 371)] = 16711422;
      (*this)[make_pair(333, 372)] = 8553090;
      (*this)[make_pair(333, 373)] = 16514043;
      (*this)[make_pair(333, 374)] = 16777215;
      (*this)[make_pair(334, 365)] = 10790052;
      (*this)[make_pair(334, 366)] = 15921906;
      (*this)[make_pair(334, 367)] = 16777215;
      (*this)[make_pair(334, 368)] = 16514043;
      (*this)[make_pair(334, 369)] = 11382189;
      (*this)[make_pair(334, 370)] = 16579836;
      (*this)[make_pair(334, 371)] = 12763842;
      (*this)[make_pair(334, 372)] = 9605778;
      (*this)[make_pair(334, 373)] = 16777215;
      (*this)[make_pair(334, 374)] = 16777215;
    }
  } s1549;
  map<pair<int, int>, int> table1549;
  void update_table1549()
  {
    for (const auto& x : s1549) {
      auto pos = x.first;
      pos.first += gen_button.first - 450;
      pos.second += gen_button.second - 480;
      table1549[pos] = x.second;
    }
  }
  // "15-29" data
  //  ^^^^^
  struct table1529_t : map<pair<int,int>, int> {
    table1529_t()
    {
      (*this)[make_pair(305, 392)] = 16777215;
      (*this)[make_pair(305, 393)] = 16777215;
      (*this)[make_pair(305, 394)] = 16777215;
      (*this)[make_pair(305, 395)] = 12632256;
      (*this)[make_pair(305, 396)] = 13816530;
      (*this)[make_pair(305, 397)] = 16777215;
      (*this)[make_pair(305, 398)] = 16777215;
      (*this)[make_pair(305, 399)] = 16777215;
      (*this)[make_pair(305, 400)] = 16777215;
      (*this)[make_pair(305, 401)] = 16777215;
      (*this)[make_pair(306, 392)] = 16777215;
      (*this)[make_pair(306, 393)] = 16777215;
      (*this)[make_pair(306, 394)] = 13882323;
      (*this)[make_pair(306, 395)] = 9868950;
      (*this)[make_pair(306, 396)] = 16711422;
      (*this)[make_pair(306, 397)] = 16777215;
      (*this)[make_pair(306, 398)] = 16777215;
      (*this)[make_pair(306, 399)] = 16777215;
      (*this)[make_pair(306, 400)] = 16777215;
      (*this)[make_pair(306, 401)] = 16777215;
      (*this)[make_pair(307, 392)] = 16777215;
      (*this)[make_pair(307, 393)] = 16053492;
      (*this)[make_pair(307, 394)] = 7500402;
      (*this)[make_pair(307, 395)] = 11842740;
      (*this)[make_pair(307, 396)] = 12369084;
      (*this)[make_pair(307, 397)] = 12369084;
      (*this)[make_pair(307, 398)] = 12369084;
      (*this)[make_pair(307, 399)] = 12369084;
      (*this)[make_pair(307, 400)] = 12369084;
      (*this)[make_pair(307, 401)] = 12369084;
      (*this)[make_pair(308, 392)] = 16777215;
      (*this)[make_pair(308, 393)] = 16185078;
      (*this)[make_pair(308, 394)] = 12369084;
      (*this)[make_pair(308, 395)] = 12369084;
      (*this)[make_pair(308, 396)] = 12369084;
      (*this)[make_pair(308, 397)] = 12369084;
      (*this)[make_pair(308, 398)] = 12369084;
      (*this)[make_pair(308, 399)] = 12369084;
      (*this)[make_pair(308, 400)] = 12369084;
      (*this)[make_pair(308, 401)] = 12369084;
      (*this)[make_pair(309, 392)] = 16777215;
      (*this)[make_pair(309, 393)] = 16777215;
      (*this)[make_pair(309, 394)] = 16777215;
      (*this)[make_pair(309, 395)] = 16777215;
      (*this)[make_pair(309, 396)] = 16777215;
      (*this)[make_pair(309, 397)] = 16777215;
      (*this)[make_pair(309, 398)] = 16777215;
      (*this)[make_pair(309, 399)] = 16777215;
      (*this)[make_pair(309, 400)] = 16777215;
      (*this)[make_pair(309, 401)] = 16777215;
      (*this)[make_pair(310, 392)] = 16777215;
      (*this)[make_pair(310, 393)] = 16777215;
      (*this)[make_pair(310, 394)] = 16777215;
      (*this)[make_pair(310, 395)] = 16777215;
      (*this)[make_pair(310, 396)] = 16777215;
      (*this)[make_pair(310, 397)] = 16777215;
      (*this)[make_pair(310, 398)] = 16777215;
      (*this)[make_pair(310, 399)] = 16777215;
      (*this)[make_pair(310, 400)] = 16777215;
      (*this)[make_pair(310, 401)] = 16777215;
      (*this)[make_pair(311, 392)] = 16777215;
      (*this)[make_pair(311, 393)] = 16777215;
      (*this)[make_pair(311, 394)] = 16777215;
      (*this)[make_pair(311, 395)] = 16777215;
      (*this)[make_pair(311, 396)] = 16777215;
      (*this)[make_pair(311, 397)] = 16777215;
      (*this)[make_pair(311, 398)] = 16777215;
      (*this)[make_pair(311, 399)] = 16777215;
      (*this)[make_pair(311, 400)] = 16777215;
      (*this)[make_pair(311, 401)] = 16777215;
      (*this)[make_pair(312, 392)] = 16777215;
      (*this)[make_pair(312, 393)] = 15987699;
      (*this)[make_pair(312, 394)] = 10724259;
      (*this)[make_pair(312, 395)] = 10132122;
      (*this)[make_pair(312, 396)] = 9605778;
      (*this)[make_pair(312, 397)] = 9013641;
      (*this)[make_pair(312, 398)] = 16185078;
      (*this)[make_pair(312, 399)] = 16777215;
      (*this)[make_pair(312, 400)] = 16316664;
      (*this)[make_pair(312, 401)] = 10000536;
      (*this)[make_pair(313, 392)] = 16777215;
      (*this)[make_pair(313, 393)] = 15329769;
      (*this)[make_pair(313, 394)] = 9737364;
      (*this)[make_pair(313, 395)] = 14935011;
      (*this)[make_pair(313, 396)] = 15592941;
      (*this)[make_pair(313, 397)] = 9013641;
      (*this)[make_pair(313, 398)] = 16711422;
      (*this)[make_pair(313, 399)] = 16777215;
      (*this)[make_pair(313, 400)] = 16777215;
      (*this)[make_pair(313, 401)] = 9145227;
      (*this)[make_pair(314, 392)] = 16777215;
      (*this)[make_pair(314, 393)] = 15329769;
      (*this)[make_pair(314, 394)] = 10592673;
      (*this)[make_pair(314, 395)] = 16777215;
      (*this)[make_pair(314, 396)] = 16119285;
      (*this)[make_pair(314, 397)] = 10197915;
      (*this)[make_pair(314, 398)] = 16777215;
      (*this)[make_pair(314, 399)] = 16777215;
      (*this)[make_pair(314, 400)] = 16777215;
      (*this)[make_pair(314, 401)] = 9474192;
      (*this)[make_pair(315, 392)] = 16777215;
      (*this)[make_pair(315, 393)] = 15329769;
      (*this)[make_pair(315, 394)] = 10592673;
      (*this)[make_pair(315, 395)] = 16777215;
      (*this)[make_pair(315, 396)] = 16777215;
      (*this)[make_pair(315, 397)] = 9408399;
      (*this)[make_pair(315, 398)] = 15461355;
      (*this)[make_pair(315, 399)] = 16711422;
      (*this)[make_pair(315, 400)] = 14013909;
      (*this)[make_pair(315, 401)] = 10197915;
      (*this)[make_pair(316, 392)] = 16777215;
      (*this)[make_pair(316, 393)] = 15790320;
      (*this)[make_pair(316, 394)] = 12500670;
      (*this)[make_pair(316, 395)] = 16777215;
      (*this)[make_pair(316, 396)] = 16777215;
      (*this)[make_pair(316, 397)] = 14211288;
      (*this)[make_pair(316, 398)] = 9408399;
      (*this)[make_pair(316, 399)] = 8158332;
      (*this)[make_pair(316, 400)] = 10658466;
      (*this)[make_pair(316, 401)] = 15198183;
      (*this)[make_pair(317, 392)] = 16777215;
      (*this)[make_pair(317, 393)] = 16777215;
      (*this)[make_pair(317, 394)] = 16777215;
      (*this)[make_pair(317, 395)] = 16777215;
      (*this)[make_pair(317, 396)] = 16777215;
      (*this)[make_pair(317, 397)] = 16777215;
      (*this)[make_pair(317, 398)] = 16777215;
      (*this)[make_pair(317, 399)] = 16777215;
      (*this)[make_pair(317, 400)] = 16777215;
      (*this)[make_pair(317, 401)] = 16777215;
      (*this)[make_pair(318, 392)] = 16777215;
      (*this)[make_pair(318, 393)] = 16777215;
      (*this)[make_pair(318, 394)] = 16777215;
      (*this)[make_pair(318, 395)] = 16777215;
      (*this)[make_pair(318, 396)] = 16777215;
      (*this)[make_pair(318, 397)] = 16777215;
      (*this)[make_pair(318, 398)] = 16316664;
      (*this)[make_pair(318, 399)] = 16645629;
      (*this)[make_pair(318, 400)] = 16777215;
      (*this)[make_pair(318, 401)] = 16777215;
      (*this)[make_pair(319, 392)] = 16777215;
      (*this)[make_pair(319, 393)] = 16777215;
      (*this)[make_pair(319, 394)] = 16777215;
      (*this)[make_pair(319, 395)] = 16777215;
      (*this)[make_pair(319, 396)] = 16777215;
      (*this)[make_pair(319, 397)] = 16777215;
      (*this)[make_pair(319, 398)] = 11711154;
      (*this)[make_pair(319, 399)] = 14869218;
      (*this)[make_pair(319, 400)] = 16777215;
      (*this)[make_pair(319, 401)] = 16777215;
      (*this)[make_pair(320, 392)] = 16777215;
      (*this)[make_pair(320, 393)] = 16777215;
      (*this)[make_pair(320, 394)] = 16777215;
      (*this)[make_pair(320, 395)] = 16777215;
      (*this)[make_pair(320, 396)] = 16777215;
      (*this)[make_pair(320, 397)] = 16777215;
      (*this)[make_pair(320, 398)] = 11711154;
      (*this)[make_pair(320, 399)] = 14869218;
      (*this)[make_pair(320, 400)] = 16777215;
      (*this)[make_pair(320, 401)] = 16777215;
      (*this)[make_pair(321, 392)] = 16777215;
      (*this)[make_pair(321, 393)] = 16777215;
      (*this)[make_pair(321, 394)] = 16777215;
      (*this)[make_pair(321, 395)] = 16777215;
      (*this)[make_pair(321, 396)] = 16777215;
      (*this)[make_pair(321, 397)] = 16777215;
      (*this)[make_pair(321, 398)] = 11711154;
      (*this)[make_pair(321, 399)] = 14869218;
      (*this)[make_pair(321, 400)] = 16777215;
      (*this)[make_pair(321, 401)] = 16777215;
      (*this)[make_pair(322, 392)] = 16777215;
      (*this)[make_pair(322, 393)] = 16777215;
      (*this)[make_pair(322, 394)] = 16777215;
      (*this)[make_pair(322, 395)] = 16777215;
      (*this)[make_pair(322, 396)] = 16777215;
      (*this)[make_pair(322, 397)] = 16777215;
      (*this)[make_pair(322, 398)] = 15329769;
      (*this)[make_pair(322, 399)] = 16250871;
      (*this)[make_pair(322, 400)] = 16777215;
      (*this)[make_pair(322, 401)] = 16777215;
      (*this)[make_pair(323, 392)] = 16777215;
      (*this)[make_pair(323, 393)] = 16777215;
      (*this)[make_pair(323, 394)] = 16777215;
      (*this)[make_pair(323, 395)] = 16777215;
      (*this)[make_pair(323, 396)] = 16777215;
      (*this)[make_pair(323, 397)] = 16777215;
      (*this)[make_pair(323, 398)] = 16777215;
      (*this)[make_pair(323, 399)] = 16777215;
      (*this)[make_pair(323, 400)] = 16777215;
      (*this)[make_pair(323, 401)] = 16711422;
      (*this)[make_pair(324, 392)] = 16777215;
      (*this)[make_pair(324, 393)] = 16777215;
      (*this)[make_pair(324, 394)] = 10790052;
      (*this)[make_pair(324, 395)] = 15724527;
      (*this)[make_pair(324, 396)] = 16777215;
      (*this)[make_pair(324, 397)] = 16777215;
      (*this)[make_pair(324, 398)] = 16777215;
      (*this)[make_pair(324, 399)] = 16777215;
      (*this)[make_pair(324, 400)] = 14540253;
      (*this)[make_pair(324, 401)] = 7039851;
      (*this)[make_pair(325, 392)] = 16777215;
      (*this)[make_pair(325, 393)] = 16777215;
      (*this)[make_pair(325, 394)] = 9013641;
      (*this)[make_pair(325, 395)] = 16777215;
      (*this)[make_pair(325, 396)] = 16777215;
      (*this)[make_pair(325, 397)] = 16777215;
      (*this)[make_pair(325, 398)] = 16777215;
      (*this)[make_pair(325, 399)] = 15329769;
      (*this)[make_pair(325, 400)] = 8816262;
      (*this)[make_pair(325, 401)] = 8553090;
      (*this)[make_pair(326, 392)] = 16777215;
      (*this)[make_pair(326, 393)] = 16119285;
      (*this)[make_pair(326, 394)] = 9737364;
      (*this)[make_pair(326, 395)] = 16777215;
      (*this)[make_pair(326, 396)] = 16777215;
      (*this)[make_pair(326, 397)] = 16777215;
      (*this)[make_pair(326, 398)] = 15198183;
      (*this)[make_pair(326, 399)] = 8684676;
      (*this)[make_pair(326, 400)] = 15329769;
      (*this)[make_pair(326, 401)] = 9342606;
      (*this)[make_pair(327, 392)] = 16777215;
      (*this)[make_pair(327, 393)] = 16777215;
      (*this)[make_pair(327, 394)] = 9276813;
      (*this)[make_pair(327, 395)] = 14145495;
      (*this)[make_pair(327, 396)] = 15395562;
      (*this)[make_pair(327, 397)] = 11382189;
      (*this)[make_pair(327, 398)] = 8618883;
      (*this)[make_pair(327, 399)] = 15132390;
      (*this)[make_pair(327, 400)] = 16777215;
      (*this)[make_pair(327, 401)] = 9342606;
      (*this)[make_pair(328, 392)] = 16777215;
      (*this)[make_pair(328, 393)] = 16777215;
      (*this)[make_pair(328, 394)] = 14803425;
      (*this)[make_pair(328, 395)] = 10197915;
      (*this)[make_pair(328, 396)] = 9013641;
      (*this)[make_pair(328, 397)] = 12566463;
      (*this)[make_pair(328, 398)] = 16119285;
      (*this)[make_pair(328, 399)] = 16777215;
      (*this)[make_pair(328, 400)] = 16777215;
      (*this)[make_pair(328, 401)] = 9803157;
      (*this)[make_pair(329, 392)] = 16777215;
      (*this)[make_pair(329, 393)] = 16777215;
      (*this)[make_pair(329, 394)] = 16777215;
      (*this)[make_pair(329, 395)] = 16777215;
      (*this)[make_pair(329, 396)] = 16777215;
      (*this)[make_pair(329, 397)] = 16777215;
      (*this)[make_pair(329, 398)] = 16777215;
      (*this)[make_pair(329, 399)] = 16777215;
      (*this)[make_pair(329, 400)] = 16777215;
      (*this)[make_pair(329, 401)] = 16777215;
      (*this)[make_pair(330, 392)] = 16777215;
      (*this)[make_pair(330, 393)] = 16777215;
      (*this)[make_pair(330, 394)] = 16777215;
      (*this)[make_pair(330, 395)] = 16448250;
      (*this)[make_pair(330, 396)] = 13816530;
      (*this)[make_pair(330, 397)] = 15921906;
      (*this)[make_pair(330, 398)] = 16777215;
      (*this)[make_pair(330, 399)] = 16777215;
      (*this)[make_pair(330, 400)] = 16777215;
      (*this)[make_pair(330, 401)] = 16777215;
      (*this)[make_pair(331, 392)] = 16777215;
      (*this)[make_pair(331, 393)] = 16777215;
      (*this)[make_pair(331, 394)] = 13290186;
      (*this)[make_pair(331, 395)] = 8618883;
      (*this)[make_pair(331, 396)] = 10987431;
      (*this)[make_pair(331, 397)] = 8947848;
      (*this)[make_pair(331, 398)] = 11119017;
      (*this)[make_pair(331, 399)] = 16777215;
      (*this)[make_pair(331, 400)] = 16777215;
      (*this)[make_pair(331, 401)] = 11184810;
      (*this)[make_pair(332, 392)] = 16777215;
      (*this)[make_pair(332, 393)] = 16777215;
      (*this)[make_pair(332, 394)] = 9474192;
      (*this)[make_pair(332, 395)] = 16579836;
      (*this)[make_pair(332, 396)] = 16777215;
      (*this)[make_pair(332, 397)] = 16777215;
      (*this)[make_pair(332, 398)] = 9868950;
      (*this)[make_pair(332, 399)] = 15987699;
      (*this)[make_pair(332, 400)] = 16777215;
      (*this)[make_pair(332, 401)] = 9671571;
      (*this)[make_pair(333, 392)] = 16777215;
      (*this)[make_pair(333, 393)] = 16250871;
      (*this)[make_pair(333, 394)] = 10197915;
      (*this)[make_pair(333, 395)] = 16777215;
      (*this)[make_pair(333, 396)] = 16777215;
      (*this)[make_pair(333, 397)] = 16777215;
      (*this)[make_pair(333, 398)] = 12171705;
      (*this)[make_pair(333, 399)] = 14935011;
      (*this)[make_pair(333, 400)] = 16711422;
      (*this)[make_pair(333, 401)] = 8553090;
      (*this)[make_pair(334, 392)] = 16777215;
      (*this)[make_pair(334, 393)] = 16777215;
      (*this)[make_pair(334, 394)] = 10790052;
      (*this)[make_pair(334, 395)] = 15921906;
      (*this)[make_pair(334, 396)] = 16777215;
      (*this)[make_pair(334, 397)] = 16514043;
      (*this)[make_pair(334, 398)] = 11382189;
      (*this)[make_pair(334, 399)] = 16579836;
      (*this)[make_pair(334, 400)] = 12763842;
      (*this)[make_pair(334, 401)] = 9605778;
    }
  } s1529;
  map<pair<int, int>, int> table1529;
  void update_table1529()
  {
    for (const auto& x : s1529) {
      auto pos = x.first;
      pos.first += gen_button.first - 450;
      pos.second += gen_button.second - 480;
      table1529[pos] = x.second;
    }
  }
  int man_bottom = 515;
  int man_top = 348;
  int woman_bottom = 516;
  int woman_top = 516 + 515 - 348;
  int start_y = 392;
  void update()
  {
    update_table20();
    update_table40();
    update_table20();
    update_table10();
    update_table100();
    update_table1529();
    update_table1539();
    update_table1549();
    update_table1579();
    man_bottom += gen_button.first - 450;
    man_top += gen_button.first - 450;
    woman_bottom += gen_button.first - 450;
    woman_top += gen_button.first - 450;
    start_y += gen_button.second - 480;
  }
  inline bool check(pair<pair<int,int>, int> p, XImage* in_image)
  {
    auto point = p.first;
    auto x = point.first;
    auto y = point.second;
    auto exp = p.second;
    auto pix = XGetPixel(in_image, x, y);
    if (exp == pix)
      return false;  // OK. match
    return true; // mismatch
  }
  int yscale(XImage* in_image)
  {
    {
      // check if "20%"
      //           ^^
      assert(!table20.empty());
      auto p = find_if(begin(table20), end(table20),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table20))
	return 20;
    }
    {
      // check if "40%"
      //           ^^
      assert(!table40.empty());
      auto p = find_if(begin(table40), end(table40),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table40))
	return 40;
    }
    {
      // check if "10%"
      //           ^^
      assert(!table10.empty());
      auto p = find_if(begin(table10), end(table10),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table10))
	return 10;
    }
    {
      // check if "100%"
      //           ^^
      assert(!table100.empty());
      auto p = find_if(begin(table100), end(table100),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table100))
	return 100;
    }
    asm("int3");
    return -1;
  }
  int num_item(XImage* in_image)
  {
    {
      // check if "15-29"
      assert(!table1529.empty());
      auto p = find_if(begin(table1529), end(table1529),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table1529))
	return 6;  // 15-29, 30-39, 40-49, 50-59, 60-69, 70-79
    }
    {
      // check if "15-49"
      assert(!table1549.empty());
      auto p = find_if(begin(table1549), end(table1549),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table1549))
	return 2;  // 15-49, 50-79
    }
    {
      // check if "15-39"
      assert(!table1539.empty());
      auto p = find_if(begin(table1539), end(table1539),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table1539))
	return 3;  // 15-39, 40-59, 60-79
    }
    {
      // check if "15-79"
      assert(!table1579.empty());
      auto p = find_if(begin(table1579), end(table1579),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table1579))
	return 1;  // 15-79
    }
    asm("int3");
    return 0;
  }
  inline int get_man(int y, XImage* in_image)
  {
    for (int x = man_top ; x != man_bottom ; ++x) {
      if (XGetPixel(in_image, x, y) == sky_blue)
	return x;
    }
    asm("int3");
    return -1;
  }
  inline int get_woman(int y, XImage* in_image)
  {
    for (int x = woman_bottom+1 ; x != man_top ; ++x) {
      if (XGetPixel(in_image, x, y) == 0xffffff)
	return x;
    }
    asm("int3");
    return -1;
  }
  inline int man_value(int i, int yscale, int delta, XImage* in_image)
  {
    int y = start_y - i * delta;
    int x = get_man(y, in_image);
    double a = man_bottom - x;
    double b = man_bottom - man_top;
    return a/b * yscale;
  }
  inline int woman_value(int i, int yscale, int delta, XImage* in_image)
  {
    int y = start_y - i * delta;
    int x = get_woman(y, in_image);
    double a = x - woman_bottom;
    double b = woman_top - woman_bottom;
    return a/b * yscale;
  }
  pair<double, double> coord;
  inline int calc_t(int h)
  {
    timeval res;
    gettimeofday(&res, nullptr);
    auto tm = localtime(&res.tv_sec);
    auto t = res.tv_sec;
    t -= tm->tm_sec;
    t -= tm->tm_min * 60;
    auto d = tm->tm_hour - h;
    if (d < 0)
      d += 24;
    assert(d >= 0);
    t -= d * 3600;
    return t;
  }
  inline string out_header()
  {
    cout << "#include <map>\n";
    cout << "#include <vector>\n";
    cout << "#include <tuple>\n";
    cout << "using namespace std;\n\n";
    cout << "struct info_t {\n";
    cout << "  map<int, int> tm;\n";
    cout << "  vector<pair<int, int> > gn;\n";
    cout << "  tuple<int, int, int> pl;\n";
    cout << "};\n";
    cout << "extern map<pair<double, double>, info_t> ";
    string vn = "g_crow_data";
    cout << vn << ";\n\n";
    ostringstream os;
    auto x = coord.first;
    auto y = coord.second;
    auto t = calc_t(14);   // any value is OK (14, 15, ...)
    os << '_' << x << '_' << y << '_' << t;
    string tn = "gn" + os.str();
    auto p = tn.find_first_of('.');
    if (p != string::npos)
      tn[p] = 'd';
    auto q = tn.find_first_of('.', p+1);
    if (q != string::npos)
      tn[q] = 'd';
    cout << "struct " << tn << " {\n";
    cout << "  " << tn << "()\n";
    cout << "  " << "{\n";
    cout << "  " << "  auto& table = " << vn;
    cout << "[make_pair(" << x << ',' << y << ")].gn;\n";
    return tn;
  }
  inline void out_footer(string name)
  {
    cout << "  " << "}\n";
    cout << "} " << name << ";\n";
  }
  inline void out_data(int i, int yscale, int delta, XImage* in_image)
  {
    int a = man_value(i, yscale, delta, in_image);
    int b = woman_value(i, yscale, delta, in_image);
    cout << "    ";
    cout << "table.push_back({" << a << ',' << b << "});\n";
  }
  inline int calc_delta(int nitem)
  {
    switch (nitem) {
    case 6: return 28;
    case 3: return 60;
    case 2: return 100;
    case 1:
    default: return 0;
    }
  }
} // end of namespace mine

static Atom wm_protocols;
static Atom wm_delete_window;
static int split;

static char *progname;

static void usage(void);
static Bool Read(char *ptr, int size, int nitems, FILE *stream);
static void putImage(Display *dpy, Window image_win, GC gc, 
		     XImage *out_image, int x, int y, int w, int h);
static void putScaledImage(Display *display, Drawable d, GC gc, 
			   XImage *src_image, int exp_x, int exp_y, 
			   unsigned int exp_width, unsigned int exp_height, 
			   unsigned int dest_width, unsigned dest_height);
static void Latin1Upper(char *s);
static void Extract_Plane(XImage *in_image, XImage *out_image, int plane);
static int EffectiveSize(XVisualInfo *vinfo);
static int VisualRank(int);
static int IsGray(Display *dpy, XStandardColormap *stdmap);
static void Do_StdGray(Display *dpy, XStandardColormap *stdmap, int ncolors, 
		       XColor *colors, XImage *in_image, XImage *out_image);
static void Do_StdCol(Display *dpy, XStandardColormap *stdmap, int ncolors, 
		      XColor *colors, XImage *in_image, XImage *out_image);
static Colormap CopyColormapAndFree(Display *dpy, Colormap colormap);
static void Do_Pseudo(Display *dpy, Colormap *colormap, int ncolors, 
		      XColor *colors, XImage *in_image, XImage *out_image);
static void Do_Direct(Display *dpy, XWDFileHeader *header, Colormap *colormap, 
		      int ncolors, XColor *colors, 
		      XImage *in_image, XImage *out_image, XVisualInfo *vinfo);
static unsigned int Image_Size(XImage *image);
static void Error(const char *string) _X_NORETURN;
static void _swapshort(char *bp, unsigned int n);
static void _swaplong(char *bp, unsigned int n);
static void DumpHeader(const XWDFileHeader *header, const char *win_name);

static void
usage(void)
{
    fprintf(stderr, "usage: %s [-in <file>] [-noclick] [-geometry <geom>] [-display <display>]\n", progname);
    fprintf(stderr, "            [-new] [-std <maptype>] [-raw] [-vis <vis-type-or-id>]\n");
    fprintf(stderr, "            [-help] [-rv] [-plane <number>] [-fg <color>] [-bg <color>]\n");
    fprintf(stderr, "            [-scale]\n");
    exit(1);
}

static Bool
Read(char *ptr, int size, int nitems, FILE *stream)
{
    size *= nitems;
    while (size) {
	nitems = fread(ptr, 1, size, stream);
	if (nitems <= 0)
	    return False;
	size -= nitems;
	ptr += nitems;
    }
    return True;
}

int 
main(int argc, char *argv[])
{
    Display *dpy;
    int screen;
    register int i;
    XImage in_image_struct;
    XImage *in_image, *out_image;
    XSetWindowAttributes attributes;
    XVisualInfo vinfo, *vinfos;
    long mask;
    register char *buffer;
    unsigned long swaptest = 1;
    int count, stdcnt;
    unsigned buffer_size;
    int win_name_size;
    int ncolors;
    char *file_name = NULL;
    char *win_name;
    Bool inverse = False, rawbits = False, newmap = False;
    Bool onclick = True;
    Bool scale = False;
    int plane = -1;
    char *std = NULL;
    char *vis = NULL;
    char *display_name = NULL;
    char *fgname = NULL;
    char *bgname = NULL;
    char *geom = NULL;
    int gbits = 0;
    XSizeHints hints;
    XTextProperty textprop;
    XClassHint class_hint;
    XColor *colors = NULL, color, igncolor;
    Window image_win;
    Colormap colormap;
    XEvent event;
    register XExposeEvent *expose = (XExposeEvent *)&event;
    GC gc;
    XGCValues gc_val;
    XWDFileHeader header;
    XWDColor xwdcolor;
    FILE *in_file = stdin;
    char *map_name;
    Atom map_prop;
    XStandardColormap *stdmaps, *stdmap = NULL;
    char c;
    int win_width, win_height;
    Bool dump_header = False;

    progname = argv[0];

    for (i = 1; i < argc; i++) {
	if (strcmp(argv[i], "-bg") == 0) {
	    if (++i >= argc) usage();
	    bgname = argv[i];
	    continue;
	}
	if (strcmp(argv[i], "-display") == 0) {
	    if (++i >= argc) usage();
	    display_name = argv[i];
	    continue;
	}
	if (strcmp(argv[i], "-dumpheader") == 0) {
	    dump_header = True;
	    continue;
	}
	if (strcmp(argv[i], "-fg") == 0) {
	    if (++i >= argc) usage();
	    fgname = argv[i];
	    continue;
	}
	if (strcmp(argv[i], "-geometry") == 0) {
	    if (++i >= argc) usage();
	    geom = argv[i];
	    continue;
	}
	if (strcmp(argv[i], "-help") == 0) {
	    usage();
	}
	if (strcmp(argv[i], "-in") == 0) {
	    if (++i >= argc) usage();
	    file_name = argv[i];
	    continue;
	}
	if (strcmp(argv[i], "-x") == 0) {
	    if (++i >= argc) usage();
	    char* end;
	    mine::coord.first = strtod(argv[i], &end);
	    continue;
	}
	if (strcmp(argv[i], "-y") == 0) {
	    if (++i >= argc) usage();
	    char* end;
	    mine::coord.second = strtod(argv[i], &end);
	    continue;
	}
	if (strcmp(argv[i], "-inverse") == 0) { /* for compatibility */
	    inverse = True;
	    continue;
	}
	if (strcmp(argv[i], "-new") == 0) {
	    newmap = True;
	    if (std) usage();
	    continue;
	}
	if (strcmp(argv[i], "-noclick") == 0) {
	    onclick = False;
	    continue;
	}
	if (strcmp(argv[i], "-plane") == 0) {
	    if (++i >= argc) usage();
	    plane = atoi(argv[i]);
	    continue;
	}
	if (strcmp(argv[i], "-raw") == 0) {
	    rawbits = True;
	    if (std) usage();
	    continue;
	}
	if (strcmp(argv[i], "-rv") == 0) {
	    inverse = True;
	    continue;
	}
	if (strcmp(argv[i], "-scale") == 0) {
	    scale = True;
	    continue;
	}
	if (strcmp(argv[i], "-split") == 0) {
	    split = True;
	    continue;
	}
	if (strcmp(argv[i], "-std") == 0) {
	    if (++i >= argc) usage();
	    std = argv[i];
	    if (newmap || rawbits) usage();
	    continue;
	}
	if (strcmp(argv[i], "-vis") == 0) {
	    if (++i >= argc) usage();
	    vis = argv[i];
	    continue;
	}
	usage();
    }
    
    if (file_name) {
	in_file = fopen(file_name, "rb");
	if (in_file == NULL)
	    Error("Can't open input file as specified.");
    }
#ifdef WIN32
    else
	_setmode(fileno(in_file), _O_BINARY);
#endif
    
    dpy = XOpenDisplay(display_name);
    if (dpy == NULL) {
	fprintf(stderr, "%s:  unable to open display \"%s\"\n",
		progname, XDisplayName(display_name));
	exit(1);
    }
    screen = DefaultScreen(dpy);

    /*
     * Read in header information.
     */
    if(!Read((char *)&header, SIZEOF(XWDheader), 1, in_file))
      Error("Unable to read dump file header.");

    if (*(char *) &swaptest)
	_swaplong((char *) &header, SIZEOF(XWDheader));

    /* check to see if the dump file is in the proper format */
    if (header.file_version != XWD_FILE_VERSION) {
	fprintf(stderr,"xwud: XWD file format version mismatch.");
	Error("exiting.");
    }
    if (header.header_size < SIZEOF(XWDheader)) {
	fprintf(stderr,"xwud: XWD header size is too small.");
	Error("exiting.");
    }

    /* alloc window name */
    win_name_size = (header.header_size - SIZEOF(XWDheader));
    if (win_name_size < 1)
      Error("win_name_size");
    if((win_name = (char*)malloc((unsigned) win_name_size + 6)) == NULL)
      Error("Can't malloc window name storage.");
    strcpy(win_name, "xwud: ");

     /* read in window name */
    if(!Read(win_name + 6, sizeof(char), win_name_size, in_file))
      Error("Unable to read window name from dump file.");
    (win_name + 6)[win_name_size - 1] = 0;

    if (dump_header) {
	DumpHeader(&header, win_name);
	exit(0);
    }
   
    /* initialize the input image */

    in_image = &in_image_struct;
    in_image->depth = header.pixmap_depth;
    in_image->format = header.pixmap_format;
    in_image->xoffset = header.xoffset;
    in_image->data = NULL;
    in_image->width = header.pixmap_width;
    in_image->height = header.pixmap_height;
    in_image->bitmap_pad = header.bitmap_pad;
    in_image->bytes_per_line = header.bytes_per_line;
    in_image->byte_order = header.byte_order;
    in_image->bitmap_unit = header.bitmap_unit;
    in_image->bitmap_bit_order = header.bitmap_bit_order;
    in_image->bits_per_pixel = header.bits_per_pixel;
    in_image->red_mask = header.red_mask;
    in_image->green_mask = header.green_mask;
    in_image->blue_mask = header.blue_mask;
    if (!XInitImage(in_image))
	Error("Invalid input image header data.");

    /* read in the color map buffer */
    if((ncolors = header.ncolors)) {
	colors = (XColor *)malloc((unsigned) ncolors * sizeof(XColor));
	if (!colors)
	    Error("Can't malloc color table");
	for (i = 0; i < ncolors; i++) {
	    if(!Read((char *) &xwdcolor, SIZEOF(XWDColor), 1, in_file))
		Error("Unable to read color map from dump file.");
	    colors[i].pixel = xwdcolor.pixel;
	    colors[i].red = xwdcolor.red;
	    colors[i].green = xwdcolor.green;
	    colors[i].blue = xwdcolor.blue;
	    colors[i].flags = xwdcolor.flags;
	}
	if (*(char *) &swaptest) {
	    for (i = 0; i < ncolors; i++) {
		_swaplong((char *) &colors[i].pixel, sizeof(long));
		_swapshort((char *) &colors[i].red, 3 * sizeof(short));
	    }
	}
    }
    else
	/* no color map exists, turn on the raw option */
	rawbits = True;

    /* alloc the pixel buffer */
    buffer_size = Image_Size(in_image);
    if((buffer = (char*)malloc(buffer_size)) == NULL)
      Error("Can't malloc data buffer.");

    /* read in the image data */
    if (!Read(buffer, sizeof(char), (int)buffer_size, in_file))
        Error("Unable to read pixmap from dump file.");

     /* close the input file */
    (void) fclose(in_file);

    if (plane >= in_image->depth)
	Error("plane number exceeds image depth");
    if ((in_image->format == XYPixmap) && (plane >= 0)) {
	buffer += in_image->bytes_per_line * in_image->height *
		  (in_image->depth - (plane + 1));
	in_image->depth = 1;
	ncolors = 0;
    }
    if (in_image->bits_per_pixel == 1 && in_image->depth == 1) {
	in_image->format = XYBitmap;
	newmap = False;
	rawbits = True;
    }
    in_image->data = buffer;

    if (std) {
      map_name = (char*)malloc(strlen(std) + 9);
	strcpy(map_name, "RGB_");
	strcat(map_name, std);
	strcat(map_name, "_MAP");
	Latin1Upper(map_name);
	map_prop = XInternAtom(dpy, map_name, True);
	if (!map_prop || !XGetRGBColormaps(dpy, RootWindow(dpy, screen),
					   &stdmaps, &stdcnt, map_prop))
	    Error("specified standard colormap does not exist");
    }
    vinfo.screen = screen;
    mask = VisualScreenMask;
    if (vis)
    {
	char *vt = strdup(vis);
	Latin1Upper(vt);
	if (strcmp(vt, "STATICGRAY") == 0) {
	    vinfo.c_class = StaticGray;
	    mask |= VisualClassMask;
	} else if (strcmp(vt, "GRAYSCALE") == 0) {
	    vinfo.c_class = GrayScale;
	    mask |= VisualClassMask;
	} else if (strcmp(vt, "STATICCOLOR") == 0) {
	    vinfo.c_class = StaticColor;
	    mask |= VisualClassMask;
	} else if (strcmp(vt, "PSEUDOCOLOR") == 0) {
	    vinfo.c_class = PseudoColor;
	    mask |= VisualClassMask;
	} else if (strcmp(vt, "DIRECTCOLOR") == 0) {
	    vinfo.c_class = DirectColor;
	    mask |= VisualClassMask;
	} else if (strcmp(vt, "TRUECOLOR") == 0) {
	    vinfo.c_class = TrueColor;
	    mask |= VisualClassMask;
	} else if (strcmp(vt, "MATCH") == 0) {
	    vinfo.c_class = header.visual_class;
	    mask |= VisualClassMask;
	} else if (strcmp(vt, "DEFAULT") == 0) {
	    vinfo.visualid= XVisualIDFromVisual(DefaultVisual(dpy, screen));
	    mask |= VisualIDMask;
	} else {
	    vinfo.visualid = 0;
	    mask |= VisualIDMask;
	    sscanf(vis, "0x%lx", &vinfo.visualid);
	    if (!vinfo.visualid)
	      sscanf(vis, "%lu", &vinfo.visualid);
	    if (!vinfo.visualid)
	      Error("invalid visual specifier");
	}
    }
    if (rawbits && (in_image->depth > 1) && (plane < 0)) {
	vinfo.depth = in_image->depth;
	mask |= VisualDepthMask;
    }
    vinfos = XGetVisualInfo(dpy, mask, &vinfo, &count);
    if (count == 0)
	Error("no matching visual found");

    /* find a workable visual */
    if (std) {
	stdmap = &stdmaps[0];
	if (mask & VisualIDMask) {
	    for (i = 0; i < stdcnt; i++) {
		if (stdmaps[i].visualid == vinfo.visualid) {
		    stdmap = &stdmaps[i];
		    break;
		}
	    }
	    if (stdmap->visualid != vinfo.visualid)
		Error("no standard colormap matching specified visual");
	}
	for (i = 0; i < count; i++) {
	    if (stdmap->visualid == vinfos[i].visualid) {
		vinfo = vinfos[i];
		break;
	    }
	}
    } else if ((in_image->depth == 1) ||
	       ((in_image->format == ZPixmap) && (plane >= 0)) ||
	       rawbits) {
	vinfo = vinfos[0];
	if (!(mask & VisualIDMask)) {
	    for (i = 0; i < count; i++) {
		if ((vinfos[i].visualid ==
		     XVisualIDFromVisual(DefaultVisual(dpy, screen))) &&
		    (vinfos[i].depth == DefaultDepth(dpy, screen))) {
		    vinfo = vinfos[i];
		    break;
		}
	    }
	}
    } else {
	/* get best visual */
	vinfo = vinfos[0];
	for (i = 0; i < count; i++) {
	    int z1, z2;
	    z2 = EffectiveSize(&vinfos[i]);
	    if ((z2 >= ncolors) &&
		(vinfos[i].depth == in_image->depth) &&
		(vinfos[i].c_class == header.visual_class))
	    {
		vinfo = vinfos[i];
		break;
	    }
	    z1 = EffectiveSize(&vinfo);
	    if ((z2 > z1) ||
		((z2 == z1) &&
		 (VisualRank(vinfos[i].c_class) >= VisualRank(vinfo.c_class))))
		vinfo = vinfos[i];
	}
	if ((newmap || (vinfo.visual != DefaultVisual(dpy, screen))) &&
	    (vinfo.c_class != StaticGray) &&
	    (vinfo.c_class != StaticColor) &&
	    (vinfo.c_class == header.visual_class) &&
	    (vinfo.depth == in_image->depth) &&
	    ((vinfo.c_class == PseudoColor) ||
	     (vinfo.c_class == GrayScale) ||
	     ((vinfo.red_mask == header.red_mask) &&
	      (vinfo.green_mask == header.green_mask) &&
	      (vinfo.blue_mask == header.blue_mask)))) {
	    rawbits = True;
	    newmap = True;
	}
    }

    /* get the appropriate colormap */
    if (newmap && (vinfo.c_class & 1) &&
	(vinfo.depth == in_image->depth) &&
	(vinfo.c_class == header.visual_class) &&
	(vinfo.colormap_size >= ncolors) &&
	(vinfo.red_mask == header.red_mask) &&
	(vinfo.green_mask == header.green_mask) &&
	(vinfo.blue_mask == header.blue_mask)) {
	colormap = XCreateColormap(dpy, RootWindow(dpy, screen), vinfo.visual,
				   AllocAll);
	if (ncolors) {
	    for (i = 0; i < ncolors; i++)
		colors[i].flags = DoRed|DoGreen|DoBlue;
	    XStoreColors(dpy, colormap, colors, ncolors);
	}
    } else if (std) {
	colormap = stdmap->colormap;
    } else {
	if (!newmap && (vinfo.visual == DefaultVisual(dpy, screen)))
	    colormap = DefaultColormap(dpy, screen);
	else
	    colormap = XCreateColormap(dpy, RootWindow(dpy, screen),
				       vinfo.visual, AllocNone);
	newmap = False;
    }

    /* create the output image */
    if ((in_image->format == ZPixmap) && (plane >= 0)) {
	out_image = XCreateImage(dpy, vinfo.visual, 1,
				 XYBitmap, 0, NULL,
				 in_image->width, in_image->height,
				 XBitmapPad(dpy), 0);
	out_image->data = (char*)malloc(Image_Size(out_image));
	Extract_Plane(in_image, out_image, plane);
	ncolors = 0;
    } else if (rawbits || newmap) {
	out_image = in_image;
    } else {
	out_image = XCreateImage(dpy, vinfo.visual, vinfo.depth,
				 (vinfo.depth == 1) ? XYBitmap :
						      in_image->format,
				 in_image->xoffset, NULL,
				 in_image->width, in_image->height,
				 XBitmapPad(dpy), 0);
	out_image->data = (char*)malloc(Image_Size(out_image));
	if (std) {
	    if (!stdmap->green_max && !stdmap->blue_max && IsGray(dpy, stdmap))
		Do_StdGray(dpy, stdmap, ncolors, colors, in_image, out_image);
	    else
		Do_StdCol(dpy, stdmap, ncolors, colors, in_image, out_image);
	} else if ((header.visual_class == TrueColor) ||
		   (header.visual_class == DirectColor))
	    Do_Direct(dpy, &header, &colormap, ncolors, colors,
		      in_image, out_image, &vinfo);
	else
	    Do_Pseudo(dpy, &colormap, ncolors, colors, in_image, out_image);
    }

    if (out_image->depth == 1) {
	if (fgname &&
	    XAllocNamedColor(dpy, colormap, fgname, &color, &igncolor))
	    gc_val.foreground = color.pixel;
	else if ((ncolors == 2) && XAllocColor(dpy, colormap, &colors[1]))
	    gc_val.foreground = colors[1].pixel;
	else
	    gc_val.foreground = BlackPixel (dpy, screen);
	if (bgname &&
	    XAllocNamedColor(dpy, colormap, bgname, &color, &igncolor))
	    gc_val.background = color.pixel;
	else if ((ncolors == 2) && XAllocColor(dpy, colormap, &colors[0]))
	    gc_val.background = colors[0].pixel;
	else
	    gc_val.background = WhitePixel (dpy, screen);
	if (inverse) {
	    unsigned long tmp;
	    tmp = gc_val.foreground;
	    gc_val.foreground = gc_val.background;
	    gc_val.background = tmp;
	}
    } else {
	gc_val.background = XGetPixel(out_image, 0, 0);
	gc_val.foreground = 0;
    }

    attributes.background_pixel = gc_val.background;
    attributes.border_pixel = gc_val.background;
    if (scale)
	attributes.bit_gravity = ForgetGravity;
    else
	attributes.bit_gravity = NorthWestGravity;
    attributes.event_mask = ButtonPressMask|ButtonReleaseMask|KeyPressMask|
			    ExposureMask;
    if (scale)
	attributes.event_mask |= StructureNotifyMask;
    attributes.colormap = colormap;

    hints.x = header.window_x;
    hints.y = header.window_y;
    hints.width = out_image->width;
    hints.height = out_image->height;
    if (geom)
	gbits = XParseGeometry(geom, &hints.x, &hints.y,
			       (unsigned int *)&hints.width,
			       (unsigned int *)&hints.height);
    hints.flags = ((gbits & (XValue|YValue)) ? USPosition : 0) |
		  ((gbits & (HeightValue|WidthValue)) ? USSize : PSize);
    if (!scale) {
	hints.flags |= PMaxSize;
	hints.max_width = (hints.width > out_image->width) ?
	    hints.width : out_image->width;
	hints.max_height = (hints.height > out_image->height) ?
	    hints.height : out_image->height;
    }
    if ((gbits & XValue) && (gbits & XNegative))
	hints.x += DisplayWidth(dpy, screen) - hints.width; 
    if ((gbits & YValue) && (gbits & YNegative))
	hints.y += DisplayHeight(dpy, screen) - hints.height;

    /* create the image window */
    image_win = XCreateWindow(dpy, RootWindow(dpy, screen),
			      hints.x, hints.y, hints.width, hints.height,
			      0, vinfo.depth, InputOutput, vinfo.visual,
			      CWBorderPixel|CWBackPixel|CWColormap|CWEventMask|CWBitGravity,
			      &attributes);
    win_width = hints.width;
    win_height = hints.height;

    /* Setup for ICCCM delete window. */
    wm_protocols = XInternAtom(dpy, "WM_PROTOCOLS", False);
    wm_delete_window = XInternAtom(dpy, "WM_DELETE_WINDOW", False);
    (void) XSetWMProtocols (dpy, image_win, &wm_delete_window, 1);
     
    textprop.value = (unsigned char *) win_name;
    textprop.encoding = XA_STRING;
    textprop.format = 8;
    textprop.nitems = strlen(win_name);
    class_hint.res_name = (char *)NULL;
    class_hint.res_class = (char*)"Xwud";
    /* set standard properties */
    XSetWMProperties(dpy, image_win, &textprop, (XTextProperty *)NULL,
		     argv, argc, &hints, (XWMHints *)NULL, &class_hint);

    /* map the image window */
    XMapWindow(dpy, image_win);

    gc = XCreateGC (dpy, image_win, GCForeground|GCBackground, &gc_val);

    while (1) {
	/* wait on mouse input event to terminate */
	XNextEvent(dpy, &event);
	switch(event.type) {
	case ClientMessage:
	  if (event.xclient.message_type == wm_protocols && 
	      event.xclient.data.l[0] == wm_delete_window)  {
	    XCloseDisplay(dpy);
	    exit(0);		/* ICCCM delete window */
	  }
	    break;
	case ButtonPress:
	    break;
	case ButtonRelease:
	    if (onclick) {
		XCloseDisplay(dpy);
		exit(0);
	    }
	    break;
	case KeyPress:
	    i = XLookupString(&event.xkey, &c, 1, NULL, NULL);
	    if ((i == 1) && ((c == 'q') || (c == 'Q') || (c == '\03'))) {
		XCloseDisplay(dpy);
		exit(0);
	    }
	    break;
	case ConfigureNotify:
	    win_width = event.xconfigure.width;
	    win_height = event.xconfigure.height;
	    break;
	case Expose:
	    if (scale)
		putScaledImage(dpy, image_win, gc, out_image,
			       expose->x, expose->y,
			       expose->width, expose->height,
			       win_width, win_height);
	    else if ((expose->x < out_image->width) &&
		     (expose->y < out_image->height)) {
		if ((out_image->width - expose->x) < expose->width)
		    expose->width = out_image->width - expose->x;
		if ((out_image->height - expose->y) < expose->height)
		    expose->height = out_image->height - expose->y;
		putImage(dpy, image_win, gc, out_image,
			  expose->x, expose->y,
			  expose->width, expose->height);
	    }
	    break;
	}
    }
    exit(0);
}

static void
putImage(Display *dpy, Window image_win, GC gc, XImage *out_image, 
	 int x, int y, int w, int h)
{
#define SPLIT_SIZE  100
    int	t_x, t_y, t_w, t_h;
    if (split) {
    	for (t_y = y; t_y < y + h; t_y += t_h) {
    	    t_h = SPLIT_SIZE;
    	    if (t_y + t_h > y + h)
	    	t_h = y + h - t_y;
    	    for (t_x = x; t_x < x + w; t_x += t_w) {
	    	t_w = SPLIT_SIZE;
	    	if (t_x + t_w > x + w)
	    	    t_w = x + w - t_x;
	    	XPutImage(dpy, image_win, gc, out_image,
		      	  t_x, t_y, t_x, t_y, t_w, t_h);
    	    }
    	}
    } else {
	XPutImage (dpy, image_win, gc, out_image, x, y, x, y, w, h);
    }
}

typedef short Position;
typedef unsigned short Dimension;
typedef unsigned long Pixel;

#define roundint(x)                   (int)((x) + 0.5)

typedef struct {
  Position *x, *y;
  Dimension *width, *height;
} Table;

static void
putScaledImage(Display *display, Drawable d, GC gc, XImage *src_image, 
	       int exp_x, int exp_y,
	       unsigned int exp_width, unsigned int exp_height, 
	       unsigned int dest_width, unsigned dest_height)
{
    XImage *dest_image;
    Position x, y, min_y, max_y, exp_max_y, src_x, src_max_x, src_y;
    Dimension w, h, strip_height;
    Table table;    
    Pixel pixel;
    double ratio_x, ratio_y;
    Bool fast8;

    if (dest_width == src_image->width && dest_height == src_image->height) {
	/* same for x and y, just send it out */
	XPutImage(display, d, gc, src_image, exp_x, exp_y, 
		  exp_x, exp_y, exp_width, exp_height); 
	return;
    }

    ratio_x = (double)dest_width / (double)src_image->width;
    ratio_y = (double)dest_height / (double)src_image->height;
 
    src_x = exp_x / ratio_x;
    if (src_x >= src_image->width)
	src_x = src_image->width - 1;
    src_y = exp_y / ratio_y;
    if (src_y >= src_image->height)
	src_y = src_image->height - 1;
    exp_max_y = exp_y + exp_height;
    src_max_x = roundint((exp_x + exp_width) / ratio_x) + 1;
    if (src_max_x > src_image->width)
	src_max_x = src_image->width;

    strip_height = 65536 / roundint(ratio_x * src_image->bytes_per_line);
    if (strip_height == 0)
	strip_height = 1;
    if (strip_height > exp_height)
	strip_height = exp_height;

    h = strip_height + roundint(ratio_y);
    dest_image = XCreateImage(display,
			      DefaultVisualOfScreen(
					     DefaultScreenOfDisplay(display)),
			      src_image->depth, src_image->format, 
			      0, NULL,
			      dest_width, h,
			      src_image->bitmap_pad, 0);
    dest_image->data = (char*)malloc(dest_image->bytes_per_line * h);
    fast8 = (src_image->depth == 8 && src_image->bits_per_pixel == 8 &&
	     dest_image->bits_per_pixel == 8 && src_image->format == ZPixmap);

    table.x = (Position *) malloc(sizeof(Position) * (src_image->width + 1));
    table.y = (Position *) malloc(sizeof(Position) * (src_image->height + 1));
    table.width = (Dimension *) malloc(sizeof(Dimension) * src_image->width);
    table.height = (Dimension *) malloc(sizeof(Dimension)*src_image->height);
    
    table.x[0] = 0;
    for (x = 1; x <= src_image->width; x++) {
	table.x[x] = roundint(ratio_x * x);
	table.width[x - 1] = table.x[x] - table.x[x - 1];
    }

    table.y[0] = 0;
    for (y = 1; y <= src_image->height; y++) {
	table.y[y] = roundint(ratio_y * y);
	table.height[y - 1] = table.y[y] - table.y[y - 1];
    }

    for (min_y = table.y[src_y]; min_y < exp_max_y; min_y = table.y[y]) {
	max_y = min_y + strip_height;
	if (max_y > exp_max_y) {
	    strip_height = exp_max_y - min_y;
	    max_y = exp_max_y;
	}
	for (y = src_y; table.y[y] < max_y; y++) {
	    if (table.y[y] < min_y)
		continue;
	    if (fast8) {
		for (x = src_x; x < src_max_x; x++) {
		    pixel = ((unsigned char *)src_image->data)
			[y * src_image->bytes_per_line + x];
		    for (h = 0; h < table.height[y]; h++) {
			memset(dest_image->data +
			       (table.y[y] + h - min_y) *
			       dest_image->bytes_per_line + table.x[x],
			       pixel, table.width[x]);
		    }
		}
	    } else {
		for (x = src_x; x < src_max_x; x++) {
		    pixel = XGetPixel(src_image, x, y);
		    for (h = 0; h < table.height[y]; h++) {
			for (w = 0; w < table.width[x]; w++)
			    XPutPixel(dest_image,
				      table.x[x] + w,
				      table.y[y] + h - min_y,
				      pixel);
		    }
		}
	    }
	}
	XPutImage(display, d, gc, dest_image, exp_x, 0,
		  exp_x, min_y, exp_width, table.y[y] - min_y);
	if (y >= src_image->height)
	    break;
    }
    
    XFree((char *)table.x);
    XFree((char *)table.y);
    XFree((char *)table.width);
    XFree((char *)table.height);

    XDestroyImage(dest_image);
}

static void
Latin1Upper(char *s)
{
    unsigned char *str = (unsigned char *)s;
    unsigned char c;

    for (; (c = *str); str++)
    {
	if ((c >= XK_a) && (c <= XK_z))
	    *str = c - (XK_a - XK_A);
	else if ((c >= XK_agrave) && (c <= XK_odiaeresis))
	    *str = c - (XK_agrave - XK_Agrave);
	else if ((c >= XK_oslash) && (c <= XK_thorn))
	    *str = c - (XK_oslash - XK_Ooblique);
    }
}

static void
Extract_Plane(XImage *in_image, XImage *out_image, int plane)
{
    register int x, y;

    for (y = 0; y < in_image->height; y++)
	for (x = 0; x < in_image->width; x++)
	    XPutPixel(out_image, x, y,
		      (XGetPixel(in_image, x, y) >> plane) & 1);
}

static int
EffectiveSize(XVisualInfo *vinfo)
{
    if ((vinfo->c_class == DirectColor) || (vinfo->c_class == TrueColor))
	return (vinfo->red_mask | vinfo->green_mask | vinfo->blue_mask) + 1;
    else
	return vinfo->colormap_size;
}

static int
VisualRank(int c_class)
{
    switch (c_class) {
    case PseudoColor:
	return 5;
    case TrueColor:
	return 4;
    case DirectColor:
	return 3;
    case StaticColor:
	return 2;
    case GrayScale:
	return 1;
    case StaticGray:
	return 0;
    }
    /* NOTREACHED */
    return -1;
}

static int
IsGray(Display *dpy, XStandardColormap *stdmap)
{
    XColor color;

    color.pixel = stdmap->base_pixel + (stdmap->red_max * stdmap->red_mult);
    XQueryColor(dpy, stdmap->colormap, &color);
    return (color.green || color.blue);
}

static void 
Do_StdGray(Display *dpy, XStandardColormap *stdmap, 
	   int ncolors, XColor *colors, XImage *in_image, XImage *out_image)
{
    register int i, x, y;
    register XColor *color;
    unsigned lim;

    lim = stdmap->red_max + 1;
    for (i = 0, color = colors; i < ncolors; i++, color++)
	color->pixel = stdmap->base_pixel +
		       (((((int)(30L * color->red +
			         59L * color->green +
			         11L * color->blue) / 100)
			  * lim) >> 16) * stdmap->red_mult);
    for (y = 0; y < in_image->height; y++) {
	for (x = 0; x < in_image->width; x++) {
	    XPutPixel(out_image, x, y,
		      colors[XGetPixel(in_image, x, y)].pixel);
	}
    }
}

#define MapVal(val,lim,mult) ((((val * lim) + 32768) / 65535) * mult)

static void
Do_StdCol(Display *dpy, XStandardColormap *stdmap, 
	  int ncolors, XColor *colors, XImage *in_image, XImage *out_image)
{
    register int i, x, y;
    register XColor *color;
    unsigned limr, limg, limb;

    limr = stdmap->red_max;
    limg = stdmap->green_max;
    limb = stdmap->blue_max;
    for (i = 0, color = colors; i < ncolors; i++, color++)
	color->pixel = stdmap->base_pixel +
		       MapVal(color->red, limr, stdmap->red_mult) +
		       MapVal(color->green, limg, stdmap->green_mult) +
		       MapVal(color->blue, limb, stdmap->blue_mult);
    for (y = 0; y < in_image->height; y++) {
	for (x = 0; x < in_image->width; x++) {
	    XPutPixel(out_image, x, y,
		      colors[XGetPixel(in_image, x, y)].pixel);
	}
    }
}

static Colormap
CopyColormapAndFree(Display *dpy, Colormap colormap)
{
    if (colormap == DefaultColormap(dpy, DefaultScreen(dpy)))
	return XCopyColormapAndFree(dpy, colormap);
    Error("Visual type is not large enough to hold all colors of the image.");
    /*NOTREACHED*/
    return (Colormap)0;
}

static void
Do_Pseudo(Display *dpy, Colormap *colormap, 
	  int ncolors, XColor *colors, XImage *in_image, XImage *out_image)
{
    register int i, x, y;
    register XColor *color;

    for (i = 0; i < ncolors; i++)
	colors[i].flags = 0;
    for (y = 0; y < in_image->height; y++) {
	for (x = 0; x < in_image->width; x++) {
	    color = &colors[XGetPixel(in_image, x, y)];
	    if (!color->flags) {
		color->flags = DoRed | DoGreen | DoBlue;
		if (!XAllocColor(dpy, *colormap, color)) {
		    *colormap = CopyColormapAndFree(dpy, *colormap);
		    XAllocColor(dpy, *colormap, color);
		}
	    }
	    XPutPixel(out_image, x, y, color->pixel);
	}
    }
}

static void
Do_Direct(Display *dpy, XWDFileHeader *header, Colormap *colormap, 
	  int ncolors, XColor *colors, XImage *in_image, XImage *out_image,
          XVisualInfo *vinfo)
{
    register int x, y;
    XColor color;
    unsigned long rmask, gmask, bmask;
    unsigned long ormask, ogmask, obmask;
    unsigned long  rshift = 0, gshift = 0, bshift = 0;
    unsigned long  orshift = 0, ogshift = 0, obshift = 0;
    int i;
    unsigned long pix, xpix;
    unsigned long *pixels, *rpixels;

    rmask = header->red_mask;
    while (!(rmask & 1)) {
	rmask >>= 1;
	rshift++;
    }
    gmask = header->green_mask;
    while (!(gmask & 1)) {
	gmask >>= 1;
	gshift++;
    }
    bmask = header->blue_mask;
    while (!(bmask & 1)) {
	bmask >>= 1;
	bshift++;
    }
    if (in_image->depth <= 12) {
	pix = 1 << in_image->depth;
	pixels = (unsigned long *)malloc(sizeof(unsigned long) * pix);
	if (pixels == NULL)
	    Error("Unable to allocate memory for pixel conversion");
	for (i = 0; i < pix; i++)
	    pixels[i] = ~0L;
	color.flags = DoRed | DoGreen | DoBlue;
	for (y = 0; y < in_image->height; y++) {
	    for (x = 0; x < in_image->width; x++) {
		pix = XGetPixel(in_image, x, y);
		if ((color.pixel = pixels[pix]) == ~0L) {
		    color.red = (pix >> rshift) & rmask;
		    color.green = (pix >> gshift) & gmask;
		    color.blue = (pix >> bshift) & bmask;
		    if (ncolors) {
			color.red = colors[color.red].red;
			color.green = colors[color.green].green;
			color.blue = colors[color.blue].blue;
		    } else {
			color.red = (((unsigned long)color.red * 65535) /
				     rmask);
			color.green = (((unsigned long)color.green * 65535) /
				       gmask);
			color.blue = (((unsigned long)color.blue * 65535) /
				      bmask);
		    }
		    if (!XAllocColor(dpy, *colormap, &color)) {
			*colormap = CopyColormapAndFree(dpy, *colormap);
			XAllocColor(dpy, *colormap, &color);
		    }
		    pixels[pix] = color.pixel;
		}
		XPutPixel(out_image, x, y, color.pixel);
	    }
	}
	free(pixels);
    } else if (header->visual_class == TrueColor &&
	       vinfo->c_class == TrueColor) {
	ormask = vinfo->red_mask;
	while (!(ormask & 1)) {
	    ormask >>= 1;
	    orshift++;
	}
	ogmask = vinfo->green_mask;
	while (!(ogmask & 1)) {
	    ogmask >>= 1;
	    ogshift++;
	}
	obmask = vinfo->blue_mask;
	while (!(obmask & 1)) {
	    obmask >>= 1;
	    obshift++;
	}
	if (1) {
	  using namespace mine;
	  find_gen_button(in_image);
	  update();
	  auto ys = yscale(in_image);
	  int n = num_item(in_image);
	  if (n == 1)
	    start_y = 320 + gen_button.second - 480;  // special case
	  int delta = calc_delta(n);
	  auto name = out_header();
	  for (int i = 0 ; i != n ; ++i)
	    out_data(i, ys, delta, in_image);
	  out_footer(name);
	  if (1)
	    exit(0);
	}
	for (y = 0; y < in_image->height; y++) {
	    for (x = 0; x < in_image->width; x++) {
		pix = XGetPixel(in_image, x, y);
		xpix = (((((pix >> rshift) & rmask) * 65535 / rmask)
			 * ormask / 65535) << orshift) |
		       (((((pix >> gshift) & gmask) * 65535 / gmask)
			 * ogmask / 65535) << ogshift) |
		       (((((pix >> bshift) & bmask) * 65535 / bmask)
			 * obmask / 65535) << obshift);
#if 0
		{
		  // man top
		  int X = 348;  // 300 : too small, 350 : a little big
		  int Y = 300;
		  int delta = 100;
		  if (X == x && Y <= y && y < Y+delta) {
		    xpix = 0;
		  }
		}
#endif
#if 0
		{
		  // bottom
		  int X = 515;  // 520 : too big, 510 : too small
		  int Y = 300;
		  int delta = 100;
		  if (X <= x && x <= X+2 && Y <= y && y < Y+delta) {
		    xpix = 0;
		  }
		}
#endif
#if 1
		{
		  // 15-39 at Katsuyama.gen
		  // ^^^^^
		  int X = 305;
		  int Y = 380;  // 365 : a little small
		  int xdelta = 30;
		  int ydelta = 10;
		  if (X <= x && x < X+xdelta && Y <= y && y < Y+ydelta) {
		    mine::s1539[std::make_pair(x,y)] = xpix;
		    xpix = 0;
		  }
		}
#endif
#if 1
		{
		  // 40-59 at Katsuyama.gen
		  // ^^^^^
		  int X = 305;
		  int Y = 330;
		  // 50 : too big, 20 : too small, 30 : a little big
		  
		  int xdelta = 30;
		  int ydelta = 10;
		  if (X <= x && x < X+xdelta && Y <= y && y < Y+ydelta) {
		    xpix = 0;
		  }
		}
#endif
#if 0
		{
		  // 100% at Meikakueki.gen
		  // ^^
		  int X = 673;
		  int Y = 420;
		  int delta = 13;
		  if (X <= x && x < X+delta && Y <= y && y < Y+delta) {
		    mine::s100[std::make_pair(x,y)] = xpix;
		    xpix = 0;
		  }
		}
#endif
		XPutPixel(out_image, x, y, xpix);
	    }
	}
    } else {
	if (header->visual_class == TrueColor)
	    ncolors = 0;
	pix = 1 << 12;
	pixels = (unsigned long *)malloc(sizeof(unsigned long) * pix);
	rpixels = (unsigned long *)malloc(sizeof(unsigned long) * pix);
	if ((pixels == NULL) || (rpixels == NULL))
	    Error("Unable to allocate memory for pixel conversion");
	for (i = 0; i < pix; i++) {
	    pixels[i] = ~0L;
	    rpixels[i] = ~0L;
	}
	color.flags = DoRed | DoGreen | DoBlue;
	for (y = 0; y < in_image->height; y++) {
	    for (x = 0; x < in_image->width; x++) {
		pix = XGetPixel(in_image, x, y);
		xpix = ((pix >> 12) ^ pix) & ((1 << 12) - 1);
		if (((color.pixel = pixels[xpix]) == ~0L) ||
		    (rpixels[xpix] != pix)) {
		    color.red = (pix >> rshift) & rmask;
		    color.green = (pix >> gshift) & gmask;
		    color.blue = (pix >> bshift) & bmask;
		    if (ncolors) {
			color.red = colors[color.red].red;
			color.green = colors[color.green].green;
			color.blue = colors[color.blue].blue;
		    } else {
			color.red = (((unsigned long)color.red * 65535) /
				     rmask);
			color.green = (((unsigned long)color.green * 65535) /
				       gmask);
			color.blue = (((unsigned long)color.blue * 65535) /
				      bmask);
		    }
		    if (!XAllocColor(dpy, *colormap, &color)) {
			*colormap = CopyColormapAndFree(dpy, *colormap);
			XAllocColor(dpy, *colormap, &color);
		    }
		    pixels[xpix] = color.pixel;
		    rpixels[xpix] = pix;
		}
		XPutPixel(out_image, x, y, color.pixel);
	    }
	}
	free(pixels);
	free(rpixels);
    }
}

static unsigned int 
Image_Size(XImage *image)
{
    if (image->format != ZPixmap)
      return(image->bytes_per_line * image->height * image->depth);

    return((unsigned)image->bytes_per_line * image->height);
}

static void
Error(const char *string)
{
	fprintf(stderr, "xwud: Error => %s\n", string);
	if (errno != 0) {
		perror("xwud");
		fprintf(stderr, "\n");
	}
	exit(1);
}

static void
_swapshort(char *bp, unsigned int n)
{
    register char c;
    register char *ep = bp + n;

    while (bp < ep) {
	c = *bp;
	*bp = *(bp + 1);
	bp++;
	*bp++ = c;
    }
}

static void
_swaplong(char *bp, unsigned int n)
{
    register char c;
    register char *ep = bp + n;
    register char *sp;

    while (bp < ep) {
	sp = bp + 3;
	c = *sp;
	*sp = *bp;
	*bp++ = c;
	sp = bp + 1;
	c = *sp;
	*sp = *bp;
	*bp++ = c;
	bp += 2;
    }
}

static void
DumpHeader(const XWDFileHeader *header, const char *win_name)
{
	printf("window name:        %s\n", win_name);
	printf("sizeof(XWDheader):  %d\n", (int)sizeof(*header));
	printf("header size:        %d\n", (int)header->header_size);
	printf("file version:       %d\n", (int)header->file_version);
	printf("pixmap format:      %d\n", (int)header->pixmap_format);
	printf("pixmap depth:       %d\n", (int)header->pixmap_depth);
	printf("pixmap width:       %d\n", (int)header->pixmap_width);
	printf("pixmap height:      %d\n", (int)header->pixmap_height);
	printf("x offset:           %d\n", (int)header->xoffset);
	printf("byte order:         %d\n", (int)header->byte_order);
	printf("bitmap unit:        %d\n", (int)header->bitmap_unit);
	printf("bitmap bit order:   %d\n", (int)header->bitmap_bit_order);
	printf("bitmap pad:         %d\n", (int)header->bitmap_pad);
	printf("bits per pixel:     %d\n", (int)header->bits_per_pixel);
	printf("bytes per line:     %d\n", (int)header->bytes_per_line);
	printf("visual class:       %d\n", (int)header->visual_class);
	printf("red mask:           %d\n", (int)header->red_mask);
	printf("green mask:         %d\n", (int)header->green_mask);
	printf("blue mask:          %d\n", (int)header->blue_mask);
	printf("bits per rgb:       %d\n", (int)header->bits_per_rgb);
	printf("colormap entries:   %d\n", (int)header->colormap_entries);
	printf("num colors:         %d\n", (int)header->ncolors);
	printf("window width:       %d\n", (int)header->window_width);
	printf("window height:      %d\n", (int)header->window_height);
	printf("window x:           %d\n", (int)header->window_x);
	printf("window y:           %d\n", (int)header->window_y);
	printf("border width:       %d\n", (int)header->window_bdrwidth);
}

