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

extern keymap_config_t keymap_config;

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { 
    QWERTY = SAFE_RANGE,
	Key00, Key01, Key02,      Key03,      Key04,
	Key10, Key11, Key12, Key13, Key14, Key15, Key16,
	Key20, Key21, Key22, Key23, Key24, Key25, Key26,
	               Key33, Key34, Key35, Key36,
	Key40, Key41, Key42, Key43, Key44, Key45, Key46,
	Key50, Key51, Key52, Key53, Key54, Key55, Key56
    };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] =LAYOUT (\
	BL_TOGG, KC_CAPS, KC_NLCK,      Key03,      Key04,\
	Key10, Key11, Key12, Key13, Key14, Key15, Key16,\
	Key20, Key21, Key22, Key23, Key24, Key25, Key26,\
	               Key33, Key34, Key35, Key36,\
	Key40, Key41, Key42, Key43, Key44, Key45, Key46,\
	Key50, Key51, Key52, Key53, Key54, Key55, Key56\
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case Key00:
            if (record->event.pressed) {
                SEND_STRING("Key00 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key01:
            if (record->event.pressed) {
                SEND_STRING("Key01 pass" SS_TAP(X_ENTER));
                tap_code(KC_CAPS);
            } else {
            }
            break;
        case Key02:
            if (record->event.pressed) {
                SEND_STRING("Key02 pass" SS_TAP(X_ENTER));
                tap_code(KC_NLCK);
            } else {
            }
            break;
        case Key03:
            if (record->event.pressed) {
                SEND_STRING("Key03 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key04:
            if (record->event.pressed) {
                SEND_STRING("Key04 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key10:
            if (record->event.pressed) {
                SEND_STRING("Key10 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key11:
            if (record->event.pressed) {
                SEND_STRING("Key11 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key12:
            if (record->event.pressed) {
                SEND_STRING("Key12 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key13:
            if (record->event.pressed) {
                SEND_STRING("Key13 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key14:
            if (record->event.pressed) {
                SEND_STRING("Key14 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key15:
            if (record->event.pressed) {
                SEND_STRING("Key15 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key16:
            if (record->event.pressed) {
                SEND_STRING("Key16 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key20:
            if (record->event.pressed) {
                SEND_STRING("Key20 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key21:
            if (record->event.pressed) {
                SEND_STRING("Key21 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key22:
            if (record->event.pressed) {
                SEND_STRING("Key22 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key23:
            if (record->event.pressed) {
                SEND_STRING("Key23 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key24:
            if (record->event.pressed) {
                SEND_STRING("Key24 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key25:
            if (record->event.pressed) {
                SEND_STRING("Key25 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key26:
            if (record->event.pressed) {
                SEND_STRING("Key26 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key33:
            if (record->event.pressed) {
                SEND_STRING("Key33 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key34:
            if (record->event.pressed) {
                SEND_STRING("Key34 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key35:
            if (record->event.pressed) {
                SEND_STRING("Key35 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key36:
            if (record->event.pressed) {
                SEND_STRING("Key36 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key40:
            if (record->event.pressed) {
                SEND_STRING("Key40 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key41:
            if (record->event.pressed) {
                SEND_STRING("Key41 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key42:
            if (record->event.pressed) {
                SEND_STRING("Key42 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key43:
            if (record->event.pressed) {
                SEND_STRING("Key43 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key44:
            if (record->event.pressed) {
                SEND_STRING("Key44 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key45:
            if (record->event.pressed) {
                SEND_STRING("Key45 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key46:
            if (record->event.pressed) {
                SEND_STRING("Key46 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key50:
            if (record->event.pressed) {
                SEND_STRING("Key50 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key51:
            if (record->event.pressed) {
                SEND_STRING("Key51 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key52:
            if (record->event.pressed) {
                SEND_STRING("Key52 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key53:
            if (record->event.pressed) {
                SEND_STRING("Key53 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key54:
            if (record->event.pressed) {
                SEND_STRING("Key54 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key55:
            if (record->event.pressed) {
                SEND_STRING("Key55 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
        case Key56:
            if (record->event.pressed) {
                SEND_STRING("Key56 pass" SS_TAP(X_ENTER));
            } else {
            }
            break;
    }
    return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
