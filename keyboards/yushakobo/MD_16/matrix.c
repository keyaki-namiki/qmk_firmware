#include <stdint.h>
#include <stdbool.h>
#include "matrix.h"
#include "tmk_core/common/matrix.h"
//#include "util.h"
//#include "debounce.h"
#include "quantum.h"

// Custom matrix
static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

/* matrix state(1:on, 0:off) */
matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values
matrix_row_t matrix[MATRIX_ROWS];      // debounced values

inline matrix_row_t matrix_get_row(uint8_t row) {
    // Matrix mask lets you disable switches in the returned matrix data. For example, if you have a
    // switch blocker installed and the switch is always pressed.
    return matrix[row];
}

static void select_row(uint8_t row) {
    setPinOutput(row_pins[row]);
    writePinLow(row_pins[row]);
}

static void select_col(uint8_t col){
    setPinOutput(col_pins[col]);
    writePinLow(col_pins[col]);
}

static void unselect_row(uint8_t row) {
    setPinInputHigh(row_pins[row]);
}

static void unselect_col(uint8_t col) {
    setPinInputHigh(col_pins[col]);
}

static void unselect_rows(void) {
    for (uint8_t x = 0; x < MATRIX_ROWS; x++){
        setPinInputHigh(row_pins[x]);
    }
}

static void unselect_cols(void) {
    for (uint8_t x = 0; x < MATRIX_COLS; x++){
        setPinInputHigh(col_pins[x]);
    }
}

static void init_pins(void) {
    unselect_rows();
    for (uint8_t x = 0; x < MATRIX_COLS; x++){
        setPinInputHigh(col_pins[x]);
    }
    unselect_cols();
    for (uint8_t x = 0; x < MATRIX_ROWS; x++){
        setPinInputHigh(row_pins[x]);
    }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Start with a clear matrix row
    matrix_row_t current_row_value = 0;

    // Select row and wait for row selection to stabilize
    select_row(current_row);
    matrix_io_delay();

    // For each col...
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        // Select the col pin to read (active low)
        uint8_t pin_state = readPin(col_pins[col_index]);

        // Populate the matrix row with the state of the pin
        current_row_value |= pin_state ? 0 : (MATRIX_ROW_SHIFTER << col_index);
    }

    // Unselect row
    unselect_row(current_row);

    // If the row has changed, store row and return the changed flag.
    if(current_matrix[current_row != current_row_value]){
        current_matrix[current_row] = current_row_value;
        return true;
    }
    return false;
}

static bool read_rows_on_col(matrix_col_t current_matrix[], uint8_t current_col) {
    // Start with a clear matrix col
    matrix_col_t current_col_value = 0;

    // Select col and wait for col selection to stabilize
    select_col(current_col);
    matrix_io_delay();

    // For each row...
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        // Select the row pin to read (active low)
        uint8_t pin_state = readPin(row_pins[row_index]);

        //Populate the matrix col with the state of the pin
        current_col_value |= pin_state ? 0 : (((matrix_row_t)1) << row_index);
    }

    // Unselect col
    unselect_col(current_col);

    //If the col has changed, store col and return the changed flag.
    if(current_matrix[current_col != current_col_value]){
        current_matrix[current_col] = current_col_value;
        return true;
    }
    return false;
}

void matrix_print(void) {
    // TODO: use print() to dump the current matrix state to console
}

void matrix_init(void) {
    // TODO: initialize hardware and global matrix state here
    init_pins();
        // initialize matrix state: all keys off
//    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
//        raw_matrix[i] = 0;
//        matrix[i]     = 0;
//    }


    // Unless hardware debouncing - Init the configured debounce routine
//    debounce_init(MATRIX_ROWS);

#ifdef BACKLIGHT_ENABLE
#    ifdef LED_MATRIX_ENABLE
    led_matrix_init();
#    else
    backlight_init_ports();
#    endif
#endif
}

uint8_t matrix_scan(void) {
    bool matrix_has_changed = false;

    // TODO: add matrix scanning routine here
        // Set row, read cols
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        matrix_has_changed |= read_cols_on_row(raw_matrix, current_row);
    }
        // Set col, read rows
    for (uint8_t current_col = 0; current_col < MATRIX_COLS; current_col++) {
        matrix_has_changed |= read_rows_on_col(raw_matrix, current_col);
    }

    // Unless hardware debouncing - use the configured debounce routine
//    debounce(raw_matrix, matrix, MATRIX_ROWS, matrix_has_changed);

    // This *must* be called for correct keyboard behavior
//    matrix_scan_quantum();

    return (uint8_t)matrix_has_changed;
}
