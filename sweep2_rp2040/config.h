/* Copyright 2018-2020
ENDO Katsuhiro <ka2hiro@curlybracket.co.jp>
David Philip Barr <@davidphilipbarr>
Pierre Chevalier <pierrechevalier83@gmail.com>

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

//#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 5

/*
#define BAD_DIRECT_PINS { \
    { GP3, GP15, GP26, GP27, GP28 }, \
    { GP14, GP29, GP13, GP12, GP0 }, \
    { GP4, GP5, GP6, GP7, GP8 }, \
    { GP9, GP10, NO_PIN, NO_PIN, NO_PIN } \
}
*/

#define DIRECT_PINS { \
    { GP7, GP26, GP27, GP28, GP29 }, \
    { GP22, GP20, GP23, GP21, GP0 }, \
    { GP2, GP3, GP4, GP5, GP6 }, \
    { GP8, GP9, NO_PIN, NO_PIN, NO_PIN } \
}




#define DIRECT_PINS_RIGHT { \
    { GP29, GP28, GP27, GP26, GP7 }, \
    { GP0, GP21, GP23, GP20, GP22 }, \
    { GP6, GP5, GP4, GP3, GP2 }, \
    { GP9, GP8, NO_PIN, NO_PIN, NO_PIN } \
}

/*
#define BAD_DIRECT_PINS_RIGHT { \
    { GP28, GP27, GP26, GP15, GP3 }, \
    { GP0, GP12, GP13, GP29, GP14 }, \
    { GP8, GP7, GP6, GP5, GP4 }, \
    { GP10, GP9, NO_PIN, NO_PIN, NO_PIN } \
}
*/

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
//#define SOFT_SERIAL_PIN GP1
#undef SOFT_SERIAL_PIN
#undef SERIAL_USART_TX_PIN
#define SERIAL_USART_TX_PIN GP1
#define SERIAL_PIO_USE_PIO1
#undef SERIAL_USART_FULL_DUPLEX
#undef SERIAL_USART_RX_PIN

#define EE_HANDS

/* Top left key on left half */
#define BOOTMAGIC_LITE_ROW    0
#define BOOTMAGIC_LITE_COLUMN 0
/* Top right key on right half */
#define BOOTMAGIC_LITE_ROW_RIGHT    4
#define BOOTMAGIC_LITE_COLUMN_RIGHT 4
