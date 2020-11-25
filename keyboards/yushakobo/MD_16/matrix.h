#pragma once

#include "quantum.h"
#include "wait.h"

#ifndef MATRIX_IO_DELAY
#    define MATRIX_IO_DELAY 30
#endif
// 
// __attribute__((weak)) void matrix_init_kb(void) {};
// 
// __attribute__((weak)) void matrix_scan_kb(void) {};

__attribute__((weak)) void matrix_io_delay(void) { wait_us(MATRIX_IO_DELAY); }

//__attribute__((weak)) void matrix_init_quantum(void) {};

//__attribute__((weak)) void matrix_scan_quantum(void) {};
