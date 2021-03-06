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


#define NO_USB_PLEASE

#define SET_RUN_STATE(state)
#define SET_IDLE_STATE(state)
#define SET_ERROR_STATE(state)

#define DEBUG(x, ...) do { ; } while (0)
//#define DEBUG printf

#include "timing.h"
#define BOARD_IDENT "Black Magic Probe (esp32), (Firmware 0.1)"

//#define PLATFORM_HAS_TRACESWO 1
//#define PLATFORM_HAS_DEBUG 1
//#define ENABLE_DEBUG 1

#define TMS_SET_MODE() do { } while (0)

#define TMS_PIN       (8) // On wroover module, this is PSRAM clock
#define TDI_PIN       (9) //
#define TDO_PIN       (10) //
#define TCK_PIN       (11) //
#define TRACESWO_PIN  (12)
#define SWDIO_PIN     (13)  // On wroover module, this is PSRAM clock
#define SWCLK_PIN     (14)


#define TRACESWO_DUMMY_TX 19
#define SWCLK_PORT  0
#define SWDIO_PORT  0

extern void bmp_gpio_write(int pin, int value);
extern int  bmp_gpio_read(int pin);
extern void bmp_gpio_drive_state(int pin, int driven);

#define gpio_set_val(port, pin, value)  bmp_gpio_write(pin,value)
#define gpio_set(port, pin)             bmp_gpio_write(pin,1)
#define gpio_clear(port, pin)           bmp_gpio_write(pin,0)
#define gpio_get(port, pin)             bmp_gpio_read(pin)
#define SWDIO_MODE_FLOAT() {}           bmp_gpio_drive_state(SWDIO_PIN,false)
#define SWDIO_MODE_DRIVE() {}           bmp_gpio_drive_state(SWDIO_PIN,true)

extern uint32_t swd_delay_cnt;

#endif
