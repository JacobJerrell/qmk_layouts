/*
Copyright 2017 Christopher Courtney <drashna@live.com> @drashna
Copyright 2020 Jacob Jerrell <jacob.jerrell+github@gmail.com>

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
#include QMK_KEYBOARD_H

#include "version.h"
#include "eeprom.h"
#include "wrappers.h"
#include "process_records.h"

enum userspace_layers {
    _WORKMAN = 0,
    _QWERTY,
    _LOWER,
    _MOUSE,
    _RAISE,
    _ADJUST,
};

void matrix_init_keymap(void);
void matrix_scan_keymap(void);
void led_set_keymap(uint8_t usb_led);
layer_state_t layer_state_set_keymap(layer_state_t state);
layer_state_t default_layer_state_set_keymap(layer_state_t state);
void suspend_power_down_keymap(void);
void suspend_wakeup_init_keymap(void);
void shutdown_keymap(void);
void eeconfig_init_keymap(void);
