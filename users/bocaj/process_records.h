/*
Copyright 2020 Jacob Jerrell @JacobJerrell

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
#include "bocaj.h"

#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    KC_EPRM = PLACEHOLDER_SAFE_RANGE,
    KC_VRSN,
    RGB_SLD,
    MC_ARRW,
    MC_WRKM,
    MC_QWRT,
    MC_LOCK,
    MC_LSWP,
    NEW_SAFE_RANGE
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
void matrix_scan_secrets(void);

// Layout beautification
#define TT_ADJ TT(_ADJUST)
#define MO_MSE MO(_MOUSE)
#define TT_MSE TT(_MOUSE)
#define KC_HME TO(0)

// Software bindings that switch to/launch XCode/VSCode/Chrome (Brave)/iTerm using BetterTouchTool
#define KC_XCD HYPR(KC_1)
#define KC_VSC HYPR(KC_2)
#define KC_WEB HYPR(KC_3)
#define KC_TRM HYPR(KC_4)

// Custom Keycode Helpers
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK  (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define MODS_GUI_MASK  (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))

// Other Keycodes
#define KC_RST RESET

void tap(uint16_t keycode);
