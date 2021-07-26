#define _HSV(H, S, V) (HSV){ .h = H, .s = S, .v = V }
#define _RGB(rgb) rgb.r, rgb.g, rgb.b

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NUMPAD,
    _NUMPAD_SHIFT,
    _FN
};