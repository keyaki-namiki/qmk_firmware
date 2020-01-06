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
#include "audio.h"
#include "bootloader.h"

enum layer_number {
    _QWERTY = 0,
    _GAME,
    _LOWER,
    _RAISE,
    _G_RAISE,
    _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { 
    QWERTY = SAFE_RANGE,
    LOWER,
    KC_LSPC,
    RAISE,
    G_RAISE,
    KC_RENT,
    ADJUST
};
#define KC_TCTL MT(MOD_LCTL,KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(\
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,\
    KC_TCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,\
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ADJUST,\
         KC_NO,   KC_NO,   LOWER,   KC_LGUI, KC_LSPC,       KC_RENT, KC_RALT, RAISE,   KC_NO,   KC_NO \
),
    [_GAME] = LAYOUT(\
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,\
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_ENT,\
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_LGUI, ADJUST,\
         KC_NO,    KC_NO,   LOWER,   KC_ENT,  KC_SPC,       G_RAISE, KC_RALT, RAISE,    KC_NO,   KC_NO \
),
  [_LOWER] = LAYOUT( \
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_DEL,\
    _______, KC_BTN1, KC_INS,  KC_DEL,  KC_BTN3,  KC_F11, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, XXXXXXX, XXXXXXX,\
    _______, KC_BTN2, KC_BSPC, KC_APP,  KC_ENT, KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,\
         KC_NO,   KC_NO,   LOWER,   _______, XXXXXXX,          KC_TAB, _______,RAISE,   KC_NO,   KC_NO\
   ),
  [_RAISE] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,      KC_9,      KC_0,    KC_GRV,\
    _______, KC_4,    KC_5,    KC_6,    KC_DOT,  XXXXXXX, KC_LBRC, KC_MINS, KC_EQL,    KC_BSLS,   KC_LPRN, KC_QUOT,\
    _______, KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_RBRC, KC_SLSH,S(KC_COMM), S(KC_DOT), KC_RPRN, _______,\
         KC_NO,   KC_NO,   LOWER,   _______, KC_TAB,          XXXXXXX, _______, RAISE,   KC_NO,  KC_NO\
  ),
  [_G_RAISE] = LAYOUT( \
    KC_ESC,   KC_1,    KC_2,   KC_3,    KC_4,    KC_5,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,\
    _______, XXXXXXX,  KC_6,   KC_7,    KC_8,    KC_9,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_0,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RPRN, _______,\
         KC_NO,   KC_NO,   LOWER,   _______, KC_TAB,          XXXXXXX, _______, RAISE,   KC_NO,   KC_NO\
  ),
  [_ADJUST] = LAYOUT( \
    RESET,DF(_QWERTY),XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EEP_RST, XXXXXXX, KC_PSCR, KC_UP,   XXXXXXX, XXXXXXX,\
    KC_CAPS, AU_ON,   AU_OFF,  MU_TOG,  MU_MOD, DF(_GAME),BL_STEP, BL_INC,  XXXXXXX, KC_LEFT, KC_RGHT, XXXXXXX,\
    _______, XXXXXXX, CK_RST,  CK_UP,   CK_DOWN,BL_TOGG,  BL_BRTG, BL_DEC,  XXXXXXX, KC_DOWN, XXXXXXX, _______,\
         KC_NO,   KC_NO,   LOWER,   _______, XXXXXXX,          XXXXXXX, _______, RAISE,   KC_NO,   KC_NO\
  ), \
};

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

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
        case KC_LSPC:
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
        case KC_RENT:
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
        case G_RAISE:
            if (record->event.pressed) {
                layer_on(_G_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_G_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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

void matrix_init_user(void) {
        startup_user();
}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {

}

void startup_user()
{
    _delay_ms(50); // gets rid of tick
}

void shutdown_user()
{
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}