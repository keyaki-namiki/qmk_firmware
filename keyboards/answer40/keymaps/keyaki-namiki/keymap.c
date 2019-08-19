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

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum layer_number {
    _QWERTY = 0,
    _GAME,
    _LOWER,
    _RAISE,
    _GAME_RAISE,
    _ADJUST
};

#define QWERTY DF(_QWERTY)
#define GAME DF(_GAME)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define GAME_R MO(_GAME_RAISE)

enum custom_keycodes {
	RGBRST = SAFE_RANGE,
  LEVER_1,
  LEVER_2,
  LEVER_T,
  LEVER_3,
  LEVER_4,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
    KC_ESC,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,          KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_DEL, KC_BSPC,\
      MT(MOD_LCTL,KC_TAB),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_ENT,\
          KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH, LT(_RAISE,KC_SLSH),\
               KC_LGUI,  LOWER,MT(MOD_LSFT,KC_SPC),LT(_LOWER,KC_SPC),LT(_RAISE,KC_ENT),RAISE, KC_RALT,\
               LEVER_1, LEVER_2, LEVER_T, LEVER_3, LEVER_4 \
  ),
  [_GAME] = LAYOUT( \
    KC_ESC,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,          KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_DEL, KC_BSPC,\
      KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_ENT,\
          KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH, RAISE,\
               KC_LGUI,  LOWER,         KC_SPC,           KC_SPC,LT(_GAME_RAISE,KC_ENT),RAISE, KC_RALT,\
               _______, _______, _______, _______, _______ \
  ),
  [_LOWER] = LAYOUT( \
    KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_DEL,\
      _______,  XXXXXXX, KC_INS,  KC_DEL,  KC_BTN3,  KC_F11, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, XXXXXXX, XXXXXXX,\
          _______, XXXXXXX, KC_BSPC, XXXXXXX, KC_ENT, KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, _______,\
              _______,  LOWER,          XXXXXXX,           XXXXXXX,     XXXXXXX,        ADJUST,_______,\
               _______, _______, _______, _______, _______ \
  ),
  [_RAISE] = LAYOUT( \
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX, KC_GRV,\
      _______,  KC_4,    KC_5,    KC_6,    KC_DOT, XXXXXXX, KC_LBRC, KC_MINS, KC_EQL, KC_BSLS, KC_LPRN,   KC_QUOT,\
          _______, KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC, KC_SLSH, XXXXXXX,S(KC_COMM),S(KC_DOT),KC_RPRN,_______,\
              _______,  ADJUST,     MT(MOD_LSFT,KC_TAB),   KC_TAB,      XXXXXXX,        RAISE, _______,\
               _______, _______, _______, _______, _______ \
  ),
  [_GAME_RAISE] = LAYOUT( \
    KC_ESC,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5, XXXXXXX, KC_GRV,\
      _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_QUOT,\
          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RBRC, KC_SLSH, XXXXXXX,S(KC_COMM),S(KC_DOT),KC_RPRN,_______,\
              _______,  ADJUST,          KC_TAB,           KC_TAB,      XXXXXXX,        RAISE, _______,\
               _______, _______, _______, _______, _______ \
  ),
  [_ADJUST] = LAYOUT( \
     RESET, DF(_QWERTY),XXXXXXX, XXXXXXX, RGBRST, RGB_TOG,    XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
      KC_CAPS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,DF(_GAME),RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,XXXXXXX, XXXXXXX,\
          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUD, XXXXXXX, RGB_SAD, RGB_VAD, XXXXXXX, _______,\
              _______,  LOWER,          XXXXXXX,           XXXXXXX,     XXXXXXX,        RAISE, _______,\
               _______, _______, _______, _______, _______ \
  ),
};

bool TOG_STATUS = false;
int RGB_current_mode;

void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
	if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
		layer_on(layer3);
	} else {
		layer_off(layer3);
	}
}

int lever_sw_state = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
		case RGBRST:
			#ifdef RGBLIGHT_ENABLE
				if (record->event.pressed) {
					eeconfig_update_rgblight_default();
					rgblight_enable();
					RGB_current_mode = rgblight_config.mode;
				}
			#endif
			break;
    case LEVER_1:
      if (record->event.pressed) {
        // do something
        if(lever_sw_state != 2){
          register_code(KC_WH_U);
        }
      } else {
        // undo something
          unregister_code(KC_WH_U);
      }
      return false;
      break;
    case LEVER_2:
      if (record->event.pressed) {
        // do something
        lever_sw_state = 2;
//        tap_code(KC_2);
      } else {
        // undo something
        lever_sw_state = 0;
      }
      return false;
      break;
    case LEVER_T:
      if (record->event.pressed) {
        // do something
        lever_sw_state = 5;
//        tap_code(KC_5);
      } else {
        lever_sw_state = 0;
        // undo something
      }
      return false;
      break;
    case LEVER_3:
      if (record->event.pressed) {
        // do something
        lever_sw_state = 3;
//        tap_code(KC_3);
      } else {
        // undo something
        lever_sw_state = 0;
      }
      return false;
      break;
    case LEVER_4:
      if (record->event.pressed) {
        // do something
        if(lever_sw_state != 3){
          register_code(KC_WH_D);
        }
      } else {
        // undo something
          unregister_code(KC_WH_D);
      }
      return false;
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
