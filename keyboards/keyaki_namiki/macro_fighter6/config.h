#pragma once

/* Custom RGBLIGHT map array layout override if needed */
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_LED_MAP {\
    12, 18, 24, 30, 31, 25,\
    19, 13, 14, 20, 26, 32,\
    33, 27, 21, 15, 16, 22,\
    28, 34, 35, 29, 23, 17,\
    11, 10, 9,  8,  7,  6,\
    0,  1,  2,  3,  4,  5\
}
#endif