/* Copyright 2019 keyaki-namiki
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
#pragma once

#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
  #include <avr/io.h>
  #include <avr/interrupt.h>
#endif
#endif

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define K_N KC_NO
#if MATRIX_SIZE == 1
#define LAYOUT(\
	k00, k01, k02,      k03,      k04, \
	k10, k11, k12, k13, k14, k15, k16, \
	k20, k21, k22, k23, k24, k25, k26, \
				k33, k34, k35, k36, \
	k40, k41, k42, k43, k44, k45, k46, \
	k50, k51, k52, k53, k54, k55, k56  \
	) \
	{\
	{ k00, k01, k02, k13, k14, k15, k16 }, \
	{ k10, k11, k12, k23, k24, k25, k26 }, \
	{ k20, k21, k22, k33, k34, k35, k36 }, \
	{ k40, k41, k42, k43, k44, k45, k46 }, \
	{ k50, k51, k52, k53, k54, k55, k56 }, \
	{ K_N, K_N, K_N, K_N, K_N, k03, k04 }, \
	}

#endif
#if MATRIX_SIZE == 2
#define LAYOUT(\
	L00, L01, L02,      L03,      L04, 		R00, R01, R02,      R03,      R04, \
	L10, L11, L12, L13, L14, L15, L16, 		R10, R11, R12, R13, R14, R15, R16, \
	L20, L21, L22, L23, L24, L25, L26, 		R20, R21, R22, R23, R24, R25, R26, \
				L33, L34, L35, L36, 					R33, R34, R35, R36, \
	L40, L41, L42, L43, L44, L45, L46, 		R40, R41, R42, R43, R44, R45, R46, \
	L50, L51, L52, L53, L54, L55, L56, 		R50, R51, R52, R53, R54, R55, R56  \
	) \
	{\
	{ L00, L01, L02, L13, L14, L15, L16 }, \
	{ L10, L11, L12, L23, L24, L25, L26 }, \
	{ L20, L21, L22, L33, L34, L35, L36 }, \
	{ L40, L41, L42, L43, L44, L45, L46 }, \
	{ L50, L51, L52, L53, L54, L55, L56 }, \
	{ K_N, K_N, K_N, K_N, K_N, L03, L04 }, \
	{ R00, R01, R02, R13, R14, R15, R16 }, \
	{ R10, R11, R12, R23, R24, R25, R26 }, \
	{ R20, R21, R22, R33, R34, R35, R36 }, \
	{ R40, R41, R42, R43, R44, R45, R46 }, \
	{ R50, R51, R52, R53, R54, R55, R56 }, \
	{ K_N, K_N, K_N, K_N, K_N, R03, R04 } \
	}

#endif
#if MATRIX_SIZE == 3
#define LAYOUT(\
	L00, L01, L02,      L03,      L04, 		R00, R01, R02, R03, R04, R05, R06, R07, R08, R09, R0A, R0B, R0C,\
	L10, L11, L12, L13, L14, L15, L16, 		R10,  R11, R12, R13, R14, R15, R16, R17, R18, R19, R1A,  R1B,\
	L20, L21, L22, L23, L24, L25, L26, 		  R20,  R21, R22, R23, R24, R25, R26, R27, R28, R29,  R2A,  R2B,\
					L33, L34, L35, L36, 					R30, R31,       R32, R33,       R34, R35, \
	L40, L41, L42, L43, L44, L45, L46, \
	L50, L51, L52, L53, L54, L55, L56 \
	) \
	{\
	{ L00, L01, L02, L13, L14, L15, L16, K_N, K_N, K_N, K_N }, \
	{ L10, L11, L12, L23, L24, L25, L26, K_N, K_N, K_N, K_N }, \
	{ L20, L21, L22, L33, L34, L35, L36, K_N, K_N, K_N, K_N }, \
	{ L40, L41, L42, L43, L44, L45, L46, K_N, K_N, K_N, K_N }, \
	{ L50, L51, L52, L53, L54, L55, L56, K_N, K_N, K_N, K_N }, \
	{ K_N, K_N, K_N, K_N, K_N, L03, L04, K_N, K_N, K_N, K_N }, \
	{ R00, R01, R02, R03, R04, R05, R06, R07, R08, R09, R0A }, \
	{ R10, R11, R12, R13, R14, R15, R16, R17, R18, R19, R1A }, \
	{ R20, R21, R22, R23, R24, R25, R26, R27, R28, R29, R2A }, \
	{ R30, R31, R32, R33, R34, R35, R2B, R1B, R0C, R0B, K_N }, \
	}


#endif
