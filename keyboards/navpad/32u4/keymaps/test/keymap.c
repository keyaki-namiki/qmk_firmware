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
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { \
    test = SAFE_RANGE,
	k00, k01, k02,      k03,      k04,\
	k10, k11, k12, k13, k14, k15, k16,\
	k20, k21, k22, k23, k24, k25, k26,\
	               k33, k34, k35, k36,\
	k40, k41, k42, k43, k44, k45, k46,\
	k50, k51, k52, k53, k54, k55, k56\ };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] =LAYOUT (\
	LED_TEST1, LED_TEST2, LED_TEST3,      k03,      k04,\
	k10, k11, k12, k13, k14, k15, k16,\
	k20, k21, k22, k23, k24, k25, k26,\
	               k33, k34, k35, k36,\
	k40, k41, k42, k43, k44, k45, k46,\
	k50, k51, k52, k53, k54, k55, k56\ 
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case k00:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("k00 pass" SS_TAP(X_ENTER));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case k01:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("k01 pass" SS_TAP(X_ENTER));
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
