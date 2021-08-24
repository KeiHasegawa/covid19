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
    update_table1529();
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
    os << '_' << x << '_' << y;
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
	  int delta = (n == 6) ? 28 : 50;
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
#if 0
		{
		  // 15-29 at Nihonbashi.gen
		  // ^^^^^
		  int X = 305;
		  int Y = 392;
		  int xdelta = 30;
		  int ydelta = 10;
		  if (X <= x && x < X+xdelta && Y <= y && y < Y+ydelta) {
		    mine::s1529[std::make_pair(x,y)] = xpix;
		    xpix = 0;
		  }
		}
#endif
#if 0
		{
		  // 30-39 at Nihonbashi.gen
		  // ^^^^^
		  int X = 305;
		  int Y = 392 - 28;
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
		  // 40% at Shibuya.gen
		  // ^^
		  int X = 673;
		  int Y = 420;
		  int delta = 13;
		  if (X <= x && x < X+delta && Y <= y && y < Y+delta) {
		    mine::s40[std::make_pair(x,y)] = xpix;
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

