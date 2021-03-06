/*
Copyright 2020 Jacob Jerrell <jacob.jerrell@gmail.com> @JacobJerrell	

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
    VRSN = PLACEHOLDER_SAFE_RANGE,  // Prints QMK Firmware and board info
    KC_WORKMAN,                     // Sets default layer to WORKMAN
    KC_QWERTY,                      // Sets default layer to QWERTY
    // KC_COLEMAK,                     // Sets default layer to COLEMAK
    // KC_DVORAK,                      // Sets default layer to DVORAK
    KC_MAKE,                        // Run keyboard's customized make command
    KC_RGB_T,                       // Toggles RGB Layer Indication mode
    RGB_IDL,                        // RGB Idling animations
    MC_ARRW,                        // ->
    UC_FLIP,                        // (ಠ痊ಠ)┻━┻
    UC_TABL,                        // ┬─┬ノ( º _ ºノ)
    UC_SHRG,                        // ¯\_(ツ)_/¯
    UC_DISA,                        // ಠ_ಠ
    NEW_SAFE_RANGE                  // use "NEWPLACEHOLDER for keymap specific codes
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

#define MO_MOD  MO(_MOD)
#define TT_MOD  TT(_MOD)

#define QWERTY  KC_QWERTY
// #define DVORAK  KC_DVORAK
// #define COLEMAK KC_COLEMAK
#define WORKMAN KC_WORKMAN

#define KC_ARRW MC_ARRW

#define KC_RST   RESET

#define ALT_APP ALT_T(KC_APP)
#define HYP_LBK ALL_T(KC_LBRACKET)
#define MEH_RBK MEH_T(KC_RBRACKET)
#define HYP_LPR ALL_T(KC_LPRN)
#define MEH_RPR MEH_T(KC_RPRN)

#define MG_NKRO MAGIC_TOGGLE_NKRO
