#include QMK_KEYBOARD_H
#include "bootloader.h"

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes { 
    QWERTY = SAFE_RANGE,
    LOWER,
    KC_LSPC,
    RAISE,
    KC_RENT,
    KC_RSLS,
    ADJUST
};
#define KC_TCTL MT(MOD_LCTL, KC_TAB)
#define KC_ATAB LT(_ADJUST, KC_TAB)
#define KC_BSFT MT(MOD_LSFT, KC_BSPC)
// #define KC_SSLS MT(MOD_RSFT,KC_SLSH)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	  [_QWERTY] = LAYOUT(
		KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
		KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
		KC_TCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT,KC_BSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_RSLS, KC_RSFT, ADJUST,
		KC_LALT,KC_LCTL,KC_LGUI,XXXXXXX,KC_LSPC,XXXXXXX,XXXXXXX,KC_LALT,XXXXXXX,KC_RCTL,RAISE
		),

	  [_LOWER] = LAYOUT(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX,
		KC_TAB,     KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, XXXXXXX, XXXXXXX, KC_DEL,
		_______, XXXXXXX, KC_INS,  KC_DEL,  KC_BTN3, KC_F11,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,
		_______, KC_BSPC, XXXXXXX, KC_BSPC, KC_APP,  KC_ENT,  KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX, _______, _______,
		_______, _______, _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, _______
		),

	  [_RAISE] = LAYOUT(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, _______, KC_GRV,
		_______, KC_4,    KC_5,    KC_6,    KC_DOT,  XXXXXXX, KC_LBRC, KC_MINS, KC_EQL,  KC_BSLS, XXXXXXX, KC_QUOT, KC_DOT,
		_______, KC_GRV,  KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_RBRC, KC_SCLN, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
		_______, _______, _______, XXXXXXX, KC_ATAB, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, _______
		),

	  [_ADJUST] = LAYOUT(
		RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
		KC_CAPS, XXXXXXX, XXXXXXX, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, _______,
		KC_CAPS, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_LEFT, KC_RGHT, _______,
		_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_DOWN, _______, _______,
		_______, _______, _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, _______
		),
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
        case KC_RSLS:
            if (record->event.pressed) {
                raise_pressed = 1;

                layer_on(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
                
                if(raise_pressed){
                    register_code(KC_SLSH);
                    unregister_code(KC_SLSH);
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