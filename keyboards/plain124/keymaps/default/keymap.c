/* Copyright 2020 keyaki-namiki
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NUMPAD,
    _LOWER,
    _RAISE,
    _SYSTEM
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    KC_LSPC,
    KC_rSPC,
    SYSTEM,
};

#define KC_TCTL MT(MOD_LCTL, KC_TAB)
#define KC_ATAB LT(_SYSTEM, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,
        KC_TCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_ENT,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,SYSTEM,
        KC_NO,  KC_NO,  KC_LGUI,LOWER,  KC_LSPC,    KC_SPC,     KC_rSPC,RAISE,  KC_LALT,KC_NO,  KC_NO
    ),
    /* Numpad */
    [_NUMPAD] = LAYOUT(
        KC_ESC, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        KC_TCTL,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
        KC_NO,  KC_NO,  _______,LOWER,  KC_LSPC,    KC_SPC,     KC_rSPC,RAISE,  _______,KC_NO,  KC_NO
    ),
    /* Lower */
    [_LOWER] = LAYOUT(
        KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_DEL,
        KC_TCTL,KC_BTN1,KC_INS, KC_DEL, KC_BTN3,KC_F11, KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,XXXXXXX,XXXXXXX,
        _______,XXXXXXX,KC_BSPC,KC_APP, KC_ENT, KC_F12, KC_HOME,KC_PGDN,KC_PGUP,KC_END, XXXXXXX,_______,
        KC_NO,  KC_NO,  _______,_______,_______,    KC_SPC,     KC_rSPC,RAISE,  _______,KC_NO,  KC_NO
    ),
    /* Raise */
    [_RAISE] = LAYOUT(
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_GRV,
        KC_TCTL,KC_4,   KC_5,   KC_6,   KC_DOT, XXXXXXX,KC_LBRC,KC_MINS,KC_EQL, KC_BSLS,KC_LPRN,KC_QUOT,
        _______,KC_7,   KC_8,   KC_9,   KC_0,   XXXXXXX,KC_RBRC,KC_SLSH,XXXXXXX,XXXXXXX,XXXXXXX,_______,
        KC_NO,  KC_NO,  _______,LOWER,  KC_LSPC,    KC_ATAB,     _______,_______,_______,KC_NO,  KC_NO
    ),
    /* System */
    [_SYSTEM] = LAYOUT(
        RESET,DF(_BASE),XXXXXXX,EEP_RST,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_PSCR,XXXXXXX,XXXXXXX,XXXXXXX,
        KC_CAPS,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
        KC_NO,  KC_NO,  _______,LOWER,  KC_LSPC,    KC_SPC,     KC_RSPC,RAISE,  _______,KC_NO,  KC_NO
    )
};

static bool lower_pressed = false;
static bool raise_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _SYSTEM);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _SYSTEM);
            }
            return false;
        case KC_LSPC:
            if (record->event.pressed) {
                lower_pressed = 1;

                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _SYSTEM);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _SYSTEM);

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
                update_tri_layer(_LOWER, _RAISE, _SYSTEM);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _SYSTEM);
            }
            return false;
        case KC_rSPC:
            if (record->event.pressed) {
                raise_pressed = 1;

                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _SYSTEM);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _SYSTEM);
                
                if(raise_pressed){
                    register_code(KC_SPC);
                    unregister_code(KC_SPC);
                }
                raise_pressed = 0;
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
                lower_pressed = 0;
                raise_pressed = 0;
            }
            break;
            
    }

    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}
*/

// How long (in milliseconds) to wait between animation steps for each of the "Swirling rainbow" animations
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {130, 130, 130};

const rgblight_segment_t PROGMEM plain124_capslock_enabled[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1,HSV_TEAL}
);
const rgblight_segment_t PROGMEM plain124_numlock_enabled[] = RGBLIGHT_LAYER_SEGMENTS(
    {1,1,HSV_TEAL}
);

const rgblight_segment_t* const PROGMEM plain124_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    plain124_capslock_enabled,
    plain124_numlock_enabled
);

void keyboard_post_init_user(void){
    rgblight_layers = plain124_rgb_layers;
    rgblight_mode(14);
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    rgblight_set_layer_state(1, led_state.num_lock);
    return true;
}
