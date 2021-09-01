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

#include <sys/time.h>
#include <map>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
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
  pair<int, int> time_button;
  void find_time_button(XImage* in_image)
  {
    int X = 310;
    int Y = 480;
    int dleta = 100;
    for (int x = X-100 ; x != X+100 ; ++x) {
      for (int y = Y-100 ; y != Y+100 ; ++y) {
	if (found(x, y, in_image)) {
	  time_button = make_pair(x, y);
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
  // "8,000" data
  //  ^^
  struct table8c_t : map<pair<int, int>, int> {
    table8c_t()
    {
      (*this)[make_pair(295, 233)] = 16777215;
      (*this)[make_pair(295, 234)] = 16777215;
      (*this)[make_pair(295, 235)] = 16777215;
      (*this)[make_pair(295, 236)] = 16777215;
      (*this)[make_pair(295, 237)] = 16777215;
      (*this)[make_pair(295, 238)] = 16777215;
      (*this)[make_pair(295, 239)] = 16777215;
      (*this)[make_pair(295, 240)] = 16777215;
      (*this)[make_pair(295, 241)] = 16777215;
      (*this)[make_pair(295, 242)] = 16777215;
      (*this)[make_pair(295, 243)] = 16777215;
      (*this)[make_pair(295, 244)] = 16777215;
      (*this)[make_pair(295, 245)] = 16777215;
      (*this)[make_pair(296, 233)] = 16777215;
      (*this)[make_pair(296, 234)] = 16777215;
      (*this)[make_pair(296, 235)] = 16777215;
      (*this)[make_pair(296, 236)] = 16777215;
      (*this)[make_pair(296, 237)] = 16777215;
      (*this)[make_pair(296, 238)] = 16777215;
      (*this)[make_pair(296, 239)] = 16777215;
      (*this)[make_pair(296, 240)] = 16777215;
      (*this)[make_pair(296, 241)] = 16777215;
      (*this)[make_pair(296, 242)] = 16777215;
      (*this)[make_pair(296, 243)] = 16777215;
      (*this)[make_pair(296, 244)] = 16777215;
      (*this)[make_pair(296, 245)] = 16777215;
      (*this)[make_pair(297, 233)] = 16777215;
      (*this)[make_pair(297, 234)] = 16777215;
      (*this)[make_pair(297, 235)] = 16777215;
      (*this)[make_pair(297, 236)] = 16777215;
      (*this)[make_pair(297, 237)] = 16777215;
      (*this)[make_pair(297, 238)] = 16777215;
      (*this)[make_pair(297, 239)] = 16777215;
      (*this)[make_pair(297, 240)] = 16777215;
      (*this)[make_pair(297, 241)] = 16777215;
      (*this)[make_pair(297, 242)] = 16777215;
      (*this)[make_pair(297, 243)] = 16777215;
      (*this)[make_pair(297, 244)] = 16777215;
      (*this)[make_pair(297, 245)] = 16777215;
      (*this)[make_pair(298, 233)] = 16777215;
      (*this)[make_pair(298, 234)] = 16777215;
      (*this)[make_pair(298, 235)] = 16448250;
      (*this)[make_pair(298, 236)] = 16777215;
      (*this)[make_pair(298, 237)] = 16777215;
      (*this)[make_pair(298, 238)] = 16645629;
      (*this)[make_pair(298, 239)] = 14079702;
      (*this)[make_pair(298, 240)] = 15592941;
      (*this)[make_pair(298, 241)] = 16777215;
      (*this)[make_pair(298, 242)] = 16777215;
      (*this)[make_pair(298, 243)] = 16777215;
      (*this)[make_pair(298, 244)] = 16777215;
      (*this)[make_pair(298, 245)] = 16777215;
      (*this)[make_pair(299, 233)] = 16777215;
      (*this)[make_pair(299, 234)] = 12961221;
      (*this)[make_pair(299, 235)] = 8487297;
      (*this)[make_pair(299, 236)] = 8421504;
      (*this)[make_pair(299, 237)] = 15329769;
      (*this)[make_pair(299, 238)] = 10263708;
      (*this)[make_pair(299, 239)] = 10790052;
      (*this)[make_pair(299, 240)] = 9342606;
      (*this)[make_pair(299, 241)] = 12369084;
      (*this)[make_pair(299, 242)] = 16777215;
      (*this)[make_pair(299, 243)] = 16777215;
      (*this)[make_pair(299, 244)] = 16777215;
      (*this)[make_pair(299, 245)] = 16777215;
      (*this)[make_pair(300, 233)] = 16777215;
      (*this)[make_pair(300, 234)] = 9737364;
      (*this)[make_pair(300, 235)] = 16579836;
      (*this)[make_pair(300, 236)] = 15658734;
      (*this)[make_pair(300, 237)] = 8224125;
      (*this)[make_pair(300, 238)] = 11908533;
      (*this)[make_pair(300, 239)] = 16777215;
      (*this)[make_pair(300, 240)] = 16777215;
      (*this)[make_pair(300, 241)] = 9737364;
      (*this)[make_pair(300, 242)] = 16777215;
      (*this)[make_pair(300, 243)] = 16777215;
      (*this)[make_pair(300, 244)] = 16777215;
      (*this)[make_pair(300, 245)] = 16777215;
      (*this)[make_pair(301, 233)] = 16053492;
      (*this)[make_pair(301, 234)] = 10395294;
      (*this)[make_pair(301, 235)] = 16777215;
      (*this)[make_pair(301, 236)] = 16777215;
      (*this)[make_pair(301, 237)] = 9408399;
      (*this)[make_pair(301, 238)] = 14935011;
      (*this)[make_pair(301, 239)] = 16777215;
      (*this)[make_pair(301, 240)] = 16777215;
      (*this)[make_pair(301, 241)] = 10132122;
      (*this)[make_pair(301, 242)] = 16382457;
      (*this)[make_pair(301, 243)] = 16777215;
      (*this)[make_pair(301, 244)] = 16777215;
      (*this)[make_pair(301, 245)] = 16777215;
      (*this)[make_pair(302, 233)] = 16777215;
      (*this)[make_pair(302, 234)] = 9737364;
      (*this)[make_pair(302, 235)] = 16514043;
      (*this)[make_pair(302, 236)] = 15527148;
      (*this)[make_pair(302, 237)] = 8355711;
      (*this)[make_pair(302, 238)] = 11711154;
      (*this)[make_pair(302, 239)] = 16777215;
      (*this)[make_pair(302, 240)] = 16777215;
      (*this)[make_pair(302, 241)] = 9605778;
      (*this)[make_pair(302, 242)] = 16777215;
      (*this)[make_pair(302, 243)] = 16777215;
      (*this)[make_pair(302, 244)] = 16777215;
      (*this)[make_pair(302, 245)] = 16777215;
      (*this)[make_pair(303, 233)] = 16777215;
      (*this)[make_pair(303, 234)] = 13290186;
      (*this)[make_pair(303, 235)] = 8618883;
      (*this)[make_pair(303, 236)] = 8684676;
      (*this)[make_pair(303, 237)] = 15724527;
      (*this)[make_pair(303, 238)] = 9539985;
      (*this)[make_pair(303, 239)] = 10263708;
      (*this)[make_pair(303, 240)] = 8882055;
      (*this)[make_pair(303, 241)] = 12566463;
      (*this)[make_pair(303, 242)] = 16777215;
      (*this)[make_pair(303, 243)] = 16777215;
      (*this)[make_pair(303, 244)] = 16777215;
      (*this)[make_pair(303, 245)] = 16777215;
      (*this)[make_pair(304, 233)] = 16777215;
      (*this)[make_pair(304, 234)] = 16777215;
      (*this)[make_pair(304, 235)] = 16579836;
      (*this)[make_pair(304, 236)] = 16777215;
      (*this)[make_pair(304, 237)] = 16777215;
      (*this)[make_pair(304, 238)] = 16645629;
      (*this)[make_pair(304, 239)] = 14277081;
      (*this)[make_pair(304, 240)] = 15856113;
      (*this)[make_pair(304, 241)] = 16777215;
      (*this)[make_pair(304, 242)] = 16777215;
      (*this)[make_pair(304, 243)] = 16777215;
      (*this)[make_pair(304, 244)] = 16777215;
      (*this)[make_pair(304, 245)] = 16777215;
      (*this)[make_pair(305, 233)] = 16777215;
      (*this)[make_pair(305, 234)] = 16777215;
      (*this)[make_pair(305, 235)] = 16777215;
      (*this)[make_pair(305, 236)] = 16777215;
      (*this)[make_pair(305, 237)] = 16777215;
      (*this)[make_pair(305, 238)] = 16777215;
      (*this)[make_pair(305, 239)] = 16777215;
      (*this)[make_pair(305, 240)] = 16777215;
      (*this)[make_pair(305, 241)] = 16777215;
      (*this)[make_pair(305, 242)] = 15658734;
      (*this)[make_pair(305, 243)] = 16250871;
      (*this)[make_pair(305, 244)] = 16777215;
      (*this)[make_pair(305, 245)] = 16777215;
      (*this)[make_pair(306, 233)] = 16777215;
      (*this)[make_pair(306, 234)] = 16777215;
      (*this)[make_pair(306, 235)] = 16777215;
      (*this)[make_pair(306, 236)] = 16777215;
      (*this)[make_pair(306, 237)] = 16777215;
      (*this)[make_pair(306, 238)] = 16777215;
      (*this)[make_pair(306, 239)] = 16777215;
      (*this)[make_pair(306, 240)] = 13816530;
      (*this)[make_pair(306, 241)] = 8618883;
      (*this)[make_pair(306, 242)] = 8947848;
      (*this)[make_pair(306, 243)] = 15658734;
      (*this)[make_pair(306, 244)] = 16777215;
      (*this)[make_pair(306, 245)] = 16777215;
      (*this)[make_pair(307, 233)] = 16777215;
      (*this)[make_pair(307, 234)] = 16777215;
      (*this)[make_pair(307, 235)] = 16777215;
      (*this)[make_pair(307, 236)] = 16777215;
      (*this)[make_pair(307, 237)] = 16777215;
      (*this)[make_pair(307, 238)] = 16777215;
      (*this)[make_pair(307, 239)] = 16777215;
      (*this)[make_pair(307, 240)] = 14277081;
      (*this)[make_pair(307, 241)] = 14869218;
      (*this)[make_pair(307, 242)] = 16777215;
      (*this)[make_pair(307, 243)] = 16777215;
      (*this)[make_pair(307, 244)] = 16777215;
      (*this)[make_pair(307, 245)] = 16777215;
    }
  } s8c;
  map<pair<int, int>, int> table8c;
  void update_table8c()
  {
    for (const auto& x : s8c) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table8c[pos] = x.second;
    }
  }
  // "400" data
  //  ^^
  struct table400_t : map<pair<int, int>, int> {
    table400_t()
    {
      (*this)[make_pair(295, 233)] = 16777215;
      (*this)[make_pair(295, 234)] = 16777215;
      (*this)[make_pair(295, 235)] = 16777215;
      (*this)[make_pair(295, 236)] = 16777215;
      (*this)[make_pair(295, 237)] = 16777215;
      (*this)[make_pair(295, 238)] = 16777215;
      (*this)[make_pair(295, 239)] = 16777215;
      (*this)[make_pair(295, 240)] = 16777215;
      (*this)[make_pair(295, 241)] = 16777215;
      (*this)[make_pair(295, 242)] = 16777215;
      (*this)[make_pair(295, 243)] = 16777215;
      (*this)[make_pair(295, 244)] = 16777215;
      (*this)[make_pair(295, 245)] = 16777215;
      (*this)[make_pair(296, 233)] = 16777215;
      (*this)[make_pair(296, 234)] = 16777215;
      (*this)[make_pair(296, 235)] = 16777215;
      (*this)[make_pair(296, 236)] = 16777215;
      (*this)[make_pair(296, 237)] = 16777215;
      (*this)[make_pair(296, 238)] = 16777215;
      (*this)[make_pair(296, 239)] = 16777215;
      (*this)[make_pair(296, 240)] = 16777215;
      (*this)[make_pair(296, 241)] = 16777215;
      (*this)[make_pair(296, 242)] = 16777215;
      (*this)[make_pair(296, 243)] = 16777215;
      (*this)[make_pair(296, 244)] = 16777215;
      (*this)[make_pair(296, 245)] = 16777215;
      (*this)[make_pair(297, 233)] = 16777215;
      (*this)[make_pair(297, 234)] = 16777215;
      (*this)[make_pair(297, 235)] = 16777215;
      (*this)[make_pair(297, 236)] = 16777215;
      (*this)[make_pair(297, 237)] = 16777215;
      (*this)[make_pair(297, 238)] = 16777215;
      (*this)[make_pair(297, 239)] = 16777215;
      (*this)[make_pair(297, 240)] = 16777215;
      (*this)[make_pair(297, 241)] = 16777215;
      (*this)[make_pair(297, 242)] = 16777215;
      (*this)[make_pair(297, 243)] = 16777215;
      (*this)[make_pair(297, 244)] = 16777215;
      (*this)[make_pair(297, 245)] = 16777215;
      (*this)[make_pair(298, 233)] = 16777215;
      (*this)[make_pair(298, 234)] = 16777215;
      (*this)[make_pair(298, 235)] = 16777215;
      (*this)[make_pair(298, 236)] = 16777215;
      (*this)[make_pair(298, 237)] = 16777215;
      (*this)[make_pair(298, 238)] = 16777215;
      (*this)[make_pair(298, 239)] = 16777215;
      (*this)[make_pair(298, 240)] = 16777215;
      (*this)[make_pair(298, 241)] = 16777215;
      (*this)[make_pair(298, 242)] = 16777215;
      (*this)[make_pair(298, 243)] = 16777215;
      (*this)[make_pair(298, 244)] = 16777215;
      (*this)[make_pair(298, 245)] = 16777215;
      (*this)[make_pair(299, 233)] = 16777215;
      (*this)[make_pair(299, 234)] = 16777215;
      (*this)[make_pair(299, 235)] = 16777215;
      (*this)[make_pair(299, 236)] = 16777215;
      (*this)[make_pair(299, 237)] = 16777215;
      (*this)[make_pair(299, 238)] = 16777215;
      (*this)[make_pair(299, 239)] = 16777215;
      (*this)[make_pair(299, 240)] = 16777215;
      (*this)[make_pair(299, 241)] = 16777215;
      (*this)[make_pair(299, 242)] = 16777215;
      (*this)[make_pair(299, 243)] = 16777215;
      (*this)[make_pair(299, 244)] = 16777215;
      (*this)[make_pair(299, 245)] = 16777215;
      (*this)[make_pair(300, 233)] = 16777215;
      (*this)[make_pair(300, 234)] = 16777215;
      (*this)[make_pair(300, 235)] = 16777215;
      (*this)[make_pair(300, 236)] = 16777215;
      (*this)[make_pair(300, 237)] = 16777215;
      (*this)[make_pair(300, 238)] = 16777215;
      (*this)[make_pair(300, 239)] = 16777215;
      (*this)[make_pair(300, 240)] = 16777215;
      (*this)[make_pair(300, 241)] = 16777215;
      (*this)[make_pair(300, 242)] = 16777215;
      (*this)[make_pair(300, 243)] = 16777215;
      (*this)[make_pair(300, 244)] = 16777215;
      (*this)[make_pair(300, 245)] = 16777215;
      (*this)[make_pair(301, 233)] = 16777215;
      (*this)[make_pair(301, 234)] = 16777215;
      (*this)[make_pair(301, 235)] = 16777215;
      (*this)[make_pair(301, 236)] = 16777215;
      (*this)[make_pair(301, 237)] = 16777215;
      (*this)[make_pair(301, 238)] = 16777215;
      (*this)[make_pair(301, 239)] = 16777215;
      (*this)[make_pair(301, 240)] = 16777215;
      (*this)[make_pair(301, 241)] = 16777215;
      (*this)[make_pair(301, 242)] = 16777215;
      (*this)[make_pair(301, 243)] = 16777215;
      (*this)[make_pair(301, 244)] = 16777215;
      (*this)[make_pair(301, 245)] = 16777215;
      (*this)[make_pair(302, 233)] = 16777215;
      (*this)[make_pair(302, 234)] = 16777215;
      (*this)[make_pair(302, 235)] = 16777215;
      (*this)[make_pair(302, 236)] = 16777215;
      (*this)[make_pair(302, 237)] = 16777215;
      (*this)[make_pair(302, 238)] = 16777215;
      (*this)[make_pair(302, 239)] = 16777215;
      (*this)[make_pair(302, 240)] = 16777215;
      (*this)[make_pair(302, 241)] = 16777215;
      (*this)[make_pair(302, 242)] = 16777215;
      (*this)[make_pair(302, 243)] = 16777215;
      (*this)[make_pair(302, 244)] = 16777215;
      (*this)[make_pair(302, 245)] = 16777215;
      (*this)[make_pair(303, 233)] = 16777215;
      (*this)[make_pair(303, 234)] = 16777215;
      (*this)[make_pair(303, 235)] = 16777215;
      (*this)[make_pair(303, 236)] = 16777215;
      (*this)[make_pair(303, 237)] = 16777215;
      (*this)[make_pair(303, 238)] = 16777215;
      (*this)[make_pair(303, 239)] = 16777215;
      (*this)[make_pair(303, 240)] = 16777215;
      (*this)[make_pair(303, 241)] = 16777215;
      (*this)[make_pair(303, 242)] = 16777215;
      (*this)[make_pair(303, 243)] = 16777215;
      (*this)[make_pair(303, 244)] = 16777215;
      (*this)[make_pair(303, 245)] = 16777215;
      (*this)[make_pair(304, 233)] = 16777215;
      (*this)[make_pair(304, 234)] = 16777215;
      (*this)[make_pair(304, 235)] = 16777215;
      (*this)[make_pair(304, 236)] = 16777215;
      (*this)[make_pair(304, 237)] = 16777215;
      (*this)[make_pair(304, 238)] = 16777215;
      (*this)[make_pair(304, 239)] = 16777215;
      (*this)[make_pair(304, 240)] = 16777215;
      (*this)[make_pair(304, 241)] = 16777215;
      (*this)[make_pair(304, 242)] = 16777215;
      (*this)[make_pair(304, 243)] = 16777215;
      (*this)[make_pair(304, 244)] = 16777215;
      (*this)[make_pair(304, 245)] = 16777215;
      (*this)[make_pair(305, 233)] = 16777215;
      (*this)[make_pair(305, 234)] = 16777215;
      (*this)[make_pair(305, 235)] = 16777215;
      (*this)[make_pair(305, 236)] = 16777215;
      (*this)[make_pair(305, 237)] = 16777215;
      (*this)[make_pair(305, 238)] = 16777215;
      (*this)[make_pair(305, 239)] = 16777215;
      (*this)[make_pair(305, 240)] = 16777215;
      (*this)[make_pair(305, 241)] = 16777215;
      (*this)[make_pair(305, 242)] = 16777215;
      (*this)[make_pair(305, 243)] = 16777215;
      (*this)[make_pair(305, 244)] = 16777215;
      (*this)[make_pair(305, 245)] = 16777215;
      (*this)[make_pair(306, 233)] = 16777215;
      (*this)[make_pair(306, 234)] = 16777215;
      (*this)[make_pair(306, 235)] = 16777215;
      (*this)[make_pair(306, 236)] = 16777215;
      (*this)[make_pair(306, 237)] = 16777215;
      (*this)[make_pair(306, 238)] = 14935011;
      (*this)[make_pair(306, 239)] = 9539985;
      (*this)[make_pair(306, 240)] = 15921906;
      (*this)[make_pair(306, 241)] = 16777215;
      (*this)[make_pair(306, 242)] = 16777215;
      (*this)[make_pair(306, 243)] = 16777215;
      (*this)[make_pair(306, 244)] = 16777215;
      (*this)[make_pair(306, 245)] = 16777215;
      (*this)[make_pair(307, 233)] = 16777215;
      (*this)[make_pair(307, 234)] = 16777215;
      (*this)[make_pair(307, 235)] = 16777215;
      (*this)[make_pair(307, 236)] = 16711422;
      (*this)[make_pair(307, 237)] = 12171705;
      (*this)[make_pair(307, 238)] = 9737364;
      (*this)[make_pair(307, 239)] = 9539985;
      (*this)[make_pair(307, 240)] = 15658734;
      (*this)[make_pair(307, 241)] = 16777215;
      (*this)[make_pair(307, 242)] = 16777215;
      (*this)[make_pair(307, 243)] = 16777215;
      (*this)[make_pair(307, 244)] = 16777215;
      (*this)[make_pair(307, 245)] = 16777215;
    }
  } s400;
  map<pair<int, int>, int> table400;
  void update_table400()
  {
    for (const auto& x : s400) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table400[pos] = x.second;
    }
  }
  // "800" data
  //  ^^
  struct table800_t : map<pair<int, int>, int> {
    table800_t()
    {
      (*this)[make_pair(295, 233)] = 16777215;
      (*this)[make_pair(295, 234)] = 16777215;
      (*this)[make_pair(295, 235)] = 16777215;
      (*this)[make_pair(295, 236)] = 16777215;
      (*this)[make_pair(295, 237)] = 16777215;
      (*this)[make_pair(295, 238)] = 16777215;
      (*this)[make_pair(295, 239)] = 16777215;
      (*this)[make_pair(295, 240)] = 16777215;
      (*this)[make_pair(295, 241)] = 16777215;
      (*this)[make_pair(295, 242)] = 16777215;
      (*this)[make_pair(295, 243)] = 16777215;
      (*this)[make_pair(295, 244)] = 16777215;
      (*this)[make_pair(295, 245)] = 16777215;
      (*this)[make_pair(296, 233)] = 16777215;
      (*this)[make_pair(296, 234)] = 16777215;
      (*this)[make_pair(296, 235)] = 16777215;
      (*this)[make_pair(296, 236)] = 16777215;
      (*this)[make_pair(296, 237)] = 16777215;
      (*this)[make_pair(296, 238)] = 16777215;
      (*this)[make_pair(296, 239)] = 16777215;
      (*this)[make_pair(296, 240)] = 16777215;
      (*this)[make_pair(296, 241)] = 16777215;
      (*this)[make_pair(296, 242)] = 16777215;
      (*this)[make_pair(296, 243)] = 16777215;
      (*this)[make_pair(296, 244)] = 16777215;
      (*this)[make_pair(296, 245)] = 16777215;
      (*this)[make_pair(297, 233)] = 16777215;
      (*this)[make_pair(297, 234)] = 16777215;
      (*this)[make_pair(297, 235)] = 16777215;
      (*this)[make_pair(297, 236)] = 16777215;
      (*this)[make_pair(297, 237)] = 16777215;
      (*this)[make_pair(297, 238)] = 16777215;
      (*this)[make_pair(297, 239)] = 16777215;
      (*this)[make_pair(297, 240)] = 16777215;
      (*this)[make_pair(297, 241)] = 16777215;
      (*this)[make_pair(297, 242)] = 16777215;
      (*this)[make_pair(297, 243)] = 16777215;
      (*this)[make_pair(297, 244)] = 16777215;
      (*this)[make_pair(297, 245)] = 16777215;
      (*this)[make_pair(298, 233)] = 16777215;
      (*this)[make_pair(298, 234)] = 16777215;
      (*this)[make_pair(298, 235)] = 16777215;
      (*this)[make_pair(298, 236)] = 16777215;
      (*this)[make_pair(298, 237)] = 16777215;
      (*this)[make_pair(298, 238)] = 16777215;
      (*this)[make_pair(298, 239)] = 16777215;
      (*this)[make_pair(298, 240)] = 16777215;
      (*this)[make_pair(298, 241)] = 16777215;
      (*this)[make_pair(298, 242)] = 16777215;
      (*this)[make_pair(298, 243)] = 16777215;
      (*this)[make_pair(298, 244)] = 16777215;
      (*this)[make_pair(298, 245)] = 16777215;
      (*this)[make_pair(299, 233)] = 16777215;
      (*this)[make_pair(299, 234)] = 16777215;
      (*this)[make_pair(299, 235)] = 16777215;
      (*this)[make_pair(299, 236)] = 16777215;
      (*this)[make_pair(299, 237)] = 16777215;
      (*this)[make_pair(299, 238)] = 16777215;
      (*this)[make_pair(299, 239)] = 16777215;
      (*this)[make_pair(299, 240)] = 16777215;
      (*this)[make_pair(299, 241)] = 16777215;
      (*this)[make_pair(299, 242)] = 16777215;
      (*this)[make_pair(299, 243)] = 16777215;
      (*this)[make_pair(299, 244)] = 16777215;
      (*this)[make_pair(299, 245)] = 16777215;
      (*this)[make_pair(300, 233)] = 16777215;
      (*this)[make_pair(300, 234)] = 16777215;
      (*this)[make_pair(300, 235)] = 16777215;
      (*this)[make_pair(300, 236)] = 16777215;
      (*this)[make_pair(300, 237)] = 16777215;
      (*this)[make_pair(300, 238)] = 16777215;
      (*this)[make_pair(300, 239)] = 16777215;
      (*this)[make_pair(300, 240)] = 16777215;
      (*this)[make_pair(300, 241)] = 16777215;
      (*this)[make_pair(300, 242)] = 16777215;
      (*this)[make_pair(300, 243)] = 16777215;
      (*this)[make_pair(300, 244)] = 16777215;
      (*this)[make_pair(300, 245)] = 16777215;
      (*this)[make_pair(301, 233)] = 16777215;
      (*this)[make_pair(301, 234)] = 16777215;
      (*this)[make_pair(301, 235)] = 16777215;
      (*this)[make_pair(301, 236)] = 16777215;
      (*this)[make_pair(301, 237)] = 16777215;
      (*this)[make_pair(301, 238)] = 16777215;
      (*this)[make_pair(301, 239)] = 16777215;
      (*this)[make_pair(301, 240)] = 16777215;
      (*this)[make_pair(301, 241)] = 16777215;
      (*this)[make_pair(301, 242)] = 16777215;
      (*this)[make_pair(301, 243)] = 16777215;
      (*this)[make_pair(301, 244)] = 16777215;
      (*this)[make_pair(301, 245)] = 16777215;
      (*this)[make_pair(302, 233)] = 16777215;
      (*this)[make_pair(302, 234)] = 16777215;
      (*this)[make_pair(302, 235)] = 16777215;
      (*this)[make_pair(302, 236)] = 16777215;
      (*this)[make_pair(302, 237)] = 16777215;
      (*this)[make_pair(302, 238)] = 16777215;
      (*this)[make_pair(302, 239)] = 16777215;
      (*this)[make_pair(302, 240)] = 16777215;
      (*this)[make_pair(302, 241)] = 16777215;
      (*this)[make_pair(302, 242)] = 16777215;
      (*this)[make_pair(302, 243)] = 16777215;
      (*this)[make_pair(302, 244)] = 16777215;
      (*this)[make_pair(302, 245)] = 16777215;
      (*this)[make_pair(303, 233)] = 16777215;
      (*this)[make_pair(303, 234)] = 16777215;
      (*this)[make_pair(303, 235)] = 16777215;
      (*this)[make_pair(303, 236)] = 16777215;
      (*this)[make_pair(303, 237)] = 16777215;
      (*this)[make_pair(303, 238)] = 16777215;
      (*this)[make_pair(303, 239)] = 16777215;
      (*this)[make_pair(303, 240)] = 16777215;
      (*this)[make_pair(303, 241)] = 16777215;
      (*this)[make_pair(303, 242)] = 16777215;
      (*this)[make_pair(303, 243)] = 16777215;
      (*this)[make_pair(303, 244)] = 16777215;
      (*this)[make_pair(303, 245)] = 16777215;
      (*this)[make_pair(304, 233)] = 16777215;
      (*this)[make_pair(304, 234)] = 16777215;
      (*this)[make_pair(304, 235)] = 16777215;
      (*this)[make_pair(304, 236)] = 16777215;
      (*this)[make_pair(304, 237)] = 16777215;
      (*this)[make_pair(304, 238)] = 16777215;
      (*this)[make_pair(304, 239)] = 16777215;
      (*this)[make_pair(304, 240)] = 16777215;
      (*this)[make_pair(304, 241)] = 16777215;
      (*this)[make_pair(304, 242)] = 16777215;
      (*this)[make_pair(304, 243)] = 16777215;
      (*this)[make_pair(304, 244)] = 16777215;
      (*this)[make_pair(304, 245)] = 16777215;
      (*this)[make_pair(305, 233)] = 16777215;
      (*this)[make_pair(305, 234)] = 16777215;
      (*this)[make_pair(305, 235)] = 16777215;
      (*this)[make_pair(305, 236)] = 16777215;
      (*this)[make_pair(305, 237)] = 16777215;
      (*this)[make_pair(305, 238)] = 16777215;
      (*this)[make_pair(305, 239)] = 16777215;
      (*this)[make_pair(305, 240)] = 16777215;
      (*this)[make_pair(305, 241)] = 16777215;
      (*this)[make_pair(305, 242)] = 16777215;
      (*this)[make_pair(305, 243)] = 16777215;
      (*this)[make_pair(305, 244)] = 16777215;
      (*this)[make_pair(305, 245)] = 16777215;
      (*this)[make_pair(306, 233)] = 16777215;
      (*this)[make_pair(306, 234)] = 16777215;
      (*this)[make_pair(306, 235)] = 16448250;
      (*this)[make_pair(306, 236)] = 16777215;
      (*this)[make_pair(306, 237)] = 16777215;
      (*this)[make_pair(306, 238)] = 16645629;
      (*this)[make_pair(306, 239)] = 14079702;
      (*this)[make_pair(306, 240)] = 15592941;
      (*this)[make_pair(306, 241)] = 16777215;
      (*this)[make_pair(306, 242)] = 16777215;
      (*this)[make_pair(306, 243)] = 16777215;
      (*this)[make_pair(306, 244)] = 16777215;
      (*this)[make_pair(306, 245)] = 16777215;
      (*this)[make_pair(307, 233)] = 16777215;
      (*this)[make_pair(307, 234)] = 12961221;
      (*this)[make_pair(307, 235)] = 8487297;
      (*this)[make_pair(307, 236)] = 8421504;
      (*this)[make_pair(307, 237)] = 15329769;
      (*this)[make_pair(307, 238)] = 10263708;
      (*this)[make_pair(307, 239)] = 10790052;
      (*this)[make_pair(307, 240)] = 9342606;
      (*this)[make_pair(307, 241)] = 12369084;
      (*this)[make_pair(307, 242)] = 16777215;
      (*this)[make_pair(307, 243)] = 16777215;
      (*this)[make_pair(307, 244)] = 16777215;
      (*this)[make_pair(307, 245)] = 16777215;
    }
  } s800;
  map<pair<int, int>, int> table800;
  void update_table800()
  {
    for (const auto& x : s800) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table800[pos] = x.second;
    }
  }
  // "150" data
  //  ^^
  struct table150_t : map<pair<int, int>, int> {
    table150_t()
    {
      (*this)[make_pair(308, 233)] = 16777215;
      (*this)[make_pair(308, 234)] = 13882323;
      (*this)[make_pair(308, 235)] = 9868950;
      (*this)[make_pair(308, 236)] = 16711422;
      (*this)[make_pair(308, 237)] = 16777215;
      (*this)[make_pair(308, 238)] = 16777215;
      (*this)[make_pair(308, 239)] = 16777215;
      (*this)[make_pair(308, 240)] = 16777215;
      (*this)[make_pair(308, 241)] = 16777215;
      (*this)[make_pair(308, 242)] = 16777215;
      (*this)[make_pair(308, 243)] = 16777215;
      (*this)[make_pair(308, 244)] = 16777215;
      (*this)[make_pair(308, 245)] = 16777215;
      (*this)[make_pair(309, 233)] = 16053492;
      (*this)[make_pair(309, 234)] = 7500402;
      (*this)[make_pair(309, 235)] = 11842740;
      (*this)[make_pair(309, 236)] = 12369084;
      (*this)[make_pair(309, 237)] = 12369084;
      (*this)[make_pair(309, 238)] = 12369084;
      (*this)[make_pair(309, 239)] = 12369084;
      (*this)[make_pair(309, 240)] = 12369084;
      (*this)[make_pair(309, 241)] = 12369084;
      (*this)[make_pair(309, 242)] = 16777215;
      (*this)[make_pair(309, 243)] = 16777215;
      (*this)[make_pair(309, 244)] = 16777215;
      (*this)[make_pair(309, 245)] = 16777215;
      (*this)[make_pair(310, 233)] = 16185078;
      (*this)[make_pair(310, 234)] = 12369084;
      (*this)[make_pair(310, 235)] = 12369084;
      (*this)[make_pair(310, 236)] = 12369084;
      (*this)[make_pair(310, 237)] = 12369084;
      (*this)[make_pair(310, 238)] = 12369084;
      (*this)[make_pair(310, 239)] = 12369084;
      (*this)[make_pair(310, 240)] = 12369084;
      (*this)[make_pair(310, 241)] = 12369084;
      (*this)[make_pair(310, 242)] = 16777215;
      (*this)[make_pair(310, 243)] = 16777215;
      (*this)[make_pair(310, 244)] = 16777215;
      (*this)[make_pair(310, 245)] = 16777215;
      (*this)[make_pair(311, 233)] = 16777215;
      (*this)[make_pair(311, 234)] = 16777215;
      (*this)[make_pair(311, 235)] = 16777215;
      (*this)[make_pair(311, 236)] = 16777215;
      (*this)[make_pair(311, 237)] = 16777215;
      (*this)[make_pair(311, 238)] = 16777215;
      (*this)[make_pair(311, 239)] = 16777215;
      (*this)[make_pair(311, 240)] = 16777215;
      (*this)[make_pair(311, 241)] = 16777215;
      (*this)[make_pair(311, 242)] = 16777215;
      (*this)[make_pair(311, 243)] = 16777215;
      (*this)[make_pair(311, 244)] = 16777215;
      (*this)[make_pair(311, 245)] = 16777215;
      (*this)[make_pair(312, 233)] = 16777215;
      (*this)[make_pair(312, 234)] = 16777215;
      (*this)[make_pair(312, 235)] = 16777215;
      (*this)[make_pair(312, 236)] = 16777215;
      (*this)[make_pair(312, 237)] = 16777215;
      (*this)[make_pair(312, 238)] = 16777215;
      (*this)[make_pair(312, 239)] = 16777215;
      (*this)[make_pair(312, 240)] = 16777215;
      (*this)[make_pair(312, 241)] = 16777215;
      (*this)[make_pair(312, 242)] = 16777215;
      (*this)[make_pair(312, 243)] = 16777215;
      (*this)[make_pair(312, 244)] = 16777215;
      (*this)[make_pair(312, 245)] = 16777215;
      (*this)[make_pair(313, 233)] = 16777215;
      (*this)[make_pair(313, 234)] = 16777215;
      (*this)[make_pair(313, 235)] = 16777215;
      (*this)[make_pair(313, 236)] = 16777215;
      (*this)[make_pair(313, 237)] = 16777215;
      (*this)[make_pair(313, 238)] = 16777215;
      (*this)[make_pair(313, 239)] = 16777215;
      (*this)[make_pair(313, 240)] = 16777215;
      (*this)[make_pair(313, 241)] = 16777215;
      (*this)[make_pair(313, 242)] = 16777215;
      (*this)[make_pair(313, 243)] = 16777215;
      (*this)[make_pair(313, 244)] = 16777215;
      (*this)[make_pair(313, 245)] = 16777215;
      (*this)[make_pair(314, 233)] = 15987699;
      (*this)[make_pair(314, 234)] = 10724259;
      (*this)[make_pair(314, 235)] = 10132122;
      (*this)[make_pair(314, 236)] = 9605778;
      (*this)[make_pair(314, 237)] = 9013641;
      (*this)[make_pair(314, 238)] = 16185078;
      (*this)[make_pair(314, 239)] = 16777215;
      (*this)[make_pair(314, 240)] = 16316664;
      (*this)[make_pair(314, 241)] = 10000536;
      (*this)[make_pair(314, 242)] = 16777215;
      (*this)[make_pair(314, 243)] = 16777215;
      (*this)[make_pair(314, 244)] = 16777215;
      (*this)[make_pair(314, 245)] = 16777215;
      (*this)[make_pair(315, 233)] = 15329769;
      (*this)[make_pair(315, 234)] = 9737364;
      (*this)[make_pair(315, 235)] = 14935011;
      (*this)[make_pair(315, 236)] = 15592941;
      (*this)[make_pair(315, 237)] = 9013641;
      (*this)[make_pair(315, 238)] = 16711422;
      (*this)[make_pair(315, 239)] = 16777215;
      (*this)[make_pair(315, 240)] = 16777215;
      (*this)[make_pair(315, 241)] = 9145227;
      (*this)[make_pair(315, 242)] = 16579836;
      (*this)[make_pair(315, 243)] = 16777215;
      (*this)[make_pair(315, 244)] = 16777215;
      (*this)[make_pair(315, 245)] = 16777215;
      (*this)[make_pair(316, 233)] = 15329769;
      (*this)[make_pair(316, 234)] = 10592673;
      (*this)[make_pair(316, 235)] = 16777215;
      (*this)[make_pair(316, 236)] = 16119285;
      (*this)[make_pair(316, 237)] = 10197915;
      (*this)[make_pair(316, 238)] = 16777215;
      (*this)[make_pair(316, 239)] = 16777215;
      (*this)[make_pair(316, 240)] = 16777215;
      (*this)[make_pair(316, 241)] = 9474192;
      (*this)[make_pair(316, 242)] = 16514043;
      (*this)[make_pair(316, 243)] = 16777215;
      (*this)[make_pair(316, 244)] = 16777215;
      (*this)[make_pair(316, 245)] = 16777215;
      (*this)[make_pair(317, 233)] = 15329769;
      (*this)[make_pair(317, 234)] = 10592673;
      (*this)[make_pair(317, 235)] = 16777215;
      (*this)[make_pair(317, 236)] = 16777215;
      (*this)[make_pair(317, 237)] = 9408399;
      (*this)[make_pair(317, 238)] = 15461355;
      (*this)[make_pair(317, 239)] = 16711422;
      (*this)[make_pair(317, 240)] = 14013909;
      (*this)[make_pair(317, 241)] = 10197915;
      (*this)[make_pair(317, 242)] = 16777215;
      (*this)[make_pair(317, 243)] = 16777215;
      (*this)[make_pair(317, 244)] = 16777215;
      (*this)[make_pair(317, 245)] = 16777215;
      (*this)[make_pair(318, 233)] = 15790320;
      (*this)[make_pair(318, 234)] = 12500670;
      (*this)[make_pair(318, 235)] = 16777215;
      (*this)[make_pair(318, 236)] = 16777215;
      (*this)[make_pair(318, 237)] = 14211288;
      (*this)[make_pair(318, 238)] = 9408399;
      (*this)[make_pair(318, 239)] = 8158332;
      (*this)[make_pair(318, 240)] = 10658466;
      (*this)[make_pair(318, 241)] = 15198183;
      (*this)[make_pair(318, 242)] = 16777215;
      (*this)[make_pair(318, 243)] = 16777215;
      (*this)[make_pair(318, 244)] = 16777215;
      (*this)[make_pair(318, 245)] = 16777215;
      (*this)[make_pair(319, 233)] = 16777215;
      (*this)[make_pair(319, 234)] = 16777215;
      (*this)[make_pair(319, 235)] = 16777215;
      (*this)[make_pair(319, 236)] = 16777215;
      (*this)[make_pair(319, 237)] = 16777215;
      (*this)[make_pair(319, 238)] = 16777215;
      (*this)[make_pair(319, 239)] = 16777215;
      (*this)[make_pair(319, 240)] = 16777215;
      (*this)[make_pair(319, 241)] = 16777215;
      (*this)[make_pair(319, 242)] = 16777215;
      (*this)[make_pair(319, 243)] = 16777215;
      (*this)[make_pair(319, 244)] = 16777215;
      (*this)[make_pair(319, 245)] = 16777215;
      (*this)[make_pair(320, 233)] = 16777215;
      (*this)[make_pair(320, 234)] = 16777215;
      (*this)[make_pair(320, 235)] = 16448250;
      (*this)[make_pair(320, 236)] = 14211288;
      (*this)[make_pair(320, 237)] = 13158600;
      (*this)[make_pair(320, 238)] = 13158600;
      (*this)[make_pair(320, 239)] = 14211288;
      (*this)[make_pair(320, 240)] = 16448250;
      (*this)[make_pair(320, 241)] = 16777215;
      (*this)[make_pair(320, 242)] = 16777215;
      (*this)[make_pair(320, 243)] = 16777215;
      (*this)[make_pair(320, 244)] = 16777215;
      (*this)[make_pair(320, 245)] = 16777215;
    }
  } s150;
  map<pair<int, int>, int> table150;
  void update_table150()
  {
    for (const auto& x : s150) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table150[pos] = x.second;
    }
  }
  // "200" data
  //  ^^
  struct table200_t : map<pair<int, int>, int> {
    table200_t()
    {
      (*this)[make_pair(295, 233)] = 16777215;
      (*this)[make_pair(295, 234)] = 16777215;
      (*this)[make_pair(295, 235)] = 16777215;
      (*this)[make_pair(295, 236)] = 16777215;
      (*this)[make_pair(295, 237)] = 16777215;
      (*this)[make_pair(295, 238)] = 16777215;
      (*this)[make_pair(295, 239)] = 16777215;
      (*this)[make_pair(295, 240)] = 16777215;
      (*this)[make_pair(295, 241)] = 16777215;
      (*this)[make_pair(295, 242)] = 16777215;
      (*this)[make_pair(295, 243)] = 16777215;
      (*this)[make_pair(295, 244)] = 16777215;
      (*this)[make_pair(295, 245)] = 16777215;
      (*this)[make_pair(296, 233)] = 16777215;
      (*this)[make_pair(296, 234)] = 16777215;
      (*this)[make_pair(296, 235)] = 16777215;
      (*this)[make_pair(296, 236)] = 16777215;
      (*this)[make_pair(296, 237)] = 16777215;
      (*this)[make_pair(296, 238)] = 16777215;
      (*this)[make_pair(296, 239)] = 16777215;
      (*this)[make_pair(296, 240)] = 16777215;
      (*this)[make_pair(296, 241)] = 16777215;
      (*this)[make_pair(296, 242)] = 16777215;
      (*this)[make_pair(296, 243)] = 16777215;
      (*this)[make_pair(296, 244)] = 16777215;
      (*this)[make_pair(296, 245)] = 16777215;
      (*this)[make_pair(297, 233)] = 16777215;
      (*this)[make_pair(297, 234)] = 16777215;
      (*this)[make_pair(297, 235)] = 16777215;
      (*this)[make_pair(297, 236)] = 16777215;
      (*this)[make_pair(297, 237)] = 16777215;
      (*this)[make_pair(297, 238)] = 16777215;
      (*this)[make_pair(297, 239)] = 16777215;
      (*this)[make_pair(297, 240)] = 16777215;
      (*this)[make_pair(297, 241)] = 16777215;
      (*this)[make_pair(297, 242)] = 16777215;
      (*this)[make_pair(297, 243)] = 16777215;
      (*this)[make_pair(297, 244)] = 16777215;
      (*this)[make_pair(297, 245)] = 16777215;
      (*this)[make_pair(298, 233)] = 16777215;
      (*this)[make_pair(298, 234)] = 16777215;
      (*this)[make_pair(298, 235)] = 16777215;
      (*this)[make_pair(298, 236)] = 16777215;
      (*this)[make_pair(298, 237)] = 16777215;
      (*this)[make_pair(298, 238)] = 16777215;
      (*this)[make_pair(298, 239)] = 16777215;
      (*this)[make_pair(298, 240)] = 16777215;
      (*this)[make_pair(298, 241)] = 16777215;
      (*this)[make_pair(298, 242)] = 16777215;
      (*this)[make_pair(298, 243)] = 16777215;
      (*this)[make_pair(298, 244)] = 16777215;
      (*this)[make_pair(298, 245)] = 16777215;
      (*this)[make_pair(299, 233)] = 16777215;
      (*this)[make_pair(299, 234)] = 16777215;
      (*this)[make_pair(299, 235)] = 16777215;
      (*this)[make_pair(299, 236)] = 16777215;
      (*this)[make_pair(299, 237)] = 16777215;
      (*this)[make_pair(299, 238)] = 16777215;
      (*this)[make_pair(299, 239)] = 16777215;
      (*this)[make_pair(299, 240)] = 16777215;
      (*this)[make_pair(299, 241)] = 16777215;
      (*this)[make_pair(299, 242)] = 16777215;
      (*this)[make_pair(299, 243)] = 16777215;
      (*this)[make_pair(299, 244)] = 16777215;
      (*this)[make_pair(299, 245)] = 16777215;
      (*this)[make_pair(300, 233)] = 16777215;
      (*this)[make_pair(300, 234)] = 16777215;
      (*this)[make_pair(300, 235)] = 16777215;
      (*this)[make_pair(300, 236)] = 16777215;
      (*this)[make_pair(300, 237)] = 16777215;
      (*this)[make_pair(300, 238)] = 16777215;
      (*this)[make_pair(300, 239)] = 16777215;
      (*this)[make_pair(300, 240)] = 16777215;
      (*this)[make_pair(300, 241)] = 16777215;
      (*this)[make_pair(300, 242)] = 16777215;
      (*this)[make_pair(300, 243)] = 16777215;
      (*this)[make_pair(300, 244)] = 16777215;
      (*this)[make_pair(300, 245)] = 16777215;
      (*this)[make_pair(301, 233)] = 16777215;
      (*this)[make_pair(301, 234)] = 16777215;
      (*this)[make_pair(301, 235)] = 16777215;
      (*this)[make_pair(301, 236)] = 16777215;
      (*this)[make_pair(301, 237)] = 16777215;
      (*this)[make_pair(301, 238)] = 16777215;
      (*this)[make_pair(301, 239)] = 16777215;
      (*this)[make_pair(301, 240)] = 16777215;
      (*this)[make_pair(301, 241)] = 16777215;
      (*this)[make_pair(301, 242)] = 16777215;
      (*this)[make_pair(301, 243)] = 16777215;
      (*this)[make_pair(301, 244)] = 16777215;
      (*this)[make_pair(301, 245)] = 16777215;
      (*this)[make_pair(302, 233)] = 16777215;
      (*this)[make_pair(302, 234)] = 16777215;
      (*this)[make_pair(302, 235)] = 16777215;
      (*this)[make_pair(302, 236)] = 16777215;
      (*this)[make_pair(302, 237)] = 16777215;
      (*this)[make_pair(302, 238)] = 16777215;
      (*this)[make_pair(302, 239)] = 16777215;
      (*this)[make_pair(302, 240)] = 16777215;
      (*this)[make_pair(302, 241)] = 16777215;
      (*this)[make_pair(302, 242)] = 16777215;
      (*this)[make_pair(302, 243)] = 16777215;
      (*this)[make_pair(302, 244)] = 16777215;
      (*this)[make_pair(302, 245)] = 16777215;
      (*this)[make_pair(303, 233)] = 16777215;
      (*this)[make_pair(303, 234)] = 16777215;
      (*this)[make_pair(303, 235)] = 16777215;
      (*this)[make_pair(303, 236)] = 16777215;
      (*this)[make_pair(303, 237)] = 16777215;
      (*this)[make_pair(303, 238)] = 16777215;
      (*this)[make_pair(303, 239)] = 16777215;
      (*this)[make_pair(303, 240)] = 16777215;
      (*this)[make_pair(303, 241)] = 16777215;
      (*this)[make_pair(303, 242)] = 16777215;
      (*this)[make_pair(303, 243)] = 16777215;
      (*this)[make_pair(303, 244)] = 16777215;
      (*this)[make_pair(303, 245)] = 16777215;
      (*this)[make_pair(304, 233)] = 16777215;
      (*this)[make_pair(304, 234)] = 16777215;
      (*this)[make_pair(304, 235)] = 16777215;
      (*this)[make_pair(304, 236)] = 16777215;
      (*this)[make_pair(304, 237)] = 16777215;
      (*this)[make_pair(304, 238)] = 16777215;
      (*this)[make_pair(304, 239)] = 16777215;
      (*this)[make_pair(304, 240)] = 16777215;
      (*this)[make_pair(304, 241)] = 16777215;
      (*this)[make_pair(304, 242)] = 16777215;
      (*this)[make_pair(304, 243)] = 16777215;
      (*this)[make_pair(304, 244)] = 16777215;
      (*this)[make_pair(304, 245)] = 16777215;
      (*this)[make_pair(305, 233)] = 16777215;
      (*this)[make_pair(305, 234)] = 16777215;
      (*this)[make_pair(305, 235)] = 16777215;
      (*this)[make_pair(305, 236)] = 16777215;
      (*this)[make_pair(305, 237)] = 16777215;
      (*this)[make_pair(305, 238)] = 16777215;
      (*this)[make_pair(305, 239)] = 16777215;
      (*this)[make_pair(305, 240)] = 16777215;
      (*this)[make_pair(305, 241)] = 16777215;
      (*this)[make_pair(305, 242)] = 16777215;
      (*this)[make_pair(305, 243)] = 16777215;
      (*this)[make_pair(305, 244)] = 16777215;
      (*this)[make_pair(305, 245)] = 16777215;
      (*this)[make_pair(306, 233)] = 16777215;
      (*this)[make_pair(306, 234)] = 16777215;
      (*this)[make_pair(306, 235)] = 16777215;
      (*this)[make_pair(306, 236)] = 16777215;
      (*this)[make_pair(306, 237)] = 16777215;
      (*this)[make_pair(306, 238)] = 16777215;
      (*this)[make_pair(306, 239)] = 16777215;
      (*this)[make_pair(306, 240)] = 16777215;
      (*this)[make_pair(306, 241)] = 16711422;
      (*this)[make_pair(306, 242)] = 16777215;
      (*this)[make_pair(306, 243)] = 16777215;
      (*this)[make_pair(306, 244)] = 16777215;
      (*this)[make_pair(306, 245)] = 16777215;
      (*this)[make_pair(307, 233)] = 16777215;
      (*this)[make_pair(307, 234)] = 10790052;
      (*this)[make_pair(307, 235)] = 15724527;
      (*this)[make_pair(307, 236)] = 16777215;
      (*this)[make_pair(307, 237)] = 16777215;
      (*this)[make_pair(307, 238)] = 16777215;
      (*this)[make_pair(307, 239)] = 16777215;
      (*this)[make_pair(307, 240)] = 14540253;
      (*this)[make_pair(307, 241)] = 7039851;
      (*this)[make_pair(307, 242)] = 16777215;
      (*this)[make_pair(307, 243)] = 16777215;
      (*this)[make_pair(307, 244)] = 16777215;
      (*this)[make_pair(307, 245)] = 16777215;
    }
  } s200;
  map<pair<int, int>, int> table200;
  void update_table200()
  {
    for (const auto& x : s200) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table200[pos] = x.second;
    }
  }
  // "300" data
  //  ^^
  struct table300_t : map<pair<int, int>, int> {
    table300_t()
    {
      (*this)[make_pair(295, 233)] = 16777215;
      (*this)[make_pair(295, 234)] = 16777215;
      (*this)[make_pair(295, 235)] = 16777215;
      (*this)[make_pair(295, 236)] = 16777215;
      (*this)[make_pair(295, 237)] = 16777215;
      (*this)[make_pair(295, 238)] = 16777215;
      (*this)[make_pair(295, 239)] = 16777215;
      (*this)[make_pair(295, 240)] = 16777215;
      (*this)[make_pair(295, 241)] = 16777215;
      (*this)[make_pair(295, 242)] = 16777215;
      (*this)[make_pair(295, 243)] = 16777215;
      (*this)[make_pair(295, 244)] = 16777215;
      (*this)[make_pair(295, 245)] = 16777215;
      (*this)[make_pair(296, 233)] = 16777215;
      (*this)[make_pair(296, 234)] = 16777215;
      (*this)[make_pair(296, 235)] = 16777215;
      (*this)[make_pair(296, 236)] = 16777215;
      (*this)[make_pair(296, 237)] = 16777215;
      (*this)[make_pair(296, 238)] = 16777215;
      (*this)[make_pair(296, 239)] = 16777215;
      (*this)[make_pair(296, 240)] = 16777215;
      (*this)[make_pair(296, 241)] = 16777215;
      (*this)[make_pair(296, 242)] = 16777215;
      (*this)[make_pair(296, 243)] = 16777215;
      (*this)[make_pair(296, 244)] = 16777215;
      (*this)[make_pair(296, 245)] = 16777215;
      (*this)[make_pair(297, 233)] = 16777215;
      (*this)[make_pair(297, 234)] = 16777215;
      (*this)[make_pair(297, 235)] = 16777215;
      (*this)[make_pair(297, 236)] = 16777215;
      (*this)[make_pair(297, 237)] = 16777215;
      (*this)[make_pair(297, 238)] = 16777215;
      (*this)[make_pair(297, 239)] = 16777215;
      (*this)[make_pair(297, 240)] = 16777215;
      (*this)[make_pair(297, 241)] = 16777215;
      (*this)[make_pair(297, 242)] = 16777215;
      (*this)[make_pair(297, 243)] = 16777215;
      (*this)[make_pair(297, 244)] = 16777215;
      (*this)[make_pair(297, 245)] = 16777215;
      (*this)[make_pair(298, 233)] = 16777215;
      (*this)[make_pair(298, 234)] = 16777215;
      (*this)[make_pair(298, 235)] = 16777215;
      (*this)[make_pair(298, 236)] = 16777215;
      (*this)[make_pair(298, 237)] = 16777215;
      (*this)[make_pair(298, 238)] = 16777215;
      (*this)[make_pair(298, 239)] = 16777215;
      (*this)[make_pair(298, 240)] = 16777215;
      (*this)[make_pair(298, 241)] = 16777215;
      (*this)[make_pair(298, 242)] = 16777215;
      (*this)[make_pair(298, 243)] = 16777215;
      (*this)[make_pair(298, 244)] = 16777215;
      (*this)[make_pair(298, 245)] = 16777215;
      (*this)[make_pair(299, 233)] = 16777215;
      (*this)[make_pair(299, 234)] = 16777215;
      (*this)[make_pair(299, 235)] = 16777215;
      (*this)[make_pair(299, 236)] = 16777215;
      (*this)[make_pair(299, 237)] = 16777215;
      (*this)[make_pair(299, 238)] = 16777215;
      (*this)[make_pair(299, 239)] = 16777215;
      (*this)[make_pair(299, 240)] = 16777215;
      (*this)[make_pair(299, 241)] = 16777215;
      (*this)[make_pair(299, 242)] = 16777215;
      (*this)[make_pair(299, 243)] = 16777215;
      (*this)[make_pair(299, 244)] = 16777215;
      (*this)[make_pair(299, 245)] = 16777215;
      (*this)[make_pair(300, 233)] = 16777215;
      (*this)[make_pair(300, 234)] = 16777215;
      (*this)[make_pair(300, 235)] = 16777215;
      (*this)[make_pair(300, 236)] = 16777215;
      (*this)[make_pair(300, 237)] = 16777215;
      (*this)[make_pair(300, 238)] = 16777215;
      (*this)[make_pair(300, 239)] = 16777215;
      (*this)[make_pair(300, 240)] = 16777215;
      (*this)[make_pair(300, 241)] = 16777215;
      (*this)[make_pair(300, 242)] = 16777215;
      (*this)[make_pair(300, 243)] = 16777215;
      (*this)[make_pair(300, 244)] = 16777215;
      (*this)[make_pair(300, 245)] = 16777215;
      (*this)[make_pair(301, 233)] = 16777215;
      (*this)[make_pair(301, 234)] = 16777215;
      (*this)[make_pair(301, 235)] = 16777215;
      (*this)[make_pair(301, 236)] = 16777215;
      (*this)[make_pair(301, 237)] = 16777215;
      (*this)[make_pair(301, 238)] = 16777215;
      (*this)[make_pair(301, 239)] = 16777215;
      (*this)[make_pair(301, 240)] = 16777215;
      (*this)[make_pair(301, 241)] = 16777215;
      (*this)[make_pair(301, 242)] = 16777215;
      (*this)[make_pair(301, 243)] = 16777215;
      (*this)[make_pair(301, 244)] = 16777215;
      (*this)[make_pair(301, 245)] = 16777215;
      (*this)[make_pair(302, 233)] = 16777215;
      (*this)[make_pair(302, 234)] = 16777215;
      (*this)[make_pair(302, 235)] = 16777215;
      (*this)[make_pair(302, 236)] = 16777215;
      (*this)[make_pair(302, 237)] = 16777215;
      (*this)[make_pair(302, 238)] = 16777215;
      (*this)[make_pair(302, 239)] = 16777215;
      (*this)[make_pair(302, 240)] = 16777215;
      (*this)[make_pair(302, 241)] = 16777215;
      (*this)[make_pair(302, 242)] = 16777215;
      (*this)[make_pair(302, 243)] = 16777215;
      (*this)[make_pair(302, 244)] = 16777215;
      (*this)[make_pair(302, 245)] = 16777215;
      (*this)[make_pair(303, 233)] = 16777215;
      (*this)[make_pair(303, 234)] = 16777215;
      (*this)[make_pair(303, 235)] = 16777215;
      (*this)[make_pair(303, 236)] = 16777215;
      (*this)[make_pair(303, 237)] = 16777215;
      (*this)[make_pair(303, 238)] = 16777215;
      (*this)[make_pair(303, 239)] = 16777215;
      (*this)[make_pair(303, 240)] = 16777215;
      (*this)[make_pair(303, 241)] = 16777215;
      (*this)[make_pair(303, 242)] = 16777215;
      (*this)[make_pair(303, 243)] = 16777215;
      (*this)[make_pair(303, 244)] = 16777215;
      (*this)[make_pair(303, 245)] = 16777215;
      (*this)[make_pair(304, 233)] = 16777215;
      (*this)[make_pair(304, 234)] = 16777215;
      (*this)[make_pair(304, 235)] = 16777215;
      (*this)[make_pair(304, 236)] = 16777215;
      (*this)[make_pair(304, 237)] = 16777215;
      (*this)[make_pair(304, 238)] = 16777215;
      (*this)[make_pair(304, 239)] = 16777215;
      (*this)[make_pair(304, 240)] = 16777215;
      (*this)[make_pair(304, 241)] = 16777215;
      (*this)[make_pair(304, 242)] = 16777215;
      (*this)[make_pair(304, 243)] = 16777215;
      (*this)[make_pair(304, 244)] = 16777215;
      (*this)[make_pair(304, 245)] = 16777215;
      (*this)[make_pair(305, 233)] = 16777215;
      (*this)[make_pair(305, 234)] = 16777215;
      (*this)[make_pair(305, 235)] = 16777215;
      (*this)[make_pair(305, 236)] = 16777215;
      (*this)[make_pair(305, 237)] = 16777215;
      (*this)[make_pair(305, 238)] = 16777215;
      (*this)[make_pair(305, 239)] = 16777215;
      (*this)[make_pair(305, 240)] = 16777215;
      (*this)[make_pair(305, 241)] = 16777215;
      (*this)[make_pair(305, 242)] = 16777215;
      (*this)[make_pair(305, 243)] = 16777215;
      (*this)[make_pair(305, 244)] = 16777215;
      (*this)[make_pair(305, 245)] = 16777215;
      (*this)[make_pair(306, 233)] = 16777215;
      (*this)[make_pair(306, 234)] = 16777215;
      (*this)[make_pair(306, 235)] = 16777215;
      (*this)[make_pair(306, 236)] = 16777215;
      (*this)[make_pair(306, 237)] = 16777215;
      (*this)[make_pair(306, 238)] = 16777215;
      (*this)[make_pair(306, 239)] = 16777215;
      (*this)[make_pair(306, 240)] = 16777215;
      (*this)[make_pair(306, 241)] = 16777215;
      (*this)[make_pair(306, 242)] = 16777215;
      (*this)[make_pair(306, 243)] = 16777215;
      (*this)[make_pair(306, 244)] = 16777215;
      (*this)[make_pair(306, 245)] = 16777215;
      (*this)[make_pair(307, 233)] = 15395562;
      (*this)[make_pair(307, 234)] = 10724259;
      (*this)[make_pair(307, 235)] = 16777215;
      (*this)[make_pair(307, 236)] = 16777215;
      (*this)[make_pair(307, 237)] = 16777215;
      (*this)[make_pair(307, 238)] = 16777215;
      (*this)[make_pair(307, 239)] = 16777215;
      (*this)[make_pair(307, 240)] = 16250871;
      (*this)[make_pair(307, 241)] = 9737364;
      (*this)[make_pair(307, 242)] = 16777215;
      (*this)[make_pair(307, 243)] = 16777215;
      (*this)[make_pair(307, 244)] = 16777215;
      (*this)[make_pair(307, 245)] = 16777215;
    }
  } s300;
  map<pair<int, int>, int> table300;
  void update_table300()
  {
    for (const auto& x : s300) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table300[pos] = x.second;
    }
  }
  // "600" data
  //  ^^
  struct table600_t : map<pair<int, int>, int> {
    table600_t()
    {
      (*this)[make_pair(295, 233)] = 16777215;
      (*this)[make_pair(295, 234)] = 16777215;
      (*this)[make_pair(295, 235)] = 16777215;
      (*this)[make_pair(295, 236)] = 16777215;
      (*this)[make_pair(295, 237)] = 16777215;
      (*this)[make_pair(295, 238)] = 16777215;
      (*this)[make_pair(295, 239)] = 16777215;
      (*this)[make_pair(295, 240)] = 16777215;
      (*this)[make_pair(295, 241)] = 16777215;
      (*this)[make_pair(295, 242)] = 16777215;
      (*this)[make_pair(295, 243)] = 16777215;
      (*this)[make_pair(295, 244)] = 16777215;
      (*this)[make_pair(295, 245)] = 16777215;
      (*this)[make_pair(296, 233)] = 16777215;
      (*this)[make_pair(296, 234)] = 16777215;
      (*this)[make_pair(296, 235)] = 16777215;
      (*this)[make_pair(296, 236)] = 16777215;
      (*this)[make_pair(296, 237)] = 16777215;
      (*this)[make_pair(296, 238)] = 16777215;
      (*this)[make_pair(296, 239)] = 16777215;
      (*this)[make_pair(296, 240)] = 16777215;
      (*this)[make_pair(296, 241)] = 16777215;
      (*this)[make_pair(296, 242)] = 16777215;
      (*this)[make_pair(296, 243)] = 16777215;
      (*this)[make_pair(296, 244)] = 16777215;
      (*this)[make_pair(296, 245)] = 16777215;
      (*this)[make_pair(297, 233)] = 16777215;
      (*this)[make_pair(297, 234)] = 16777215;
      (*this)[make_pair(297, 235)] = 16777215;
      (*this)[make_pair(297, 236)] = 16777215;
      (*this)[make_pair(297, 237)] = 16777215;
      (*this)[make_pair(297, 238)] = 16777215;
      (*this)[make_pair(297, 239)] = 16777215;
      (*this)[make_pair(297, 240)] = 16777215;
      (*this)[make_pair(297, 241)] = 16777215;
      (*this)[make_pair(297, 242)] = 16777215;
      (*this)[make_pair(297, 243)] = 16777215;
      (*this)[make_pair(297, 244)] = 16777215;
      (*this)[make_pair(297, 245)] = 16777215;
      (*this)[make_pair(298, 233)] = 16777215;
      (*this)[make_pair(298, 234)] = 16777215;
      (*this)[make_pair(298, 235)] = 16777215;
      (*this)[make_pair(298, 236)] = 16777215;
      (*this)[make_pair(298, 237)] = 16777215;
      (*this)[make_pair(298, 238)] = 16777215;
      (*this)[make_pair(298, 239)] = 16777215;
      (*this)[make_pair(298, 240)] = 16777215;
      (*this)[make_pair(298, 241)] = 16777215;
      (*this)[make_pair(298, 242)] = 16777215;
      (*this)[make_pair(298, 243)] = 16777215;
      (*this)[make_pair(298, 244)] = 16777215;
      (*this)[make_pair(298, 245)] = 16777215;
      (*this)[make_pair(299, 233)] = 16777215;
      (*this)[make_pair(299, 234)] = 16777215;
      (*this)[make_pair(299, 235)] = 16777215;
      (*this)[make_pair(299, 236)] = 16777215;
      (*this)[make_pair(299, 237)] = 16777215;
      (*this)[make_pair(299, 238)] = 16777215;
      (*this)[make_pair(299, 239)] = 16777215;
      (*this)[make_pair(299, 240)] = 16777215;
      (*this)[make_pair(299, 241)] = 16777215;
      (*this)[make_pair(299, 242)] = 16777215;
      (*this)[make_pair(299, 243)] = 16777215;
      (*this)[make_pair(299, 244)] = 16777215;
      (*this)[make_pair(299, 245)] = 16777215;
      (*this)[make_pair(300, 233)] = 16777215;
      (*this)[make_pair(300, 234)] = 16777215;
      (*this)[make_pair(300, 235)] = 16777215;
      (*this)[make_pair(300, 236)] = 16777215;
      (*this)[make_pair(300, 237)] = 16777215;
      (*this)[make_pair(300, 238)] = 16777215;
      (*this)[make_pair(300, 239)] = 16777215;
      (*this)[make_pair(300, 240)] = 16777215;
      (*this)[make_pair(300, 241)] = 16777215;
      (*this)[make_pair(300, 242)] = 16777215;
      (*this)[make_pair(300, 243)] = 16777215;
      (*this)[make_pair(300, 244)] = 16777215;
      (*this)[make_pair(300, 245)] = 16777215;
      (*this)[make_pair(301, 233)] = 16777215;
      (*this)[make_pair(301, 234)] = 16777215;
      (*this)[make_pair(301, 235)] = 16777215;
      (*this)[make_pair(301, 236)] = 16777215;
      (*this)[make_pair(301, 237)] = 16777215;
      (*this)[make_pair(301, 238)] = 16777215;
      (*this)[make_pair(301, 239)] = 16777215;
      (*this)[make_pair(301, 240)] = 16777215;
      (*this)[make_pair(301, 241)] = 16777215;
      (*this)[make_pair(301, 242)] = 16777215;
      (*this)[make_pair(301, 243)] = 16777215;
      (*this)[make_pair(301, 244)] = 16777215;
      (*this)[make_pair(301, 245)] = 16777215;
      (*this)[make_pair(302, 233)] = 16777215;
      (*this)[make_pair(302, 234)] = 16777215;
      (*this)[make_pair(302, 235)] = 16777215;
      (*this)[make_pair(302, 236)] = 16777215;
      (*this)[make_pair(302, 237)] = 16777215;
      (*this)[make_pair(302, 238)] = 16777215;
      (*this)[make_pair(302, 239)] = 16777215;
      (*this)[make_pair(302, 240)] = 16777215;
      (*this)[make_pair(302, 241)] = 16777215;
      (*this)[make_pair(302, 242)] = 16777215;
      (*this)[make_pair(302, 243)] = 16777215;
      (*this)[make_pair(302, 244)] = 16777215;
      (*this)[make_pair(302, 245)] = 16777215;
      (*this)[make_pair(303, 233)] = 16777215;
      (*this)[make_pair(303, 234)] = 16777215;
      (*this)[make_pair(303, 235)] = 16777215;
      (*this)[make_pair(303, 236)] = 16777215;
      (*this)[make_pair(303, 237)] = 16777215;
      (*this)[make_pair(303, 238)] = 16777215;
      (*this)[make_pair(303, 239)] = 16777215;
      (*this)[make_pair(303, 240)] = 16777215;
      (*this)[make_pair(303, 241)] = 16777215;
      (*this)[make_pair(303, 242)] = 16777215;
      (*this)[make_pair(303, 243)] = 16777215;
      (*this)[make_pair(303, 244)] = 16777215;
      (*this)[make_pair(303, 245)] = 16777215;
      (*this)[make_pair(304, 233)] = 16777215;
      (*this)[make_pair(304, 234)] = 16777215;
      (*this)[make_pair(304, 235)] = 16777215;
      (*this)[make_pair(304, 236)] = 16777215;
      (*this)[make_pair(304, 237)] = 16777215;
      (*this)[make_pair(304, 238)] = 16777215;
      (*this)[make_pair(304, 239)] = 16777215;
      (*this)[make_pair(304, 240)] = 16777215;
      (*this)[make_pair(304, 241)] = 16777215;
      (*this)[make_pair(304, 242)] = 16777215;
      (*this)[make_pair(304, 243)] = 16777215;
      (*this)[make_pair(304, 244)] = 16777215;
      (*this)[make_pair(304, 245)] = 16777215;
      (*this)[make_pair(305, 233)] = 16777215;
      (*this)[make_pair(305, 234)] = 16777215;
      (*this)[make_pair(305, 235)] = 16777215;
      (*this)[make_pair(305, 236)] = 16777215;
      (*this)[make_pair(305, 237)] = 16777215;
      (*this)[make_pair(305, 238)] = 16777215;
      (*this)[make_pair(305, 239)] = 16777215;
      (*this)[make_pair(305, 240)] = 16777215;
      (*this)[make_pair(305, 241)] = 16777215;
      (*this)[make_pair(305, 242)] = 16777215;
      (*this)[make_pair(305, 243)] = 16777215;
      (*this)[make_pair(305, 244)] = 16777215;
      (*this)[make_pair(305, 245)] = 16777215;
      (*this)[make_pair(306, 233)] = 16777215;
      (*this)[make_pair(306, 234)] = 16777215;
      (*this)[make_pair(306, 235)] = 16777215;
      (*this)[make_pair(306, 236)] = 16053492;
      (*this)[make_pair(306, 237)] = 14803425;
      (*this)[make_pair(306, 238)] = 14277081;
      (*this)[make_pair(306, 239)] = 16250871;
      (*this)[make_pair(306, 240)] = 16777215;
      (*this)[make_pair(306, 241)] = 16777215;
      (*this)[make_pair(306, 242)] = 16777215;
      (*this)[make_pair(306, 243)] = 16777215;
      (*this)[make_pair(306, 244)] = 16777215;
      (*this)[make_pair(306, 245)] = 16777215;
      (*this)[make_pair(307, 233)] = 16777215;
      (*this)[make_pair(307, 234)] = 15987699;
      (*this)[make_pair(307, 235)] = 10066329;
      (*this)[make_pair(307, 236)] = 7434609;
      (*this)[make_pair(307, 237)] = 8158332;
      (*this)[make_pair(307, 238)] = 7763574;
      (*this)[make_pair(307, 239)] = 9737364;
      (*this)[make_pair(307, 240)] = 9342606;
      (*this)[make_pair(307, 241)] = 14803425;
      (*this)[make_pair(307, 242)] = 16777215;
      (*this)[make_pair(307, 243)] = 16777215;
      (*this)[make_pair(307, 244)] = 16777215;
      (*this)[make_pair(307, 245)] = 16777215;
    }
  } s600;
  map<pair<int, int>, int> table600;
  void update_table600()
  {
    for (const auto& x : s600) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table600[pos] = x.second;
    }
  }
  // "2,000" data
  //  ^^
  struct table2c_t : map<pair<int, int>, int> {
    table2c_t()
    {
      (*this)[make_pair(295, 233)] = 16777215;
      (*this)[make_pair(295, 234)] = 16777215;
      (*this)[make_pair(295, 235)] = 16777215;
      (*this)[make_pair(295, 236)] = 16777215;
      (*this)[make_pair(295, 237)] = 16777215;
      (*this)[make_pair(295, 238)] = 16777215;
      (*this)[make_pair(295, 239)] = 16777215;
      (*this)[make_pair(295, 240)] = 16777215;
      (*this)[make_pair(295, 241)] = 16777215;
      (*this)[make_pair(295, 242)] = 16777215;
      (*this)[make_pair(295, 243)] = 16777215;
      (*this)[make_pair(295, 244)] = 16777215;
      (*this)[make_pair(295, 245)] = 16777215;
      (*this)[make_pair(296, 233)] = 16777215;
      (*this)[make_pair(296, 234)] = 16777215;
      (*this)[make_pair(296, 235)] = 16777215;
      (*this)[make_pair(296, 236)] = 16777215;
      (*this)[make_pair(296, 237)] = 16777215;
      (*this)[make_pair(296, 238)] = 16777215;
      (*this)[make_pair(296, 239)] = 16777215;
      (*this)[make_pair(296, 240)] = 16777215;
      (*this)[make_pair(296, 241)] = 16777215;
      (*this)[make_pair(296, 242)] = 16777215;
      (*this)[make_pair(296, 243)] = 16777215;
      (*this)[make_pair(296, 244)] = 16777215;
      (*this)[make_pair(296, 245)] = 16777215;
      (*this)[make_pair(297, 233)] = 16777215;
      (*this)[make_pair(297, 234)] = 16777215;
      (*this)[make_pair(297, 235)] = 16777215;
      (*this)[make_pair(297, 236)] = 16777215;
      (*this)[make_pair(297, 237)] = 16777215;
      (*this)[make_pair(297, 238)] = 16777215;
      (*this)[make_pair(297, 239)] = 16777215;
      (*this)[make_pair(297, 240)] = 16777215;
      (*this)[make_pair(297, 241)] = 16777215;
      (*this)[make_pair(297, 242)] = 16777215;
      (*this)[make_pair(297, 243)] = 16777215;
      (*this)[make_pair(297, 244)] = 16777215;
      (*this)[make_pair(297, 245)] = 16777215;
      (*this)[make_pair(298, 233)] = 16777215;
      (*this)[make_pair(298, 234)] = 16777215;
      (*this)[make_pair(298, 235)] = 16777215;
      (*this)[make_pair(298, 236)] = 16777215;
      (*this)[make_pair(298, 237)] = 16777215;
      (*this)[make_pair(298, 238)] = 16777215;
      (*this)[make_pair(298, 239)] = 16777215;
      (*this)[make_pair(298, 240)] = 16777215;
      (*this)[make_pair(298, 241)] = 16711422;
      (*this)[make_pair(298, 242)] = 16777215;
      (*this)[make_pair(298, 243)] = 16777215;
      (*this)[make_pair(298, 244)] = 16777215;
      (*this)[make_pair(298, 245)] = 16777215;
      (*this)[make_pair(299, 233)] = 16777215;
      (*this)[make_pair(299, 234)] = 10790052;
      (*this)[make_pair(299, 235)] = 15724527;
      (*this)[make_pair(299, 236)] = 16777215;
      (*this)[make_pair(299, 237)] = 16777215;
      (*this)[make_pair(299, 238)] = 16777215;
      (*this)[make_pair(299, 239)] = 16777215;
      (*this)[make_pair(299, 240)] = 14540253;
      (*this)[make_pair(299, 241)] = 7039851;
      (*this)[make_pair(299, 242)] = 16777215;
      (*this)[make_pair(299, 243)] = 16777215;
      (*this)[make_pair(299, 244)] = 16777215;
      (*this)[make_pair(299, 245)] = 16777215;
      (*this)[make_pair(300, 233)] = 16777215;
      (*this)[make_pair(300, 234)] = 9013641;
      (*this)[make_pair(300, 235)] = 16777215;
      (*this)[make_pair(300, 236)] = 16777215;
      (*this)[make_pair(300, 237)] = 16777215;
      (*this)[make_pair(300, 238)] = 16777215;
      (*this)[make_pair(300, 239)] = 15329769;
      (*this)[make_pair(300, 240)] = 8816262;
      (*this)[make_pair(300, 241)] = 8553090;
      (*this)[make_pair(300, 242)] = 16777215;
      (*this)[make_pair(300, 243)] = 16777215;
      (*this)[make_pair(300, 244)] = 16777215;
      (*this)[make_pair(300, 245)] = 16777215;
      (*this)[make_pair(301, 233)] = 16119285;
      (*this)[make_pair(301, 234)] = 9737364;
      (*this)[make_pair(301, 235)] = 16777215;
      (*this)[make_pair(301, 236)] = 16777215;
      (*this)[make_pair(301, 237)] = 16777215;
      (*this)[make_pair(301, 238)] = 15198183;
      (*this)[make_pair(301, 239)] = 8684676;
      (*this)[make_pair(301, 240)] = 15329769;
      (*this)[make_pair(301, 241)] = 9342606;
      (*this)[make_pair(301, 242)] = 16777215;
      (*this)[make_pair(301, 243)] = 16777215;
      (*this)[make_pair(301, 244)] = 16777215;
      (*this)[make_pair(301, 245)] = 16777215;
      (*this)[make_pair(302, 233)] = 16777215;
      (*this)[make_pair(302, 234)] = 9276813;
      (*this)[make_pair(302, 235)] = 14145495;
      (*this)[make_pair(302, 236)] = 15395562;
      (*this)[make_pair(302, 237)] = 11382189;
      (*this)[make_pair(302, 238)] = 8618883;
      (*this)[make_pair(302, 239)] = 15132390;
      (*this)[make_pair(302, 240)] = 16777215;
      (*this)[make_pair(302, 241)] = 9342606;
      (*this)[make_pair(302, 242)] = 16777215;
      (*this)[make_pair(302, 243)] = 16777215;
      (*this)[make_pair(302, 244)] = 16777215;
      (*this)[make_pair(302, 245)] = 16777215;
      (*this)[make_pair(303, 233)] = 16777215;
      (*this)[make_pair(303, 234)] = 14803425;
      (*this)[make_pair(303, 235)] = 10197915;
      (*this)[make_pair(303, 236)] = 9013641;
      (*this)[make_pair(303, 237)] = 12566463;
      (*this)[make_pair(303, 238)] = 16119285;
      (*this)[make_pair(303, 239)] = 16777215;
      (*this)[make_pair(303, 240)] = 16777215;
      (*this)[make_pair(303, 241)] = 9803157;
      (*this)[make_pair(303, 242)] = 16777215;
      (*this)[make_pair(303, 243)] = 16777215;
      (*this)[make_pair(303, 244)] = 16777215;
      (*this)[make_pair(303, 245)] = 16777215;
      (*this)[make_pair(304, 233)] = 16777215;
      (*this)[make_pair(304, 234)] = 16777215;
      (*this)[make_pair(304, 235)] = 16777215;
      (*this)[make_pair(304, 236)] = 16777215;
      (*this)[make_pair(304, 237)] = 16777215;
      (*this)[make_pair(304, 238)] = 16777215;
      (*this)[make_pair(304, 239)] = 16777215;
      (*this)[make_pair(304, 240)] = 16777215;
      (*this)[make_pair(304, 241)] = 16777215;
      (*this)[make_pair(304, 242)] = 16777215;
      (*this)[make_pair(304, 243)] = 16777215;
      (*this)[make_pair(304, 244)] = 16777215;
      (*this)[make_pair(304, 245)] = 16777215;
      (*this)[make_pair(305, 233)] = 16777215;
      (*this)[make_pair(305, 234)] = 16777215;
      (*this)[make_pair(305, 235)] = 16777215;
      (*this)[make_pair(305, 236)] = 16777215;
      (*this)[make_pair(305, 237)] = 16777215;
      (*this)[make_pair(305, 238)] = 16777215;
      (*this)[make_pair(305, 239)] = 16777215;
      (*this)[make_pair(305, 240)] = 16777215;
      (*this)[make_pair(305, 241)] = 16777215;
      (*this)[make_pair(305, 242)] = 15658734;
      (*this)[make_pair(305, 243)] = 16250871;
      (*this)[make_pair(305, 244)] = 16777215;
      (*this)[make_pair(305, 245)] = 16777215;
      (*this)[make_pair(306, 233)] = 16777215;
      (*this)[make_pair(306, 234)] = 16777215;
      (*this)[make_pair(306, 235)] = 16777215;
      (*this)[make_pair(306, 236)] = 16777215;
      (*this)[make_pair(306, 237)] = 16777215;
      (*this)[make_pair(306, 238)] = 16777215;
      (*this)[make_pair(306, 239)] = 16777215;
      (*this)[make_pair(306, 240)] = 13816530;
      (*this)[make_pair(306, 241)] = 8618883;
      (*this)[make_pair(306, 242)] = 8947848;
      (*this)[make_pair(306, 243)] = 15658734;
      (*this)[make_pair(306, 244)] = 16777215;
      (*this)[make_pair(306, 245)] = 16777215;
      (*this)[make_pair(307, 233)] = 16777215;
      (*this)[make_pair(307, 234)] = 16777215;
      (*this)[make_pair(307, 235)] = 16777215;
      (*this)[make_pair(307, 236)] = 16777215;
      (*this)[make_pair(307, 237)] = 16777215;
      (*this)[make_pair(307, 238)] = 16777215;
      (*this)[make_pair(307, 239)] = 16777215;
      (*this)[make_pair(307, 240)] = 14277081;
      (*this)[make_pair(307, 241)] = 14869218;
      (*this)[make_pair(307, 242)] = 16777215;
      (*this)[make_pair(307, 243)] = 16777215;
      (*this)[make_pair(307, 244)] = 16777215;
      (*this)[make_pair(307, 245)] = 16777215;
    }
  } s2c;
  map<pair<int, int>, int> table2c;
  void update_table2c()
  {
    for (const auto& x : s2c) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table2c[pos] = x.second;
    }
  }
  // "1,000" data
  //  ^^
  struct table1c_t : map<pair<int, int>, int> {
    table1c_t()
    {
      (*this)[make_pair(295, 233)] = 16777215;
      (*this)[make_pair(295, 234)] = 16777215;
      (*this)[make_pair(295, 235)] = 16777215;
      (*this)[make_pair(295, 236)] = 16777215;
      (*this)[make_pair(295, 237)] = 16777215;
      (*this)[make_pair(295, 238)] = 16777215;
      (*this)[make_pair(295, 239)] = 16777215;
      (*this)[make_pair(295, 240)] = 16777215;
      (*this)[make_pair(295, 241)] = 16777215;
      (*this)[make_pair(295, 242)] = 16777215;
      (*this)[make_pair(295, 243)] = 16777215;
      (*this)[make_pair(295, 244)] = 16777215;
      (*this)[make_pair(295, 245)] = 16777215;
      (*this)[make_pair(296, 233)] = 16777215;
      (*this)[make_pair(296, 234)] = 16777215;
      (*this)[make_pair(296, 235)] = 16777215;
      (*this)[make_pair(296, 236)] = 16777215;
      (*this)[make_pair(296, 237)] = 16777215;
      (*this)[make_pair(296, 238)] = 16777215;
      (*this)[make_pair(296, 239)] = 16777215;
      (*this)[make_pair(296, 240)] = 16777215;
      (*this)[make_pair(296, 241)] = 16777215;
      (*this)[make_pair(296, 242)] = 16777215;
      (*this)[make_pair(296, 243)] = 16777215;
      (*this)[make_pair(296, 244)] = 16777215;
      (*this)[make_pair(296, 245)] = 16777215;
      (*this)[make_pair(297, 233)] = 16777215;
      (*this)[make_pair(297, 234)] = 16777215;
      (*this)[make_pair(297, 235)] = 16777215;
      (*this)[make_pair(297, 236)] = 16777215;
      (*this)[make_pair(297, 237)] = 16777215;
      (*this)[make_pair(297, 238)] = 16777215;
      (*this)[make_pair(297, 239)] = 16777215;
      (*this)[make_pair(297, 240)] = 16777215;
      (*this)[make_pair(297, 241)] = 16777215;
      (*this)[make_pair(297, 242)] = 16777215;
      (*this)[make_pair(297, 243)] = 16777215;
      (*this)[make_pair(297, 244)] = 16777215;
      (*this)[make_pair(297, 245)] = 16777215;
      (*this)[make_pair(298, 233)] = 16777215;
      (*this)[make_pair(298, 234)] = 16777215;
      (*this)[make_pair(298, 235)] = 16777215;
      (*this)[make_pair(298, 236)] = 16777215;
      (*this)[make_pair(298, 237)] = 16777215;
      (*this)[make_pair(298, 238)] = 16777215;
      (*this)[make_pair(298, 239)] = 16777215;
      (*this)[make_pair(298, 240)] = 16777215;
      (*this)[make_pair(298, 241)] = 16777215;
      (*this)[make_pair(298, 242)] = 16777215;
      (*this)[make_pair(298, 243)] = 16777215;
      (*this)[make_pair(298, 244)] = 16777215;
      (*this)[make_pair(298, 245)] = 16777215;
      (*this)[make_pair(299, 233)] = 16777215;
      (*this)[make_pair(299, 234)] = 16777215;
      (*this)[make_pair(299, 235)] = 12632256;
      (*this)[make_pair(299, 236)] = 13816530;
      (*this)[make_pair(299, 237)] = 16777215;
      (*this)[make_pair(299, 238)] = 16777215;
      (*this)[make_pair(299, 239)] = 16777215;
      (*this)[make_pair(299, 240)] = 16777215;
      (*this)[make_pair(299, 241)] = 16777215;
      (*this)[make_pair(299, 242)] = 16777215;
      (*this)[make_pair(299, 243)] = 16777215;
      (*this)[make_pair(299, 244)] = 16777215;
      (*this)[make_pair(299, 245)] = 16777215;
      (*this)[make_pair(300, 233)] = 16777215;
      (*this)[make_pair(300, 234)] = 13882323;
      (*this)[make_pair(300, 235)] = 9868950;
      (*this)[make_pair(300, 236)] = 16711422;
      (*this)[make_pair(300, 237)] = 16777215;
      (*this)[make_pair(300, 238)] = 16777215;
      (*this)[make_pair(300, 239)] = 16777215;
      (*this)[make_pair(300, 240)] = 16777215;
      (*this)[make_pair(300, 241)] = 16777215;
      (*this)[make_pair(300, 242)] = 16777215;
      (*this)[make_pair(300, 243)] = 16777215;
      (*this)[make_pair(300, 244)] = 16777215;
      (*this)[make_pair(300, 245)] = 16777215;
      (*this)[make_pair(301, 233)] = 16053492;
      (*this)[make_pair(301, 234)] = 7500402;
      (*this)[make_pair(301, 235)] = 11842740;
      (*this)[make_pair(301, 236)] = 12369084;
      (*this)[make_pair(301, 237)] = 12369084;
      (*this)[make_pair(301, 238)] = 12369084;
      (*this)[make_pair(301, 239)] = 12369084;
      (*this)[make_pair(301, 240)] = 12369084;
      (*this)[make_pair(301, 241)] = 12369084;
      (*this)[make_pair(301, 242)] = 16777215;
      (*this)[make_pair(301, 243)] = 16777215;
      (*this)[make_pair(301, 244)] = 16777215;
      (*this)[make_pair(301, 245)] = 16777215;
      (*this)[make_pair(302, 233)] = 16185078;
      (*this)[make_pair(302, 234)] = 12369084;
      (*this)[make_pair(302, 235)] = 12369084;
      (*this)[make_pair(302, 236)] = 12369084;
      (*this)[make_pair(302, 237)] = 12369084;
      (*this)[make_pair(302, 238)] = 12369084;
      (*this)[make_pair(302, 239)] = 12369084;
      (*this)[make_pair(302, 240)] = 12369084;
      (*this)[make_pair(302, 241)] = 12369084;
      (*this)[make_pair(302, 242)] = 16777215;
      (*this)[make_pair(302, 243)] = 16777215;
      (*this)[make_pair(302, 244)] = 16777215;
      (*this)[make_pair(302, 245)] = 16777215;
      (*this)[make_pair(303, 233)] = 16777215;
      (*this)[make_pair(303, 234)] = 16777215;
      (*this)[make_pair(303, 235)] = 16777215;
      (*this)[make_pair(303, 236)] = 16777215;
      (*this)[make_pair(303, 237)] = 16777215;
      (*this)[make_pair(303, 238)] = 16777215;
      (*this)[make_pair(303, 239)] = 16777215;
      (*this)[make_pair(303, 240)] = 16777215;
      (*this)[make_pair(303, 241)] = 16777215;
      (*this)[make_pair(303, 242)] = 16777215;
      (*this)[make_pair(303, 243)] = 16777215;
      (*this)[make_pair(303, 244)] = 16777215;
      (*this)[make_pair(303, 245)] = 16777215;
      (*this)[make_pair(304, 233)] = 16777215;
      (*this)[make_pair(304, 234)] = 16777215;
      (*this)[make_pair(304, 235)] = 16777215;
      (*this)[make_pair(304, 236)] = 16777215;
      (*this)[make_pair(304, 237)] = 16777215;
      (*this)[make_pair(304, 238)] = 16777215;
      (*this)[make_pair(304, 239)] = 16777215;
      (*this)[make_pair(304, 240)] = 16777215;
      (*this)[make_pair(304, 241)] = 16777215;
      (*this)[make_pair(304, 242)] = 16777215;
      (*this)[make_pair(304, 243)] = 16777215;
      (*this)[make_pair(304, 244)] = 16777215;
      (*this)[make_pair(304, 245)] = 16777215;
      (*this)[make_pair(305, 233)] = 16777215;
      (*this)[make_pair(305, 234)] = 16777215;
      (*this)[make_pair(305, 235)] = 16777215;
      (*this)[make_pair(305, 236)] = 16777215;
      (*this)[make_pair(305, 237)] = 16777215;
      (*this)[make_pair(305, 238)] = 16777215;
      (*this)[make_pair(305, 239)] = 16777215;
      (*this)[make_pair(305, 240)] = 16777215;
      (*this)[make_pair(305, 241)] = 16777215;
      (*this)[make_pair(305, 242)] = 15658734;
      (*this)[make_pair(305, 243)] = 16250871;
      (*this)[make_pair(305, 244)] = 16777215;
      (*this)[make_pair(305, 245)] = 16777215;
      (*this)[make_pair(306, 233)] = 16777215;
      (*this)[make_pair(306, 234)] = 16777215;
      (*this)[make_pair(306, 235)] = 16777215;
      (*this)[make_pair(306, 236)] = 16777215;
      (*this)[make_pair(306, 237)] = 16777215;
      (*this)[make_pair(306, 238)] = 16777215;
      (*this)[make_pair(306, 239)] = 16777215;
      (*this)[make_pair(306, 240)] = 13816530;
      (*this)[make_pair(306, 241)] = 8618883;
      (*this)[make_pair(306, 242)] = 8947848;
      (*this)[make_pair(306, 243)] = 15658734;
      (*this)[make_pair(306, 244)] = 16777215;
      (*this)[make_pair(306, 245)] = 16777215;
      (*this)[make_pair(307, 233)] = 16777215;
      (*this)[make_pair(307, 234)] = 16777215;
      (*this)[make_pair(307, 235)] = 16777215;
      (*this)[make_pair(307, 236)] = 16777215;
      (*this)[make_pair(307, 237)] = 16777215;
      (*this)[make_pair(307, 238)] = 16777215;
      (*this)[make_pair(307, 239)] = 16777215;
      (*this)[make_pair(307, 240)] = 14277081;
      (*this)[make_pair(307, 241)] = 14869218;
      (*this)[make_pair(307, 242)] = 16777215;
      (*this)[make_pair(307, 243)] = 16777215;
      (*this)[make_pair(307, 244)] = 16777215;
      (*this)[make_pair(307, 245)] = 16777215;
    }
  } s1c;
  map<pair<int, int>, int> table1c;
  void update_table1c()
  {
    for (const auto& x : s1c) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table1c[pos] = x.second;
    }
  }
  // "4,000" data
  //  ^^
  struct table4c_t : map<pair<int, int>, int> {
    table4c_t()
    {
      (*this)[make_pair(295, 233)] = 16777215;
      (*this)[make_pair(295, 234)] = 16777215;
      (*this)[make_pair(295, 235)] = 16777215;
      (*this)[make_pair(295, 236)] = 16777215;
      (*this)[make_pair(295, 237)] = 16777215;
      (*this)[make_pair(295, 238)] = 16777215;
      (*this)[make_pair(295, 239)] = 16777215;
      (*this)[make_pair(295, 240)] = 16777215;
      (*this)[make_pair(295, 241)] = 16777215;
      (*this)[make_pair(295, 242)] = 16777215;
      (*this)[make_pair(295, 243)] = 16777215;
      (*this)[make_pair(295, 244)] = 16777215;
      (*this)[make_pair(295, 245)] = 16777215;
      (*this)[make_pair(296, 233)] = 16777215;
      (*this)[make_pair(296, 234)] = 16777215;
      (*this)[make_pair(296, 235)] = 16777215;
      (*this)[make_pair(296, 236)] = 16777215;
      (*this)[make_pair(296, 237)] = 16777215;
      (*this)[make_pair(296, 238)] = 16777215;
      (*this)[make_pair(296, 239)] = 16777215;
      (*this)[make_pair(296, 240)] = 16777215;
      (*this)[make_pair(296, 241)] = 16777215;
      (*this)[make_pair(296, 242)] = 16777215;
      (*this)[make_pair(296, 243)] = 16777215;
      (*this)[make_pair(296, 244)] = 16777215;
      (*this)[make_pair(296, 245)] = 16777215;
      (*this)[make_pair(297, 233)] = 16777215;
      (*this)[make_pair(297, 234)] = 16777215;
      (*this)[make_pair(297, 235)] = 16777215;
      (*this)[make_pair(297, 236)] = 16777215;
      (*this)[make_pair(297, 237)] = 16777215;
      (*this)[make_pair(297, 238)] = 16777215;
      (*this)[make_pair(297, 239)] = 16777215;
      (*this)[make_pair(297, 240)] = 16777215;
      (*this)[make_pair(297, 241)] = 16777215;
      (*this)[make_pair(297, 242)] = 16777215;
      (*this)[make_pair(297, 243)] = 16777215;
      (*this)[make_pair(297, 244)] = 16777215;
      (*this)[make_pair(297, 245)] = 16777215;
      (*this)[make_pair(298, 233)] = 16777215;
      (*this)[make_pair(298, 234)] = 16777215;
      (*this)[make_pair(298, 235)] = 16777215;
      (*this)[make_pair(298, 236)] = 16777215;
      (*this)[make_pair(298, 237)] = 16777215;
      (*this)[make_pair(298, 238)] = 14935011;
      (*this)[make_pair(298, 239)] = 9539985;
      (*this)[make_pair(298, 240)] = 15921906;
      (*this)[make_pair(298, 241)] = 16777215;
      (*this)[make_pair(298, 242)] = 16777215;
      (*this)[make_pair(298, 243)] = 16777215;
      (*this)[make_pair(298, 244)] = 16777215;
      (*this)[make_pair(298, 245)] = 16777215;
      (*this)[make_pair(299, 233)] = 16777215;
      (*this)[make_pair(299, 234)] = 16777215;
      (*this)[make_pair(299, 235)] = 16777215;
      (*this)[make_pair(299, 236)] = 16711422;
      (*this)[make_pair(299, 237)] = 12171705;
      (*this)[make_pair(299, 238)] = 9737364;
      (*this)[make_pair(299, 239)] = 9539985;
      (*this)[make_pair(299, 240)] = 15658734;
      (*this)[make_pair(299, 241)] = 16777215;
      (*this)[make_pair(299, 242)] = 16777215;
      (*this)[make_pair(299, 243)] = 16777215;
      (*this)[make_pair(299, 244)] = 16777215;
      (*this)[make_pair(299, 245)] = 16777215;
      (*this)[make_pair(300, 233)] = 16777215;
      (*this)[make_pair(300, 234)] = 16777215;
      (*this)[make_pair(300, 235)] = 15592941;
      (*this)[make_pair(300, 236)] = 9605778;
      (*this)[make_pair(300, 237)] = 12434877;
      (*this)[make_pair(300, 238)] = 16711422;
      (*this)[make_pair(300, 239)] = 10461087;
      (*this)[make_pair(300, 240)] = 15658734;
      (*this)[make_pair(300, 241)] = 16777215;
      (*this)[make_pair(300, 242)] = 16777215;
      (*this)[make_pair(300, 243)] = 16777215;
      (*this)[make_pair(300, 244)] = 16777215;
      (*this)[make_pair(300, 245)] = 16777215;
      (*this)[make_pair(301, 233)] = 16777215;
      (*this)[make_pair(301, 234)] = 13158600;
      (*this)[make_pair(301, 235)] = 9342606;
      (*this)[make_pair(301, 236)] = 15132390;
      (*this)[make_pair(301, 237)] = 16777215;
      (*this)[make_pair(301, 238)] = 16777215;
      (*this)[make_pair(301, 239)] = 10461087;
      (*this)[make_pair(301, 240)] = 15658734;
      (*this)[make_pair(301, 241)] = 16777215;
      (*this)[make_pair(301, 242)] = 16777215;
      (*this)[make_pair(301, 243)] = 16777215;
      (*this)[make_pair(301, 244)] = 16777215;
      (*this)[make_pair(301, 245)] = 16777215;
      (*this)[make_pair(302, 233)] = 15461355;
      (*this)[make_pair(302, 234)] = 6974058;
      (*this)[make_pair(302, 235)] = 7763574;
      (*this)[make_pair(302, 236)] = 7960953;
      (*this)[make_pair(302, 237)] = 7960953;
      (*this)[make_pair(302, 238)] = 7960953;
      (*this)[make_pair(302, 239)] = 7171437;
      (*this)[make_pair(302, 240)] = 7829367;
      (*this)[make_pair(302, 241)] = 7960953;
      (*this)[make_pair(302, 242)] = 16777215;
      (*this)[make_pair(302, 243)] = 16777215;
      (*this)[make_pair(302, 244)] = 16777215;
      (*this)[make_pair(302, 245)] = 16777215;
      (*this)[make_pair(303, 233)] = 16777215;
      (*this)[make_pair(303, 234)] = 16777215;
      (*this)[make_pair(303, 235)] = 16777215;
      (*this)[make_pair(303, 236)] = 16777215;
      (*this)[make_pair(303, 237)] = 16777215;
      (*this)[make_pair(303, 238)] = 16777215;
      (*this)[make_pair(303, 239)] = 10461087;
      (*this)[make_pair(303, 240)] = 15658734;
      (*this)[make_pair(303, 241)] = 16777215;
      (*this)[make_pair(303, 242)] = 16777215;
      (*this)[make_pair(303, 243)] = 16777215;
      (*this)[make_pair(303, 244)] = 16777215;
      (*this)[make_pair(303, 245)] = 16777215;
      (*this)[make_pair(304, 233)] = 16777215;
      (*this)[make_pair(304, 234)] = 16777215;
      (*this)[make_pair(304, 235)] = 16777215;
      (*this)[make_pair(304, 236)] = 16777215;
      (*this)[make_pair(304, 237)] = 16777215;
      (*this)[make_pair(304, 238)] = 16777215;
      (*this)[make_pair(304, 239)] = 14737632;
      (*this)[make_pair(304, 240)] = 16448250;
      (*this)[make_pair(304, 241)] = 16777215;
      (*this)[make_pair(304, 242)] = 16777215;
      (*this)[make_pair(304, 243)] = 16777215;
      (*this)[make_pair(304, 244)] = 16777215;
      (*this)[make_pair(304, 245)] = 16777215;
      (*this)[make_pair(305, 233)] = 16777215;
      (*this)[make_pair(305, 234)] = 16777215;
      (*this)[make_pair(305, 235)] = 16777215;
      (*this)[make_pair(305, 236)] = 16777215;
      (*this)[make_pair(305, 237)] = 16777215;
      (*this)[make_pair(305, 238)] = 16777215;
      (*this)[make_pair(305, 239)] = 16777215;
      (*this)[make_pair(305, 240)] = 16777215;
      (*this)[make_pair(305, 241)] = 16777215;
      (*this)[make_pair(305, 242)] = 15658734;
      (*this)[make_pair(305, 243)] = 16250871;
      (*this)[make_pair(305, 244)] = 16777215;
      (*this)[make_pair(305, 245)] = 16777215;
      (*this)[make_pair(306, 233)] = 16777215;
      (*this)[make_pair(306, 234)] = 16777215;
      (*this)[make_pair(306, 235)] = 16777215;
      (*this)[make_pair(306, 236)] = 16777215;
      (*this)[make_pair(306, 237)] = 16777215;
      (*this)[make_pair(306, 238)] = 16777215;
      (*this)[make_pair(306, 239)] = 16777215;
      (*this)[make_pair(306, 240)] = 13816530;
      (*this)[make_pair(306, 241)] = 8618883;
      (*this)[make_pair(306, 242)] = 8947848;
      (*this)[make_pair(306, 243)] = 15658734;
      (*this)[make_pair(306, 244)] = 16777215;
      (*this)[make_pair(306, 245)] = 16777215;
      (*this)[make_pair(307, 233)] = 16777215;
      (*this)[make_pair(307, 234)] = 16777215;
      (*this)[make_pair(307, 235)] = 16777215;
      (*this)[make_pair(307, 236)] = 16777215;
      (*this)[make_pair(307, 237)] = 16777215;
      (*this)[make_pair(307, 238)] = 16777215;
      (*this)[make_pair(307, 239)] = 16777215;
      (*this)[make_pair(307, 240)] = 14277081;
      (*this)[make_pair(307, 241)] = 14869218;
      (*this)[make_pair(307, 242)] = 16777215;
      (*this)[make_pair(307, 243)] = 16777215;
      (*this)[make_pair(307, 244)] = 16777215;
      (*this)[make_pair(307, 245)] = 16777215;
    }
  } s4c;
  map<pair<int, int>, int> table4c;
  void update_table4c()
  {
    for (const auto& x : s4c) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table4c[pos] = x.second;
    }
  }
  // "3,000" data
  //  ^^
  struct table3c_t : map<pair<int, int>, int> {
    table3c_t()
    {
      (*this)[make_pair(295, 233)] = 16777215;
      (*this)[make_pair(295, 234)] = 16777215;
      (*this)[make_pair(295, 235)] = 16777215;
      (*this)[make_pair(295, 236)] = 16777215;
      (*this)[make_pair(295, 237)] = 16777215;
      (*this)[make_pair(295, 238)] = 16777215;
      (*this)[make_pair(295, 239)] = 16777215;
      (*this)[make_pair(295, 240)] = 16777215;
      (*this)[make_pair(295, 241)] = 16777215;
      (*this)[make_pair(295, 242)] = 16777215;
      (*this)[make_pair(295, 243)] = 16777215;
      (*this)[make_pair(295, 244)] = 16777215;
      (*this)[make_pair(295, 245)] = 16777215;
      (*this)[make_pair(296, 233)] = 16777215;
      (*this)[make_pair(296, 234)] = 16777215;
      (*this)[make_pair(296, 235)] = 16777215;
      (*this)[make_pair(296, 236)] = 16777215;
      (*this)[make_pair(296, 237)] = 16777215;
      (*this)[make_pair(296, 238)] = 16777215;
      (*this)[make_pair(296, 239)] = 16777215;
      (*this)[make_pair(296, 240)] = 16777215;
      (*this)[make_pair(296, 241)] = 16777215;
      (*this)[make_pair(296, 242)] = 16777215;
      (*this)[make_pair(296, 243)] = 16777215;
      (*this)[make_pair(296, 244)] = 16777215;
      (*this)[make_pair(296, 245)] = 16777215;
      (*this)[make_pair(297, 233)] = 16777215;
      (*this)[make_pair(297, 234)] = 16777215;
      (*this)[make_pair(297, 235)] = 16777215;
      (*this)[make_pair(297, 236)] = 16777215;
      (*this)[make_pair(297, 237)] = 16777215;
      (*this)[make_pair(297, 238)] = 16777215;
      (*this)[make_pair(297, 239)] = 16777215;
      (*this)[make_pair(297, 240)] = 16777215;
      (*this)[make_pair(297, 241)] = 16777215;
      (*this)[make_pair(297, 242)] = 16777215;
      (*this)[make_pair(297, 243)] = 16777215;
      (*this)[make_pair(297, 244)] = 16777215;
      (*this)[make_pair(297, 245)] = 16777215;
      (*this)[make_pair(298, 233)] = 16777215;
      (*this)[make_pair(298, 234)] = 16777215;
      (*this)[make_pair(298, 235)] = 16777215;
      (*this)[make_pair(298, 236)] = 16777215;
      (*this)[make_pair(298, 237)] = 16777215;
      (*this)[make_pair(298, 238)] = 16777215;
      (*this)[make_pair(298, 239)] = 16777215;
      (*this)[make_pair(298, 240)] = 16777215;
      (*this)[make_pair(298, 241)] = 16777215;
      (*this)[make_pair(298, 242)] = 16777215;
      (*this)[make_pair(298, 243)] = 16777215;
      (*this)[make_pair(298, 244)] = 16777215;
      (*this)[make_pair(298, 245)] = 16777215;
      (*this)[make_pair(299, 233)] = 15395562;
      (*this)[make_pair(299, 234)] = 10724259;
      (*this)[make_pair(299, 235)] = 16777215;
      (*this)[make_pair(299, 236)] = 16777215;
      (*this)[make_pair(299, 237)] = 16777215;
      (*this)[make_pair(299, 238)] = 16777215;
      (*this)[make_pair(299, 239)] = 16777215;
      (*this)[make_pair(299, 240)] = 16250871;
      (*this)[make_pair(299, 241)] = 9737364;
      (*this)[make_pair(299, 242)] = 16777215;
      (*this)[make_pair(299, 243)] = 16777215;
      (*this)[make_pair(299, 244)] = 16777215;
      (*this)[make_pair(299, 245)] = 16777215;
      (*this)[make_pair(300, 233)] = 15329769;
      (*this)[make_pair(300, 234)] = 10592673;
      (*this)[make_pair(300, 235)] = 16777215;
      (*this)[make_pair(300, 236)] = 14277081;
      (*this)[make_pair(300, 237)] = 8421504;
      (*this)[make_pair(300, 238)] = 16777215;
      (*this)[make_pair(300, 239)] = 16777215;
      (*this)[make_pair(300, 240)] = 16777215;
      (*this)[make_pair(300, 241)] = 9145227;
      (*this)[make_pair(300, 242)] = 16579836;
      (*this)[make_pair(300, 243)] = 16777215;
      (*this)[make_pair(300, 244)] = 16777215;
      (*this)[make_pair(300, 245)] = 16777215;
      (*this)[make_pair(301, 233)] = 15329769;
      (*this)[make_pair(301, 234)] = 10592673;
      (*this)[make_pair(301, 235)] = 14342874;
      (*this)[make_pair(301, 236)] = 8816262;
      (*this)[make_pair(301, 237)] = 8882055;
      (*this)[make_pair(301, 238)] = 16119285;
      (*this)[make_pair(301, 239)] = 16777215;
      (*this)[make_pair(301, 240)] = 16777215;
      (*this)[make_pair(301, 241)] = 9474192;
      (*this)[make_pair(301, 242)] = 16514043;
      (*this)[make_pair(301, 243)] = 16777215;
      (*this)[make_pair(301, 244)] = 16777215;
      (*this)[make_pair(301, 245)] = 16777215;
      (*this)[make_pair(302, 233)] = 15329769;
      (*this)[make_pair(302, 234)] = 8750469;
      (*this)[make_pair(302, 235)] = 8816262;
      (*this)[make_pair(302, 236)] = 15856113;
      (*this)[make_pair(302, 237)] = 12303291;
      (*this)[make_pair(302, 238)] = 11908533;
      (*this)[make_pair(302, 239)] = 16316664;
      (*this)[make_pair(302, 240)] = 13487565;
      (*this)[make_pair(302, 241)] = 10197915;
      (*this)[make_pair(302, 242)] = 16777215;
      (*this)[make_pair(302, 243)] = 16777215;
      (*this)[make_pair(302, 244)] = 16777215;
      (*this)[make_pair(302, 245)] = 16777215;
      (*this)[make_pair(303, 233)] = 15658734;
      (*this)[make_pair(303, 234)] = 9211020;
      (*this)[make_pair(303, 235)] = 15856113;
      (*this)[make_pair(303, 236)] = 16777215;
      (*this)[make_pair(303, 237)] = 15987699;
      (*this)[make_pair(303, 238)] = 10987431;
      (*this)[make_pair(303, 239)] = 8355711;
      (*this)[make_pair(303, 240)] = 11184810;
      (*this)[make_pair(303, 241)] = 15461355;
      (*this)[make_pair(303, 242)] = 16777215;
      (*this)[make_pair(303, 243)] = 16777215;
      (*this)[make_pair(303, 244)] = 16777215;
      (*this)[make_pair(303, 245)] = 16777215;
      (*this)[make_pair(304, 233)] = 16777215;
      (*this)[make_pair(304, 234)] = 16777215;
      (*this)[make_pair(304, 235)] = 16777215;
      (*this)[make_pair(304, 236)] = 16777215;
      (*this)[make_pair(304, 237)] = 16777215;
      (*this)[make_pair(304, 238)] = 16777215;
      (*this)[make_pair(304, 239)] = 16777215;
      (*this)[make_pair(304, 240)] = 16777215;
      (*this)[make_pair(304, 241)] = 16777215;
      (*this)[make_pair(304, 242)] = 16777215;
      (*this)[make_pair(304, 243)] = 16777215;
      (*this)[make_pair(304, 244)] = 16777215;
      (*this)[make_pair(304, 245)] = 16777215;
      (*this)[make_pair(305, 233)] = 16777215;
      (*this)[make_pair(305, 234)] = 16777215;
      (*this)[make_pair(305, 235)] = 16777215;
      (*this)[make_pair(305, 236)] = 16777215;
      (*this)[make_pair(305, 237)] = 16777215;
      (*this)[make_pair(305, 238)] = 16777215;
      (*this)[make_pair(305, 239)] = 16777215;
      (*this)[make_pair(305, 240)] = 16777215;
      (*this)[make_pair(305, 241)] = 16777215;
      (*this)[make_pair(305, 242)] = 15658734;
      (*this)[make_pair(305, 243)] = 16250871;
      (*this)[make_pair(305, 244)] = 16777215;
      (*this)[make_pair(305, 245)] = 16777215;
      (*this)[make_pair(306, 233)] = 16777215;
      (*this)[make_pair(306, 234)] = 16777215;
      (*this)[make_pair(306, 235)] = 16777215;
      (*this)[make_pair(306, 236)] = 16777215;
      (*this)[make_pair(306, 237)] = 16777215;
      (*this)[make_pair(306, 238)] = 16777215;
      (*this)[make_pair(306, 239)] = 16777215;
      (*this)[make_pair(306, 240)] = 13816530;
      (*this)[make_pair(306, 241)] = 8618883;
      (*this)[make_pair(306, 242)] = 8947848;
      (*this)[make_pair(306, 243)] = 15658734;
      (*this)[make_pair(306, 244)] = 16777215;
      (*this)[make_pair(306, 245)] = 16777215;
      (*this)[make_pair(307, 233)] = 16777215;
      (*this)[make_pair(307, 234)] = 16777215;
      (*this)[make_pair(307, 235)] = 16777215;
      (*this)[make_pair(307, 236)] = 16777215;
      (*this)[make_pair(307, 237)] = 16777215;
      (*this)[make_pair(307, 238)] = 16777215;
      (*this)[make_pair(307, 239)] = 16777215;
      (*this)[make_pair(307, 240)] = 14277081;
      (*this)[make_pair(307, 241)] = 14869218;
      (*this)[make_pair(307, 242)] = 16777215;
      (*this)[make_pair(307, 243)] = 16777215;
      (*this)[make_pair(307, 244)] = 16777215;
      (*this)[make_pair(307, 245)] = 16777215;
    }
  } s3c;
  map<pair<int, int>, int> table3c;
  void update_table3c()
  {
    for (const auto& x : s3c) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table3c[pos] = x.second;
    }
  }
  
  // "6,000" data
  //  ^^
  struct table6c_t : map<pair<int, int>, int> {
    table6c_t()
    {
      (*this)[make_pair(295, 233)] = 16777215;
      (*this)[make_pair(295, 234)] = 16777215;
      (*this)[make_pair(295, 235)] = 16777215;
      (*this)[make_pair(295, 236)] = 16777215;
      (*this)[make_pair(295, 237)] = 16777215;
      (*this)[make_pair(295, 238)] = 16777215;
      (*this)[make_pair(295, 239)] = 16777215;
      (*this)[make_pair(295, 240)] = 16777215;
      (*this)[make_pair(295, 241)] = 16777215;
      (*this)[make_pair(295, 242)] = 16777215;
      (*this)[make_pair(295, 243)] = 16777215;
      (*this)[make_pair(295, 244)] = 16777215;
      (*this)[make_pair(295, 245)] = 16777215;
      (*this)[make_pair(296, 233)] = 16777215;
      (*this)[make_pair(296, 234)] = 16777215;
      (*this)[make_pair(296, 235)] = 16777215;
      (*this)[make_pair(296, 236)] = 16777215;
      (*this)[make_pair(296, 237)] = 16777215;
      (*this)[make_pair(296, 238)] = 16777215;
      (*this)[make_pair(296, 239)] = 16777215;
      (*this)[make_pair(296, 240)] = 16777215;
      (*this)[make_pair(296, 241)] = 16777215;
      (*this)[make_pair(296, 242)] = 16777215;
      (*this)[make_pair(296, 243)] = 16777215;
      (*this)[make_pair(296, 244)] = 16777215;
      (*this)[make_pair(296, 245)] = 16777215;
      (*this)[make_pair(297, 233)] = 16777215;
      (*this)[make_pair(297, 234)] = 16777215;
      (*this)[make_pair(297, 235)] = 16777215;
      (*this)[make_pair(297, 236)] = 16777215;
      (*this)[make_pair(297, 237)] = 16777215;
      (*this)[make_pair(297, 238)] = 16777215;
      (*this)[make_pair(297, 239)] = 16777215;
      (*this)[make_pair(297, 240)] = 16777215;
      (*this)[make_pair(297, 241)] = 16777215;
      (*this)[make_pair(297, 242)] = 16777215;
      (*this)[make_pair(297, 243)] = 16777215;
      (*this)[make_pair(297, 244)] = 16777215;
      (*this)[make_pair(297, 245)] = 16777215;
      (*this)[make_pair(298, 233)] = 16777215;
      (*this)[make_pair(298, 234)] = 16777215;
      (*this)[make_pair(298, 235)] = 16777215;
      (*this)[make_pair(298, 236)] = 16053492;
      (*this)[make_pair(298, 237)] = 14803425;
      (*this)[make_pair(298, 238)] = 14277081;
      (*this)[make_pair(298, 239)] = 16250871;
      (*this)[make_pair(298, 240)] = 16777215;
      (*this)[make_pair(298, 241)] = 16777215;
      (*this)[make_pair(298, 242)] = 16777215;
      (*this)[make_pair(298, 243)] = 16777215;
      (*this)[make_pair(298, 244)] = 16777215;
      (*this)[make_pair(298, 245)] = 16777215;
      (*this)[make_pair(299, 233)] = 16777215;
      (*this)[make_pair(299, 234)] = 15987699;
      (*this)[make_pair(299, 235)] = 10066329;
      (*this)[make_pair(299, 236)] = 7434609;
      (*this)[make_pair(299, 237)] = 8158332;
      (*this)[make_pair(299, 238)] = 7763574;
      (*this)[make_pair(299, 239)] = 9737364;
      (*this)[make_pair(299, 240)] = 9342606;
      (*this)[make_pair(299, 241)] = 14803425;
      (*this)[make_pair(299, 242)] = 16777215;
      (*this)[make_pair(299, 243)] = 16777215;
      (*this)[make_pair(299, 244)] = 16777215;
      (*this)[make_pair(299, 245)] = 16777215;
      (*this)[make_pair(300, 233)] = 16777215;
      (*this)[make_pair(300, 234)] = 9474192;
      (*this)[make_pair(300, 235)] = 12763842;
      (*this)[make_pair(300, 236)] = 16514043;
      (*this)[make_pair(300, 237)] = 11382189;
      (*this)[make_pair(300, 238)] = 16645629;
      (*this)[make_pair(300, 239)] = 16777215;
      (*this)[make_pair(300, 240)] = 15527148;
      (*this)[make_pair(300, 241)] = 10263708;
      (*this)[make_pair(300, 242)] = 16777215;
      (*this)[make_pair(300, 243)] = 16777215;
      (*this)[make_pair(300, 244)] = 16777215;
      (*this)[make_pair(300, 245)] = 16777215;
      (*this)[make_pair(301, 233)] = 16316664;
      (*this)[make_pair(301, 234)] = 8618883;
      (*this)[make_pair(301, 235)] = 16777215;
      (*this)[make_pair(301, 236)] = 14671839;
      (*this)[make_pair(301, 237)] = 12500670;
      (*this)[make_pair(301, 238)] = 16777215;
      (*this)[make_pair(301, 239)] = 16777215;
      (*this)[make_pair(301, 240)] = 16777215;
      (*this)[make_pair(301, 241)] = 9605778;
      (*this)[make_pair(301, 242)] = 16514043;
      (*this)[make_pair(301, 243)] = 16777215;
      (*this)[make_pair(301, 244)] = 16777215;
      (*this)[make_pair(301, 245)] = 16777215;
      (*this)[make_pair(302, 233)] = 16185078;
      (*this)[make_pair(302, 234)] = 9803157;
      (*this)[make_pair(302, 235)] = 16777215;
      (*this)[make_pair(302, 236)] = 15790320;
      (*this)[make_pair(302, 237)] = 10066329;
      (*this)[make_pair(302, 238)] = 16777215;
      (*this)[make_pair(302, 239)] = 16777215;
      (*this)[make_pair(302, 240)] = 16448250;
      (*this)[make_pair(302, 241)] = 9605778;
      (*this)[make_pair(302, 242)] = 16777215;
      (*this)[make_pair(302, 243)] = 16777215;
      (*this)[make_pair(302, 244)] = 16777215;
      (*this)[make_pair(302, 245)] = 16777215;
      (*this)[make_pair(303, 233)] = 16777215;
      (*this)[make_pair(303, 234)] = 12171705;
      (*this)[make_pair(303, 235)] = 16777215;
      (*this)[make_pair(303, 236)] = 16777215;
      (*this)[make_pair(303, 237)] = 10790052;
      (*this)[make_pair(303, 238)] = 8947848;
      (*this)[make_pair(303, 239)] = 10724259;
      (*this)[make_pair(303, 240)] = 8684676;
      (*this)[make_pair(303, 241)] = 13684944;
      (*this)[make_pair(303, 242)] = 16777215;
      (*this)[make_pair(303, 243)] = 16777215;
      (*this)[make_pair(303, 244)] = 16777215;
      (*this)[make_pair(303, 245)] = 16777215;
      (*this)[make_pair(304, 233)] = 16777215;
      (*this)[make_pair(304, 234)] = 16777215;
      (*this)[make_pair(304, 235)] = 16777215;
      (*this)[make_pair(304, 236)] = 16777215;
      (*this)[make_pair(304, 237)] = 16777215;
      (*this)[make_pair(304, 238)] = 15790320;
      (*this)[make_pair(304, 239)] = 14145495;
      (*this)[make_pair(304, 240)] = 16645629;
      (*this)[make_pair(304, 241)] = 16777215;
      (*this)[make_pair(304, 242)] = 16777215;
      (*this)[make_pair(304, 243)] = 16777215;
      (*this)[make_pair(304, 244)] = 16777215;
      (*this)[make_pair(304, 245)] = 16777215;
      (*this)[make_pair(305, 233)] = 16777215;
      (*this)[make_pair(305, 234)] = 16777215;
      (*this)[make_pair(305, 235)] = 16777215;
      (*this)[make_pair(305, 236)] = 16777215;
      (*this)[make_pair(305, 237)] = 16777215;
      (*this)[make_pair(305, 238)] = 16777215;
      (*this)[make_pair(305, 239)] = 16777215;
      (*this)[make_pair(305, 240)] = 16777215;
      (*this)[make_pair(305, 241)] = 16777215;
      (*this)[make_pair(305, 242)] = 15658734;
      (*this)[make_pair(305, 243)] = 16250871;
      (*this)[make_pair(305, 244)] = 16777215;
      (*this)[make_pair(305, 245)] = 16777215;
      (*this)[make_pair(306, 233)] = 16777215;
      (*this)[make_pair(306, 234)] = 16777215;
      (*this)[make_pair(306, 235)] = 16777215;
      (*this)[make_pair(306, 236)] = 16777215;
      (*this)[make_pair(306, 237)] = 16777215;
      (*this)[make_pair(306, 238)] = 16777215;
      (*this)[make_pair(306, 239)] = 16777215;
      (*this)[make_pair(306, 240)] = 13816530;
      (*this)[make_pair(306, 241)] = 8618883;
      (*this)[make_pair(306, 242)] = 8947848;
      (*this)[make_pair(306, 243)] = 15658734;
      (*this)[make_pair(306, 244)] = 16777215;
      (*this)[make_pair(306, 245)] = 16777215;
      (*this)[make_pair(307, 233)] = 16777215;
      (*this)[make_pair(307, 234)] = 16777215;
      (*this)[make_pair(307, 235)] = 16777215;
      (*this)[make_pair(307, 236)] = 16777215;
      (*this)[make_pair(307, 237)] = 16777215;
      (*this)[make_pair(307, 238)] = 16777215;
      (*this)[make_pair(307, 239)] = 16777215;
      (*this)[make_pair(307, 240)] = 14277081;
      (*this)[make_pair(307, 241)] = 14869218;
      (*this)[make_pair(307, 242)] = 16777215;
      (*this)[make_pair(307, 243)] = 16777215;
      (*this)[make_pair(307, 244)] = 16777215;
      (*this)[make_pair(307, 245)] = 16777215;
    }
  } s6c;
  map<pair<int, int>, int> table6c;
  void update_table6c()
  {
    for (const auto& x : s6c) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table6c[pos] = x.second;
    }
  }
  
  // "10,000" data
  //  ^^
  struct table10c_t : map<pair<int, int>, int> {
    table10c_t()
    {
      (*this)[make_pair(295, 233)] = 16777215;
      (*this)[make_pair(295, 234)] = 16777215;
      (*this)[make_pair(295, 235)] = 16777215;
      (*this)[make_pair(295, 236)] = 16777215;
      (*this)[make_pair(295, 237)] = 16777215;
      (*this)[make_pair(295, 238)] = 16777215;
      (*this)[make_pair(295, 239)] = 16777215;
      (*this)[make_pair(295, 240)] = 16777215;
      (*this)[make_pair(295, 241)] = 16777215;
      (*this)[make_pair(295, 242)] = 16777215;
      (*this)[make_pair(295, 243)] = 16777215;
      (*this)[make_pair(295, 244)] = 16777215;
      (*this)[make_pair(295, 245)] = 16777215;
      (*this)[make_pair(296, 233)] = 16777215;
      (*this)[make_pair(296, 234)] = 16777215;
      (*this)[make_pair(296, 235)] = 12632256;
      (*this)[make_pair(296, 236)] = 13816530;
      (*this)[make_pair(296, 237)] = 16777215;
      (*this)[make_pair(296, 238)] = 16777215;
      (*this)[make_pair(296, 239)] = 16777215;
      (*this)[make_pair(296, 240)] = 16777215;
      (*this)[make_pair(296, 241)] = 16777215;
      (*this)[make_pair(296, 242)] = 16777215;
      (*this)[make_pair(296, 243)] = 16777215;
      (*this)[make_pair(296, 244)] = 16777215;
      (*this)[make_pair(296, 245)] = 16777215;
      (*this)[make_pair(297, 233)] = 16777215;
      (*this)[make_pair(297, 234)] = 13882323;
      (*this)[make_pair(297, 235)] = 9868950;
      (*this)[make_pair(297, 236)] = 16711422;
      (*this)[make_pair(297, 237)] = 16777215;
      (*this)[make_pair(297, 238)] = 16777215;
      (*this)[make_pair(297, 239)] = 16777215;
      (*this)[make_pair(297, 240)] = 16777215;
      (*this)[make_pair(297, 241)] = 16777215;
      (*this)[make_pair(297, 242)] = 16777215;
      (*this)[make_pair(297, 243)] = 16777215;
      (*this)[make_pair(297, 244)] = 16777215;
      (*this)[make_pair(297, 245)] = 16777215;
      (*this)[make_pair(298, 233)] = 16053492;
      (*this)[make_pair(298, 234)] = 7500402;
      (*this)[make_pair(298, 235)] = 11842740;
      (*this)[make_pair(298, 236)] = 12369084;
      (*this)[make_pair(298, 237)] = 12369084;
      (*this)[make_pair(298, 238)] = 12369084;
      (*this)[make_pair(298, 239)] = 12369084;
      (*this)[make_pair(298, 240)] = 12369084;
      (*this)[make_pair(298, 241)] = 12369084;
      (*this)[make_pair(298, 242)] = 16777215;
      (*this)[make_pair(298, 243)] = 16777215;
      (*this)[make_pair(298, 244)] = 16777215;
      (*this)[make_pair(298, 245)] = 16777215;
      (*this)[make_pair(299, 233)] = 16185078;
      (*this)[make_pair(299, 234)] = 12369084;
      (*this)[make_pair(299, 235)] = 12369084;
      (*this)[make_pair(299, 236)] = 12369084;
      (*this)[make_pair(299, 237)] = 12369084;
      (*this)[make_pair(299, 238)] = 12369084;
      (*this)[make_pair(299, 239)] = 12369084;
      (*this)[make_pair(299, 240)] = 12369084;
      (*this)[make_pair(299, 241)] = 12369084;
      (*this)[make_pair(299, 242)] = 16777215;
      (*this)[make_pair(299, 243)] = 16777215;
      (*this)[make_pair(299, 244)] = 16777215;
      (*this)[make_pair(299, 245)] = 16777215;
      (*this)[make_pair(300, 233)] = 16777215;
      (*this)[make_pair(300, 234)] = 16777215;
      (*this)[make_pair(300, 235)] = 16777215;
      (*this)[make_pair(300, 236)] = 16777215;
      (*this)[make_pair(300, 237)] = 16777215;
      (*this)[make_pair(300, 238)] = 16777215;
      (*this)[make_pair(300, 239)] = 16777215;
      (*this)[make_pair(300, 240)] = 16777215;
      (*this)[make_pair(300, 241)] = 16777215;
      (*this)[make_pair(300, 242)] = 16777215;
      (*this)[make_pair(300, 243)] = 16777215;
      (*this)[make_pair(300, 244)] = 16777215;
      (*this)[make_pair(300, 245)] = 16777215;
      (*this)[make_pair(301, 233)] = 16777215;
      (*this)[make_pair(301, 234)] = 16777215;
      (*this)[make_pair(301, 235)] = 16777215;
      (*this)[make_pair(301, 236)] = 16777215;
      (*this)[make_pair(301, 237)] = 16777215;
      (*this)[make_pair(301, 238)] = 16777215;
      (*this)[make_pair(301, 239)] = 16777215;
      (*this)[make_pair(301, 240)] = 16777215;
      (*this)[make_pair(301, 241)] = 16777215;
      (*this)[make_pair(301, 242)] = 16777215;
      (*this)[make_pair(301, 243)] = 16777215;
      (*this)[make_pair(301, 244)] = 16777215;
      (*this)[make_pair(301, 245)] = 16777215;
      (*this)[make_pair(302, 233)] = 16777215;
      (*this)[make_pair(302, 234)] = 16777215;
      (*this)[make_pair(302, 235)] = 16448250;
      (*this)[make_pair(302, 236)] = 14211288;
      (*this)[make_pair(302, 237)] = 13158600;
      (*this)[make_pair(302, 238)] = 13158600;
      (*this)[make_pair(302, 239)] = 14211288;
      (*this)[make_pair(302, 240)] = 16448250;
      (*this)[make_pair(302, 241)] = 16777215;
      (*this)[make_pair(302, 242)] = 16777215;
      (*this)[make_pair(302, 243)] = 16777215;
      (*this)[make_pair(302, 244)] = 16777215;
      (*this)[make_pair(302, 245)] = 16777215;
      (*this)[make_pair(303, 233)] = 16777215;
      (*this)[make_pair(303, 234)] = 14606046;
      (*this)[make_pair(303, 235)] = 8026746;
      (*this)[make_pair(303, 236)] = 9211020;
      (*this)[make_pair(303, 237)] = 11119017;
      (*this)[make_pair(303, 238)] = 11119017;
      (*this)[make_pair(303, 239)] = 9145227;
      (*this)[make_pair(303, 240)] = 8092539;
      (*this)[make_pair(303, 241)] = 14737632;
      (*this)[make_pair(303, 242)] = 16777215;
      (*this)[make_pair(303, 243)] = 16777215;
      (*this)[make_pair(303, 244)] = 16777215;
      (*this)[make_pair(303, 245)] = 16777215;
      (*this)[make_pair(304, 233)] = 16777215;
      (*this)[make_pair(304, 234)] = 10000536;
      (*this)[make_pair(304, 235)] = 15461355;
      (*this)[make_pair(304, 236)] = 16777215;
      (*this)[make_pair(304, 237)] = 16777215;
      (*this)[make_pair(304, 238)] = 16777215;
      (*this)[make_pair(304, 239)] = 16777215;
      (*this)[make_pair(304, 240)] = 15329769;
      (*this)[make_pair(304, 241)] = 10197915;
      (*this)[make_pair(304, 242)] = 16777215;
      (*this)[make_pair(304, 243)] = 16777215;
      (*this)[make_pair(304, 244)] = 16777215;
      (*this)[make_pair(304, 245)] = 16777215;
      (*this)[make_pair(305, 233)] = 16316664;
      (*this)[make_pair(305, 234)] = 9737364;
      (*this)[make_pair(305, 235)] = 16777215;
      (*this)[make_pair(305, 236)] = 16777215;
      (*this)[make_pair(305, 237)] = 16777215;
      (*this)[make_pair(305, 238)] = 16777215;
      (*this)[make_pair(305, 239)] = 16777215;
      (*this)[make_pair(305, 240)] = 16777215;
      (*this)[make_pair(305, 241)] = 9605778;
      (*this)[make_pair(305, 242)] = 16514043;
      (*this)[make_pair(305, 243)] = 16777215;
      (*this)[make_pair(305, 244)] = 16777215;
      (*this)[make_pair(305, 245)] = 16777215;
      (*this)[make_pair(306, 233)] = 16777215;
      (*this)[make_pair(306, 234)] = 10197915;
      (*this)[make_pair(306, 235)] = 15329769;
      (*this)[make_pair(306, 236)] = 16777215;
      (*this)[make_pair(306, 237)] = 16777215;
      (*this)[make_pair(306, 238)] = 16777215;
      (*this)[make_pair(306, 239)] = 16777215;
      (*this)[make_pair(306, 240)] = 15198183;
      (*this)[make_pair(306, 241)] = 10329501;
      (*this)[make_pair(306, 242)] = 16777215;
      (*this)[make_pair(306, 243)] = 16777215;
      (*this)[make_pair(306, 244)] = 16777215;
      (*this)[make_pair(306, 245)] = 16777215;
      (*this)[make_pair(307, 233)] = 16777215;
      (*this)[make_pair(307, 234)] = 14869218;
      (*this)[make_pair(307, 235)] = 8158332;
      (*this)[make_pair(307, 236)] = 8816262;
      (*this)[make_pair(307, 237)] = 10790052;
      (*this)[make_pair(307, 238)] = 10724259;
      (*this)[make_pair(307, 239)] = 8816262;
      (*this)[make_pair(307, 240)] = 8158332;
      (*this)[make_pair(307, 241)] = 14935011;
      (*this)[make_pair(307, 242)] = 16777215;
      (*this)[make_pair(307, 243)] = 16777215;
      (*this)[make_pair(307, 244)] = 16777215;
      (*this)[make_pair(307, 245)] = 16777215;
    }
  } s10c;
  map<pair<int, int>, int> table10c;
  void update_table10c()
  {
    for (const auto& x : s10c) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table10c[pos] = x.second;
    }
  }
  // "20,000" data
  //  ^^
  struct table20c_t : map<pair<int, int>, int> {
    table20c_t()
    {
      (*this)[make_pair(295, 233)] = 16777215;
      (*this)[make_pair(295, 234)] = 16777215;
      (*this)[make_pair(295, 235)] = 16777215;
      (*this)[make_pair(295, 236)] = 16777215;
      (*this)[make_pair(295, 237)] = 16777215;
      (*this)[make_pair(295, 238)] = 16777215;
      (*this)[make_pair(295, 239)] = 16777215;
      (*this)[make_pair(295, 240)] = 16777215;
      (*this)[make_pair(295, 241)] = 16711422;
      (*this)[make_pair(295, 242)] = 16777215;
      (*this)[make_pair(295, 243)] = 16777215;
      (*this)[make_pair(295, 244)] = 16777215;
      (*this)[make_pair(295, 245)] = 16777215;
      (*this)[make_pair(296, 233)] = 16777215;
      (*this)[make_pair(296, 234)] = 10790052;
      (*this)[make_pair(296, 235)] = 15724527;
      (*this)[make_pair(296, 236)] = 16777215;
      (*this)[make_pair(296, 237)] = 16777215;
      (*this)[make_pair(296, 238)] = 16777215;
      (*this)[make_pair(296, 239)] = 16777215;
      (*this)[make_pair(296, 240)] = 14540253;
      (*this)[make_pair(296, 241)] = 7039851;
      (*this)[make_pair(296, 242)] = 16777215;
      (*this)[make_pair(296, 243)] = 16777215;
      (*this)[make_pair(296, 244)] = 16777215;
      (*this)[make_pair(296, 245)] = 16777215;
      (*this)[make_pair(297, 233)] = 16777215;
      (*this)[make_pair(297, 234)] = 9013641;
      (*this)[make_pair(297, 235)] = 16777215;
      (*this)[make_pair(297, 236)] = 16777215;
      (*this)[make_pair(297, 237)] = 16777215;
      (*this)[make_pair(297, 238)] = 16777215;
      (*this)[make_pair(297, 239)] = 15329769;
      (*this)[make_pair(297, 240)] = 8816262;
      (*this)[make_pair(297, 241)] = 8553090;
      (*this)[make_pair(297, 242)] = 16777215;
      (*this)[make_pair(297, 243)] = 16777215;
      (*this)[make_pair(297, 244)] = 16777215;
      (*this)[make_pair(297, 245)] = 16777215;
      (*this)[make_pair(298, 233)] = 16119285;
      (*this)[make_pair(298, 234)] = 9737364;
      (*this)[make_pair(298, 235)] = 16777215;
      (*this)[make_pair(298, 236)] = 16777215;
      (*this)[make_pair(298, 237)] = 16777215;
      (*this)[make_pair(298, 238)] = 15198183;
      (*this)[make_pair(298, 239)] = 8684676;
      (*this)[make_pair(298, 240)] = 15329769;
      (*this)[make_pair(298, 241)] = 9342606;
      (*this)[make_pair(298, 242)] = 16777215;
      (*this)[make_pair(298, 243)] = 16777215;
      (*this)[make_pair(298, 244)] = 16777215;
      (*this)[make_pair(298, 245)] = 16777215;
      (*this)[make_pair(299, 233)] = 16777215;
      (*this)[make_pair(299, 234)] = 9276813;
      (*this)[make_pair(299, 235)] = 14145495;
      (*this)[make_pair(299, 236)] = 15395562;
      (*this)[make_pair(299, 237)] = 11382189;
      (*this)[make_pair(299, 238)] = 8618883;
      (*this)[make_pair(299, 239)] = 15132390;
      (*this)[make_pair(299, 240)] = 16777215;
      (*this)[make_pair(299, 241)] = 9342606;
      (*this)[make_pair(299, 242)] = 16777215;
      (*this)[make_pair(299, 243)] = 16777215;
      (*this)[make_pair(299, 244)] = 16777215;
      (*this)[make_pair(299, 245)] = 16777215;
      (*this)[make_pair(300, 233)] = 16777215;
      (*this)[make_pair(300, 234)] = 14803425;
      (*this)[make_pair(300, 235)] = 10197915;
      (*this)[make_pair(300, 236)] = 9013641;
      (*this)[make_pair(300, 237)] = 12566463;
      (*this)[make_pair(300, 238)] = 16119285;
      (*this)[make_pair(300, 239)] = 16777215;
      (*this)[make_pair(300, 240)] = 16777215;
      (*this)[make_pair(300, 241)] = 9803157;
      (*this)[make_pair(300, 242)] = 16777215;
      (*this)[make_pair(300, 243)] = 16777215;
      (*this)[make_pair(300, 244)] = 16777215;
      (*this)[make_pair(300, 245)] = 16777215;
      (*this)[make_pair(301, 233)] = 16777215;
      (*this)[make_pair(301, 234)] = 16777215;
      (*this)[make_pair(301, 235)] = 16777215;
      (*this)[make_pair(301, 236)] = 16777215;
      (*this)[make_pair(301, 237)] = 16777215;
      (*this)[make_pair(301, 238)] = 16777215;
      (*this)[make_pair(301, 239)] = 16777215;
      (*this)[make_pair(301, 240)] = 16777215;
      (*this)[make_pair(301, 241)] = 16777215;
      (*this)[make_pair(301, 242)] = 16777215;
      (*this)[make_pair(301, 243)] = 16777215;
      (*this)[make_pair(301, 244)] = 16777215;
      (*this)[make_pair(301, 245)] = 16777215;
      (*this)[make_pair(302, 233)] = 16777215;
      (*this)[make_pair(302, 234)] = 16777215;
      (*this)[make_pair(302, 235)] = 16448250;
      (*this)[make_pair(302, 236)] = 14211288;
      (*this)[make_pair(302, 237)] = 13158600;
      (*this)[make_pair(302, 238)] = 13158600;
      (*this)[make_pair(302, 239)] = 14211288;
      (*this)[make_pair(302, 240)] = 16448250;
      (*this)[make_pair(302, 241)] = 16777215;
      (*this)[make_pair(302, 242)] = 16777215;
      (*this)[make_pair(302, 243)] = 16777215;
      (*this)[make_pair(302, 244)] = 16777215;
      (*this)[make_pair(302, 245)] = 16777215;
      (*this)[make_pair(303, 233)] = 16777215;
      (*this)[make_pair(303, 234)] = 14606046;
      (*this)[make_pair(303, 235)] = 8026746;
      (*this)[make_pair(303, 236)] = 9211020;
      (*this)[make_pair(303, 237)] = 11119017;
      (*this)[make_pair(303, 238)] = 11119017;
      (*this)[make_pair(303, 239)] = 9145227;
      (*this)[make_pair(303, 240)] = 8092539;
      (*this)[make_pair(303, 241)] = 14737632;
      (*this)[make_pair(303, 242)] = 16777215;
      (*this)[make_pair(303, 243)] = 16777215;
      (*this)[make_pair(303, 244)] = 16777215;
      (*this)[make_pair(303, 245)] = 16777215;
      (*this)[make_pair(304, 233)] = 16777215;
      (*this)[make_pair(304, 234)] = 10000536;
      (*this)[make_pair(304, 235)] = 15461355;
      (*this)[make_pair(304, 236)] = 16777215;
      (*this)[make_pair(304, 237)] = 16777215;
      (*this)[make_pair(304, 238)] = 16777215;
      (*this)[make_pair(304, 239)] = 16777215;
      (*this)[make_pair(304, 240)] = 15329769;
      (*this)[make_pair(304, 241)] = 10197915;
      (*this)[make_pair(304, 242)] = 16777215;
      (*this)[make_pair(304, 243)] = 16777215;
      (*this)[make_pair(304, 244)] = 16777215;
      (*this)[make_pair(304, 245)] = 16777215;
      (*this)[make_pair(305, 233)] = 16316664;
      (*this)[make_pair(305, 234)] = 9737364;
      (*this)[make_pair(305, 235)] = 16777215;
      (*this)[make_pair(305, 236)] = 16777215;
      (*this)[make_pair(305, 237)] = 16777215;
      (*this)[make_pair(305, 238)] = 16777215;
      (*this)[make_pair(305, 239)] = 16777215;
      (*this)[make_pair(305, 240)] = 16777215;
      (*this)[make_pair(305, 241)] = 9605778;
      (*this)[make_pair(305, 242)] = 16514043;
      (*this)[make_pair(305, 243)] = 16777215;
      (*this)[make_pair(305, 244)] = 16777215;
      (*this)[make_pair(305, 245)] = 16777215;
      (*this)[make_pair(306, 233)] = 16777215;
      (*this)[make_pair(306, 234)] = 10197915;
      (*this)[make_pair(306, 235)] = 15329769;
      (*this)[make_pair(306, 236)] = 16777215;
      (*this)[make_pair(306, 237)] = 16777215;
      (*this)[make_pair(306, 238)] = 16777215;
      (*this)[make_pair(306, 239)] = 16777215;
      (*this)[make_pair(306, 240)] = 15198183;
      (*this)[make_pair(306, 241)] = 10329501;
      (*this)[make_pair(306, 242)] = 16777215;
      (*this)[make_pair(306, 243)] = 16777215;
      (*this)[make_pair(306, 244)] = 16777215;
      (*this)[make_pair(306, 245)] = 16777215;
      (*this)[make_pair(307, 233)] = 16777215;
      (*this)[make_pair(307, 234)] = 14869218;
      (*this)[make_pair(307, 235)] = 8158332;
      (*this)[make_pair(307, 236)] = 8816262;
      (*this)[make_pair(307, 237)] = 10790052;
      (*this)[make_pair(307, 238)] = 10724259;
      (*this)[make_pair(307, 239)] = 8816262;
      (*this)[make_pair(307, 240)] = 8158332;
      (*this)[make_pair(307, 241)] = 14935011;
      (*this)[make_pair(307, 242)] = 16777215;
      (*this)[make_pair(307, 243)] = 16777215;
      (*this)[make_pair(307, 244)] = 16777215;
      (*this)[make_pair(307, 245)] = 16777215;
    }
  } s20c;
  map<pair<int, int>, int> table20c;
  void update_table20c()
  {
    for (const auto& x : s20c) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table20c[pos] = x.second;
    }
  }
  // "15,000" data
  //  ^^
  struct table15c_t : map<pair<int, int>, int> {
    table15c_t()
    {
      (*this)[make_pair(295, 233)] = 16777215;
      (*this)[make_pair(295, 234)] = 16777215;
      (*this)[make_pair(295, 235)] = 16777215;
      (*this)[make_pair(295, 236)] = 16777215;
      (*this)[make_pair(295, 237)] = 16777215;
      (*this)[make_pair(295, 238)] = 16777215;
      (*this)[make_pair(295, 239)] = 16777215;
      (*this)[make_pair(295, 240)] = 16777215;
      (*this)[make_pair(295, 241)] = 16777215;
      (*this)[make_pair(295, 242)] = 16777215;
      (*this)[make_pair(295, 243)] = 16777215;
      (*this)[make_pair(295, 244)] = 16777215;
      (*this)[make_pair(295, 245)] = 16777215;
      (*this)[make_pair(296, 233)] = 16777215;
      (*this)[make_pair(296, 234)] = 16777215;
      (*this)[make_pair(296, 235)] = 12632256;
      (*this)[make_pair(296, 236)] = 13816530;
      (*this)[make_pair(296, 237)] = 16777215;
      (*this)[make_pair(296, 238)] = 16777215;
      (*this)[make_pair(296, 239)] = 16777215;
      (*this)[make_pair(296, 240)] = 16777215;
      (*this)[make_pair(296, 241)] = 16777215;
      (*this)[make_pair(296, 242)] = 16777215;
      (*this)[make_pair(296, 243)] = 16777215;
      (*this)[make_pair(296, 244)] = 16777215;
      (*this)[make_pair(296, 245)] = 16777215;
      (*this)[make_pair(297, 233)] = 16777215;
      (*this)[make_pair(297, 234)] = 13882323;
      (*this)[make_pair(297, 235)] = 9868950;
      (*this)[make_pair(297, 236)] = 16711422;
      (*this)[make_pair(297, 237)] = 16777215;
      (*this)[make_pair(297, 238)] = 16777215;
      (*this)[make_pair(297, 239)] = 16777215;
      (*this)[make_pair(297, 240)] = 16777215;
      (*this)[make_pair(297, 241)] = 16777215;
      (*this)[make_pair(297, 242)] = 16777215;
      (*this)[make_pair(297, 243)] = 16777215;
      (*this)[make_pair(297, 244)] = 16777215;
      (*this)[make_pair(297, 245)] = 16777215;
      (*this)[make_pair(298, 233)] = 16053492;
      (*this)[make_pair(298, 234)] = 7500402;
      (*this)[make_pair(298, 235)] = 11842740;
      (*this)[make_pair(298, 236)] = 12369084;
      (*this)[make_pair(298, 237)] = 12369084;
      (*this)[make_pair(298, 238)] = 12369084;
      (*this)[make_pair(298, 239)] = 12369084;
      (*this)[make_pair(298, 240)] = 12369084;
      (*this)[make_pair(298, 241)] = 12369084;
      (*this)[make_pair(298, 242)] = 16777215;
      (*this)[make_pair(298, 243)] = 16777215;
      (*this)[make_pair(298, 244)] = 16777215;
      (*this)[make_pair(298, 245)] = 16777215;
      (*this)[make_pair(299, 233)] = 16185078;
      (*this)[make_pair(299, 234)] = 12369084;
      (*this)[make_pair(299, 235)] = 12369084;
      (*this)[make_pair(299, 236)] = 12369084;
      (*this)[make_pair(299, 237)] = 12369084;
      (*this)[make_pair(299, 238)] = 12369084;
      (*this)[make_pair(299, 239)] = 12369084;
      (*this)[make_pair(299, 240)] = 12369084;
      (*this)[make_pair(299, 241)] = 12369084;
      (*this)[make_pair(299, 242)] = 16777215;
      (*this)[make_pair(299, 243)] = 16777215;
      (*this)[make_pair(299, 244)] = 16777215;
      (*this)[make_pair(299, 245)] = 16777215;
      (*this)[make_pair(300, 233)] = 16777215;
      (*this)[make_pair(300, 234)] = 16777215;
      (*this)[make_pair(300, 235)] = 16777215;
      (*this)[make_pair(300, 236)] = 16777215;
      (*this)[make_pair(300, 237)] = 16777215;
      (*this)[make_pair(300, 238)] = 16777215;
      (*this)[make_pair(300, 239)] = 16777215;
      (*this)[make_pair(300, 240)] = 16777215;
      (*this)[make_pair(300, 241)] = 16777215;
      (*this)[make_pair(300, 242)] = 16777215;
      (*this)[make_pair(300, 243)] = 16777215;
      (*this)[make_pair(300, 244)] = 16777215;
      (*this)[make_pair(300, 245)] = 16777215;
      (*this)[make_pair(301, 233)] = 16777215;
      (*this)[make_pair(301, 234)] = 16777215;
      (*this)[make_pair(301, 235)] = 16777215;
      (*this)[make_pair(301, 236)] = 16777215;
      (*this)[make_pair(301, 237)] = 16777215;
      (*this)[make_pair(301, 238)] = 16777215;
      (*this)[make_pair(301, 239)] = 16777215;
      (*this)[make_pair(301, 240)] = 16777215;
      (*this)[make_pair(301, 241)] = 16777215;
      (*this)[make_pair(301, 242)] = 16777215;
      (*this)[make_pair(301, 243)] = 16777215;
      (*this)[make_pair(301, 244)] = 16777215;
      (*this)[make_pair(301, 245)] = 16777215;
      (*this)[make_pair(302, 233)] = 16777215;
      (*this)[make_pair(302, 234)] = 16777215;
      (*this)[make_pair(302, 235)] = 16777215;
      (*this)[make_pair(302, 236)] = 16777215;
      (*this)[make_pair(302, 237)] = 16777215;
      (*this)[make_pair(302, 238)] = 16777215;
      (*this)[make_pair(302, 239)] = 16777215;
      (*this)[make_pair(302, 240)] = 16777215;
      (*this)[make_pair(302, 241)] = 16777215;
      (*this)[make_pair(302, 242)] = 16777215;
      (*this)[make_pair(302, 243)] = 16777215;
      (*this)[make_pair(302, 244)] = 16777215;
      (*this)[make_pair(302, 245)] = 16777215;
      (*this)[make_pair(303, 233)] = 15987699;
      (*this)[make_pair(303, 234)] = 10724259;
      (*this)[make_pair(303, 235)] = 10132122;
      (*this)[make_pair(303, 236)] = 9605778;
      (*this)[make_pair(303, 237)] = 9013641;
      (*this)[make_pair(303, 238)] = 16185078;
      (*this)[make_pair(303, 239)] = 16777215;
      (*this)[make_pair(303, 240)] = 16316664;
      (*this)[make_pair(303, 241)] = 10000536;
      (*this)[make_pair(303, 242)] = 16777215;
      (*this)[make_pair(303, 243)] = 16777215;
      (*this)[make_pair(303, 244)] = 16777215;
      (*this)[make_pair(303, 245)] = 16777215;
      (*this)[make_pair(304, 233)] = 15329769;
      (*this)[make_pair(304, 234)] = 9737364;
      (*this)[make_pair(304, 235)] = 14935011;
      (*this)[make_pair(304, 236)] = 15592941;
      (*this)[make_pair(304, 237)] = 9013641;
      (*this)[make_pair(304, 238)] = 16711422;
      (*this)[make_pair(304, 239)] = 16777215;
      (*this)[make_pair(304, 240)] = 16777215;
      (*this)[make_pair(304, 241)] = 9145227;
      (*this)[make_pair(304, 242)] = 16579836;
      (*this)[make_pair(304, 243)] = 16777215;
      (*this)[make_pair(304, 244)] = 16777215;
      (*this)[make_pair(304, 245)] = 16777215;
      (*this)[make_pair(305, 233)] = 15329769;
      (*this)[make_pair(305, 234)] = 10592673;
      (*this)[make_pair(305, 235)] = 16777215;
      (*this)[make_pair(305, 236)] = 16119285;
      (*this)[make_pair(305, 237)] = 10197915;
      (*this)[make_pair(305, 238)] = 16777215;
      (*this)[make_pair(305, 239)] = 16777215;
      (*this)[make_pair(305, 240)] = 16777215;
      (*this)[make_pair(305, 241)] = 9474192;
      (*this)[make_pair(305, 242)] = 16514043;
      (*this)[make_pair(305, 243)] = 16777215;
      (*this)[make_pair(305, 244)] = 16777215;
      (*this)[make_pair(305, 245)] = 16777215;
      (*this)[make_pair(306, 233)] = 15329769;
      (*this)[make_pair(306, 234)] = 10592673;
      (*this)[make_pair(306, 235)] = 16777215;
      (*this)[make_pair(306, 236)] = 16777215;
      (*this)[make_pair(306, 237)] = 9408399;
      (*this)[make_pair(306, 238)] = 15461355;
      (*this)[make_pair(306, 239)] = 16711422;
      (*this)[make_pair(306, 240)] = 14013909;
      (*this)[make_pair(306, 241)] = 10197915;
      (*this)[make_pair(306, 242)] = 16777215;
      (*this)[make_pair(306, 243)] = 16777215;
      (*this)[make_pair(306, 244)] = 16777215;
      (*this)[make_pair(306, 245)] = 16777215;
      (*this)[make_pair(307, 233)] = 15790320;
      (*this)[make_pair(307, 234)] = 12500670;
      (*this)[make_pair(307, 235)] = 16777215;
      (*this)[make_pair(307, 236)] = 16777215;
      (*this)[make_pair(307, 237)] = 14211288;
      (*this)[make_pair(307, 238)] = 9408399;
      (*this)[make_pair(307, 239)] = 8158332;
      (*this)[make_pair(307, 240)] = 10658466;
      (*this)[make_pair(307, 241)] = 15198183;
      (*this)[make_pair(307, 242)] = 16777215;
      (*this)[make_pair(307, 243)] = 16777215;
      (*this)[make_pair(307, 244)] = 16777215;
      (*this)[make_pair(307, 245)] = 16777215;
    }
  } s15c;
  map<pair<int, int>, int> table15c;
  void update_table15c()
  {
    for (const auto& x : s15c) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table15c[pos] = x.second;
    }
  }
  
  // "40,000" data
  //  ^^
  struct table40_t : map<pair<int, int>, int> {
    table40_t()
    {
      (*this)[make_pair(256, 235)] = 16777215;
      (*this)[make_pair(256, 236)] = 16777215;
      (*this)[make_pair(256, 237)] = 16777215;
      (*this)[make_pair(256, 238)] = 16777215;
      (*this)[make_pair(256, 239)] = 16777215;
      (*this)[make_pair(256, 240)] = 14935011;
      (*this)[make_pair(256, 241)] = 9539985;
      (*this)[make_pair(256, 242)] = 15921906;
      (*this)[make_pair(256, 243)] = 16777215;
      (*this)[make_pair(256, 244)] = 16777215;
      (*this)[make_pair(256, 245)] = 16777215;
      (*this)[make_pair(256, 246)] = 16777215;
      (*this)[make_pair(256, 247)] = 16777215;
      (*this)[make_pair(257, 235)] = 16777215;
      (*this)[make_pair(257, 236)] = 16777215;
      (*this)[make_pair(257, 237)] = 16777215;
      (*this)[make_pair(257, 238)] = 16711422;
      (*this)[make_pair(257, 239)] = 12171705;
      (*this)[make_pair(257, 240)] = 9737364;
      (*this)[make_pair(257, 241)] = 9539985;
      (*this)[make_pair(257, 242)] = 15658734;
      (*this)[make_pair(257, 243)] = 16777215;
      (*this)[make_pair(257, 244)] = 16777215;
      (*this)[make_pair(257, 245)] = 16777215;
      (*this)[make_pair(257, 246)] = 16777215;
      (*this)[make_pair(257, 247)] = 16777215;
      (*this)[make_pair(258, 235)] = 16777215;
      (*this)[make_pair(258, 236)] = 16777215;
      (*this)[make_pair(258, 237)] = 15592941;
      (*this)[make_pair(258, 238)] = 9605778;
      (*this)[make_pair(258, 239)] = 12434877;
      (*this)[make_pair(258, 240)] = 16711422;
      (*this)[make_pair(258, 241)] = 10461087;
      (*this)[make_pair(258, 242)] = 15658734;
      (*this)[make_pair(258, 243)] = 16777215;
      (*this)[make_pair(258, 244)] = 16777215;
      (*this)[make_pair(258, 245)] = 16777215;
      (*this)[make_pair(258, 246)] = 16777215;
      (*this)[make_pair(258, 247)] = 16777215;
      (*this)[make_pair(259, 235)] = 16777215;
      (*this)[make_pair(259, 236)] = 13158600;
      (*this)[make_pair(259, 237)] = 9342606;
      (*this)[make_pair(259, 238)] = 15132390;
      (*this)[make_pair(259, 239)] = 16777215;
      (*this)[make_pair(259, 240)] = 16777215;
      (*this)[make_pair(259, 241)] = 10461087;
      (*this)[make_pair(259, 242)] = 15658734;
      (*this)[make_pair(259, 243)] = 16777215;
      (*this)[make_pair(259, 244)] = 16777215;
      (*this)[make_pair(259, 245)] = 16777215;
      (*this)[make_pair(259, 246)] = 16777215;
      (*this)[make_pair(259, 247)] = 16777215;
      (*this)[make_pair(260, 235)] = 15461355;
      (*this)[make_pair(260, 236)] = 6974058;
      (*this)[make_pair(260, 237)] = 7763574;
      (*this)[make_pair(260, 238)] = 7960953;
      (*this)[make_pair(260, 239)] = 7960953;
      (*this)[make_pair(260, 240)] = 7960953;
      (*this)[make_pair(260, 241)] = 7171437;
      (*this)[make_pair(260, 242)] = 7829367;
      (*this)[make_pair(260, 243)] = 7960953;
      (*this)[make_pair(260, 244)] = 16777215;
      (*this)[make_pair(260, 245)] = 16777215;
      (*this)[make_pair(260, 246)] = 16777215;
      (*this)[make_pair(260, 247)] = 16777215;
      (*this)[make_pair(261, 235)] = 16777215;
      (*this)[make_pair(261, 236)] = 16777215;
      (*this)[make_pair(261, 237)] = 16777215;
      (*this)[make_pair(261, 238)] = 16777215;
      (*this)[make_pair(261, 239)] = 16777215;
      (*this)[make_pair(261, 240)] = 16777215;
      (*this)[make_pair(261, 241)] = 10461087;
      (*this)[make_pair(261, 242)] = 15658734;
      (*this)[make_pair(261, 243)] = 16777215;
      (*this)[make_pair(261, 244)] = 16777215;
      (*this)[make_pair(261, 245)] = 16777215;
      (*this)[make_pair(261, 246)] = 16777215;
      (*this)[make_pair(261, 247)] = 16777215;
      (*this)[make_pair(262, 235)] = 16777215;
      (*this)[make_pair(262, 236)] = 16777215;
      (*this)[make_pair(262, 237)] = 16777215;
      (*this)[make_pair(262, 238)] = 16777215;
      (*this)[make_pair(262, 239)] = 16777215;
      (*this)[make_pair(262, 240)] = 16777215;
      (*this)[make_pair(262, 241)] = 14737632;
      (*this)[make_pair(262, 242)] = 16448250;
      (*this)[make_pair(262, 243)] = 16777215;
      (*this)[make_pair(262, 244)] = 16777215;
      (*this)[make_pair(262, 245)] = 16777215;
      (*this)[make_pair(262, 246)] = 16777215;
      (*this)[make_pair(262, 247)] = 16777215;
      (*this)[make_pair(263, 235)] = 16777215;
      (*this)[make_pair(263, 236)] = 16777215;
      (*this)[make_pair(263, 237)] = 16448250;
      (*this)[make_pair(263, 238)] = 14211288;
      (*this)[make_pair(263, 239)] = 13158600;
      (*this)[make_pair(263, 240)] = 13158600;
      (*this)[make_pair(263, 241)] = 14211288;
      (*this)[make_pair(263, 242)] = 16448250;
      (*this)[make_pair(263, 243)] = 16777215;
      (*this)[make_pair(263, 244)] = 16777215;
      (*this)[make_pair(263, 245)] = 16777215;
      (*this)[make_pair(263, 246)] = 16777215;
      (*this)[make_pair(263, 247)] = 16777215;
      (*this)[make_pair(264, 235)] = 16777215;
      (*this)[make_pair(264, 236)] = 14606046;
      (*this)[make_pair(264, 237)] = 8026746;
      (*this)[make_pair(264, 238)] = 9211020;
      (*this)[make_pair(264, 239)] = 11119017;
      (*this)[make_pair(264, 240)] = 11119017;
      (*this)[make_pair(264, 241)] = 9145227;
      (*this)[make_pair(264, 242)] = 8092539;
      (*this)[make_pair(264, 243)] = 14737632;
      (*this)[make_pair(264, 244)] = 16777215;
      (*this)[make_pair(264, 245)] = 16777215;
      (*this)[make_pair(264, 246)] = 16777215;
      (*this)[make_pair(264, 247)] = 16777215;
      (*this)[make_pair(265, 235)] = 16777215;
      (*this)[make_pair(265, 236)] = 10000536;
      (*this)[make_pair(265, 237)] = 15461355;
      (*this)[make_pair(265, 238)] = 16777215;
      (*this)[make_pair(265, 239)] = 16777215;
      (*this)[make_pair(265, 240)] = 16777215;
      (*this)[make_pair(265, 241)] = 16777215;
      (*this)[make_pair(265, 242)] = 15329769;
      (*this)[make_pair(265, 243)] = 10197915;
      (*this)[make_pair(265, 244)] = 16777215;
      (*this)[make_pair(265, 245)] = 16777215;
      (*this)[make_pair(265, 246)] = 16777215;
      (*this)[make_pair(265, 247)] = 16777215;
      (*this)[make_pair(266, 235)] = 16316664;
      (*this)[make_pair(266, 236)] = 9737364;
      (*this)[make_pair(266, 237)] = 16777215;
      (*this)[make_pair(266, 238)] = 16777215;
      (*this)[make_pair(266, 239)] = 16777215;
      (*this)[make_pair(266, 240)] = 16777215;
      (*this)[make_pair(266, 241)] = 16777215;
      (*this)[make_pair(266, 242)] = 16777215;
      (*this)[make_pair(266, 243)] = 9605778;
      (*this)[make_pair(266, 244)] = 16514043;
      (*this)[make_pair(266, 245)] = 16777215;
      (*this)[make_pair(266, 246)] = 16777215;
      (*this)[make_pair(266, 247)] = 16777215;
      (*this)[make_pair(267, 235)] = 16777215;
      (*this)[make_pair(267, 236)] = 10197915;
      (*this)[make_pair(267, 237)] = 15329769;
      (*this)[make_pair(267, 238)] = 16777215;
      (*this)[make_pair(267, 239)] = 16777215;
      (*this)[make_pair(267, 240)] = 16777215;
      (*this)[make_pair(267, 241)] = 16777215;
      (*this)[make_pair(267, 242)] = 15198183;
      (*this)[make_pair(267, 243)] = 10329501;
      (*this)[make_pair(267, 244)] = 16777215;
      (*this)[make_pair(267, 245)] = 16777215;
      (*this)[make_pair(267, 246)] = 16777215;
      (*this)[make_pair(267, 247)] = 16777215;
      (*this)[make_pair(268, 235)] = 16777215;
      (*this)[make_pair(268, 236)] = 14869218;
      (*this)[make_pair(268, 237)] = 8158332;
      (*this)[make_pair(268, 238)] = 8816262;
      (*this)[make_pair(268, 239)] = 10790052;
      (*this)[make_pair(268, 240)] = 10724259;
      (*this)[make_pair(268, 241)] = 8816262;
      (*this)[make_pair(268, 242)] = 8158332;
      (*this)[make_pair(268, 243)] = 14935011;
      (*this)[make_pair(268, 244)] = 16777215;
      (*this)[make_pair(268, 245)] = 16777215;
      (*this)[make_pair(268, 246)] = 16777215;
      (*this)[make_pair(268, 247)] = 16777215;
    }
  } s40;
  map<pair<int, int>, int> table40;
  void update_table40()
  {
    for (const auto& x : s40) {
      auto pos = x.first;
      pos.first += time_button.first - 271;
      pos.second += time_button.second - 482;
      table40[pos] = x.second;
    }
  }
  struct table30_t : map<pair<int, int>, int> {
    table30_t()
    {
      (*this)[make_pair(295, 233)] = 16777215;
      (*this)[make_pair(295, 234)] = 16777215;
      (*this)[make_pair(295, 235)] = 16777215;
      (*this)[make_pair(295, 236)] = 16777215;
      (*this)[make_pair(295, 237)] = 16777215;
      (*this)[make_pair(295, 238)] = 16777215;
      (*this)[make_pair(295, 239)] = 16777215;
      (*this)[make_pair(295, 240)] = 16777215;
      (*this)[make_pair(295, 241)] = 16777215;
      (*this)[make_pair(295, 242)] = 16777215;
      (*this)[make_pair(295, 243)] = 16777215;
      (*this)[make_pair(295, 244)] = 16777215;
      (*this)[make_pair(295, 245)] = 16777215;
      (*this)[make_pair(296, 233)] = 15395562;
      (*this)[make_pair(296, 234)] = 10724259;
      (*this)[make_pair(296, 235)] = 16777215;
      (*this)[make_pair(296, 236)] = 16777215;
      (*this)[make_pair(296, 237)] = 16777215;
      (*this)[make_pair(296, 238)] = 16777215;
      (*this)[make_pair(296, 239)] = 16777215;
      (*this)[make_pair(296, 240)] = 16250871;
      (*this)[make_pair(296, 241)] = 9737364;
      (*this)[make_pair(296, 242)] = 16777215;
      (*this)[make_pair(296, 243)] = 16777215;
      (*this)[make_pair(296, 244)] = 16777215;
      (*this)[make_pair(296, 245)] = 16777215;
      (*this)[make_pair(297, 233)] = 15329769;
      (*this)[make_pair(297, 234)] = 10592673;
      (*this)[make_pair(297, 235)] = 16777215;
      (*this)[make_pair(297, 236)] = 14277081;
      (*this)[make_pair(297, 237)] = 8421504;
      (*this)[make_pair(297, 238)] = 16777215;
      (*this)[make_pair(297, 239)] = 16777215;
      (*this)[make_pair(297, 240)] = 16777215;
      (*this)[make_pair(297, 241)] = 9145227;
      (*this)[make_pair(297, 242)] = 16579836;
      (*this)[make_pair(297, 243)] = 16777215;
      (*this)[make_pair(297, 244)] = 16777215;
      (*this)[make_pair(297, 245)] = 16777215;
      (*this)[make_pair(298, 233)] = 15329769;
      (*this)[make_pair(298, 234)] = 10592673;
      (*this)[make_pair(298, 235)] = 14342874;
      (*this)[make_pair(298, 236)] = 8816262;
      (*this)[make_pair(298, 237)] = 8882055;
      (*this)[make_pair(298, 238)] = 16119285;
      (*this)[make_pair(298, 239)] = 16777215;
      (*this)[make_pair(298, 240)] = 16777215;
      (*this)[make_pair(298, 241)] = 9474192;
      (*this)[make_pair(298, 242)] = 16514043;
      (*this)[make_pair(298, 243)] = 16777215;
      (*this)[make_pair(298, 244)] = 16777215;
      (*this)[make_pair(298, 245)] = 16777215;
      (*this)[make_pair(299, 233)] = 15329769;
      (*this)[make_pair(299, 234)] = 8750469;
      (*this)[make_pair(299, 235)] = 8816262;
      (*this)[make_pair(299, 236)] = 15856113;
      (*this)[make_pair(299, 237)] = 12303291;
      (*this)[make_pair(299, 238)] = 11908533;
      (*this)[make_pair(299, 239)] = 16316664;
      (*this)[make_pair(299, 240)] = 13487565;
      (*this)[make_pair(299, 241)] = 10197915;
      (*this)[make_pair(299, 242)] = 16777215;
      (*this)[make_pair(299, 243)] = 16777215;
      (*this)[make_pair(299, 244)] = 16777215;
      (*this)[make_pair(299, 245)] = 16777215;
      (*this)[make_pair(300, 233)] = 15658734;
      (*this)[make_pair(300, 234)] = 9211020;
      (*this)[make_pair(300, 235)] = 15856113;
      (*this)[make_pair(300, 236)] = 16777215;
      (*this)[make_pair(300, 237)] = 15987699;
      (*this)[make_pair(300, 238)] = 10987431;
      (*this)[make_pair(300, 239)] = 8355711;
      (*this)[make_pair(300, 240)] = 11184810;
      (*this)[make_pair(300, 241)] = 15461355;
      (*this)[make_pair(300, 242)] = 16777215;
      (*this)[make_pair(300, 243)] = 16777215;
      (*this)[make_pair(300, 244)] = 16777215;
      (*this)[make_pair(300, 245)] = 16777215;
      (*this)[make_pair(301, 233)] = 16777215;
      (*this)[make_pair(301, 234)] = 16777215;
      (*this)[make_pair(301, 235)] = 16777215;
      (*this)[make_pair(301, 236)] = 16777215;
      (*this)[make_pair(301, 237)] = 16777215;
      (*this)[make_pair(301, 238)] = 16777215;
      (*this)[make_pair(301, 239)] = 16777215;
      (*this)[make_pair(301, 240)] = 16777215;
      (*this)[make_pair(301, 241)] = 16777215;
      (*this)[make_pair(301, 242)] = 16777215;
      (*this)[make_pair(301, 243)] = 16777215;
      (*this)[make_pair(301, 244)] = 16777215;
      (*this)[make_pair(301, 245)] = 16777215;
      (*this)[make_pair(302, 233)] = 16777215;
      (*this)[make_pair(302, 234)] = 16777215;
      (*this)[make_pair(302, 235)] = 16448250;
      (*this)[make_pair(302, 236)] = 14211288;
      (*this)[make_pair(302, 237)] = 13158600;
      (*this)[make_pair(302, 238)] = 13158600;
      (*this)[make_pair(302, 239)] = 14211288;
      (*this)[make_pair(302, 240)] = 16448250;
      (*this)[make_pair(302, 241)] = 16777215;
      (*this)[make_pair(302, 242)] = 16777215;
      (*this)[make_pair(302, 243)] = 16777215;
      (*this)[make_pair(302, 244)] = 16777215;
      (*this)[make_pair(302, 245)] = 16777215;
      (*this)[make_pair(303, 233)] = 16777215;
      (*this)[make_pair(303, 234)] = 14606046;
      (*this)[make_pair(303, 235)] = 8026746;
      (*this)[make_pair(303, 236)] = 9211020;
      (*this)[make_pair(303, 237)] = 11119017;
      (*this)[make_pair(303, 238)] = 11119017;
      (*this)[make_pair(303, 239)] = 9145227;
      (*this)[make_pair(303, 240)] = 8092539;
      (*this)[make_pair(303, 241)] = 14737632;
      (*this)[make_pair(303, 242)] = 16777215;
      (*this)[make_pair(303, 243)] = 16777215;
      (*this)[make_pair(303, 244)] = 16777215;
      (*this)[make_pair(303, 245)] = 16777215;
      (*this)[make_pair(304, 233)] = 16777215;
      (*this)[make_pair(304, 234)] = 10000536;
      (*this)[make_pair(304, 235)] = 15461355;
      (*this)[make_pair(304, 236)] = 16777215;
      (*this)[make_pair(304, 237)] = 16777215;
      (*this)[make_pair(304, 238)] = 16777215;
      (*this)[make_pair(304, 239)] = 16777215;
      (*this)[make_pair(304, 240)] = 15329769;
      (*this)[make_pair(304, 241)] = 10197915;
      (*this)[make_pair(304, 242)] = 16777215;
      (*this)[make_pair(304, 243)] = 16777215;
      (*this)[make_pair(304, 244)] = 16777215;
      (*this)[make_pair(304, 245)] = 16777215;
      (*this)[make_pair(305, 233)] = 16316664;
      (*this)[make_pair(305, 234)] = 9737364;
      (*this)[make_pair(305, 235)] = 16777215;
      (*this)[make_pair(305, 236)] = 16777215;
      (*this)[make_pair(305, 237)] = 16777215;
      (*this)[make_pair(305, 238)] = 16777215;
      (*this)[make_pair(305, 239)] = 16777215;
      (*this)[make_pair(305, 240)] = 16777215;
      (*this)[make_pair(305, 241)] = 9605778;
      (*this)[make_pair(305, 242)] = 16514043;
      (*this)[make_pair(305, 243)] = 16777215;
      (*this)[make_pair(305, 244)] = 16777215;
      (*this)[make_pair(305, 245)] = 16777215;
      (*this)[make_pair(306, 233)] = 16777215;
      (*this)[make_pair(306, 234)] = 10197915;
      (*this)[make_pair(306, 235)] = 15329769;
      (*this)[make_pair(306, 236)] = 16777215;
      (*this)[make_pair(306, 237)] = 16777215;
      (*this)[make_pair(306, 238)] = 16777215;
      (*this)[make_pair(306, 239)] = 16777215;
      (*this)[make_pair(306, 240)] = 15198183;
      (*this)[make_pair(306, 241)] = 10329501;
      (*this)[make_pair(306, 242)] = 16777215;
      (*this)[make_pair(306, 243)] = 16777215;
      (*this)[make_pair(306, 244)] = 16777215;
      (*this)[make_pair(306, 245)] = 16777215;
      (*this)[make_pair(307, 233)] = 16777215;
      (*this)[make_pair(307, 234)] = 14869218;
      (*this)[make_pair(307, 235)] = 8158332;
      (*this)[make_pair(307, 236)] = 8816262;
      (*this)[make_pair(307, 237)] = 10790052;
      (*this)[make_pair(307, 238)] = 10724259;
      (*this)[make_pair(307, 239)] = 8816262;
      (*this)[make_pair(307, 240)] = 8158332;
      (*this)[make_pair(307, 241)] = 14935011;
      (*this)[make_pair(307, 242)] = 16777215;
      (*this)[make_pair(307, 243)] = 16777215;
      (*this)[make_pair(307, 244)] = 16777215;
      (*this)[make_pair(307, 245)] = 16777215;
    }
  } s30;
  map<pair<int, int>, int> table30;
  void update_table30()
  {
    for (const auto& x : s30) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table30[pos] = x.second;
    }
  }
  // "15:00" data
  //  ^^
  struct table15j_t : map<pair<int, int>, int> {
    table15j_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 12632256;
      (*this)[make_pair(696, 424)] = 13816530;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 13882323;
      (*this)[make_pair(697, 423)] = 9868950;
      (*this)[make_pair(697, 424)] = 16711422;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16053492;
      (*this)[make_pair(698, 422)] = 7500402;
      (*this)[make_pair(698, 423)] = 11842740;
      (*this)[make_pair(698, 424)] = 12369084;
      (*this)[make_pair(698, 425)] = 12369084;
      (*this)[make_pair(698, 426)] = 12369084;
      (*this)[make_pair(698, 427)] = 12369084;
      (*this)[make_pair(698, 428)] = 12369084;
      (*this)[make_pair(698, 429)] = 12369084;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16185078;
      (*this)[make_pair(699, 422)] = 12369084;
      (*this)[make_pair(699, 423)] = 12369084;
      (*this)[make_pair(699, 424)] = 12369084;
      (*this)[make_pair(699, 425)] = 12369084;
      (*this)[make_pair(699, 426)] = 12369084;
      (*this)[make_pair(699, 427)] = 12369084;
      (*this)[make_pair(699, 428)] = 12369084;
      (*this)[make_pair(699, 429)] = 12369084;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 16777215;
      (*this)[make_pair(700, 423)] = 16777215;
      (*this)[make_pair(700, 424)] = 16777215;
      (*this)[make_pair(700, 425)] = 16777215;
      (*this)[make_pair(700, 426)] = 16777215;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 16777215;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 16777215;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 16777215;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16777215;
      (*this)[make_pair(702, 422)] = 16777215;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 16777215;
      (*this)[make_pair(702, 425)] = 16777215;
      (*this)[make_pair(702, 426)] = 16777215;
      (*this)[make_pair(702, 427)] = 16777215;
      (*this)[make_pair(702, 428)] = 16777215;
      (*this)[make_pair(702, 429)] = 16777215;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 15987699;
      (*this)[make_pair(703, 422)] = 10724259;
      (*this)[make_pair(703, 423)] = 10132122;
      (*this)[make_pair(703, 424)] = 9605778;
      (*this)[make_pair(703, 425)] = 9013641;
      (*this)[make_pair(703, 426)] = 16185078;
      (*this)[make_pair(703, 427)] = 16777215;
      (*this)[make_pair(703, 428)] = 16316664;
      (*this)[make_pair(703, 429)] = 10000536;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 15329769;
      (*this)[make_pair(704, 422)] = 9737364;
      (*this)[make_pair(704, 423)] = 14935011;
      (*this)[make_pair(704, 424)] = 15592941;
      (*this)[make_pair(704, 425)] = 9013641;
      (*this)[make_pair(704, 426)] = 16711422;
      (*this)[make_pair(704, 427)] = 16777215;
      (*this)[make_pair(704, 428)] = 16777215;
      (*this)[make_pair(704, 429)] = 9145227;
      (*this)[make_pair(704, 430)] = 16579836;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 15329769;
      (*this)[make_pair(705, 422)] = 10592673;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 16119285;
      (*this)[make_pair(705, 425)] = 10197915;
      (*this)[make_pair(705, 426)] = 16777215;
      (*this)[make_pair(705, 427)] = 16777215;
      (*this)[make_pair(705, 428)] = 16777215;
      (*this)[make_pair(705, 429)] = 9474192;
      (*this)[make_pair(705, 430)] = 16514043;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 15329769;
      (*this)[make_pair(706, 422)] = 10592673;
      (*this)[make_pair(706, 423)] = 16777215;
      (*this)[make_pair(706, 424)] = 16777215;
      (*this)[make_pair(706, 425)] = 9408399;
      (*this)[make_pair(706, 426)] = 15461355;
      (*this)[make_pair(706, 427)] = 16711422;
      (*this)[make_pair(706, 428)] = 14013909;
      (*this)[make_pair(706, 429)] = 10197915;
      (*this)[make_pair(706, 430)] = 16777215;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 15790320;
      (*this)[make_pair(707, 422)] = 12500670;
      (*this)[make_pair(707, 423)] = 16777215;
      (*this)[make_pair(707, 424)] = 16777215;
      (*this)[make_pair(707, 425)] = 14211288;
      (*this)[make_pair(707, 426)] = 9408399;
      (*this)[make_pair(707, 427)] = 8158332;
      (*this)[make_pair(707, 428)] = 10658466;
      (*this)[make_pair(707, 429)] = 15198183;
      (*this)[make_pair(707, 430)] = 16777215;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 16777215;
      (*this)[make_pair(708, 422)] = 16777215;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 16777215;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 16777215;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s15j;
  map<pair<int, int>, int> table15j;
  void update_table15j()
  {
    for (const auto& x : s15j) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table15j[pos] = x.second;
    }
  }
  // "10:00" data
  //  ^^
  struct table10j_t : map<pair<int, int>, int> {
    table10j_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 12632256;
      (*this)[make_pair(696, 424)] = 13816530;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 13882323;
      (*this)[make_pair(697, 423)] = 9868950;
      (*this)[make_pair(697, 424)] = 16711422;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16053492;
      (*this)[make_pair(698, 422)] = 7500402;
      (*this)[make_pair(698, 423)] = 11842740;
      (*this)[make_pair(698, 424)] = 12369084;
      (*this)[make_pair(698, 425)] = 12369084;
      (*this)[make_pair(698, 426)] = 12369084;
      (*this)[make_pair(698, 427)] = 12369084;
      (*this)[make_pair(698, 428)] = 12369084;
      (*this)[make_pair(698, 429)] = 12369084;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16185078;
      (*this)[make_pair(699, 422)] = 12369084;
      (*this)[make_pair(699, 423)] = 12369084;
      (*this)[make_pair(699, 424)] = 12369084;
      (*this)[make_pair(699, 425)] = 12369084;
      (*this)[make_pair(699, 426)] = 12369084;
      (*this)[make_pair(699, 427)] = 12369084;
      (*this)[make_pair(699, 428)] = 12369084;
      (*this)[make_pair(699, 429)] = 12369084;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 16777215;
      (*this)[make_pair(700, 423)] = 16777215;
      (*this)[make_pair(700, 424)] = 16777215;
      (*this)[make_pair(700, 425)] = 16777215;
      (*this)[make_pair(700, 426)] = 16777215;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 16777215;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 16777215;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 16777215;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16777215;
      (*this)[make_pair(702, 422)] = 16777215;
      (*this)[make_pair(702, 423)] = 16448250;
      (*this)[make_pair(702, 424)] = 14211288;
      (*this)[make_pair(702, 425)] = 13158600;
      (*this)[make_pair(702, 426)] = 13158600;
      (*this)[make_pair(702, 427)] = 14211288;
      (*this)[make_pair(702, 428)] = 16448250;
      (*this)[make_pair(702, 429)] = 16777215;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 16777215;
      (*this)[make_pair(703, 422)] = 14606046;
      (*this)[make_pair(703, 423)] = 8026746;
      (*this)[make_pair(703, 424)] = 9211020;
      (*this)[make_pair(703, 425)] = 11119017;
      (*this)[make_pair(703, 426)] = 11119017;
      (*this)[make_pair(703, 427)] = 9145227;
      (*this)[make_pair(703, 428)] = 8092539;
      (*this)[make_pair(703, 429)] = 14737632;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 10000536;
      (*this)[make_pair(704, 423)] = 15461355;
      (*this)[make_pair(704, 424)] = 16777215;
      (*this)[make_pair(704, 425)] = 16777215;
      (*this)[make_pair(704, 426)] = 16777215;
      (*this)[make_pair(704, 427)] = 16777215;
      (*this)[make_pair(704, 428)] = 15329769;
      (*this)[make_pair(704, 429)] = 10197915;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16316664;
      (*this)[make_pair(705, 422)] = 9737364;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 16777215;
      (*this)[make_pair(705, 425)] = 16777215;
      (*this)[make_pair(705, 426)] = 16777215;
      (*this)[make_pair(705, 427)] = 16777215;
      (*this)[make_pair(705, 428)] = 16777215;
      (*this)[make_pair(705, 429)] = 9605778;
      (*this)[make_pair(705, 430)] = 16514043;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 16777215;
      (*this)[make_pair(706, 422)] = 10197915;
      (*this)[make_pair(706, 423)] = 15329769;
      (*this)[make_pair(706, 424)] = 16777215;
      (*this)[make_pair(706, 425)] = 16777215;
      (*this)[make_pair(706, 426)] = 16777215;
      (*this)[make_pair(706, 427)] = 16777215;
      (*this)[make_pair(706, 428)] = 15198183;
      (*this)[make_pair(706, 429)] = 10329501;
      (*this)[make_pair(706, 430)] = 16777215;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 16777215;
      (*this)[make_pair(707, 422)] = 14869218;
      (*this)[make_pair(707, 423)] = 8158332;
      (*this)[make_pair(707, 424)] = 8816262;
      (*this)[make_pair(707, 425)] = 10790052;
      (*this)[make_pair(707, 426)] = 10724259;
      (*this)[make_pair(707, 427)] = 8816262;
      (*this)[make_pair(707, 428)] = 8158332;
      (*this)[make_pair(707, 429)] = 14935011;
      (*this)[make_pair(707, 430)] = 16777215;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 16777215;
      (*this)[make_pair(708, 422)] = 16777215;
      (*this)[make_pair(708, 423)] = 16579836;
      (*this)[make_pair(708, 424)] = 14540253;
      (*this)[make_pair(708, 425)] = 13487565;
      (*this)[make_pair(708, 426)] = 13487565;
      (*this)[make_pair(708, 427)] = 14540253;
      (*this)[make_pair(708, 428)] = 16579836;
      (*this)[make_pair(708, 429)] = 16777215;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s10j;
  map<pair<int, int>, int> table10j;
  void update_table10j()
  {
    for (const auto& x : s10j) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table10j[pos] = x.second;
    }
  }
  // "9:00" data
  //  ^^
  struct table9_t : map<pair<int, int>, int> {
    table9_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 16777215;
      (*this)[make_pair(696, 424)] = 16777215;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 16777215;
      (*this)[make_pair(697, 423)] = 16777215;
      (*this)[make_pair(697, 424)] = 16777215;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16777215;
      (*this)[make_pair(698, 422)] = 16777215;
      (*this)[make_pair(698, 423)] = 16777215;
      (*this)[make_pair(698, 424)] = 16777215;
      (*this)[make_pair(698, 425)] = 16777215;
      (*this)[make_pair(698, 426)] = 16777215;
      (*this)[make_pair(698, 427)] = 16777215;
      (*this)[make_pair(698, 428)] = 16777215;
      (*this)[make_pair(698, 429)] = 16777215;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16777215;
      (*this)[make_pair(699, 422)] = 16777215;
      (*this)[make_pair(699, 423)] = 16448250;
      (*this)[make_pair(699, 424)] = 13816530;
      (*this)[make_pair(699, 425)] = 15921906;
      (*this)[make_pair(699, 426)] = 16777215;
      (*this)[make_pair(699, 427)] = 16777215;
      (*this)[make_pair(699, 428)] = 16777215;
      (*this)[make_pair(699, 429)] = 16777215;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 13290186;
      (*this)[make_pair(700, 423)] = 8618883;
      (*this)[make_pair(700, 424)] = 10987431;
      (*this)[make_pair(700, 425)] = 8947848;
      (*this)[make_pair(700, 426)] = 11119017;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 11184810;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 9474192;
      (*this)[make_pair(701, 423)] = 16579836;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 9868950;
      (*this)[make_pair(701, 427)] = 15987699;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 9671571;
      (*this)[make_pair(701, 430)] = 16382457;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16250871;
      (*this)[make_pair(702, 422)] = 10197915;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 16777215;
      (*this)[make_pair(702, 425)] = 16777215;
      (*this)[make_pair(702, 426)] = 12171705;
      (*this)[make_pair(702, 427)] = 14935011;
      (*this)[make_pair(702, 428)] = 16711422;
      (*this)[make_pair(702, 429)] = 8553090;
      (*this)[make_pair(702, 430)] = 16514043;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 16777215;
      (*this)[make_pair(703, 422)] = 10790052;
      (*this)[make_pair(703, 423)] = 15921906;
      (*this)[make_pair(703, 424)] = 16777215;
      (*this)[make_pair(703, 425)] = 16514043;
      (*this)[make_pair(703, 426)] = 11382189;
      (*this)[make_pair(703, 427)] = 16579836;
      (*this)[make_pair(703, 428)] = 12763842;
      (*this)[make_pair(703, 429)] = 9605778;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 14474460;
      (*this)[make_pair(704, 423)] = 9605778;
      (*this)[make_pair(704, 424)] = 10000536;
      (*this)[make_pair(704, 425)] = 7434609;
      (*this)[make_pair(704, 426)] = 8158332;
      (*this)[make_pair(704, 427)] = 7434609;
      (*this)[make_pair(704, 428)] = 10197915;
      (*this)[make_pair(704, 429)] = 16053492;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16777215;
      (*this)[make_pair(705, 422)] = 16777215;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 16119285;
      (*this)[make_pair(705, 425)] = 14211288;
      (*this)[make_pair(705, 426)] = 14935011;
      (*this)[make_pair(705, 427)] = 16119285;
      (*this)[make_pair(705, 428)] = 16777215;
      (*this)[make_pair(705, 429)] = 16777215;
      (*this)[make_pair(705, 430)] = 16777215;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 15987699;
      (*this)[make_pair(706, 422)] = 14737632;
      (*this)[make_pair(706, 423)] = 14737632;
      (*this)[make_pair(706, 424)] = 14737632;
      (*this)[make_pair(706, 425)] = 14737632;
      (*this)[make_pair(706, 426)] = 14737632;
      (*this)[make_pair(706, 427)] = 14737632;
      (*this)[make_pair(706, 428)] = 14737632;
      (*this)[make_pair(706, 429)] = 14737632;
      (*this)[make_pair(706, 430)] = 15527148;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 12829635;
      (*this)[make_pair(707, 422)] = 9211020;
      (*this)[make_pair(707, 423)] = 10592673;
      (*this)[make_pair(707, 424)] = 10592673;
      (*this)[make_pair(707, 425)] = 7763574;
      (*this)[make_pair(707, 426)] = 10592673;
      (*this)[make_pair(707, 427)] = 10592673;
      (*this)[make_pair(707, 428)] = 10592673;
      (*this)[make_pair(707, 429)] = 7829367;
      (*this)[make_pair(707, 430)] = 12961221;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 12829635;
      (*this)[make_pair(708, 422)] = 13158600;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 9342606;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 9539985;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s9;
  map<pair<int, int>, int> table9;
  void update_table9()
  {
    for (const auto& x : s9) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table9[pos] = x.second;
    }
  }
  // "2:00" data
  //  ^^
  struct table2j_t : map<pair<int, int>, int> {
    table2j_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 16777215;
      (*this)[make_pair(696, 424)] = 16777215;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 16777215;
      (*this)[make_pair(697, 423)] = 16777215;
      (*this)[make_pair(697, 424)] = 16777215;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16777215;
      (*this)[make_pair(698, 422)] = 16777215;
      (*this)[make_pair(698, 423)] = 16777215;
      (*this)[make_pair(698, 424)] = 16777215;
      (*this)[make_pair(698, 425)] = 16777215;
      (*this)[make_pair(698, 426)] = 16777215;
      (*this)[make_pair(698, 427)] = 16777215;
      (*this)[make_pair(698, 428)] = 16777215;
      (*this)[make_pair(698, 429)] = 16777215;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16777215;
      (*this)[make_pair(699, 422)] = 16777215;
      (*this)[make_pair(699, 423)] = 16777215;
      (*this)[make_pair(699, 424)] = 16777215;
      (*this)[make_pair(699, 425)] = 16777215;
      (*this)[make_pair(699, 426)] = 16777215;
      (*this)[make_pair(699, 427)] = 16777215;
      (*this)[make_pair(699, 428)] = 16777215;
      (*this)[make_pair(699, 429)] = 16711422;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 10790052;
      (*this)[make_pair(700, 423)] = 15724527;
      (*this)[make_pair(700, 424)] = 16777215;
      (*this)[make_pair(700, 425)] = 16777215;
      (*this)[make_pair(700, 426)] = 16777215;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 14540253;
      (*this)[make_pair(700, 429)] = 7039851;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 9013641;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 15329769;
      (*this)[make_pair(701, 428)] = 8816262;
      (*this)[make_pair(701, 429)] = 8553090;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16119285;
      (*this)[make_pair(702, 422)] = 9737364;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 16777215;
      (*this)[make_pair(702, 425)] = 16777215;
      (*this)[make_pair(702, 426)] = 15198183;
      (*this)[make_pair(702, 427)] = 8684676;
      (*this)[make_pair(702, 428)] = 15329769;
      (*this)[make_pair(702, 429)] = 9342606;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 16777215;
      (*this)[make_pair(703, 422)] = 9276813;
      (*this)[make_pair(703, 423)] = 14145495;
      (*this)[make_pair(703, 424)] = 15395562;
      (*this)[make_pair(703, 425)] = 11382189;
      (*this)[make_pair(703, 426)] = 8618883;
      (*this)[make_pair(703, 427)] = 15132390;
      (*this)[make_pair(703, 428)] = 16777215;
      (*this)[make_pair(703, 429)] = 9342606;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 14803425;
      (*this)[make_pair(704, 423)] = 10197915;
      (*this)[make_pair(704, 424)] = 9013641;
      (*this)[make_pair(704, 425)] = 12566463;
      (*this)[make_pair(704, 426)] = 16119285;
      (*this)[make_pair(704, 427)] = 16777215;
      (*this)[make_pair(704, 428)] = 16777215;
      (*this)[make_pair(704, 429)] = 9803157;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16777215;
      (*this)[make_pair(705, 422)] = 16777215;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 16777215;
      (*this)[make_pair(705, 425)] = 16777215;
      (*this)[make_pair(705, 426)] = 16777215;
      (*this)[make_pair(705, 427)] = 16777215;
      (*this)[make_pair(705, 428)] = 16777215;
      (*this)[make_pair(705, 429)] = 16777215;
      (*this)[make_pair(705, 430)] = 16777215;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 15987699;
      (*this)[make_pair(706, 422)] = 14737632;
      (*this)[make_pair(706, 423)] = 14737632;
      (*this)[make_pair(706, 424)] = 14737632;
      (*this)[make_pair(706, 425)] = 14737632;
      (*this)[make_pair(706, 426)] = 14737632;
      (*this)[make_pair(706, 427)] = 14737632;
      (*this)[make_pair(706, 428)] = 14737632;
      (*this)[make_pair(706, 429)] = 14737632;
      (*this)[make_pair(706, 430)] = 15527148;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 12829635;
      (*this)[make_pair(707, 422)] = 9211020;
      (*this)[make_pair(707, 423)] = 10592673;
      (*this)[make_pair(707, 424)] = 10592673;
      (*this)[make_pair(707, 425)] = 7763574;
      (*this)[make_pair(707, 426)] = 10592673;
      (*this)[make_pair(707, 427)] = 10592673;
      (*this)[make_pair(707, 428)] = 10592673;
      (*this)[make_pair(707, 429)] = 7829367;
      (*this)[make_pair(707, 430)] = 12961221;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 12829635;
      (*this)[make_pair(708, 422)] = 13158600;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 9342606;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 9539985;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s2j;
  map<pair<int, int>, int> table2j;
  void update_table2j()
  {
    for (const auto& x : s2j) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table2j[pos] = x.second;
    }
  }
  // "1:00" data
  //  ^^
  struct table1j_t : map<pair<int, int>, int> {
    table1j_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 16777215;
      (*this)[make_pair(696, 424)] = 16777215;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 16777215;
      (*this)[make_pair(697, 423)] = 16777215;
      (*this)[make_pair(697, 424)] = 16777215;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16777215;
      (*this)[make_pair(698, 422)] = 16777215;
      (*this)[make_pair(698, 423)] = 16777215;
      (*this)[make_pair(698, 424)] = 16777215;
      (*this)[make_pair(698, 425)] = 16777215;
      (*this)[make_pair(698, 426)] = 16777215;
      (*this)[make_pair(698, 427)] = 16777215;
      (*this)[make_pair(698, 428)] = 16777215;
      (*this)[make_pair(698, 429)] = 16777215;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16777215;
      (*this)[make_pair(699, 422)] = 16777215;
      (*this)[make_pair(699, 423)] = 16777215;
      (*this)[make_pair(699, 424)] = 16777215;
      (*this)[make_pair(699, 425)] = 16777215;
      (*this)[make_pair(699, 426)] = 16777215;
      (*this)[make_pair(699, 427)] = 16777215;
      (*this)[make_pair(699, 428)] = 16777215;
      (*this)[make_pair(699, 429)] = 16777215;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 16777215;
      (*this)[make_pair(700, 423)] = 12632256;
      (*this)[make_pair(700, 424)] = 13816530;
      (*this)[make_pair(700, 425)] = 16777215;
      (*this)[make_pair(700, 426)] = 16777215;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 16777215;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 13882323;
      (*this)[make_pair(701, 423)] = 9868950;
      (*this)[make_pair(701, 424)] = 16711422;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 16777215;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16053492;
      (*this)[make_pair(702, 422)] = 7500402;
      (*this)[make_pair(702, 423)] = 11842740;
      (*this)[make_pair(702, 424)] = 12369084;
      (*this)[make_pair(702, 425)] = 12369084;
      (*this)[make_pair(702, 426)] = 12369084;
      (*this)[make_pair(702, 427)] = 12369084;
      (*this)[make_pair(702, 428)] = 12369084;
      (*this)[make_pair(702, 429)] = 12369084;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 16185078;
      (*this)[make_pair(703, 422)] = 12369084;
      (*this)[make_pair(703, 423)] = 12369084;
      (*this)[make_pair(703, 424)] = 12369084;
      (*this)[make_pair(703, 425)] = 12369084;
      (*this)[make_pair(703, 426)] = 12369084;
      (*this)[make_pair(703, 427)] = 12369084;
      (*this)[make_pair(703, 428)] = 12369084;
      (*this)[make_pair(703, 429)] = 12369084;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 16777215;
      (*this)[make_pair(704, 423)] = 16777215;
      (*this)[make_pair(704, 424)] = 16777215;
      (*this)[make_pair(704, 425)] = 16777215;
      (*this)[make_pair(704, 426)] = 16777215;
      (*this)[make_pair(704, 427)] = 16777215;
      (*this)[make_pair(704, 428)] = 16777215;
      (*this)[make_pair(704, 429)] = 16777215;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16777215;
      (*this)[make_pair(705, 422)] = 16777215;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 16777215;
      (*this)[make_pair(705, 425)] = 16777215;
      (*this)[make_pair(705, 426)] = 16777215;
      (*this)[make_pair(705, 427)] = 16777215;
      (*this)[make_pair(705, 428)] = 16777215;
      (*this)[make_pair(705, 429)] = 16777215;
      (*this)[make_pair(705, 430)] = 16777215;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 15987699;
      (*this)[make_pair(706, 422)] = 14737632;
      (*this)[make_pair(706, 423)] = 14737632;
      (*this)[make_pair(706, 424)] = 14737632;
      (*this)[make_pair(706, 425)] = 14737632;
      (*this)[make_pair(706, 426)] = 14737632;
      (*this)[make_pair(706, 427)] = 14737632;
      (*this)[make_pair(706, 428)] = 14737632;
      (*this)[make_pair(706, 429)] = 14737632;
      (*this)[make_pair(706, 430)] = 15527148;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 12829635;
      (*this)[make_pair(707, 422)] = 9211020;
      (*this)[make_pair(707, 423)] = 10592673;
      (*this)[make_pair(707, 424)] = 10592673;
      (*this)[make_pair(707, 425)] = 7763574;
      (*this)[make_pair(707, 426)] = 10592673;
      (*this)[make_pair(707, 427)] = 10592673;
      (*this)[make_pair(707, 428)] = 10592673;
      (*this)[make_pair(707, 429)] = 7829367;
      (*this)[make_pair(707, 430)] = 12961221;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 12829635;
      (*this)[make_pair(708, 422)] = 13158600;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 9342606;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 9539985;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s1j;
  map<pair<int, int>, int> table1j;
  void update_table1j()
  {
    for (const auto& x : s1j) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table1j[pos] = x.second;
    }
  }
  // "0:00" data
  //  ^^
  struct table0_t : map<pair<int, int>, int> {
    table0_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 16777215;
      (*this)[make_pair(696, 424)] = 16777215;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 16777215;
      (*this)[make_pair(697, 423)] = 16777215;
      (*this)[make_pair(697, 424)] = 16777215;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16777215;
      (*this)[make_pair(698, 422)] = 16777215;
      (*this)[make_pair(698, 423)] = 16777215;
      (*this)[make_pair(698, 424)] = 16777215;
      (*this)[make_pair(698, 425)] = 16777215;
      (*this)[make_pair(698, 426)] = 16777215;
      (*this)[make_pair(698, 427)] = 16777215;
      (*this)[make_pair(698, 428)] = 16777215;
      (*this)[make_pair(698, 429)] = 16777215;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16777215;
      (*this)[make_pair(699, 422)] = 16777215;
      (*this)[make_pair(699, 423)] = 16448250;
      (*this)[make_pair(699, 424)] = 14211288;
      (*this)[make_pair(699, 425)] = 13158600;
      (*this)[make_pair(699, 426)] = 13158600;
      (*this)[make_pair(699, 427)] = 14211288;
      (*this)[make_pair(699, 428)] = 16448250;
      (*this)[make_pair(699, 429)] = 16777215;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 14606046;
      (*this)[make_pair(700, 423)] = 8026746;
      (*this)[make_pair(700, 424)] = 9211020;
      (*this)[make_pair(700, 425)] = 11119017;
      (*this)[make_pair(700, 426)] = 11119017;
      (*this)[make_pair(700, 427)] = 9145227;
      (*this)[make_pair(700, 428)] = 8092539;
      (*this)[make_pair(700, 429)] = 14737632;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 10000536;
      (*this)[make_pair(701, 423)] = 15461355;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 15329769;
      (*this)[make_pair(701, 429)] = 10197915;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16316664;
      (*this)[make_pair(702, 422)] = 9737364;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 16777215;
      (*this)[make_pair(702, 425)] = 16777215;
      (*this)[make_pair(702, 426)] = 16777215;
      (*this)[make_pair(702, 427)] = 16777215;
      (*this)[make_pair(702, 428)] = 16777215;
      (*this)[make_pair(702, 429)] = 9605778;
      (*this)[make_pair(702, 430)] = 16514043;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 16777215;
      (*this)[make_pair(703, 422)] = 10197915;
      (*this)[make_pair(703, 423)] = 15329769;
      (*this)[make_pair(703, 424)] = 16777215;
      (*this)[make_pair(703, 425)] = 16777215;
      (*this)[make_pair(703, 426)] = 16777215;
      (*this)[make_pair(703, 427)] = 16777215;
      (*this)[make_pair(703, 428)] = 15198183;
      (*this)[make_pair(703, 429)] = 10329501;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 14869218;
      (*this)[make_pair(704, 423)] = 8158332;
      (*this)[make_pair(704, 424)] = 8816262;
      (*this)[make_pair(704, 425)] = 10790052;
      (*this)[make_pair(704, 426)] = 10724259;
      (*this)[make_pair(704, 427)] = 8816262;
      (*this)[make_pair(704, 428)] = 8158332;
      (*this)[make_pair(704, 429)] = 14935011;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16777215;
      (*this)[make_pair(705, 422)] = 16777215;
      (*this)[make_pair(705, 423)] = 16579836;
      (*this)[make_pair(705, 424)] = 14540253;
      (*this)[make_pair(705, 425)] = 13487565;
      (*this)[make_pair(705, 426)] = 13487565;
      (*this)[make_pair(705, 427)] = 14540253;
      (*this)[make_pair(705, 428)] = 16579836;
      (*this)[make_pair(705, 429)] = 16777215;
      (*this)[make_pair(705, 430)] = 16777215;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 15987699;
      (*this)[make_pair(706, 422)] = 14737632;
      (*this)[make_pair(706, 423)] = 14737632;
      (*this)[make_pair(706, 424)] = 14737632;
      (*this)[make_pair(706, 425)] = 14737632;
      (*this)[make_pair(706, 426)] = 14737632;
      (*this)[make_pair(706, 427)] = 14737632;
      (*this)[make_pair(706, 428)] = 14737632;
      (*this)[make_pair(706, 429)] = 14737632;
      (*this)[make_pair(706, 430)] = 15527148;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 12829635;
      (*this)[make_pair(707, 422)] = 9211020;
      (*this)[make_pair(707, 423)] = 10592673;
      (*this)[make_pair(707, 424)] = 10592673;
      (*this)[make_pair(707, 425)] = 7763574;
      (*this)[make_pair(707, 426)] = 10592673;
      (*this)[make_pair(707, 427)] = 10592673;
      (*this)[make_pair(707, 428)] = 10592673;
      (*this)[make_pair(707, 429)] = 7829367;
      (*this)[make_pair(707, 430)] = 12961221;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 12829635;
      (*this)[make_pair(708, 422)] = 13158600;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 9342606;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 9539985;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s0;
  map<pair<int, int>, int> table0;
  void update_table0()
  {
    for (const auto& x : s0) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table0[pos] = x.second;
    }
  }
  // "23:00" data
  //  ^^
  struct table23_t : map<pair<int, int>, int> {
    table23_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 10790052;
      (*this)[make_pair(696, 423)] = 15724527;
      (*this)[make_pair(696, 424)] = 16777215;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 14540253;
      (*this)[make_pair(696, 429)] = 7039851;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 9013641;
      (*this)[make_pair(697, 423)] = 16777215;
      (*this)[make_pair(697, 424)] = 16777215;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 15329769;
      (*this)[make_pair(697, 428)] = 8816262;
      (*this)[make_pair(697, 429)] = 8553090;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16119285;
      (*this)[make_pair(698, 422)] = 9737364;
      (*this)[make_pair(698, 423)] = 16777215;
      (*this)[make_pair(698, 424)] = 16777215;
      (*this)[make_pair(698, 425)] = 16777215;
      (*this)[make_pair(698, 426)] = 15198183;
      (*this)[make_pair(698, 427)] = 8684676;
      (*this)[make_pair(698, 428)] = 15329769;
      (*this)[make_pair(698, 429)] = 9342606;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16777215;
      (*this)[make_pair(699, 422)] = 9276813;
      (*this)[make_pair(699, 423)] = 14145495;
      (*this)[make_pair(699, 424)] = 15395562;
      (*this)[make_pair(699, 425)] = 11382189;
      (*this)[make_pair(699, 426)] = 8618883;
      (*this)[make_pair(699, 427)] = 15132390;
      (*this)[make_pair(699, 428)] = 16777215;
      (*this)[make_pair(699, 429)] = 9342606;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 14803425;
      (*this)[make_pair(700, 423)] = 10197915;
      (*this)[make_pair(700, 424)] = 9013641;
      (*this)[make_pair(700, 425)] = 12566463;
      (*this)[make_pair(700, 426)] = 16119285;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 9803157;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 16777215;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 16777215;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16777215;
      (*this)[make_pair(702, 422)] = 16777215;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 16777215;
      (*this)[make_pair(702, 425)] = 16777215;
      (*this)[make_pair(702, 426)] = 16777215;
      (*this)[make_pair(702, 427)] = 16777215;
      (*this)[make_pair(702, 428)] = 16777215;
      (*this)[make_pair(702, 429)] = 16777215;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 15395562;
      (*this)[make_pair(703, 422)] = 10724259;
      (*this)[make_pair(703, 423)] = 16777215;
      (*this)[make_pair(703, 424)] = 16777215;
      (*this)[make_pair(703, 425)] = 16777215;
      (*this)[make_pair(703, 426)] = 16777215;
      (*this)[make_pair(703, 427)] = 16777215;
      (*this)[make_pair(703, 428)] = 16250871;
      (*this)[make_pair(703, 429)] = 9737364;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 15329769;
      (*this)[make_pair(704, 422)] = 10592673;
      (*this)[make_pair(704, 423)] = 16777215;
      (*this)[make_pair(704, 424)] = 14277081;
      (*this)[make_pair(704, 425)] = 8421504;
      (*this)[make_pair(704, 426)] = 16777215;
      (*this)[make_pair(704, 427)] = 16777215;
      (*this)[make_pair(704, 428)] = 16777215;
      (*this)[make_pair(704, 429)] = 9145227;
      (*this)[make_pair(704, 430)] = 16579836;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 15329769;
      (*this)[make_pair(705, 422)] = 10592673;
      (*this)[make_pair(705, 423)] = 14342874;
      (*this)[make_pair(705, 424)] = 8816262;
      (*this)[make_pair(705, 425)] = 8882055;
      (*this)[make_pair(705, 426)] = 16119285;
      (*this)[make_pair(705, 427)] = 16777215;
      (*this)[make_pair(705, 428)] = 16777215;
      (*this)[make_pair(705, 429)] = 9474192;
      (*this)[make_pair(705, 430)] = 16514043;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 15329769;
      (*this)[make_pair(706, 422)] = 8750469;
      (*this)[make_pair(706, 423)] = 8816262;
      (*this)[make_pair(706, 424)] = 15856113;
      (*this)[make_pair(706, 425)] = 12303291;
      (*this)[make_pair(706, 426)] = 11908533;
      (*this)[make_pair(706, 427)] = 16316664;
      (*this)[make_pair(706, 428)] = 13487565;
      (*this)[make_pair(706, 429)] = 10197915;
      (*this)[make_pair(706, 430)] = 16777215;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 15658734;
      (*this)[make_pair(707, 422)] = 9211020;
      (*this)[make_pair(707, 423)] = 15856113;
      (*this)[make_pair(707, 424)] = 16777215;
      (*this)[make_pair(707, 425)] = 15987699;
      (*this)[make_pair(707, 426)] = 10987431;
      (*this)[make_pair(707, 427)] = 8355711;
      (*this)[make_pair(707, 428)] = 11184810;
      (*this)[make_pair(707, 429)] = 15461355;
      (*this)[make_pair(707, 430)] = 16777215;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 16777215;
      (*this)[make_pair(708, 422)] = 16777215;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 16777215;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 16777215;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s23;
  map<pair<int, int>, int> table23;
  void update_table23()
  {
    for (const auto& x : s23) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table23[pos] = x.second;
    }
  }
  // "22:00" data
  //  ^^
  struct table22_t : map<pair<int, int>, int> {
    table22_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 10790052;
      (*this)[make_pair(696, 423)] = 15724527;
      (*this)[make_pair(696, 424)] = 16777215;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 14540253;
      (*this)[make_pair(696, 429)] = 7039851;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 9013641;
      (*this)[make_pair(697, 423)] = 16777215;
      (*this)[make_pair(697, 424)] = 16777215;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 15329769;
      (*this)[make_pair(697, 428)] = 8816262;
      (*this)[make_pair(697, 429)] = 8553090;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16119285;
      (*this)[make_pair(698, 422)] = 9737364;
      (*this)[make_pair(698, 423)] = 16777215;
      (*this)[make_pair(698, 424)] = 16777215;
      (*this)[make_pair(698, 425)] = 16777215;
      (*this)[make_pair(698, 426)] = 15198183;
      (*this)[make_pair(698, 427)] = 8684676;
      (*this)[make_pair(698, 428)] = 15329769;
      (*this)[make_pair(698, 429)] = 9342606;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16777215;
      (*this)[make_pair(699, 422)] = 9276813;
      (*this)[make_pair(699, 423)] = 14145495;
      (*this)[make_pair(699, 424)] = 15395562;
      (*this)[make_pair(699, 425)] = 11382189;
      (*this)[make_pair(699, 426)] = 8618883;
      (*this)[make_pair(699, 427)] = 15132390;
      (*this)[make_pair(699, 428)] = 16777215;
      (*this)[make_pair(699, 429)] = 9342606;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 14803425;
      (*this)[make_pair(700, 423)] = 10197915;
      (*this)[make_pair(700, 424)] = 9013641;
      (*this)[make_pair(700, 425)] = 12566463;
      (*this)[make_pair(700, 426)] = 16119285;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 9803157;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 16777215;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 16777215;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16777215;
      (*this)[make_pair(702, 422)] = 16777215;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 16777215;
      (*this)[make_pair(702, 425)] = 16777215;
      (*this)[make_pair(702, 426)] = 16777215;
      (*this)[make_pair(702, 427)] = 16777215;
      (*this)[make_pair(702, 428)] = 16777215;
      (*this)[make_pair(702, 429)] = 16711422;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 16777215;
      (*this)[make_pair(703, 422)] = 10790052;
      (*this)[make_pair(703, 423)] = 15724527;
      (*this)[make_pair(703, 424)] = 16777215;
      (*this)[make_pair(703, 425)] = 16777215;
      (*this)[make_pair(703, 426)] = 16777215;
      (*this)[make_pair(703, 427)] = 16777215;
      (*this)[make_pair(703, 428)] = 14540253;
      (*this)[make_pair(703, 429)] = 7039851;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 9013641;
      (*this)[make_pair(704, 423)] = 16777215;
      (*this)[make_pair(704, 424)] = 16777215;
      (*this)[make_pair(704, 425)] = 16777215;
      (*this)[make_pair(704, 426)] = 16777215;
      (*this)[make_pair(704, 427)] = 15329769;
      (*this)[make_pair(704, 428)] = 8816262;
      (*this)[make_pair(704, 429)] = 8553090;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16119285;
      (*this)[make_pair(705, 422)] = 9737364;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 16777215;
      (*this)[make_pair(705, 425)] = 16777215;
      (*this)[make_pair(705, 426)] = 15198183;
      (*this)[make_pair(705, 427)] = 8684676;
      (*this)[make_pair(705, 428)] = 15329769;
      (*this)[make_pair(705, 429)] = 9342606;
      (*this)[make_pair(705, 430)] = 16777215;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 16777215;
      (*this)[make_pair(706, 422)] = 9276813;
      (*this)[make_pair(706, 423)] = 14145495;
      (*this)[make_pair(706, 424)] = 15395562;
      (*this)[make_pair(706, 425)] = 11382189;
      (*this)[make_pair(706, 426)] = 8618883;
      (*this)[make_pair(706, 427)] = 15132390;
      (*this)[make_pair(706, 428)] = 16777215;
      (*this)[make_pair(706, 429)] = 9342606;
      (*this)[make_pair(706, 430)] = 16777215;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 16777215;
      (*this)[make_pair(707, 422)] = 14803425;
      (*this)[make_pair(707, 423)] = 10197915;
      (*this)[make_pair(707, 424)] = 9013641;
      (*this)[make_pair(707, 425)] = 12566463;
      (*this)[make_pair(707, 426)] = 16119285;
      (*this)[make_pair(707, 427)] = 16777215;
      (*this)[make_pair(707, 428)] = 16777215;
      (*this)[make_pair(707, 429)] = 9803157;
      (*this)[make_pair(707, 430)] = 16777215;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 16777215;
      (*this)[make_pair(708, 422)] = 16777215;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 16777215;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 16777215;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s22;
  map<pair<int, int>, int> table22;
  void update_table22()
  {
    for (const auto& x : s22) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table22[pos] = x.second;
    }
  }
  // "21:00" data
  //  ^^
  struct table21_t : map<pair<int, int>, int> {
    table21_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 10790052;
      (*this)[make_pair(696, 423)] = 15724527;
      (*this)[make_pair(696, 424)] = 16777215;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 14540253;
      (*this)[make_pair(696, 429)] = 7039851;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 9013641;
      (*this)[make_pair(697, 423)] = 16777215;
      (*this)[make_pair(697, 424)] = 16777215;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 15329769;
      (*this)[make_pair(697, 428)] = 8816262;
      (*this)[make_pair(697, 429)] = 8553090;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16119285;
      (*this)[make_pair(698, 422)] = 9737364;
      (*this)[make_pair(698, 423)] = 16777215;
      (*this)[make_pair(698, 424)] = 16777215;
      (*this)[make_pair(698, 425)] = 16777215;
      (*this)[make_pair(698, 426)] = 15198183;
      (*this)[make_pair(698, 427)] = 8684676;
      (*this)[make_pair(698, 428)] = 15329769;
      (*this)[make_pair(698, 429)] = 9342606;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16777215;
      (*this)[make_pair(699, 422)] = 9276813;
      (*this)[make_pair(699, 423)] = 14145495;
      (*this)[make_pair(699, 424)] = 15395562;
      (*this)[make_pair(699, 425)] = 11382189;
      (*this)[make_pair(699, 426)] = 8618883;
      (*this)[make_pair(699, 427)] = 15132390;
      (*this)[make_pair(699, 428)] = 16777215;
      (*this)[make_pair(699, 429)] = 9342606;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 14803425;
      (*this)[make_pair(700, 423)] = 10197915;
      (*this)[make_pair(700, 424)] = 9013641;
      (*this)[make_pair(700, 425)] = 12566463;
      (*this)[make_pair(700, 426)] = 16119285;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 9803157;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 16777215;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 16777215;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16777215;
      (*this)[make_pair(702, 422)] = 16777215;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 16777215;
      (*this)[make_pair(702, 425)] = 16777215;
      (*this)[make_pair(702, 426)] = 16777215;
      (*this)[make_pair(702, 427)] = 16777215;
      (*this)[make_pair(702, 428)] = 16777215;
      (*this)[make_pair(702, 429)] = 16777215;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 16777215;
      (*this)[make_pair(703, 422)] = 16777215;
      (*this)[make_pair(703, 423)] = 12632256;
      (*this)[make_pair(703, 424)] = 13816530;
      (*this)[make_pair(703, 425)] = 16777215;
      (*this)[make_pair(703, 426)] = 16777215;
      (*this)[make_pair(703, 427)] = 16777215;
      (*this)[make_pair(703, 428)] = 16777215;
      (*this)[make_pair(703, 429)] = 16777215;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 13882323;
      (*this)[make_pair(704, 423)] = 9868950;
      (*this)[make_pair(704, 424)] = 16711422;
      (*this)[make_pair(704, 425)] = 16777215;
      (*this)[make_pair(704, 426)] = 16777215;
      (*this)[make_pair(704, 427)] = 16777215;
      (*this)[make_pair(704, 428)] = 16777215;
      (*this)[make_pair(704, 429)] = 16777215;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16053492;
      (*this)[make_pair(705, 422)] = 7500402;
      (*this)[make_pair(705, 423)] = 11842740;
      (*this)[make_pair(705, 424)] = 12369084;
      (*this)[make_pair(705, 425)] = 12369084;
      (*this)[make_pair(705, 426)] = 12369084;
      (*this)[make_pair(705, 427)] = 12369084;
      (*this)[make_pair(705, 428)] = 12369084;
      (*this)[make_pair(705, 429)] = 12369084;
      (*this)[make_pair(705, 430)] = 16777215;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 16185078;
      (*this)[make_pair(706, 422)] = 12369084;
      (*this)[make_pair(706, 423)] = 12369084;
      (*this)[make_pair(706, 424)] = 12369084;
      (*this)[make_pair(706, 425)] = 12369084;
      (*this)[make_pair(706, 426)] = 12369084;
      (*this)[make_pair(706, 427)] = 12369084;
      (*this)[make_pair(706, 428)] = 12369084;
      (*this)[make_pair(706, 429)] = 12369084;
      (*this)[make_pair(706, 430)] = 16777215;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 16777215;
      (*this)[make_pair(707, 422)] = 16777215;
      (*this)[make_pair(707, 423)] = 16777215;
      (*this)[make_pair(707, 424)] = 16777215;
      (*this)[make_pair(707, 425)] = 16777215;
      (*this)[make_pair(707, 426)] = 16777215;
      (*this)[make_pair(707, 427)] = 16777215;
      (*this)[make_pair(707, 428)] = 16777215;
      (*this)[make_pair(707, 429)] = 16777215;
      (*this)[make_pair(707, 430)] = 16777215;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 16777215;
      (*this)[make_pair(708, 422)] = 16777215;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 16777215;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 16777215;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s21;
  map<pair<int, int>, int> table21;
  void update_table21()
  {
    for (const auto& x : s21) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table21[pos] = x.second;
    }
  }
  // "20:00" data
  //  ^^
  struct table20j_t : map<pair<int, int>, int> {
    table20j_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 10790052;
      (*this)[make_pair(696, 423)] = 15724527;
      (*this)[make_pair(696, 424)] = 16777215;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 14540253;
      (*this)[make_pair(696, 429)] = 7039851;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 9013641;
      (*this)[make_pair(697, 423)] = 16777215;
      (*this)[make_pair(697, 424)] = 16777215;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 15329769;
      (*this)[make_pair(697, 428)] = 8816262;
      (*this)[make_pair(697, 429)] = 8553090;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16119285;
      (*this)[make_pair(698, 422)] = 9737364;
      (*this)[make_pair(698, 423)] = 16777215;
      (*this)[make_pair(698, 424)] = 16777215;
      (*this)[make_pair(698, 425)] = 16777215;
      (*this)[make_pair(698, 426)] = 15198183;
      (*this)[make_pair(698, 427)] = 8684676;
      (*this)[make_pair(698, 428)] = 15329769;
      (*this)[make_pair(698, 429)] = 9342606;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16777215;
      (*this)[make_pair(699, 422)] = 9276813;
      (*this)[make_pair(699, 423)] = 14145495;
      (*this)[make_pair(699, 424)] = 15395562;
      (*this)[make_pair(699, 425)] = 11382189;
      (*this)[make_pair(699, 426)] = 8618883;
      (*this)[make_pair(699, 427)] = 15132390;
      (*this)[make_pair(699, 428)] = 16777215;
      (*this)[make_pair(699, 429)] = 9342606;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 14803425;
      (*this)[make_pair(700, 423)] = 10197915;
      (*this)[make_pair(700, 424)] = 9013641;
      (*this)[make_pair(700, 425)] = 12566463;
      (*this)[make_pair(700, 426)] = 16119285;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 9803157;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 16777215;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 16777215;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16777215;
      (*this)[make_pair(702, 422)] = 16777215;
      (*this)[make_pair(702, 423)] = 16448250;
      (*this)[make_pair(702, 424)] = 14211288;
      (*this)[make_pair(702, 425)] = 13158600;
      (*this)[make_pair(702, 426)] = 13158600;
      (*this)[make_pair(702, 427)] = 14211288;
      (*this)[make_pair(702, 428)] = 16448250;
      (*this)[make_pair(702, 429)] = 16777215;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 16777215;
      (*this)[make_pair(703, 422)] = 14606046;
      (*this)[make_pair(703, 423)] = 8026746;
      (*this)[make_pair(703, 424)] = 9211020;
      (*this)[make_pair(703, 425)] = 11119017;
      (*this)[make_pair(703, 426)] = 11119017;
      (*this)[make_pair(703, 427)] = 9145227;
      (*this)[make_pair(703, 428)] = 8092539;
      (*this)[make_pair(703, 429)] = 14737632;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 10000536;
      (*this)[make_pair(704, 423)] = 15461355;
      (*this)[make_pair(704, 424)] = 16777215;
      (*this)[make_pair(704, 425)] = 16777215;
      (*this)[make_pair(704, 426)] = 16777215;
      (*this)[make_pair(704, 427)] = 16777215;
      (*this)[make_pair(704, 428)] = 15329769;
      (*this)[make_pair(704, 429)] = 10197915;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16316664;
      (*this)[make_pair(705, 422)] = 9737364;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 16777215;
      (*this)[make_pair(705, 425)] = 16777215;
      (*this)[make_pair(705, 426)] = 16777215;
      (*this)[make_pair(705, 427)] = 16777215;
      (*this)[make_pair(705, 428)] = 16777215;
      (*this)[make_pair(705, 429)] = 9605778;
      (*this)[make_pair(705, 430)] = 16514043;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 16777215;
      (*this)[make_pair(706, 422)] = 10197915;
      (*this)[make_pair(706, 423)] = 15329769;
      (*this)[make_pair(706, 424)] = 16777215;
      (*this)[make_pair(706, 425)] = 16777215;
      (*this)[make_pair(706, 426)] = 16777215;
      (*this)[make_pair(706, 427)] = 16777215;
      (*this)[make_pair(706, 428)] = 15198183;
      (*this)[make_pair(706, 429)] = 10329501;
      (*this)[make_pair(706, 430)] = 16777215;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 16777215;
      (*this)[make_pair(707, 422)] = 14869218;
      (*this)[make_pair(707, 423)] = 8158332;
      (*this)[make_pair(707, 424)] = 8816262;
      (*this)[make_pair(707, 425)] = 10790052;
      (*this)[make_pair(707, 426)] = 10724259;
      (*this)[make_pair(707, 427)] = 8816262;
      (*this)[make_pair(707, 428)] = 8158332;
      (*this)[make_pair(707, 429)] = 14935011;
      (*this)[make_pair(707, 430)] = 16777215;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 16777215;
      (*this)[make_pair(708, 422)] = 16777215;
      (*this)[make_pair(708, 423)] = 16579836;
      (*this)[make_pair(708, 424)] = 14540253;
      (*this)[make_pair(708, 425)] = 13487565;
      (*this)[make_pair(708, 426)] = 13487565;
      (*this)[make_pair(708, 427)] = 14540253;
      (*this)[make_pair(708, 428)] = 16579836;
      (*this)[make_pair(708, 429)] = 16777215;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s20j;
  map<pair<int, int>, int> table20j;
  void update_table20j()
  {
    for (const auto& x : s20j) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table20j[pos] = x.second;
    }
  }
  // "19:00" data
  //  ^^
  struct table19_t : map<pair<int, int>, int> {
    table19_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 12632256;
      (*this)[make_pair(696, 424)] = 13816530;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 13882323;
      (*this)[make_pair(697, 423)] = 9868950;
      (*this)[make_pair(697, 424)] = 16711422;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16053492;
      (*this)[make_pair(698, 422)] = 7500402;
      (*this)[make_pair(698, 423)] = 11842740;
      (*this)[make_pair(698, 424)] = 12369084;
      (*this)[make_pair(698, 425)] = 12369084;
      (*this)[make_pair(698, 426)] = 12369084;
      (*this)[make_pair(698, 427)] = 12369084;
      (*this)[make_pair(698, 428)] = 12369084;
      (*this)[make_pair(698, 429)] = 12369084;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16185078;
      (*this)[make_pair(699, 422)] = 12369084;
      (*this)[make_pair(699, 423)] = 12369084;
      (*this)[make_pair(699, 424)] = 12369084;
      (*this)[make_pair(699, 425)] = 12369084;
      (*this)[make_pair(699, 426)] = 12369084;
      (*this)[make_pair(699, 427)] = 12369084;
      (*this)[make_pair(699, 428)] = 12369084;
      (*this)[make_pair(699, 429)] = 12369084;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 16777215;
      (*this)[make_pair(700, 423)] = 16777215;
      (*this)[make_pair(700, 424)] = 16777215;
      (*this)[make_pair(700, 425)] = 16777215;
      (*this)[make_pair(700, 426)] = 16777215;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 16777215;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 16777215;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 16777215;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16777215;
      (*this)[make_pair(702, 422)] = 16777215;
      (*this)[make_pair(702, 423)] = 16448250;
      (*this)[make_pair(702, 424)] = 13816530;
      (*this)[make_pair(702, 425)] = 15921906;
      (*this)[make_pair(702, 426)] = 16777215;
      (*this)[make_pair(702, 427)] = 16777215;
      (*this)[make_pair(702, 428)] = 16777215;
      (*this)[make_pair(702, 429)] = 16777215;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 16777215;
      (*this)[make_pair(703, 422)] = 13290186;
      (*this)[make_pair(703, 423)] = 8618883;
      (*this)[make_pair(703, 424)] = 10987431;
      (*this)[make_pair(703, 425)] = 8947848;
      (*this)[make_pair(703, 426)] = 11119017;
      (*this)[make_pair(703, 427)] = 16777215;
      (*this)[make_pair(703, 428)] = 16777215;
      (*this)[make_pair(703, 429)] = 11184810;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 9474192;
      (*this)[make_pair(704, 423)] = 16579836;
      (*this)[make_pair(704, 424)] = 16777215;
      (*this)[make_pair(704, 425)] = 16777215;
      (*this)[make_pair(704, 426)] = 9868950;
      (*this)[make_pair(704, 427)] = 15987699;
      (*this)[make_pair(704, 428)] = 16777215;
      (*this)[make_pair(704, 429)] = 9671571;
      (*this)[make_pair(704, 430)] = 16382457;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16250871;
      (*this)[make_pair(705, 422)] = 10197915;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 16777215;
      (*this)[make_pair(705, 425)] = 16777215;
      (*this)[make_pair(705, 426)] = 12171705;
      (*this)[make_pair(705, 427)] = 14935011;
      (*this)[make_pair(705, 428)] = 16711422;
      (*this)[make_pair(705, 429)] = 8553090;
      (*this)[make_pair(705, 430)] = 16514043;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 16777215;
      (*this)[make_pair(706, 422)] = 10790052;
      (*this)[make_pair(706, 423)] = 15921906;
      (*this)[make_pair(706, 424)] = 16777215;
      (*this)[make_pair(706, 425)] = 16514043;
      (*this)[make_pair(706, 426)] = 11382189;
      (*this)[make_pair(706, 427)] = 16579836;
      (*this)[make_pair(706, 428)] = 12763842;
      (*this)[make_pair(706, 429)] = 9605778;
      (*this)[make_pair(706, 430)] = 16777215;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 16777215;
      (*this)[make_pair(707, 422)] = 14474460;
      (*this)[make_pair(707, 423)] = 9605778;
      (*this)[make_pair(707, 424)] = 10000536;
      (*this)[make_pair(707, 425)] = 7434609;
      (*this)[make_pair(707, 426)] = 8158332;
      (*this)[make_pair(707, 427)] = 7434609;
      (*this)[make_pair(707, 428)] = 10197915;
      (*this)[make_pair(707, 429)] = 16053492;
      (*this)[make_pair(707, 430)] = 16777215;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 16777215;
      (*this)[make_pair(708, 422)] = 16777215;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16119285;
      (*this)[make_pair(708, 425)] = 14211288;
      (*this)[make_pair(708, 426)] = 14935011;
      (*this)[make_pair(708, 427)] = 16119285;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 16777215;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s19;
  map<pair<int, int>, int> table19;
  void update_table19()
  {
    for (const auto& x : s19) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table19[pos] = x.second;
    }
  }
  // "18:00" data
  //  ^^
  struct table18_t : map<pair<int, int>, int> {
    table18_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 12632256;
      (*this)[make_pair(696, 424)] = 13816530;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 13882323;
      (*this)[make_pair(697, 423)] = 9868950;
      (*this)[make_pair(697, 424)] = 16711422;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16053492;
      (*this)[make_pair(698, 422)] = 7500402;
      (*this)[make_pair(698, 423)] = 11842740;
      (*this)[make_pair(698, 424)] = 12369084;
      (*this)[make_pair(698, 425)] = 12369084;
      (*this)[make_pair(698, 426)] = 12369084;
      (*this)[make_pair(698, 427)] = 12369084;
      (*this)[make_pair(698, 428)] = 12369084;
      (*this)[make_pair(698, 429)] = 12369084;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16185078;
      (*this)[make_pair(699, 422)] = 12369084;
      (*this)[make_pair(699, 423)] = 12369084;
      (*this)[make_pair(699, 424)] = 12369084;
      (*this)[make_pair(699, 425)] = 12369084;
      (*this)[make_pair(699, 426)] = 12369084;
      (*this)[make_pair(699, 427)] = 12369084;
      (*this)[make_pair(699, 428)] = 12369084;
      (*this)[make_pair(699, 429)] = 12369084;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 16777215;
      (*this)[make_pair(700, 423)] = 16777215;
      (*this)[make_pair(700, 424)] = 16777215;
      (*this)[make_pair(700, 425)] = 16777215;
      (*this)[make_pair(700, 426)] = 16777215;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 16777215;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 16777215;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 16777215;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16777215;
      (*this)[make_pair(702, 422)] = 16777215;
      (*this)[make_pair(702, 423)] = 16448250;
      (*this)[make_pair(702, 424)] = 16777215;
      (*this)[make_pair(702, 425)] = 16777215;
      (*this)[make_pair(702, 426)] = 16645629;
      (*this)[make_pair(702, 427)] = 14079702;
      (*this)[make_pair(702, 428)] = 15592941;
      (*this)[make_pair(702, 429)] = 16777215;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 16777215;
      (*this)[make_pair(703, 422)] = 12961221;
      (*this)[make_pair(703, 423)] = 8487297;
      (*this)[make_pair(703, 424)] = 8421504;
      (*this)[make_pair(703, 425)] = 15329769;
      (*this)[make_pair(703, 426)] = 10263708;
      (*this)[make_pair(703, 427)] = 10790052;
      (*this)[make_pair(703, 428)] = 9342606;
      (*this)[make_pair(703, 429)] = 12369084;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 9737364;
      (*this)[make_pair(704, 423)] = 16579836;
      (*this)[make_pair(704, 424)] = 15658734;
      (*this)[make_pair(704, 425)] = 8224125;
      (*this)[make_pair(704, 426)] = 11908533;
      (*this)[make_pair(704, 427)] = 16777215;
      (*this)[make_pair(704, 428)] = 16777215;
      (*this)[make_pair(704, 429)] = 9737364;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16053492;
      (*this)[make_pair(705, 422)] = 10395294;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 16777215;
      (*this)[make_pair(705, 425)] = 9408399;
      (*this)[make_pair(705, 426)] = 14935011;
      (*this)[make_pair(705, 427)] = 16777215;
      (*this)[make_pair(705, 428)] = 16777215;
      (*this)[make_pair(705, 429)] = 10132122;
      (*this)[make_pair(705, 430)] = 16382457;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 16777215;
      (*this)[make_pair(706, 422)] = 9737364;
      (*this)[make_pair(706, 423)] = 16514043;
      (*this)[make_pair(706, 424)] = 15527148;
      (*this)[make_pair(706, 425)] = 8355711;
      (*this)[make_pair(706, 426)] = 11711154;
      (*this)[make_pair(706, 427)] = 16777215;
      (*this)[make_pair(706, 428)] = 16777215;
      (*this)[make_pair(706, 429)] = 9605778;
      (*this)[make_pair(706, 430)] = 16777215;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 16777215;
      (*this)[make_pair(707, 422)] = 13290186;
      (*this)[make_pair(707, 423)] = 8618883;
      (*this)[make_pair(707, 424)] = 8684676;
      (*this)[make_pair(707, 425)] = 15724527;
      (*this)[make_pair(707, 426)] = 9539985;
      (*this)[make_pair(707, 427)] = 10263708;
      (*this)[make_pair(707, 428)] = 8882055;
      (*this)[make_pair(707, 429)] = 12566463;
      (*this)[make_pair(707, 430)] = 16777215;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 16777215;
      (*this)[make_pair(708, 422)] = 16777215;
      (*this)[make_pair(708, 423)] = 16579836;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 16777215;
      (*this)[make_pair(708, 426)] = 16645629;
      (*this)[make_pair(708, 427)] = 14277081;
      (*this)[make_pair(708, 428)] = 15856113;
      (*this)[make_pair(708, 429)] = 16777215;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s18;
  map<pair<int, int>, int> table18;
  void update_table18()
  {
    for (const auto& x : s18) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table18[pos] = x.second;
    }
  }
  // "17:00" data
  //  ^^
  struct table17_t : map<pair<int, int>, int> {
    table17_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 12632256;
      (*this)[make_pair(696, 424)] = 13816530;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 13882323;
      (*this)[make_pair(697, 423)] = 9868950;
      (*this)[make_pair(697, 424)] = 16711422;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16053492;
      (*this)[make_pair(698, 422)] = 7500402;
      (*this)[make_pair(698, 423)] = 11842740;
      (*this)[make_pair(698, 424)] = 12369084;
      (*this)[make_pair(698, 425)] = 12369084;
      (*this)[make_pair(698, 426)] = 12369084;
      (*this)[make_pair(698, 427)] = 12369084;
      (*this)[make_pair(698, 428)] = 12369084;
      (*this)[make_pair(698, 429)] = 12369084;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16185078;
      (*this)[make_pair(699, 422)] = 12369084;
      (*this)[make_pair(699, 423)] = 12369084;
      (*this)[make_pair(699, 424)] = 12369084;
      (*this)[make_pair(699, 425)] = 12369084;
      (*this)[make_pair(699, 426)] = 12369084;
      (*this)[make_pair(699, 427)] = 12369084;
      (*this)[make_pair(699, 428)] = 12369084;
      (*this)[make_pair(699, 429)] = 12369084;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 16777215;
      (*this)[make_pair(700, 423)] = 16777215;
      (*this)[make_pair(700, 424)] = 16777215;
      (*this)[make_pair(700, 425)] = 16777215;
      (*this)[make_pair(700, 426)] = 16777215;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 16777215;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 16777215;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 16777215;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16711422;
      (*this)[make_pair(702, 422)] = 16448250;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 16777215;
      (*this)[make_pair(702, 425)] = 16777215;
      (*this)[make_pair(702, 426)] = 16777215;
      (*this)[make_pair(702, 427)] = 16777215;
      (*this)[make_pair(702, 428)] = 16777215;
      (*this)[make_pair(702, 429)] = 16777215;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 15329769;
      (*this)[make_pair(703, 422)] = 10592673;
      (*this)[make_pair(703, 423)] = 16777215;
      (*this)[make_pair(703, 424)] = 16777215;
      (*this)[make_pair(703, 425)] = 16777215;
      (*this)[make_pair(703, 426)] = 16777215;
      (*this)[make_pair(703, 427)] = 16777215;
      (*this)[make_pair(703, 428)] = 16777215;
      (*this)[make_pair(703, 429)] = 16777215;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 15329769;
      (*this)[make_pair(704, 422)] = 10592673;
      (*this)[make_pair(704, 423)] = 16777215;
      (*this)[make_pair(704, 424)] = 16777215;
      (*this)[make_pair(704, 425)] = 16777215;
      (*this)[make_pair(704, 426)] = 16777215;
      (*this)[make_pair(704, 427)] = 16645629;
      (*this)[make_pair(704, 428)] = 13355979;
      (*this)[make_pair(704, 429)] = 9013641;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 15329769;
      (*this)[make_pair(705, 422)] = 10592673;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 16777215;
      (*this)[make_pair(705, 425)] = 16185078;
      (*this)[make_pair(705, 426)] = 12237498;
      (*this)[make_pair(705, 427)] = 8487297;
      (*this)[make_pair(705, 428)] = 11053224;
      (*this)[make_pair(705, 429)] = 15329769;
      (*this)[make_pair(705, 430)] = 16777215;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 15329769;
      (*this)[make_pair(706, 422)] = 10592673;
      (*this)[make_pair(706, 423)] = 15461355;
      (*this)[make_pair(706, 424)] = 11053224;
      (*this)[make_pair(706, 425)] = 8684676;
      (*this)[make_pair(706, 426)] = 12434877;
      (*this)[make_pair(706, 427)] = 16250871;
      (*this)[make_pair(706, 428)] = 16777215;
      (*this)[make_pair(706, 429)] = 16777215;
      (*this)[make_pair(706, 430)] = 16777215;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 15329769;
      (*this)[make_pair(707, 422)] = 7434609;
      (*this)[make_pair(707, 423)] = 9605778;
      (*this)[make_pair(707, 424)] = 13816530;
      (*this)[make_pair(707, 425)] = 16711422;
      (*this)[make_pair(707, 426)] = 16777215;
      (*this)[make_pair(707, 427)] = 16777215;
      (*this)[make_pair(707, 428)] = 16777215;
      (*this)[make_pair(707, 429)] = 16777215;
      (*this)[make_pair(707, 430)] = 16777215;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 16645629;
      (*this)[make_pair(708, 422)] = 15987699;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 16777215;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 16777215;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s17;
  map<pair<int, int>, int> table17;
  void update_table17()
  {
    for (const auto& x : s17) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table17[pos] = x.second;
    }
  }
  // "16:00" data
  //  ^^
  struct table16_t : map<pair<int, int>, int> {
    table16_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 12632256;
      (*this)[make_pair(696, 424)] = 13816530;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 13882323;
      (*this)[make_pair(697, 423)] = 9868950;
      (*this)[make_pair(697, 424)] = 16711422;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16053492;
      (*this)[make_pair(698, 422)] = 7500402;
      (*this)[make_pair(698, 423)] = 11842740;
      (*this)[make_pair(698, 424)] = 12369084;
      (*this)[make_pair(698, 425)] = 12369084;
      (*this)[make_pair(698, 426)] = 12369084;
      (*this)[make_pair(698, 427)] = 12369084;
      (*this)[make_pair(698, 428)] = 12369084;
      (*this)[make_pair(698, 429)] = 12369084;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16185078;
      (*this)[make_pair(699, 422)] = 12369084;
      (*this)[make_pair(699, 423)] = 12369084;
      (*this)[make_pair(699, 424)] = 12369084;
      (*this)[make_pair(699, 425)] = 12369084;
      (*this)[make_pair(699, 426)] = 12369084;
      (*this)[make_pair(699, 427)] = 12369084;
      (*this)[make_pair(699, 428)] = 12369084;
      (*this)[make_pair(699, 429)] = 12369084;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 16777215;
      (*this)[make_pair(700, 423)] = 16777215;
      (*this)[make_pair(700, 424)] = 16777215;
      (*this)[make_pair(700, 425)] = 16777215;
      (*this)[make_pair(700, 426)] = 16777215;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 16777215;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 16777215;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 16777215;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16777215;
      (*this)[make_pair(702, 422)] = 16777215;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 16053492;
      (*this)[make_pair(702, 425)] = 14803425;
      (*this)[make_pair(702, 426)] = 14277081;
      (*this)[make_pair(702, 427)] = 16250871;
      (*this)[make_pair(702, 428)] = 16777215;
      (*this)[make_pair(702, 429)] = 16777215;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 16777215;
      (*this)[make_pair(703, 422)] = 15987699;
      (*this)[make_pair(703, 423)] = 10066329;
      (*this)[make_pair(703, 424)] = 7434609;
      (*this)[make_pair(703, 425)] = 8158332;
      (*this)[make_pair(703, 426)] = 7763574;
      (*this)[make_pair(703, 427)] = 9737364;
      (*this)[make_pair(703, 428)] = 9342606;
      (*this)[make_pair(703, 429)] = 14803425;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 9474192;
      (*this)[make_pair(704, 423)] = 12763842;
      (*this)[make_pair(704, 424)] = 16514043;
      (*this)[make_pair(704, 425)] = 11382189;
      (*this)[make_pair(704, 426)] = 16645629;
      (*this)[make_pair(704, 427)] = 16777215;
      (*this)[make_pair(704, 428)] = 15527148;
      (*this)[make_pair(704, 429)] = 10263708;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16316664;
      (*this)[make_pair(705, 422)] = 8618883;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 14671839;
      (*this)[make_pair(705, 425)] = 12500670;
      (*this)[make_pair(705, 426)] = 16777215;
      (*this)[make_pair(705, 427)] = 16777215;
      (*this)[make_pair(705, 428)] = 16777215;
      (*this)[make_pair(705, 429)] = 9605778;
      (*this)[make_pair(705, 430)] = 16514043;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 16185078;
      (*this)[make_pair(706, 422)] = 9803157;
      (*this)[make_pair(706, 423)] = 16777215;
      (*this)[make_pair(706, 424)] = 15790320;
      (*this)[make_pair(706, 425)] = 10066329;
      (*this)[make_pair(706, 426)] = 16777215;
      (*this)[make_pair(706, 427)] = 16777215;
      (*this)[make_pair(706, 428)] = 16448250;
      (*this)[make_pair(706, 429)] = 9605778;
      (*this)[make_pair(706, 430)] = 16777215;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 16777215;
      (*this)[make_pair(707, 422)] = 12171705;
      (*this)[make_pair(707, 423)] = 16777215;
      (*this)[make_pair(707, 424)] = 16777215;
      (*this)[make_pair(707, 425)] = 10790052;
      (*this)[make_pair(707, 426)] = 8947848;
      (*this)[make_pair(707, 427)] = 10724259;
      (*this)[make_pair(707, 428)] = 8684676;
      (*this)[make_pair(707, 429)] = 13684944;
      (*this)[make_pair(707, 430)] = 16777215;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 16777215;
      (*this)[make_pair(708, 422)] = 16777215;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 16777215;
      (*this)[make_pair(708, 426)] = 15790320;
      (*this)[make_pair(708, 427)] = 14145495;
      (*this)[make_pair(708, 428)] = 16645629;
      (*this)[make_pair(708, 429)] = 16777215;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s16;
  map<pair<int, int>, int> table16;
  void update_table16()
  {
    for (const auto& x : s16) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table16[pos] = x.second;
    }
  }
  // "8:00" data
  //  ^^
  struct table8_t : map<pair<int, int>, int> {
    table8_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 16777215;
      (*this)[make_pair(696, 424)] = 16777215;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 16777215;
      (*this)[make_pair(697, 423)] = 16777215;
      (*this)[make_pair(697, 424)] = 16777215;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16777215;
      (*this)[make_pair(698, 422)] = 16777215;
      (*this)[make_pair(698, 423)] = 16777215;
      (*this)[make_pair(698, 424)] = 16777215;
      (*this)[make_pair(698, 425)] = 16777215;
      (*this)[make_pair(698, 426)] = 16777215;
      (*this)[make_pair(698, 427)] = 16777215;
      (*this)[make_pair(698, 428)] = 16777215;
      (*this)[make_pair(698, 429)] = 16777215;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16777215;
      (*this)[make_pair(699, 422)] = 16777215;
      (*this)[make_pair(699, 423)] = 16448250;
      (*this)[make_pair(699, 424)] = 16777215;
      (*this)[make_pair(699, 425)] = 16777215;
      (*this)[make_pair(699, 426)] = 16645629;
      (*this)[make_pair(699, 427)] = 14079702;
      (*this)[make_pair(699, 428)] = 15592941;
      (*this)[make_pair(699, 429)] = 16777215;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 12961221;
      (*this)[make_pair(700, 423)] = 8487297;
      (*this)[make_pair(700, 424)] = 8421504;
      (*this)[make_pair(700, 425)] = 15329769;
      (*this)[make_pair(700, 426)] = 10263708;
      (*this)[make_pair(700, 427)] = 10790052;
      (*this)[make_pair(700, 428)] = 9342606;
      (*this)[make_pair(700, 429)] = 12369084;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 9737364;
      (*this)[make_pair(701, 423)] = 16579836;
      (*this)[make_pair(701, 424)] = 15658734;
      (*this)[make_pair(701, 425)] = 8224125;
      (*this)[make_pair(701, 426)] = 11908533;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 9737364;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16053492;
      (*this)[make_pair(702, 422)] = 10395294;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 16777215;
      (*this)[make_pair(702, 425)] = 9408399;
      (*this)[make_pair(702, 426)] = 14935011;
      (*this)[make_pair(702, 427)] = 16777215;
      (*this)[make_pair(702, 428)] = 16777215;
      (*this)[make_pair(702, 429)] = 10132122;
      (*this)[make_pair(702, 430)] = 16382457;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 16777215;
      (*this)[make_pair(703, 422)] = 9737364;
      (*this)[make_pair(703, 423)] = 16514043;
      (*this)[make_pair(703, 424)] = 15527148;
      (*this)[make_pair(703, 425)] = 8355711;
      (*this)[make_pair(703, 426)] = 11711154;
      (*this)[make_pair(703, 427)] = 16777215;
      (*this)[make_pair(703, 428)] = 16777215;
      (*this)[make_pair(703, 429)] = 9605778;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 13290186;
      (*this)[make_pair(704, 423)] = 8618883;
      (*this)[make_pair(704, 424)] = 8684676;
      (*this)[make_pair(704, 425)] = 15724527;
      (*this)[make_pair(704, 426)] = 9539985;
      (*this)[make_pair(704, 427)] = 10263708;
      (*this)[make_pair(704, 428)] = 8882055;
      (*this)[make_pair(704, 429)] = 12566463;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16777215;
      (*this)[make_pair(705, 422)] = 16777215;
      (*this)[make_pair(705, 423)] = 16579836;
      (*this)[make_pair(705, 424)] = 16777215;
      (*this)[make_pair(705, 425)] = 16777215;
      (*this)[make_pair(705, 426)] = 16645629;
      (*this)[make_pair(705, 427)] = 14277081;
      (*this)[make_pair(705, 428)] = 15856113;
      (*this)[make_pair(705, 429)] = 16777215;
      (*this)[make_pair(705, 430)] = 16777215;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 15987699;
      (*this)[make_pair(706, 422)] = 14737632;
      (*this)[make_pair(706, 423)] = 14737632;
      (*this)[make_pair(706, 424)] = 14737632;
      (*this)[make_pair(706, 425)] = 14737632;
      (*this)[make_pair(706, 426)] = 14737632;
      (*this)[make_pair(706, 427)] = 14737632;
      (*this)[make_pair(706, 428)] = 14737632;
      (*this)[make_pair(706, 429)] = 14737632;
      (*this)[make_pair(706, 430)] = 15527148;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 12829635;
      (*this)[make_pair(707, 422)] = 9211020;
      (*this)[make_pair(707, 423)] = 10592673;
      (*this)[make_pair(707, 424)] = 10592673;
      (*this)[make_pair(707, 425)] = 7763574;
      (*this)[make_pair(707, 426)] = 10592673;
      (*this)[make_pair(707, 427)] = 10592673;
      (*this)[make_pair(707, 428)] = 10592673;
      (*this)[make_pair(707, 429)] = 7829367;
      (*this)[make_pair(707, 430)] = 12961221;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 12829635;
      (*this)[make_pair(708, 422)] = 13158600;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 9342606;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 9539985;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s8;
  map<pair<int, int>, int> table8;
  void update_table8()
  {
    for (const auto& x : s8) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table8[pos] = x.second;
    }
  }
  // "7:00" data
  //  ^^
  struct table7_t : map<pair<int, int>, int> {
    table7_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 16777215;
      (*this)[make_pair(696, 424)] = 16777215;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 16777215;
      (*this)[make_pair(697, 423)] = 16777215;
      (*this)[make_pair(697, 424)] = 16777215;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16777215;
      (*this)[make_pair(698, 422)] = 16777215;
      (*this)[make_pair(698, 423)] = 16777215;
      (*this)[make_pair(698, 424)] = 16777215;
      (*this)[make_pair(698, 425)] = 16777215;
      (*this)[make_pair(698, 426)] = 16777215;
      (*this)[make_pair(698, 427)] = 16777215;
      (*this)[make_pair(698, 428)] = 16777215;
      (*this)[make_pair(698, 429)] = 16777215;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16711422;
      (*this)[make_pair(699, 422)] = 16448250;
      (*this)[make_pair(699, 423)] = 16777215;
      (*this)[make_pair(699, 424)] = 16777215;
      (*this)[make_pair(699, 425)] = 16777215;
      (*this)[make_pair(699, 426)] = 16777215;
      (*this)[make_pair(699, 427)] = 16777215;
      (*this)[make_pair(699, 428)] = 16777215;
      (*this)[make_pair(699, 429)] = 16777215;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 15329769;
      (*this)[make_pair(700, 422)] = 10592673;
      (*this)[make_pair(700, 423)] = 16777215;
      (*this)[make_pair(700, 424)] = 16777215;
      (*this)[make_pair(700, 425)] = 16777215;
      (*this)[make_pair(700, 426)] = 16777215;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 16777215;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 15329769;
      (*this)[make_pair(701, 422)] = 10592673;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16645629;
      (*this)[make_pair(701, 428)] = 13355979;
      (*this)[make_pair(701, 429)] = 9013641;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 15329769;
      (*this)[make_pair(702, 422)] = 10592673;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 16777215;
      (*this)[make_pair(702, 425)] = 16185078;
      (*this)[make_pair(702, 426)] = 12237498;
      (*this)[make_pair(702, 427)] = 8487297;
      (*this)[make_pair(702, 428)] = 11053224;
      (*this)[make_pair(702, 429)] = 15329769;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 15329769;
      (*this)[make_pair(703, 422)] = 10592673;
      (*this)[make_pair(703, 423)] = 15461355;
      (*this)[make_pair(703, 424)] = 11053224;
      (*this)[make_pair(703, 425)] = 8684676;
      (*this)[make_pair(703, 426)] = 12434877;
      (*this)[make_pair(703, 427)] = 16250871;
      (*this)[make_pair(703, 428)] = 16777215;
      (*this)[make_pair(703, 429)] = 16777215;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 15329769;
      (*this)[make_pair(704, 422)] = 7434609;
      (*this)[make_pair(704, 423)] = 9605778;
      (*this)[make_pair(704, 424)] = 13816530;
      (*this)[make_pair(704, 425)] = 16711422;
      (*this)[make_pair(704, 426)] = 16777215;
      (*this)[make_pair(704, 427)] = 16777215;
      (*this)[make_pair(704, 428)] = 16777215;
      (*this)[make_pair(704, 429)] = 16777215;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16645629;
      (*this)[make_pair(705, 422)] = 15987699;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 16777215;
      (*this)[make_pair(705, 425)] = 16777215;
      (*this)[make_pair(705, 426)] = 16777215;
      (*this)[make_pair(705, 427)] = 16777215;
      (*this)[make_pair(705, 428)] = 16777215;
      (*this)[make_pair(705, 429)] = 16777215;
      (*this)[make_pair(705, 430)] = 16777215;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 15987699;
      (*this)[make_pair(706, 422)] = 14737632;
      (*this)[make_pair(706, 423)] = 14737632;
      (*this)[make_pair(706, 424)] = 14737632;
      (*this)[make_pair(706, 425)] = 14737632;
      (*this)[make_pair(706, 426)] = 14737632;
      (*this)[make_pair(706, 427)] = 14737632;
      (*this)[make_pair(706, 428)] = 14737632;
      (*this)[make_pair(706, 429)] = 14737632;
      (*this)[make_pair(706, 430)] = 15527148;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 12829635;
      (*this)[make_pair(707, 422)] = 9211020;
      (*this)[make_pair(707, 423)] = 10592673;
      (*this)[make_pair(707, 424)] = 10592673;
      (*this)[make_pair(707, 425)] = 7763574;
      (*this)[make_pair(707, 426)] = 10592673;
      (*this)[make_pair(707, 427)] = 10592673;
      (*this)[make_pair(707, 428)] = 10592673;
      (*this)[make_pair(707, 429)] = 7829367;
      (*this)[make_pair(707, 430)] = 12961221;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 12829635;
      (*this)[make_pair(708, 422)] = 13158600;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 9342606;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 9539985;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s7;
  map<pair<int, int>, int> table7;
  void update_table7()
  {
    for (const auto& x : s7) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table7[pos] = x.second;
    }
  }
  // "6:00" data
  //  ^^
  struct table6_t : map<pair<int, int>, int> {
    table6_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 16777215;
      (*this)[make_pair(696, 424)] = 16777215;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 16777215;
      (*this)[make_pair(697, 423)] = 16777215;
      (*this)[make_pair(697, 424)] = 16777215;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16777215;
      (*this)[make_pair(698, 422)] = 16777215;
      (*this)[make_pair(698, 423)] = 16777215;
      (*this)[make_pair(698, 424)] = 16777215;
      (*this)[make_pair(698, 425)] = 16777215;
      (*this)[make_pair(698, 426)] = 16777215;
      (*this)[make_pair(698, 427)] = 16777215;
      (*this)[make_pair(698, 428)] = 16777215;
      (*this)[make_pair(698, 429)] = 16777215;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16777215;
      (*this)[make_pair(699, 422)] = 16777215;
      (*this)[make_pair(699, 423)] = 16777215;
      (*this)[make_pair(699, 424)] = 16053492;
      (*this)[make_pair(699, 425)] = 14803425;
      (*this)[make_pair(699, 426)] = 14277081;
      (*this)[make_pair(699, 427)] = 16250871;
      (*this)[make_pair(699, 428)] = 16777215;
      (*this)[make_pair(699, 429)] = 16777215;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 15987699;
      (*this)[make_pair(700, 423)] = 10066329;
      (*this)[make_pair(700, 424)] = 7434609;
      (*this)[make_pair(700, 425)] = 8158332;
      (*this)[make_pair(700, 426)] = 7763574;
      (*this)[make_pair(700, 427)] = 9737364;
      (*this)[make_pair(700, 428)] = 9342606;
      (*this)[make_pair(700, 429)] = 14803425;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 9474192;
      (*this)[make_pair(701, 423)] = 12763842;
      (*this)[make_pair(701, 424)] = 16514043;
      (*this)[make_pair(701, 425)] = 11382189;
      (*this)[make_pair(701, 426)] = 16645629;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 15527148;
      (*this)[make_pair(701, 429)] = 10263708;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16316664;
      (*this)[make_pair(702, 422)] = 8618883;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 14671839;
      (*this)[make_pair(702, 425)] = 12500670;
      (*this)[make_pair(702, 426)] = 16777215;
      (*this)[make_pair(702, 427)] = 16777215;
      (*this)[make_pair(702, 428)] = 16777215;
      (*this)[make_pair(702, 429)] = 9605778;
      (*this)[make_pair(702, 430)] = 16514043;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 16185078;
      (*this)[make_pair(703, 422)] = 9803157;
      (*this)[make_pair(703, 423)] = 16777215;
      (*this)[make_pair(703, 424)] = 15790320;
      (*this)[make_pair(703, 425)] = 10066329;
      (*this)[make_pair(703, 426)] = 16777215;
      (*this)[make_pair(703, 427)] = 16777215;
      (*this)[make_pair(703, 428)] = 16448250;
      (*this)[make_pair(703, 429)] = 9605778;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 12171705;
      (*this)[make_pair(704, 423)] = 16777215;
      (*this)[make_pair(704, 424)] = 16777215;
      (*this)[make_pair(704, 425)] = 10790052;
      (*this)[make_pair(704, 426)] = 8947848;
      (*this)[make_pair(704, 427)] = 10724259;
      (*this)[make_pair(704, 428)] = 8684676;
      (*this)[make_pair(704, 429)] = 13684944;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16777215;
      (*this)[make_pair(705, 422)] = 16777215;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 16777215;
      (*this)[make_pair(705, 425)] = 16777215;
      (*this)[make_pair(705, 426)] = 15790320;
      (*this)[make_pair(705, 427)] = 14145495;
      (*this)[make_pair(705, 428)] = 16645629;
      (*this)[make_pair(705, 429)] = 16777215;
      (*this)[make_pair(705, 430)] = 16777215;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 15987699;
      (*this)[make_pair(706, 422)] = 14737632;
      (*this)[make_pair(706, 423)] = 14737632;
      (*this)[make_pair(706, 424)] = 14737632;
      (*this)[make_pair(706, 425)] = 14737632;
      (*this)[make_pair(706, 426)] = 14737632;
      (*this)[make_pair(706, 427)] = 14737632;
      (*this)[make_pair(706, 428)] = 14737632;
      (*this)[make_pair(706, 429)] = 14737632;
      (*this)[make_pair(706, 430)] = 15527148;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 12829635;
      (*this)[make_pair(707, 422)] = 9211020;
      (*this)[make_pair(707, 423)] = 10592673;
      (*this)[make_pair(707, 424)] = 10592673;
      (*this)[make_pair(707, 425)] = 7763574;
      (*this)[make_pair(707, 426)] = 10592673;
      (*this)[make_pair(707, 427)] = 10592673;
      (*this)[make_pair(707, 428)] = 10592673;
      (*this)[make_pair(707, 429)] = 7829367;
      (*this)[make_pair(707, 430)] = 12961221;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 12829635;
      (*this)[make_pair(708, 422)] = 13158600;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 9342606;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 9539985;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s6;
  map<pair<int, int>, int> table6;
  void update_table6()
  {
    for (const auto& x : s6) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table6[pos] = x.second;
    }
  }
  // "5:00" data
  //  ^^
  struct table5_t : map<pair<int, int>, int> {
    table5_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 16777215;
      (*this)[make_pair(696, 424)] = 16777215;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 16777215;
      (*this)[make_pair(697, 423)] = 16777215;
      (*this)[make_pair(697, 424)] = 16777215;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16777215;
      (*this)[make_pair(698, 422)] = 16777215;
      (*this)[make_pair(698, 423)] = 16777215;
      (*this)[make_pair(698, 424)] = 16777215;
      (*this)[make_pair(698, 425)] = 16777215;
      (*this)[make_pair(698, 426)] = 16777215;
      (*this)[make_pair(698, 427)] = 16777215;
      (*this)[make_pair(698, 428)] = 16777215;
      (*this)[make_pair(698, 429)] = 16777215;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16777215;
      (*this)[make_pair(699, 422)] = 16777215;
      (*this)[make_pair(699, 423)] = 16777215;
      (*this)[make_pair(699, 424)] = 16777215;
      (*this)[make_pair(699, 425)] = 16777215;
      (*this)[make_pair(699, 426)] = 16777215;
      (*this)[make_pair(699, 427)] = 16777215;
      (*this)[make_pair(699, 428)] = 16777215;
      (*this)[make_pair(699, 429)] = 16777215;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 15987699;
      (*this)[make_pair(700, 422)] = 10724259;
      (*this)[make_pair(700, 423)] = 10132122;
      (*this)[make_pair(700, 424)] = 9605778;
      (*this)[make_pair(700, 425)] = 9013641;
      (*this)[make_pair(700, 426)] = 16185078;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16316664;
      (*this)[make_pair(700, 429)] = 10000536;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 15329769;
      (*this)[make_pair(701, 422)] = 9737364;
      (*this)[make_pair(701, 423)] = 14935011;
      (*this)[make_pair(701, 424)] = 15592941;
      (*this)[make_pair(701, 425)] = 9013641;
      (*this)[make_pair(701, 426)] = 16711422;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 9145227;
      (*this)[make_pair(701, 430)] = 16579836;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 15329769;
      (*this)[make_pair(702, 422)] = 10592673;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 16119285;
      (*this)[make_pair(702, 425)] = 10197915;
      (*this)[make_pair(702, 426)] = 16777215;
      (*this)[make_pair(702, 427)] = 16777215;
      (*this)[make_pair(702, 428)] = 16777215;
      (*this)[make_pair(702, 429)] = 9474192;
      (*this)[make_pair(702, 430)] = 16514043;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 15329769;
      (*this)[make_pair(703, 422)] = 10592673;
      (*this)[make_pair(703, 423)] = 16777215;
      (*this)[make_pair(703, 424)] = 16777215;
      (*this)[make_pair(703, 425)] = 9408399;
      (*this)[make_pair(703, 426)] = 15461355;
      (*this)[make_pair(703, 427)] = 16711422;
      (*this)[make_pair(703, 428)] = 14013909;
      (*this)[make_pair(703, 429)] = 10197915;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 15790320;
      (*this)[make_pair(704, 422)] = 12500670;
      (*this)[make_pair(704, 423)] = 16777215;
      (*this)[make_pair(704, 424)] = 16777215;
      (*this)[make_pair(704, 425)] = 14211288;
      (*this)[make_pair(704, 426)] = 9408399;
      (*this)[make_pair(704, 427)] = 8158332;
      (*this)[make_pair(704, 428)] = 10658466;
      (*this)[make_pair(704, 429)] = 15198183;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16777215;
      (*this)[make_pair(705, 422)] = 16777215;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 16777215;
      (*this)[make_pair(705, 425)] = 16777215;
      (*this)[make_pair(705, 426)] = 16777215;
      (*this)[make_pair(705, 427)] = 16777215;
      (*this)[make_pair(705, 428)] = 16777215;
      (*this)[make_pair(705, 429)] = 16777215;
      (*this)[make_pair(705, 430)] = 16777215;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 15987699;
      (*this)[make_pair(706, 422)] = 14737632;
      (*this)[make_pair(706, 423)] = 14737632;
      (*this)[make_pair(706, 424)] = 14737632;
      (*this)[make_pair(706, 425)] = 14737632;
      (*this)[make_pair(706, 426)] = 14737632;
      (*this)[make_pair(706, 427)] = 14737632;
      (*this)[make_pair(706, 428)] = 14737632;
      (*this)[make_pair(706, 429)] = 14737632;
      (*this)[make_pair(706, 430)] = 15527148;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 12829635;
      (*this)[make_pair(707, 422)] = 9211020;
      (*this)[make_pair(707, 423)] = 10592673;
      (*this)[make_pair(707, 424)] = 10592673;
      (*this)[make_pair(707, 425)] = 7763574;
      (*this)[make_pair(707, 426)] = 10592673;
      (*this)[make_pair(707, 427)] = 10592673;
      (*this)[make_pair(707, 428)] = 10592673;
      (*this)[make_pair(707, 429)] = 7829367;
      (*this)[make_pair(707, 430)] = 12961221;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 12829635;
      (*this)[make_pair(708, 422)] = 13158600;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 9342606;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 9539985;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s5;
  map<pair<int, int>, int> table5;
  void update_table5()
  {
    for (const auto& x : s5) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table5[pos] = x.second;
    }
  }
  // "4:00" data
  //  ^^
  struct table4_t : map<pair<int, int>, int> {
    table4_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 16777215;
      (*this)[make_pair(696, 424)] = 16777215;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 16777215;
      (*this)[make_pair(697, 423)] = 16777215;
      (*this)[make_pair(697, 424)] = 16777215;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16777215;
      (*this)[make_pair(698, 422)] = 16777215;
      (*this)[make_pair(698, 423)] = 16777215;
      (*this)[make_pair(698, 424)] = 16777215;
      (*this)[make_pair(698, 425)] = 16777215;
      (*this)[make_pair(698, 426)] = 16777215;
      (*this)[make_pair(698, 427)] = 16777215;
      (*this)[make_pair(698, 428)] = 16777215;
      (*this)[make_pair(698, 429)] = 16777215;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16777215;
      (*this)[make_pair(699, 422)] = 16777215;
      (*this)[make_pair(699, 423)] = 16777215;
      (*this)[make_pair(699, 424)] = 16777215;
      (*this)[make_pair(699, 425)] = 16777215;
      (*this)[make_pair(699, 426)] = 14935011;
      (*this)[make_pair(699, 427)] = 9539985;
      (*this)[make_pair(699, 428)] = 15921906;
      (*this)[make_pair(699, 429)] = 16777215;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 16777215;
      (*this)[make_pair(700, 423)] = 16777215;
      (*this)[make_pair(700, 424)] = 16711422;
      (*this)[make_pair(700, 425)] = 12171705;
      (*this)[make_pair(700, 426)] = 9737364;
      (*this)[make_pair(700, 427)] = 9539985;
      (*this)[make_pair(700, 428)] = 15658734;
      (*this)[make_pair(700, 429)] = 16777215;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 16777215;
      (*this)[make_pair(701, 423)] = 15592941;
      (*this)[make_pair(701, 424)] = 9605778;
      (*this)[make_pair(701, 425)] = 12434877;
      (*this)[make_pair(701, 426)] = 16711422;
      (*this)[make_pair(701, 427)] = 10461087;
      (*this)[make_pair(701, 428)] = 15658734;
      (*this)[make_pair(701, 429)] = 16777215;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16777215;
      (*this)[make_pair(702, 422)] = 13158600;
      (*this)[make_pair(702, 423)] = 9342606;
      (*this)[make_pair(702, 424)] = 15132390;
      (*this)[make_pair(702, 425)] = 16777215;
      (*this)[make_pair(702, 426)] = 16777215;
      (*this)[make_pair(702, 427)] = 10461087;
      (*this)[make_pair(702, 428)] = 15658734;
      (*this)[make_pair(702, 429)] = 16777215;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 15461355;
      (*this)[make_pair(703, 422)] = 6974058;
      (*this)[make_pair(703, 423)] = 7763574;
      (*this)[make_pair(703, 424)] = 7960953;
      (*this)[make_pair(703, 425)] = 7960953;
      (*this)[make_pair(703, 426)] = 7960953;
      (*this)[make_pair(703, 427)] = 7171437;
      (*this)[make_pair(703, 428)] = 7829367;
      (*this)[make_pair(703, 429)] = 7960953;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 16777215;
      (*this)[make_pair(704, 423)] = 16777215;
      (*this)[make_pair(704, 424)] = 16777215;
      (*this)[make_pair(704, 425)] = 16777215;
      (*this)[make_pair(704, 426)] = 16777215;
      (*this)[make_pair(704, 427)] = 10461087;
      (*this)[make_pair(704, 428)] = 15658734;
      (*this)[make_pair(704, 429)] = 16777215;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16777215;
      (*this)[make_pair(705, 422)] = 16777215;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 16777215;
      (*this)[make_pair(705, 425)] = 16777215;
      (*this)[make_pair(705, 426)] = 16777215;
      (*this)[make_pair(705, 427)] = 14737632;
      (*this)[make_pair(705, 428)] = 16448250;
      (*this)[make_pair(705, 429)] = 16777215;
      (*this)[make_pair(705, 430)] = 16777215;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 15987699;
      (*this)[make_pair(706, 422)] = 14737632;
      (*this)[make_pair(706, 423)] = 14737632;
      (*this)[make_pair(706, 424)] = 14737632;
      (*this)[make_pair(706, 425)] = 14737632;
      (*this)[make_pair(706, 426)] = 14737632;
      (*this)[make_pair(706, 427)] = 14737632;
      (*this)[make_pair(706, 428)] = 14737632;
      (*this)[make_pair(706, 429)] = 14737632;
      (*this)[make_pair(706, 430)] = 15527148;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 12829635;
      (*this)[make_pair(707, 422)] = 9211020;
      (*this)[make_pair(707, 423)] = 10592673;
      (*this)[make_pair(707, 424)] = 10592673;
      (*this)[make_pair(707, 425)] = 7763574;
      (*this)[make_pair(707, 426)] = 10592673;
      (*this)[make_pair(707, 427)] = 10592673;
      (*this)[make_pair(707, 428)] = 10592673;
      (*this)[make_pair(707, 429)] = 7829367;
      (*this)[make_pair(707, 430)] = 12961221;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 12829635;
      (*this)[make_pair(708, 422)] = 13158600;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 9342606;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 9539985;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s4;
  map<pair<int, int>, int> table4;
  void update_table4()
  {
    for (const auto& x : s4) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table4[pos] = x.second;
    }
  }
  // "3:00" data
  //  ^^
  struct table3_t : map<pair<int, int>, int> {
    table3_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 16777215;
      (*this)[make_pair(696, 424)] = 16777215;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 16777215;
      (*this)[make_pair(697, 423)] = 16777215;
      (*this)[make_pair(697, 424)] = 16777215;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16777215;
      (*this)[make_pair(698, 422)] = 16777215;
      (*this)[make_pair(698, 423)] = 16777215;
      (*this)[make_pair(698, 424)] = 16777215;
      (*this)[make_pair(698, 425)] = 16777215;
      (*this)[make_pair(698, 426)] = 16777215;
      (*this)[make_pair(698, 427)] = 16777215;
      (*this)[make_pair(698, 428)] = 16777215;
      (*this)[make_pair(698, 429)] = 16777215;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16777215;
      (*this)[make_pair(699, 422)] = 16777215;
      (*this)[make_pair(699, 423)] = 16777215;
      (*this)[make_pair(699, 424)] = 16777215;
      (*this)[make_pair(699, 425)] = 16777215;
      (*this)[make_pair(699, 426)] = 16777215;
      (*this)[make_pair(699, 427)] = 16777215;
      (*this)[make_pair(699, 428)] = 16777215;
      (*this)[make_pair(699, 429)] = 16777215;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 15395562;
      (*this)[make_pair(700, 422)] = 10724259;
      (*this)[make_pair(700, 423)] = 16777215;
      (*this)[make_pair(700, 424)] = 16777215;
      (*this)[make_pair(700, 425)] = 16777215;
      (*this)[make_pair(700, 426)] = 16777215;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16250871;
      (*this)[make_pair(700, 429)] = 9737364;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 15329769;
      (*this)[make_pair(701, 422)] = 10592673;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 14277081;
      (*this)[make_pair(701, 425)] = 8421504;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 9145227;
      (*this)[make_pair(701, 430)] = 16579836;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 15329769;
      (*this)[make_pair(702, 422)] = 10592673;
      (*this)[make_pair(702, 423)] = 14342874;
      (*this)[make_pair(702, 424)] = 8816262;
      (*this)[make_pair(702, 425)] = 8882055;
      (*this)[make_pair(702, 426)] = 16119285;
      (*this)[make_pair(702, 427)] = 16777215;
      (*this)[make_pair(702, 428)] = 16777215;
      (*this)[make_pair(702, 429)] = 9474192;
      (*this)[make_pair(702, 430)] = 16514043;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 15329769;
      (*this)[make_pair(703, 422)] = 8750469;
      (*this)[make_pair(703, 423)] = 8816262;
      (*this)[make_pair(703, 424)] = 15856113;
      (*this)[make_pair(703, 425)] = 12303291;
      (*this)[make_pair(703, 426)] = 11908533;
      (*this)[make_pair(703, 427)] = 16316664;
      (*this)[make_pair(703, 428)] = 13487565;
      (*this)[make_pair(703, 429)] = 10197915;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 15658734;
      (*this)[make_pair(704, 422)] = 9211020;
      (*this)[make_pair(704, 423)] = 15856113;
      (*this)[make_pair(704, 424)] = 16777215;
      (*this)[make_pair(704, 425)] = 15987699;
      (*this)[make_pair(704, 426)] = 10987431;
      (*this)[make_pair(704, 427)] = 8355711;
      (*this)[make_pair(704, 428)] = 11184810;
      (*this)[make_pair(704, 429)] = 15461355;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16777215;
      (*this)[make_pair(705, 422)] = 16777215;
      (*this)[make_pair(705, 423)] = 16777215;
      (*this)[make_pair(705, 424)] = 16777215;
      (*this)[make_pair(705, 425)] = 16777215;
      (*this)[make_pair(705, 426)] = 16777215;
      (*this)[make_pair(705, 427)] = 16777215;
      (*this)[make_pair(705, 428)] = 16777215;
      (*this)[make_pair(705, 429)] = 16777215;
      (*this)[make_pair(705, 430)] = 16777215;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 15987699;
      (*this)[make_pair(706, 422)] = 14737632;
      (*this)[make_pair(706, 423)] = 14737632;
      (*this)[make_pair(706, 424)] = 14737632;
      (*this)[make_pair(706, 425)] = 14737632;
      (*this)[make_pair(706, 426)] = 14737632;
      (*this)[make_pair(706, 427)] = 14737632;
      (*this)[make_pair(706, 428)] = 14737632;
      (*this)[make_pair(706, 429)] = 14737632;
      (*this)[make_pair(706, 430)] = 15527148;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 12829635;
      (*this)[make_pair(707, 422)] = 9211020;
      (*this)[make_pair(707, 423)] = 10592673;
      (*this)[make_pair(707, 424)] = 10592673;
      (*this)[make_pair(707, 425)] = 7763574;
      (*this)[make_pair(707, 426)] = 10592673;
      (*this)[make_pair(707, 427)] = 10592673;
      (*this)[make_pair(707, 428)] = 10592673;
      (*this)[make_pair(707, 429)] = 7829367;
      (*this)[make_pair(707, 430)] = 12961221;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 12829635;
      (*this)[make_pair(708, 422)] = 13158600;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 9342606;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 9539985;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s3;
  map<pair<int, int>, int> table3;
  void update_table3()
  {
    for (const auto& x : s3) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table3[pos] = x.second;
    }
  }
  // "14:00" data
  //  ^^
  struct table14_t : map<pair<int, int>, int> {
    table14_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 12632256;
      (*this)[make_pair(696, 424)] = 13816530;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 13882323;
      (*this)[make_pair(697, 423)] = 9868950;
      (*this)[make_pair(697, 424)] = 16711422;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16053492;
      (*this)[make_pair(698, 422)] = 7500402;
      (*this)[make_pair(698, 423)] = 11842740;
      (*this)[make_pair(698, 424)] = 12369084;
      (*this)[make_pair(698, 425)] = 12369084;
      (*this)[make_pair(698, 426)] = 12369084;
      (*this)[make_pair(698, 427)] = 12369084;
      (*this)[make_pair(698, 428)] = 12369084;
      (*this)[make_pair(698, 429)] = 12369084;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16185078;
      (*this)[make_pair(699, 422)] = 12369084;
      (*this)[make_pair(699, 423)] = 12369084;
      (*this)[make_pair(699, 424)] = 12369084;
      (*this)[make_pair(699, 425)] = 12369084;
      (*this)[make_pair(699, 426)] = 12369084;
      (*this)[make_pair(699, 427)] = 12369084;
      (*this)[make_pair(699, 428)] = 12369084;
      (*this)[make_pair(699, 429)] = 12369084;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 16777215;
      (*this)[make_pair(700, 423)] = 16777215;
      (*this)[make_pair(700, 424)] = 16777215;
      (*this)[make_pair(700, 425)] = 16777215;
      (*this)[make_pair(700, 426)] = 16777215;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 16777215;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 16777215;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 16777215;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16777215;
      (*this)[make_pair(702, 422)] = 16777215;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 16777215;
      (*this)[make_pair(702, 425)] = 16777215;
      (*this)[make_pair(702, 426)] = 14935011;
      (*this)[make_pair(702, 427)] = 9539985;
      (*this)[make_pair(702, 428)] = 15921906;
      (*this)[make_pair(702, 429)] = 16777215;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 16777215;
      (*this)[make_pair(703, 422)] = 16777215;
      (*this)[make_pair(703, 423)] = 16777215;
      (*this)[make_pair(703, 424)] = 16711422;
      (*this)[make_pair(703, 425)] = 12171705;
      (*this)[make_pair(703, 426)] = 9737364;
      (*this)[make_pair(703, 427)] = 9539985;
      (*this)[make_pair(703, 428)] = 15658734;
      (*this)[make_pair(703, 429)] = 16777215;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 16777215;
      (*this)[make_pair(704, 423)] = 15592941;
      (*this)[make_pair(704, 424)] = 9605778;
      (*this)[make_pair(704, 425)] = 12434877;
      (*this)[make_pair(704, 426)] = 16711422;
      (*this)[make_pair(704, 427)] = 10461087;
      (*this)[make_pair(704, 428)] = 15658734;
      (*this)[make_pair(704, 429)] = 16777215;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16777215;
      (*this)[make_pair(705, 422)] = 13158600;
      (*this)[make_pair(705, 423)] = 9342606;
      (*this)[make_pair(705, 424)] = 15132390;
      (*this)[make_pair(705, 425)] = 16777215;
      (*this)[make_pair(705, 426)] = 16777215;
      (*this)[make_pair(705, 427)] = 10461087;
      (*this)[make_pair(705, 428)] = 15658734;
      (*this)[make_pair(705, 429)] = 16777215;
      (*this)[make_pair(705, 430)] = 16777215;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 15461355;
      (*this)[make_pair(706, 422)] = 6974058;
      (*this)[make_pair(706, 423)] = 7763574;
      (*this)[make_pair(706, 424)] = 7960953;
      (*this)[make_pair(706, 425)] = 7960953;
      (*this)[make_pair(706, 426)] = 7960953;
      (*this)[make_pair(706, 427)] = 7171437;
      (*this)[make_pair(706, 428)] = 7829367;
      (*this)[make_pair(706, 429)] = 7960953;
      (*this)[make_pair(706, 430)] = 16777215;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 16777215;
      (*this)[make_pair(707, 422)] = 16777215;
      (*this)[make_pair(707, 423)] = 16777215;
      (*this)[make_pair(707, 424)] = 16777215;
      (*this)[make_pair(707, 425)] = 16777215;
      (*this)[make_pair(707, 426)] = 16777215;
      (*this)[make_pair(707, 427)] = 10461087;
      (*this)[make_pair(707, 428)] = 15658734;
      (*this)[make_pair(707, 429)] = 16777215;
      (*this)[make_pair(707, 430)] = 16777215;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 16777215;
      (*this)[make_pair(708, 422)] = 16777215;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 16777215;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 14737632;
      (*this)[make_pair(708, 428)] = 16448250;
      (*this)[make_pair(708, 429)] = 16777215;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s14;
  map<pair<int, int>, int> table14;
  void update_table14()
  {
    for (const auto& x : s14) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table14[pos] = x.second;
    }
  }
  // "12:00" data
  //  ^^
  struct table12_t : map<pair<int, int>, int> {
    table12_t()
    {
      (*this)[make_pair(657, 423)] = 16777215;
      (*this)[make_pair(657, 424)] = 16777215;
      (*this)[make_pair(657, 425)] = 12632256;
      (*this)[make_pair(657, 426)] = 13816530;
      (*this)[make_pair(657, 427)] = 16777215;
      (*this)[make_pair(657, 428)] = 16777215;
      (*this)[make_pair(657, 429)] = 16777215;
      (*this)[make_pair(657, 430)] = 16777215;
      (*this)[make_pair(657, 431)] = 16777215;
      (*this)[make_pair(657, 432)] = 16777215;
      (*this)[make_pair(657, 433)] = 16777215;
      (*this)[make_pair(657, 434)] = 16777215;
      (*this)[make_pair(657, 435)] = 16777215;
      (*this)[make_pair(658, 423)] = 16777215;
      (*this)[make_pair(658, 424)] = 13882323;
      (*this)[make_pair(658, 425)] = 9868950;
      (*this)[make_pair(658, 426)] = 16711422;
      (*this)[make_pair(658, 427)] = 16777215;
      (*this)[make_pair(658, 428)] = 16777215;
      (*this)[make_pair(658, 429)] = 16777215;
      (*this)[make_pair(658, 430)] = 16777215;
      (*this)[make_pair(658, 431)] = 16777215;
      (*this)[make_pair(658, 432)] = 16777215;
      (*this)[make_pair(658, 433)] = 16777215;
      (*this)[make_pair(658, 434)] = 16777215;
      (*this)[make_pair(658, 435)] = 16777215;
      (*this)[make_pair(659, 423)] = 16053492;
      (*this)[make_pair(659, 424)] = 7500402;
      (*this)[make_pair(659, 425)] = 11842740;
      (*this)[make_pair(659, 426)] = 12369084;
      (*this)[make_pair(659, 427)] = 12369084;
      (*this)[make_pair(659, 428)] = 12369084;
      (*this)[make_pair(659, 429)] = 12369084;
      (*this)[make_pair(659, 430)] = 12369084;
      (*this)[make_pair(659, 431)] = 12369084;
      (*this)[make_pair(659, 432)] = 16777215;
      (*this)[make_pair(659, 433)] = 16777215;
      (*this)[make_pair(659, 434)] = 16777215;
      (*this)[make_pair(659, 435)] = 16777215;
      (*this)[make_pair(660, 423)] = 16185078;
      (*this)[make_pair(660, 424)] = 12369084;
      (*this)[make_pair(660, 425)] = 12369084;
      (*this)[make_pair(660, 426)] = 12369084;
      (*this)[make_pair(660, 427)] = 12369084;
      (*this)[make_pair(660, 428)] = 12369084;
      (*this)[make_pair(660, 429)] = 12369084;
      (*this)[make_pair(660, 430)] = 12369084;
      (*this)[make_pair(660, 431)] = 12369084;
      (*this)[make_pair(660, 432)] = 16777215;
      (*this)[make_pair(660, 433)] = 16777215;
      (*this)[make_pair(660, 434)] = 16777215;
      (*this)[make_pair(660, 435)] = 16777215;
      (*this)[make_pair(661, 423)] = 16777215;
      (*this)[make_pair(661, 424)] = 16777215;
      (*this)[make_pair(661, 425)] = 16777215;
      (*this)[make_pair(661, 426)] = 16777215;
      (*this)[make_pair(661, 427)] = 16777215;
      (*this)[make_pair(661, 428)] = 16777215;
      (*this)[make_pair(661, 429)] = 16777215;
      (*this)[make_pair(661, 430)] = 16777215;
      (*this)[make_pair(661, 431)] = 16777215;
      (*this)[make_pair(661, 432)] = 16777215;
      (*this)[make_pair(661, 433)] = 16777215;
      (*this)[make_pair(661, 434)] = 16777215;
      (*this)[make_pair(661, 435)] = 16777215;
      (*this)[make_pair(662, 423)] = 16777215;
      (*this)[make_pair(662, 424)] = 16777215;
      (*this)[make_pair(662, 425)] = 16777215;
      (*this)[make_pair(662, 426)] = 16777215;
      (*this)[make_pair(662, 427)] = 16777215;
      (*this)[make_pair(662, 428)] = 16777215;
      (*this)[make_pair(662, 429)] = 16777215;
      (*this)[make_pair(662, 430)] = 16777215;
      (*this)[make_pair(662, 431)] = 16777215;
      (*this)[make_pair(662, 432)] = 16777215;
      (*this)[make_pair(662, 433)] = 16777215;
      (*this)[make_pair(662, 434)] = 16777215;
      (*this)[make_pair(662, 435)] = 16777215;
      (*this)[make_pair(663, 423)] = 16777215;
      (*this)[make_pair(663, 424)] = 16777215;
      (*this)[make_pair(663, 425)] = 16777215;
      (*this)[make_pair(663, 426)] = 16777215;
      (*this)[make_pair(663, 427)] = 16777215;
      (*this)[make_pair(663, 428)] = 16777215;
      (*this)[make_pair(663, 429)] = 16777215;
      (*this)[make_pair(663, 430)] = 16777215;
      (*this)[make_pair(663, 431)] = 16711422;
      (*this)[make_pair(663, 432)] = 16777215;
      (*this)[make_pair(663, 433)] = 16777215;
      (*this)[make_pair(663, 434)] = 16777215;
      (*this)[make_pair(663, 435)] = 16777215;
      (*this)[make_pair(664, 423)] = 16777215;
      (*this)[make_pair(664, 424)] = 10790052;
      (*this)[make_pair(664, 425)] = 15724527;
      (*this)[make_pair(664, 426)] = 16777215;
      (*this)[make_pair(664, 427)] = 16777215;
      (*this)[make_pair(664, 428)] = 16777215;
      (*this)[make_pair(664, 429)] = 16777215;
      (*this)[make_pair(664, 430)] = 14540253;
      (*this)[make_pair(664, 431)] = 7039851;
      (*this)[make_pair(664, 432)] = 16777215;
      (*this)[make_pair(664, 433)] = 16777215;
      (*this)[make_pair(664, 434)] = 16777215;
      (*this)[make_pair(664, 435)] = 16777215;
      (*this)[make_pair(665, 423)] = 16777215;
      (*this)[make_pair(665, 424)] = 9013641;
      (*this)[make_pair(665, 425)] = 16777215;
      (*this)[make_pair(665, 426)] = 16777215;
      (*this)[make_pair(665, 427)] = 16777215;
      (*this)[make_pair(665, 428)] = 16777215;
      (*this)[make_pair(665, 429)] = 15329769;
      (*this)[make_pair(665, 430)] = 8816262;
      (*this)[make_pair(665, 431)] = 8553090;
      (*this)[make_pair(665, 432)] = 16777215;
      (*this)[make_pair(665, 433)] = 16777215;
      (*this)[make_pair(665, 434)] = 16777215;
      (*this)[make_pair(665, 435)] = 16777215;
      (*this)[make_pair(666, 423)] = 16119285;
      (*this)[make_pair(666, 424)] = 9737364;
      (*this)[make_pair(666, 425)] = 16777215;
      (*this)[make_pair(666, 426)] = 16777215;
      (*this)[make_pair(666, 427)] = 16777215;
      (*this)[make_pair(666, 428)] = 15198183;
      (*this)[make_pair(666, 429)] = 8684676;
      (*this)[make_pair(666, 430)] = 15329769;
      (*this)[make_pair(666, 431)] = 9342606;
      (*this)[make_pair(666, 432)] = 16777215;
      (*this)[make_pair(666, 433)] = 16777215;
      (*this)[make_pair(666, 434)] = 16777215;
      (*this)[make_pair(666, 435)] = 16777215;
      (*this)[make_pair(667, 423)] = 16777215;
      (*this)[make_pair(667, 424)] = 9276813;
      (*this)[make_pair(667, 425)] = 14145495;
      (*this)[make_pair(667, 426)] = 15395562;
      (*this)[make_pair(667, 427)] = 11382189;
      (*this)[make_pair(667, 428)] = 8618883;
      (*this)[make_pair(667, 429)] = 15132390;
      (*this)[make_pair(667, 430)] = 16777215;
      (*this)[make_pair(667, 431)] = 9342606;
      (*this)[make_pair(667, 432)] = 16777215;
      (*this)[make_pair(667, 433)] = 16777215;
      (*this)[make_pair(667, 434)] = 16777215;
      (*this)[make_pair(667, 435)] = 16777215;
      (*this)[make_pair(668, 423)] = 16777215;
      (*this)[make_pair(668, 424)] = 14803425;
      (*this)[make_pair(668, 425)] = 10197915;
      (*this)[make_pair(668, 426)] = 9013641;
      (*this)[make_pair(668, 427)] = 12566463;
      (*this)[make_pair(668, 428)] = 16119285;
      (*this)[make_pair(668, 429)] = 16777215;
      (*this)[make_pair(668, 430)] = 16777215;
      (*this)[make_pair(668, 431)] = 9803157;
      (*this)[make_pair(668, 432)] = 16777215;
      (*this)[make_pair(668, 433)] = 16777215;
      (*this)[make_pair(668, 434)] = 16777215;
      (*this)[make_pair(668, 435)] = 16777215;
      (*this)[make_pair(669, 423)] = 16777215;
      (*this)[make_pair(669, 424)] = 16777215;
      (*this)[make_pair(669, 425)] = 16777215;
      (*this)[make_pair(669, 426)] = 16777215;
      (*this)[make_pair(669, 427)] = 16777215;
      (*this)[make_pair(669, 428)] = 16777215;
      (*this)[make_pair(669, 429)] = 16777215;
      (*this)[make_pair(669, 430)] = 16777215;
      (*this)[make_pair(669, 431)] = 16777215;
      (*this)[make_pair(669, 432)] = 16777215;
      (*this)[make_pair(669, 433)] = 16777215;
      (*this)[make_pair(669, 434)] = 16777215;
      (*this)[make_pair(669, 435)] = 16777215;
    }
  } s12;
  map<pair<int,int>, int> table12;
  void update_table12()
  {
    for (const auto& x : s12) {
      auto pos = x.first;
      pos.first += time_button.first - 271;
      pos.second += time_button.second - 482;
      table12[pos] = x.second;
    }
  }
  // "13:00" data
  //  ^^
  struct table13_t : map<pair<int, int>, int> {
    table13_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 12632256;
      (*this)[make_pair(696, 424)] = 13816530;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 13882323;
      (*this)[make_pair(697, 423)] = 9868950;
      (*this)[make_pair(697, 424)] = 16711422;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16053492;
      (*this)[make_pair(698, 422)] = 7500402;
      (*this)[make_pair(698, 423)] = 11842740;
      (*this)[make_pair(698, 424)] = 12369084;
      (*this)[make_pair(698, 425)] = 12369084;
      (*this)[make_pair(698, 426)] = 12369084;
      (*this)[make_pair(698, 427)] = 12369084;
      (*this)[make_pair(698, 428)] = 12369084;
      (*this)[make_pair(698, 429)] = 12369084;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16185078;
      (*this)[make_pair(699, 422)] = 12369084;
      (*this)[make_pair(699, 423)] = 12369084;
      (*this)[make_pair(699, 424)] = 12369084;
      (*this)[make_pair(699, 425)] = 12369084;
      (*this)[make_pair(699, 426)] = 12369084;
      (*this)[make_pair(699, 427)] = 12369084;
      (*this)[make_pair(699, 428)] = 12369084;
      (*this)[make_pair(699, 429)] = 12369084;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 16777215;
      (*this)[make_pair(700, 423)] = 16777215;
      (*this)[make_pair(700, 424)] = 16777215;
      (*this)[make_pair(700, 425)] = 16777215;
      (*this)[make_pair(700, 426)] = 16777215;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 16777215;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 16777215;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 16777215;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16777215;
      (*this)[make_pair(702, 422)] = 16777215;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 16777215;
      (*this)[make_pair(702, 425)] = 16777215;
      (*this)[make_pair(702, 426)] = 16777215;
      (*this)[make_pair(702, 427)] = 16777215;
      (*this)[make_pair(702, 428)] = 16777215;
      (*this)[make_pair(702, 429)] = 16777215;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 15395562;
      (*this)[make_pair(703, 422)] = 10724259;
      (*this)[make_pair(703, 423)] = 16777215;
      (*this)[make_pair(703, 424)] = 16777215;
      (*this)[make_pair(703, 425)] = 16777215;
      (*this)[make_pair(703, 426)] = 16777215;
      (*this)[make_pair(703, 427)] = 16777215;
      (*this)[make_pair(703, 428)] = 16250871;
      (*this)[make_pair(703, 429)] = 9737364;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 15329769;
      (*this)[make_pair(704, 422)] = 10592673;
      (*this)[make_pair(704, 423)] = 16777215;
      (*this)[make_pair(704, 424)] = 14277081;
      (*this)[make_pair(704, 425)] = 8421504;
      (*this)[make_pair(704, 426)] = 16777215;
      (*this)[make_pair(704, 427)] = 16777215;
      (*this)[make_pair(704, 428)] = 16777215;
      (*this)[make_pair(704, 429)] = 9145227;
      (*this)[make_pair(704, 430)] = 16579836;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 15329769;
      (*this)[make_pair(705, 422)] = 10592673;
      (*this)[make_pair(705, 423)] = 14342874;
      (*this)[make_pair(705, 424)] = 8816262;
      (*this)[make_pair(705, 425)] = 8882055;
      (*this)[make_pair(705, 426)] = 16119285;
      (*this)[make_pair(705, 427)] = 16777215;
      (*this)[make_pair(705, 428)] = 16777215;
      (*this)[make_pair(705, 429)] = 9474192;
      (*this)[make_pair(705, 430)] = 16514043;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 15329769;
      (*this)[make_pair(706, 422)] = 8750469;
      (*this)[make_pair(706, 423)] = 8816262;
      (*this)[make_pair(706, 424)] = 15856113;
      (*this)[make_pair(706, 425)] = 12303291;
      (*this)[make_pair(706, 426)] = 11908533;
      (*this)[make_pair(706, 427)] = 16316664;
      (*this)[make_pair(706, 428)] = 13487565;
      (*this)[make_pair(706, 429)] = 10197915;
      (*this)[make_pair(706, 430)] = 16777215;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 15658734;
      (*this)[make_pair(707, 422)] = 9211020;
      (*this)[make_pair(707, 423)] = 15856113;
      (*this)[make_pair(707, 424)] = 16777215;
      (*this)[make_pair(707, 425)] = 15987699;
      (*this)[make_pair(707, 426)] = 10987431;
      (*this)[make_pair(707, 427)] = 8355711;
      (*this)[make_pair(707, 428)] = 11184810;
      (*this)[make_pair(707, 429)] = 15461355;
      (*this)[make_pair(707, 430)] = 16777215;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 16777215;
      (*this)[make_pair(708, 422)] = 16777215;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 16777215;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 16777215;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s13;
  map<pair<int,int>, int> table13;
  void update_table13()
  {
    for (const auto& x : s13) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table13[pos] = x.second;
    }
  }
  // "11:00" data
  //  ^^
  struct table11_t : map<pair<int, int>, int> {
    table11_t()
    {
      (*this)[make_pair(696, 421)] = 16777215;
      (*this)[make_pair(696, 422)] = 16777215;
      (*this)[make_pair(696, 423)] = 12632256;
      (*this)[make_pair(696, 424)] = 13816530;
      (*this)[make_pair(696, 425)] = 16777215;
      (*this)[make_pair(696, 426)] = 16777215;
      (*this)[make_pair(696, 427)] = 16777215;
      (*this)[make_pair(696, 428)] = 16777215;
      (*this)[make_pair(696, 429)] = 16777215;
      (*this)[make_pair(696, 430)] = 16777215;
      (*this)[make_pair(696, 431)] = 16777215;
      (*this)[make_pair(696, 432)] = 16777215;
      (*this)[make_pair(696, 433)] = 16777215;
      (*this)[make_pair(697, 421)] = 16777215;
      (*this)[make_pair(697, 422)] = 13882323;
      (*this)[make_pair(697, 423)] = 9868950;
      (*this)[make_pair(697, 424)] = 16711422;
      (*this)[make_pair(697, 425)] = 16777215;
      (*this)[make_pair(697, 426)] = 16777215;
      (*this)[make_pair(697, 427)] = 16777215;
      (*this)[make_pair(697, 428)] = 16777215;
      (*this)[make_pair(697, 429)] = 16777215;
      (*this)[make_pair(697, 430)] = 16777215;
      (*this)[make_pair(697, 431)] = 16777215;
      (*this)[make_pair(697, 432)] = 16777215;
      (*this)[make_pair(697, 433)] = 16777215;
      (*this)[make_pair(698, 421)] = 16053492;
      (*this)[make_pair(698, 422)] = 7500402;
      (*this)[make_pair(698, 423)] = 11842740;
      (*this)[make_pair(698, 424)] = 12369084;
      (*this)[make_pair(698, 425)] = 12369084;
      (*this)[make_pair(698, 426)] = 12369084;
      (*this)[make_pair(698, 427)] = 12369084;
      (*this)[make_pair(698, 428)] = 12369084;
      (*this)[make_pair(698, 429)] = 12369084;
      (*this)[make_pair(698, 430)] = 16777215;
      (*this)[make_pair(698, 431)] = 16777215;
      (*this)[make_pair(698, 432)] = 16777215;
      (*this)[make_pair(698, 433)] = 16777215;
      (*this)[make_pair(699, 421)] = 16185078;
      (*this)[make_pair(699, 422)] = 12369084;
      (*this)[make_pair(699, 423)] = 12369084;
      (*this)[make_pair(699, 424)] = 12369084;
      (*this)[make_pair(699, 425)] = 12369084;
      (*this)[make_pair(699, 426)] = 12369084;
      (*this)[make_pair(699, 427)] = 12369084;
      (*this)[make_pair(699, 428)] = 12369084;
      (*this)[make_pair(699, 429)] = 12369084;
      (*this)[make_pair(699, 430)] = 16777215;
      (*this)[make_pair(699, 431)] = 16777215;
      (*this)[make_pair(699, 432)] = 16777215;
      (*this)[make_pair(699, 433)] = 16777215;
      (*this)[make_pair(700, 421)] = 16777215;
      (*this)[make_pair(700, 422)] = 16777215;
      (*this)[make_pair(700, 423)] = 16777215;
      (*this)[make_pair(700, 424)] = 16777215;
      (*this)[make_pair(700, 425)] = 16777215;
      (*this)[make_pair(700, 426)] = 16777215;
      (*this)[make_pair(700, 427)] = 16777215;
      (*this)[make_pair(700, 428)] = 16777215;
      (*this)[make_pair(700, 429)] = 16777215;
      (*this)[make_pair(700, 430)] = 16777215;
      (*this)[make_pair(700, 431)] = 16777215;
      (*this)[make_pair(700, 432)] = 16777215;
      (*this)[make_pair(700, 433)] = 16777215;
      (*this)[make_pair(701, 421)] = 16777215;
      (*this)[make_pair(701, 422)] = 16777215;
      (*this)[make_pair(701, 423)] = 16777215;
      (*this)[make_pair(701, 424)] = 16777215;
      (*this)[make_pair(701, 425)] = 16777215;
      (*this)[make_pair(701, 426)] = 16777215;
      (*this)[make_pair(701, 427)] = 16777215;
      (*this)[make_pair(701, 428)] = 16777215;
      (*this)[make_pair(701, 429)] = 16777215;
      (*this)[make_pair(701, 430)] = 16777215;
      (*this)[make_pair(701, 431)] = 16777215;
      (*this)[make_pair(701, 432)] = 16777215;
      (*this)[make_pair(701, 433)] = 16777215;
      (*this)[make_pair(702, 421)] = 16777215;
      (*this)[make_pair(702, 422)] = 16777215;
      (*this)[make_pair(702, 423)] = 16777215;
      (*this)[make_pair(702, 424)] = 16777215;
      (*this)[make_pair(702, 425)] = 16777215;
      (*this)[make_pair(702, 426)] = 16777215;
      (*this)[make_pair(702, 427)] = 16777215;
      (*this)[make_pair(702, 428)] = 16777215;
      (*this)[make_pair(702, 429)] = 16777215;
      (*this)[make_pair(702, 430)] = 16777215;
      (*this)[make_pair(702, 431)] = 16777215;
      (*this)[make_pair(702, 432)] = 16777215;
      (*this)[make_pair(702, 433)] = 16777215;
      (*this)[make_pair(703, 421)] = 16777215;
      (*this)[make_pair(703, 422)] = 16777215;
      (*this)[make_pair(703, 423)] = 12632256;
      (*this)[make_pair(703, 424)] = 13816530;
      (*this)[make_pair(703, 425)] = 16777215;
      (*this)[make_pair(703, 426)] = 16777215;
      (*this)[make_pair(703, 427)] = 16777215;
      (*this)[make_pair(703, 428)] = 16777215;
      (*this)[make_pair(703, 429)] = 16777215;
      (*this)[make_pair(703, 430)] = 16777215;
      (*this)[make_pair(703, 431)] = 16777215;
      (*this)[make_pair(703, 432)] = 16777215;
      (*this)[make_pair(703, 433)] = 16777215;
      (*this)[make_pair(704, 421)] = 16777215;
      (*this)[make_pair(704, 422)] = 13882323;
      (*this)[make_pair(704, 423)] = 9868950;
      (*this)[make_pair(704, 424)] = 16711422;
      (*this)[make_pair(704, 425)] = 16777215;
      (*this)[make_pair(704, 426)] = 16777215;
      (*this)[make_pair(704, 427)] = 16777215;
      (*this)[make_pair(704, 428)] = 16777215;
      (*this)[make_pair(704, 429)] = 16777215;
      (*this)[make_pair(704, 430)] = 16777215;
      (*this)[make_pair(704, 431)] = 16777215;
      (*this)[make_pair(704, 432)] = 16777215;
      (*this)[make_pair(704, 433)] = 16777215;
      (*this)[make_pair(705, 421)] = 16053492;
      (*this)[make_pair(705, 422)] = 7500402;
      (*this)[make_pair(705, 423)] = 11842740;
      (*this)[make_pair(705, 424)] = 12369084;
      (*this)[make_pair(705, 425)] = 12369084;
      (*this)[make_pair(705, 426)] = 12369084;
      (*this)[make_pair(705, 427)] = 12369084;
      (*this)[make_pair(705, 428)] = 12369084;
      (*this)[make_pair(705, 429)] = 12369084;
      (*this)[make_pair(705, 430)] = 16777215;
      (*this)[make_pair(705, 431)] = 16777215;
      (*this)[make_pair(705, 432)] = 16777215;
      (*this)[make_pair(705, 433)] = 16777215;
      (*this)[make_pair(706, 421)] = 16185078;
      (*this)[make_pair(706, 422)] = 12369084;
      (*this)[make_pair(706, 423)] = 12369084;
      (*this)[make_pair(706, 424)] = 12369084;
      (*this)[make_pair(706, 425)] = 12369084;
      (*this)[make_pair(706, 426)] = 12369084;
      (*this)[make_pair(706, 427)] = 12369084;
      (*this)[make_pair(706, 428)] = 12369084;
      (*this)[make_pair(706, 429)] = 12369084;
      (*this)[make_pair(706, 430)] = 16777215;
      (*this)[make_pair(706, 431)] = 16777215;
      (*this)[make_pair(706, 432)] = 16777215;
      (*this)[make_pair(706, 433)] = 16777215;
      (*this)[make_pair(707, 421)] = 16777215;
      (*this)[make_pair(707, 422)] = 16777215;
      (*this)[make_pair(707, 423)] = 16777215;
      (*this)[make_pair(707, 424)] = 16777215;
      (*this)[make_pair(707, 425)] = 16777215;
      (*this)[make_pair(707, 426)] = 16777215;
      (*this)[make_pair(707, 427)] = 16777215;
      (*this)[make_pair(707, 428)] = 16777215;
      (*this)[make_pair(707, 429)] = 16777215;
      (*this)[make_pair(707, 430)] = 16777215;
      (*this)[make_pair(707, 431)] = 16777215;
      (*this)[make_pair(707, 432)] = 16777215;
      (*this)[make_pair(707, 433)] = 16777215;
      (*this)[make_pair(708, 421)] = 16777215;
      (*this)[make_pair(708, 422)] = 16777215;
      (*this)[make_pair(708, 423)] = 16777215;
      (*this)[make_pair(708, 424)] = 16777215;
      (*this)[make_pair(708, 425)] = 16777215;
      (*this)[make_pair(708, 426)] = 16777215;
      (*this)[make_pair(708, 427)] = 16777215;
      (*this)[make_pair(708, 428)] = 16777215;
      (*this)[make_pair(708, 429)] = 16777215;
      (*this)[make_pair(708, 430)] = 16777215;
      (*this)[make_pair(708, 431)] = 16777215;
      (*this)[make_pair(708, 432)] = 16777215;
      (*this)[make_pair(708, 433)] = 16777215;
    }
  } s11;
  map<pair<int, int>, int> table11;
  void update_table11()
  {
    for (const auto& x : s11) {
      auto pos = x.first;
      pos.first += time_button.first - 271 - 39;
      pos.second += time_button.second - 482 + 2;
      table11[pos] = x.second;
    }
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
  //
  //               p11
  //            p5 p3 p8
  //         p9 p1 p0 p2 p10
  //            p6 p4 p7
  //               p12
  //
  vector<pair<int,int> > neighbours = {
    { 0,  0}, // p0
    {-1,  0}, // p1
    {+1,  0}, // p2
    { 0, -1}, // p3
    { 0, +1}, // p4
    {-1, -1}, // p5
    {-1, +1}, // p6
    {+1, +1}, // p7
    {+1, -1}, // p8
    {-2,  0}, // p9
    {+2,  0}, // p10
    { 0, -2}, // p11
    { 0, +2}, // p12
  };
  inline bool
  match2(int x, int y, const pair<int,int>& neighbour, XImage* in_image)
  {
    x += neighbour.first;
    y += neighbour.second;
    auto pix = XGetPixel(in_image, x, y);
    return pix == sky_blue;
  }
  inline bool match(int x, int y, XImage* in_image)
  {
    auto p = find_if(begin(neighbours), end(neighbours),
		     [x, y, in_image](const pair<int, int>& neigbour)
		     { return !match2(x, y, neigbour, in_image); });
    return p == end(neighbours);
  }
  int top = 235;
  int bottom = 415;
  inline int search(int x, XImage* in_image)
  {
    for (int y = top ; y != bottom ; ++y) {
      if (match(x, y, in_image))
	return y;
    }
    return -1;
  }
  pair<double, double> coord;
  string pref;
  inline string out_header(__time_t t)
  {
    cout << "#include <map>\n";
    cout << "#include <vector>\n";
    cout << "#include <tuple>\n";
    cout << "#include <string>\n";
    cout << "using namespace std;\n\n";
    cout << "struct info_t {\n";
    cout << "  map<int, int> tm;\n";
    cout << "  vector<pair<int, int> > gn;\n";
    cout << "  tuple<int, int, int> pl;\n";
    cout << "};\n";
    cout << "extern map<string, map<pair<double, double>, info_t> > ";
    string vn = "g_crow_data";
    cout << vn << ";\n\n";
    ostringstream os;
    auto x = coord.first;
    auto y = coord.second;
    os << '_' << x << '_' << y << '_' << t;
    string tn = "tm" + os.str();
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
    cout << '[' << '"' << pref << '"' << ']';
    cout << "[make_pair(" << x << ',' << y << ")].tm;\n";
    return tn;
  }
  int first_x = 306;
  inline void out_data(int i, int xscale, __time_t t, XImage* in_image)
  {
    int x = first_x;
    int pitch = 16;
    x += pitch * i;
    auto y = search(x, in_image);
    assert(y > 0);
    double a = bottom - y;
    double b = bottom - top;
    int v = a/b * xscale;
    int u = t - 3600 *(23-i);
    cout << "    ";
    cout << "table[" << u << "] = " << v << ";\n";
  }
  inline void out_footer(string name)
  {
    cout << "  " << "}\n";
    cout << "} " << name << ";\n";
  }
  inline void update()
  {
    update_table150();
    update_table200();
    update_table300();
    update_table400();
    update_table600();
    update_table800();
    update_table1c();
    update_table2c();
    update_table3c();
    update_table4c();
    update_table8c();
    update_table6c();
    update_table15c();
    update_table20c();
    update_table10c();
    update_table40();
    update_table30();

    update_table2j();
    update_table1j();
    update_table0();
    update_table23();
    update_table22();
    update_table21();
    update_table20j();
    update_table19();
    update_table18();
    update_table17();
    update_table16();
    update_table15j();
    update_table14();
    update_table13();
    update_table12();
    update_table11();
    update_table10j();
    update_table9();
    update_table8();
    update_table7();
    update_table6();
    update_table5();
    update_table4();
    update_table3();
    top += time_button.second - 482;
    bottom += time_button.second - 482;
    first_x += time_button.first - 271;
  }
  int xscale(XImage* in_image)
  {
    {
      // check if "40,000"
      //           ^^
      assert(!table40.empty());
      auto p = find_if(begin(table40), end(table40),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table40))
	return 40000;
    }
    {
      // check if "30,000"
      //           ^^
      assert(!table30.empty());      
      auto p = find_if(begin(table30), end(table30),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table30))
	return 30000;
    }
    {
      // check if "20,000"
      //           ^^
      assert(!table20c.empty());
      auto p = find_if(begin(table20c), end(table20c),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table20c))
	return 20000;
    }
    {
      // check if "15,000"
      //           ^^
      assert(!table15c.empty());
      auto p = find_if(begin(table15c), end(table15c),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table15c))
	return 15000;
    }
    {
      // check if "10,000"
      //           ^^
      assert(!table10c.empty());
      auto p = find_if(begin(table10c), end(table10c),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table10c))
	return 10000;
    }
    {
      // check if "6,000"
      //           ^^
      assert(!table6c.empty());
      auto p = find_if(begin(table6c), end(table6c),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table6c))
	return 6000;
    }
    {
      // check if "8,000"
      //           ^^
      assert(!table8c.empty());
      auto p = find_if(begin(table8c), end(table8c),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table8c))
	return 8000;
    }
    {
      // check if "3,000"
      //           ^^
      assert(!table3c.empty());
      auto p = find_if(begin(table3c), end(table3c),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table3c))
	return 3000;
    }
    {
      // check if "4,000"
      //           ^^
      assert(!table4c.empty());
      auto p = find_if(begin(table4c), end(table4c),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table4c))
	return 4000;
    }
    {
      // check if "2,000"
      //           ^^
      assert(!table2c.empty());
      auto p = find_if(begin(table2c), end(table2c),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table2c))
	return 2000;
    }
    {
      // check if "1,000"
      //           ^^
      assert(!table1c.empty());
      auto p = find_if(begin(table1c), end(table1c),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table1c))
	return 1000;
    }
    {
      // check if "600"
      //           ^^
      assert(!table600.empty());
      auto p = find_if(begin(table600), end(table600),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table600))
	return 600;
    }
    {
      // check if "400"
      //           ^^
      assert(!table400.empty());
      auto p = find_if(begin(table400), end(table400),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table400))
	return 400;
    }
    {
      // check if "800"
      //           ^^
      assert(!table800.empty());
      auto p = find_if(begin(table800), end(table800),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table800))
	return 800;
    }
    {
      // check if "300"
      //           ^^
      assert(!table300.empty());
      auto p = find_if(begin(table300), end(table300),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table300))
	return 300;
    }
    {
      // check if "200"
      //           ^^
      assert(!table200.empty());
      auto p = find_if(begin(table200), end(table200),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table200))
	return 200;
    }
    {
      // check if "150"
      //           ^^
      assert(!table150.empty());
      auto p = find_if(begin(table150), end(table150),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table150))
	return 150;
    }
    asm("int3");
    return 0;
  }
  int hour(XImage* in_image)
  {
    {
      // Check if 2:00
      //          ^^
      assert(!table2j.empty());
      auto p = find_if(begin(table2j), end(table2j),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table2j))
	return 2;
    }
    {
      // Check if 1:00
      //          ^^
      assert(!table1j.empty());
      auto p = find_if(begin(table1j), end(table1j),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table1j))
	return 1;
    }
    {
      // Check if 0:00
      //          ^^
      assert(!table0.empty());
      auto p = find_if(begin(table0), end(table0),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table0))
	return 0;
    }
    {
      // Check if 23:00
      //          ^^
      assert(!table23.empty());
      auto p = find_if(begin(table23), end(table23),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table23))
	return 23;
    }
    {
      // Check if 22:00
      //          ^^
      assert(!table22.empty());
      auto p = find_if(begin(table22), end(table22),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table22))
	return 22;
    }
    {
      // Check if 21:00
      //          ^^
      assert(!table21.empty());
      auto p = find_if(begin(table21), end(table21),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table21))
	return 21;
    }
    {
      // Check if 20:00
      //          ^^
      assert(!table20j.empty());
      auto p = find_if(begin(table20j), end(table20j),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table20j))
	return 20;
    }
    {
      // Check if 19:00
      //          ^^
      assert(!table19.empty());
      auto p = find_if(begin(table19), end(table19),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table19))
	return 19;
    }
    {
      // Check if 18:00
      //          ^^
      assert(!table18.empty());
      auto p = find_if(begin(table18), end(table18),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table18))
	return 18;
    }
    {
      // Check if 17:00
      //          ^^
      assert(!table17.empty());
      auto p = find_if(begin(table17), end(table17),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table17))
	return 17;
    }
    {
      // Check if 16:00
      //          ^^
      assert(!table16.empty());
      auto p = find_if(begin(table16), end(table16),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table16))
	return 16;
    }
    {
      // Check if 15:00
      //          ^^
      assert(!table15j.empty());
      auto p = find_if(begin(table15j), end(table15j),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table15j))
	return 15;
    }
    {
      // Check if "13:00"
      //           ^^
      assert(!table13.empty());
      auto p = find_if(begin(table13), end(table13),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table13))
	return 13;
    }
    {
      // Check if "12:00"
      //           ^^
      assert(!table12.empty());
      auto p = find_if(begin(table12), end(table12),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table12))
	return 12;
    }
    {
      // Check if 11:00
      //          ^^
      assert(!table11.empty());
      auto p = find_if(begin(table11), end(table11),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table11))
	return 11;
    }
    {
      // Check if 14:00
      //          ^^
      assert(!table14.empty());
      auto p = find_if(begin(table14), end(table14),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table14))
	return 14;
    }
    {
      // Check if 3:00
      //          ^^
      assert(!table3.empty());
      auto p = find_if(begin(table3), end(table3),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table3))
	return 3;
    }
    {
      // Check if 4:00
      //          ^^
      assert(!table4.empty());
      auto p = find_if(begin(table4), end(table4),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table4))
	return 4;
    }
    {
      // Check if 5:00
      //          ^^
      assert(!table5.empty());
      auto p = find_if(begin(table5), end(table5),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table5))
	return 5;
    }
    {
      // Check if 6:00
      //          ^^
      assert(!table6.empty());
      auto p = find_if(begin(table6), end(table6),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table6))
	return 6;
    }
    {
      // Check if 7:00
      //          ^^
      assert(!table7.empty());
      auto p = find_if(begin(table7), end(table7),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table7))
	return 7;
    }
    {
      // Check if 8:00
      //          ^^
      assert(!table8.empty());
      auto p = find_if(begin(table8), end(table8),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table8))
	return 8;
    }
    {
      // Check if 9:00
      //          ^^
      assert(!table9.empty());
      auto p = find_if(begin(table9), end(table9),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table9))
	return 9;
    }
    {
      // Check if 10:00
      //          ^^
      assert(!table10j.empty());
      auto p = find_if(begin(table10j), end(table10j),
		       bind2nd(ptr_fun(check), in_image));
      if (p == end(table10j))
	return 10;
    }
    asm("int3");
    return -1;
  }
  int calc_t(int h)
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
	if (strcmp(argv[i], "-p") == 0) {
	    if (++i >= argc) usage();
	    mine::pref = argv[i];
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
	  find_time_button(in_image);
	  update();
	  auto xs = xscale(in_image);
	  auto h = hour(in_image);
	  auto t = calc_t(h);
	  auto nm = out_header(t);
	  for (int i = 0 ; i != 24 ; ++i)
	    out_data(i, xs, t, in_image);
	  out_footer(nm);
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
		  // 2:00 at Nihonbashi.time
		  // ^^
		  int X = 657 + 39;
		  int Y = 423 - 2;
		  int delta = 13;
		  if (X <= x && x < X+delta && Y <= y && y < Y+delta) {
		    mine::s2j[std::make_pair(x,y)] = xpix;
		    xpix = 0;
		  }
		}
#endif
#if 0
		{
		  // 150 at Namekata.time
		  // ^^
		  int X = 295 + 13;
		  int Y = 235 - 2;
		  int delta = 13;
		  if (X <= x && x < X+delta && Y <= y && y < Y+delta) {
		    mine::s150[std::make_pair(x,y)] = xpix;
		    xpix = 0;
		  }
		}
#endif
#if 0
		{
		  // 1st bule dot at Nihonbashi.time
		  int X = 304;
		  int Y = 276;
		  int delta = 5;
		  if (X <= x && x < X+delta && Y <= y && y < Y+delta) {
		    xpix = 0;
		  }
		}
#endif		
#if 0
		{
		  // top
		  int X = 500;
		  int Y = 235;
		  int delta = 5;
		  if (X <= x && x < X+delta && Y <= y && y < Y+delta) {
		    xpix = 0;
		  }
		}
#endif
#if 0
		{
		  // bottom
		  int X = 500;
		  int Y = 415;
		  int delta = 5;
		  if (X <= x && x < X+delta && Y <= y && y < Y+delta) {
		    xpix = 0;
		  }
		}
#endif
#if 0
		{
		  // time seriese bottom
		  int X = 310;
		  int Y = 480;  // 477 : NG, 478, NG, 480 : OK
		  int delta = 130;
		  if (X <= x && x < X+delta && y == Y) {
		    assert(xpix == mine::sky_blue);
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

