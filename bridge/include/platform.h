/*
 * This file is part of the Black Magic Debug project.
 *
 * Copyright (C) 2011  Black Sphere Technologies Ltd.
 * Written by Gareth McMullin <gareth@blacksphere.co.nz>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#ifndef __PLATFORM_H
#define __PLATFORM_H

#undef PRIx32
#define PRIx32 "x"

#undef SCNx32
#define SCNx32 "x"

#define NO_USB_PLEASE

#define SET_RUN_STATE(state)
#define SET_IDLE_STATE(state)
#define SET_ERROR_STATE(state)

#define DEBUG(x, ...) do { ; } while (0)
//#define DEBUG printf

#include "timing.h"
#define BOARD_IDENT "Black Magic Probe (esp32), (Firmware 0.1)"

#define TMS_SET_MODE() do { } while (0)

#define TMS_PIN (17) // On wroover module, this is PSRAM clock
#define TDI_PIN (13) //
#define TDO_PIN (14) //
#define TCK_PIN (12) //
/* These are used for input JTAG on esp32
2 	MTDO / GPIO15 	TDO
3 	MTDI / GPIO12 	TDI
4 	MTCK / GPIO13 	TCK
5 	MTMS / GPIO14 	TMS
*/

//#define PLATFORM_HAS_TRACESWO 1
#define TRACESWO_PIN 13
// Workaround for driver
#define TRACESWO_DUMMY_TX 19

// ON ESP32 we dont have the PORTS (unlike stm32), this is dummy value to keep things similar as other platforms
#define SWCLK_PORT  0
#define SWDIO_PORT  0

#define SWDIO_PIN (17)  // On wroover module, this is PSRAM clock
#define SWCLK_PIN (23)

#define gpio_set_val(port, pin, value) {}
#define gpio_set(port, pin) {}
#define gpio_clear(port, pin) {}
#define gpio_get(port, pin) 0
#define SWDIO_MODE_FLOAT() {}
#define SWDIO_MODE_DRIVE() {}

//#define PLATFORM_HAS_DEBUG 1
//#define ENABLE_DEBUG 1

extern uint32_t swd_delay_cnt;

#endif
