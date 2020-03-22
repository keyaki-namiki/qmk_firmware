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

//enum layer_number {
//    _QWERTY = 0,
//    _LOWER,
//    _RAISE,
//    _ADJUST
//};

#define _QWERTY 0
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 5

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { 
    QWERTY = SAFE_RANGE,
    LOWER,
    LOWER_SPC,
    RAISE,
    RAISE_ENT,
    ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(\
    KC_ESC,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,          KC_Y,   KC_U,   KC_I,   KC_O,   KC_P, KC_BSPC,\
     MT(MOD_LCTL,KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_ENT,\
          KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH, ADJUST,\
                                LOWER,KC_LGUI, LOWER_SPC,RAISE_ENT,KC_RALT,RAISE \( \

                                        k40, KC_HOME, KC_END, KC_INS, KC_DEL, KC_MUTE,\
  k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B,    k0C,\
   k10,  k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A,  k1B, k1C,\
    k20,  k21, k22, k23, k24, k25, k26, k27, k28, k29,  k2A,  k2B,\
              k30, k31,       k32, k33,       k34, k35, \
                            k50, k51, k52\
) \
),
  [_LOWER] = LAYOUT( \
    KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_DEL,\
       _______, XXXXXXX, KC_INS, KC_DEL, KC_BTN3,  KC_F11, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, XXXXXXX, XXXXXXX,\
            _______, XXXXXXX, KC_BSPC, XXXXXXX, KC_ENT, KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,\
                                 LOWER,_______, XXXXXXX, KC_TAB, _______,RAISE\
   ),
  [_RAISE] = LAYOUT( \
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX, KC_GRV,\
      _______,  KC_4,    KC_5,    KC_6,    KC_DOT, XXXXXXX, KC_LBRC, KC_MINS, KC_EQL, KC_BSLS, KC_LPRN,   KC_QUOT,\
          _______, KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_RBRC, KC_SLSH,S(KC_COMM),S(KC_DOT),KC_RPRN,_______,\
                                     LOWER,_______, KC_TAB, XXXXXXX, _______,RAISE\
  ),
  [_ADJUST] = LAYOUT( \
     RESET, DF(_QWERTY),XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_PSCR, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,\
        KC_CAPS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,BL_STEP, BL_INC, XXXXXXX, KC_LEFT, KC_RGHT, XXXXXXX,\
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_TOGG, BL_BRTG, BL_DEC, XXXXXXX, KC_DOWN, XXXXXXX, _______,\
                                    LOWER,_______, XXXXXXX, XXXXXXX, _______,RAISE\
  ), \
};

void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
	if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
		layer_on(layer3);
	} else {
		layer_off(layer3);
	}
}

static bool lower_pressed = false;
static bool raise_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case LOWER_SPC:
            if (record->event.pressed) {
                lower_pressed = 1;

                layer_on(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);

                if(lower_pressed){
                    register_code(KC_SPC);
                    unregister_code(KC_SPC);
                }
                lower_pressed = 0;
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE_ENT:
            if (record->event.pressed) {
                raise_pressed = 1;

                layer_on(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
                
                if(raise_pressed){
                    register_code(KC_ENT);
                    unregister_code(KC_ENT);
                }
                raise_pressed = 0;
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        default:
            if (record->event.pressed) {
                lower_pressed = 0;
                raise_pressed = 0;
            }
            break;
            
    }

    return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {

}

uint32_t layer_state_set_user(uint32_t state) {
		
	return state;
}