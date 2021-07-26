/* Copyright 2021 keyaki-namiki
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "macro_fighter6.h"


#ifdef RGB_MATRIX_ENABLE

#define RGBmX(led_x) ( 224 / ( 6 - 1 ) * led_x )
#define RGBmY(led_y) ( 64 / ( 6 - 1 ) * led_y )

led_config_t g_led_config = {
  {\
    { 30, 31, 2,  33, 34, 35 },\
    { 29, 2,  27, 26, 25, 24 },\
    { 0,  7,  8,  15, 16, 23 },\
    { 1,  6,  9,  14, 17, 22 },\
    { 2,  5,  10, 13, 18, 21 },\
    { 3,  4,  11, 12, 19, 20 },\
  }, {
    { RGBmX(0), RGBmY(5) }, { RGBmX(1), RGBmY(5) }, { RGBmX(2), RGBmY(5) }, { RGBmX(3), RGBmY(5) }, { RGBmX(4), RGBmY(5) }, { RGBmX(5), RGBmY(5) },
    { RGBmX(0), RGBmY(4) }, { RGBmX(1), RGBmY(4) }, { RGBmX(2), RGBmY(4) }, { RGBmX(3), RGBmY(4) }, { RGBmX(4), RGBmY(4) }, { RGBmX(5), RGBmY(4) },
    { RGBmX(0), RGBmY(3) }, { RGBmX(1), RGBmY(3) }, { RGBmX(2), RGBmY(3) }, { RGBmX(3), RGBmY(3) }, { RGBmX(4), RGBmY(3) }, { RGBmX(5), RGBmY(3) },
    { RGBmX(0), RGBmY(2) }, { RGBmX(1), RGBmY(2) }, { RGBmX(2), RGBmY(2) }, { RGBmX(3), RGBmY(2) }, { RGBmX(4), RGBmY(2) }, { RGBmX(5), RGBmY(2) },
    { RGBmX(0), RGBmY(1) }, { RGBmX(1), RGBmY(1) }, { RGBmX(2), RGBmY(1) }, { RGBmX(3), RGBmY(1) }, { RGBmX(4), RGBmY(1) }, { RGBmX(5), RGBmY(1) },
    { RGBmX(0), RGBmY(0) }, { RGBmX(1), RGBmY(0) }, { RGBmX(2), RGBmY(0) }, { RGBmX(3), RGBmY(0) }, { RGBmX(4), RGBmY(0) }, { RGBmX(5), RGBmY(0) }
  }, {
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4
  }
};
#endif