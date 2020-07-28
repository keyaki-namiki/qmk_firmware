/* Copyright 2019 Ryota Goto
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

enum layer_number {
	_BASE = 0,
	_NAVCLUSTER,
	_CUSTOM,
	_SYSTEM
};

enum custom_keycodes {
	CUSTOM0,
	NAV_ENT,
	SYSTEM,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_6x4( /* Base */
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, \
	KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
	KC_P7,   KC_P8,   KC_P9,   KC_NO, \
	KC_P4,   KC_P5,   KC_P6,   KC_PPLS, \
	KC_P1,   KC_P2,   KC_P3,   KC_NO, \
	CUSTOM0, KC_NO,   KC_PDOT, NAV_ENT  \
  ),
  [_NAVCLUSTER] = LAYOUT_ortho_6x4( /* Base */
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, \
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
	KC_HOME, KC_UP,   KC_PGUP, _______, \
	KC_LEFT, XXXXXXX, KC_RGHT, XXXXXXX, \
	KC_END,  KC_DOWN, KC_PGDN, _______, \
	KC_INS,  _______, KC_DEL,  _______  \
  ),
  [_CUSTOM] = LAYOUT_ortho_6x4( /* Base */
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, \
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
	S(KC_TAB),KC_UP,  KC_TAB,  _______, \
	KC_LEFT, KC_DOWN, KC_RGHT, SYSTEM, \
	KC_BSPC, XXXXXXX, KC_DEL,  _______, \
	_______, _______, XXXXXXX, S(KC_PENT)  \
  ),
  [_SYSTEM] = LAYOUT_ortho_6x4( /* Base */
    RESET,   EEP_RST, XXXXXXX, XXXXXXX, \
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
	XXXXXXX, XXXXXXX, XXXXXXX, _______, \
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
	_______, _______, XXXXXXX, XXXXXXX  \
  ),
};

static bool custom0_pressed = false;
static bool navent_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CUSTOM0:
            if (record->event.pressed) {
                custom0_pressed = 1;

                layer_on(_CUSTOM);
                update_tri_layer(_CUSTOM, _NAVCLUSTER, _SYSTEM);
            } else {
                layer_off(_CUSTOM);
                update_tri_layer(_CUSTOM, _NAVCLUSTER, _SYSTEM);
                
                if(custom0_pressed){
                    register_code(KC_P0);
                    unregister_code(KC_P0);
                }
                custom0_pressed = 0;
            }
            return false;
        case NAV_ENT:
            if (record->event.pressed) {
                navent_pressed = 1;

                layer_on(_NAVCLUSTER);
                update_tri_layer(_NAVCLUSTER, _CUSTOM, _SYSTEM);
            } else {
                layer_off(_NAVCLUSTER);
                update_tri_layer(_NAVCLUSTER, _CUSTOM, _SYSTEM);
                
                if(navent_pressed){
                    register_code(KC_PENT);
                    unregister_code(KC_PENT);
                }
                navent_pressed = 0;
            }
            return false;
        case SYSTEM:
            if (record->event.pressed) {
                layer_on(_SYSTEM);
            } else {
                layer_off(_SYSTEM);
            }
            return false;
        default:
            if (record->event.pressed) {
                custom0_pressed = 0;
                navent_pressed = 0;
            }
            break;
            
    }

    return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
