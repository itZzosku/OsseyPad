/*
Copyright 2021 Osku Väyrynen

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x9230
#define DEVICE_VER 0x0002
#define MANUFACTURER Osku Väyrynen
#define PRODUCT OsseyPad
#define DESCRIPTION Num Pad with Macro keys and Encoder

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 6

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS \
    { D0, B1, F7, F6, F5, F4 }
#define MATRIX_COL_PINS \
    { B6, B4, E6, D7, C6, D4 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 20

/* ENCODER THINGS */
#define ENCODERS_PAD_A \
    { D1 }
#define ENCODERS_PAD_B \
    { B5 }
#define ENCODER_RESOLUTION 15

/* Tap Dance timing */
#define TAPPING_TERM 200
