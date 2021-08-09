RGB_MATRIX_EFFECT(macro_fighter6_matrix)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "keymap_prefs.h"

#define LED_LAYOUT(\
    L0,  L1,  L2,  L3,  L4,  L5,\
    L6,  L7,  L8,  L9,  L10, L11,\
    L12, L13, L14, L15, L16, L17,\
    L18, L19, L20, L21, L22, L23,\
    L24, L25, L26, L27, L28, L29,\
    L30, L31, L32, L33, L34, L35\
) {\
    L12, L18, L24, L30, L31, L25,\
    L19, L13, L14, L20, L26, L32,\
    L33, L27, L21, L15, L16, L22,\
    L28, L34, L35, L29, L23, L17,\
    L11, L10, L9,  L8,  L7,  L6,\
    L0,  L1,  L2,  L3,  L4,  L5\
}

enum lighting_types {
    BLANKS,
    ______,
    LAYERS,
    NUMPAD,
    ALPHAS,
    NAVKEY,
    SYSTEM,
    CAPSLK,
    NUM_LK,
    NACLYR
};

const uint8_t rgb_keymaps [][DRIVER_LED_TOTAL] = {
    [_BASE] = LED_LAYOUT(
        LAYERS, NACLYR, NACLYR, NACLYR, SYSTEM, SYSTEM,
        CAPSLK, NUM_LK, BLANKS, BLANKS, ______, ______,
        ______, ALPHAS, ALPHAS, ALPHAS, ALPHAS, ALPHAS,
        ______, NAVKEY, NAVKEY, NAVKEY, NAVKEY, ______,
        ______, NAVKEY, NAVKEY, NAVKEY, NAVKEY, BLANKS,
        ______, BLANKS, BLANKS, BLANKS, ______, ______
    ),
    [_NUMPAD] = LED_LAYOUT(
        NACLYR, LAYERS, NACLYR, NACLYR, BLANKS, BLANKS,
        CAPSLK, NUM_LK, ______, NUMPAD, NUMPAD, NUMPAD,
        BLANKS, BLANKS, NUMPAD, NUMPAD, NUMPAD, NUMPAD,
        BLANKS, ______, NUMPAD, NUMPAD, NUMPAD, NUMPAD,
        BLANKS, ______, NUMPAD, NUMPAD, NUMPAD, NUMPAD,
        BLANKS, ______, NUMPAD, NUMPAD, NUMPAD, NUMPAD
    ),
    [_NUMPAD_SHIFT] = LED_LAYOUT(
        NACLYR, NACLYR, LAYERS, NACLYR, BLANKS, BLANKS,
        CAPSLK, BLANKS, NUM_LK, ______, ______, ______,
        BLANKS, BLANKS, NAVKEY, NAVKEY, NAVKEY, ______,
        BLANKS, ______, NAVKEY, BLANKS, NAVKEY, ______,
        BLANKS, ______, ______, NAVKEY, ______, ______,
        BLANKS, BLANKS, ______, ______, ______, ______
    ),
    [_FN] = LED_LAYOUT(
        NACLYR, NACLYR, NACLYR, LAYERS, SYSTEM, SYSTEM,
        BLANKS, BLANKS, BLANKS, BLANKS, BLANKS, BLANKS,
        BLANKS, BLANKS, BLANKS, BLANKS, BLANKS, BLANKS,
        BLANKS, BLANKS, BLANKS, BLANKS, BLANKS, BLANKS,
        BLANKS, BLANKS, BLANKS, BLANKS, BLANKS, BLANKS,
        BLANKS, BLANKS, BLANKS, BLANKS, BLANKS, BLANKS
    )
};

static void led_color_set(uint8_t index, uint8_t color_patterns) {
    HSV hsv = rgb_matrix_config.hsv; // 'quantum/rgblight_list.h'
    RGB rgb_white = hsv_to_rgb(_HSV(  0,   0, hsv.v)); // HSV_WHITE
    RGB rgb_indc1 = hsv_to_rgb(_HSV(128, 255, hsv.v)); // HSV_TEAL
    RGB rgb_indc2 = hsv_to_rgb(_HSV(191, 255, hsv.v)); // HSV_PURPLE
    RGB rgb_indc3 = hsv_to_rgb(_HSV( 64, 255, hsv.v)); // HSV_CHARTREUSE
    RGB rgb_indc4 = hsv_to_rgb(_HSV(106, 255, hsv.v)); // HSV_SPRINGGREEN
    RGB rgb_indc5 = hsv_to_rgb(_HSV(234, 128, hsv.v)); // HSV_PINK
    RGB rgb_indc6 = hsv_to_rgb(_HSV(213, 255, hsv.v)); // HSV_MAGENTA
    RGB rgb_indc7 = hsv_to_rgb(_HSV(132, 102, hsv.v)); // HSV_AZURE
    switch(color_patterns){
        case BLANKS:  rgb_matrix_set_color(index, RGB_BLACK); break;
        case ______: rgb_matrix_set_color(index, _RGB(rgb_white)); break;
        case LAYERS: rgb_matrix_set_color(index, _RGB(rgb_indc1)); break;
        case NUMPAD: rgb_matrix_set_color(index, _RGB(rgb_indc2)); break;
        case ALPHAS: rgb_matrix_set_color(index, _RGB(rgb_indc3)); break;
        case NAVKEY: rgb_matrix_set_color(index, _RGB(rgb_indc4)); break;
        case SYSTEM: rgb_matrix_set_color(index, _RGB(rgb_indc5)); break;
        case NACLYR: rgb_matrix_set_color(index, _RGB(rgb_indc7)); break;
        case CAPSLK:
            if (host_keyboard_led_state().caps_lock) {
                rgb_matrix_set_color(index, _RGB(rgb_indc6));
            } else {
                rgb_matrix_set_color(index, _RGB(rgb_white));
            }
            break;
        case NUM_LK:
            if (host_keyboard_led_state().num_lock) {
                rgb_matrix_set_color(index, _RGB(rgb_indc6));
            } else {
                rgb_matrix_set_color(index, _RGB(rgb_white));
            }
            break;
    }
}

static bool macro_fighter6_matrix (effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        if (IS_LAYER_ON(_NUMPAD_SHIFT)){
            led_color_set(i, rgb_keymaps[_NUMPAD_SHIFT][i]);
        } else if (IS_LAYER_ON(_FN)){
            led_color_set(i, rgb_keymaps[_FN][i]);
        } else if (IS_LAYER_ON(_NUMPAD)){
            led_color_set(i, rgb_keymaps[_NUMPAD][i]);
        } else if (IS_LAYER_ON(_BASE)){
            led_color_set(i, rgb_keymaps[_BASE][i]);
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}

#endif