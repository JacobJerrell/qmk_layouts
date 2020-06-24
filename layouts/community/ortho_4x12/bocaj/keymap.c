/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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

#include QMK_KEYBOARD_H
#include "bocaj.h"

enum planck_keycodes {
    TH_LVL = NEW_SAFE_RANGE,
};

#define LAYOUT_ortho_4x12_bocaj(...) WRAPPER_planck_bocaj(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
    *   Goal: Create a layout that easily adapts to my Ergodox layout to reduce mental burden when swapping keyboards
    *          although I haven't had issues like that for quite some time now... Who knows with a new non-standard keyboard in the mix though?
    */

  /* Default Planck QWERTY Layout
  * ,-----------------------------------------------------------------------------------.
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
  * `-----------------------------------------------------------------------------------'
  */
//   [_DEFAULT] = LAYOUT_planck_grid(
//     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
//     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
//     BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
//   )

  [_WORKMAN] = LAYOUT_ortho_4x12_bocaj(
    KC_ESC,  _______________WORKMAN_LHS_1_______________,  _______________WORKMAN_RHS_1_______________,   KC_BSLS,
    KC_TAB,  _______________WORKMAN_LHS_2_______________,  _______________WORKMAN_RHS_2_______________,   KC_QUOT,
    KC_LSFT, _______________WORKMAN_LHS_3_______________,  _______________WORKMAN_RHS_3_______________,   XXXXXXX,
    KC_LEAD, KC_LBRC, KC_UP, KC_LEFT, KC_BSPACE, KC_SPACE, XXXXXXX, KC_ENTER, KC_RIGHT, KC_DOWN, KC_RBRC, MO_MSE
  ),

  [_QWERTY] = LAYOUT_ortho_4x12_bocaj(
    KC_ESC,  ________________QWERTY_LHS1________________,  ________________QWERTY_RHS1________________,   KC_BSLS,
    KC_TAB,  ________________QWERTY_LHS2________________,  ________________QWERTY_RHS2________________,   KC_QUOT,
    KC_LSFT, ________________QWERTY_LHS3________________,  ________________QWERTY_RHS3________________,   XXXXXXX,
    KC_LEAD, KC_LBRC, KC_UP, KC_LEFT, KC_BSPACE,KC_SPACE,  XXXXXXX, KC_ENTER, KC_RIGHT, KC_DOWN, KC_RBRC, MO_MSE
  ),

  [_LOWER] = LAYOUT_ortho_4x12_bocaj(
     KC_GRAVE, _______, _______, KC_UP,  XXXXXXX,   MC_ARRW,  KC_MINS, KC_7, KC_8,    KC_9,    KC_PSLS, KC_EQUAL,
     KC_DEL, _______, KC_LEFT, KC_DOWN,  KC_RIGHT,  KC_LPRN,  KC_RPRN, KC_4, KC_5,    KC_6,    KC_PAST, KC_ENTER,
     _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,   KC_LBRC,  KC_RBRC, KC_1, KC_2,    KC_3,    KC_PPLS, _______,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPACE, KC_SPACE, XXXXXXX, KC_0, KC_PDOT, KC_COMM, KC_MINS, XXXXXXX
  ),

  [_MOUSE] = LAYOUT_planck_grid(
    _______, _______, _______, KC_WH_D, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, KC_WH_L, KC_WH_U, KC_WH_R, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______
  ),


  [_RAISE] = LAYOUT_ortho_4x12_bocaj(
    KC_GRAVE,  ________________NUMBERS_LHS________________,    ________________NUMBERS_RHS________________, KC_MINS,
    KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,  KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12,
    _______,  _______,  _______,  _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______,  _______,  _______,  _______, _______, _______,   _______, _______, _______, _______, _______, _______
  ),

//   [_] = LAYOUT_planck_grid(

//   ),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | MUTE |Vol Dn|Vol Up| LOCK |AUTogg|MusSwp|Wrkman|Qwerty|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_ADJUST] = LAYOUT_ortho_4x12_bocaj(
    _______, RESET,    DEBUG,       RGB_TOG,   RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
    _______, KC__MUTE, KC__VOLDOWN, KC__VOLUP, MC_LOCK, AU_TOG,  MU_MOD,  MC_WRKM, MC_QWRT, _______, _______, _______,
    _______, MUV_DE,   MUV_IN,      MU_ON,     MU_OFF,  MI_ON,   MI_OFF,   TH_LVL, _______, _______, _______, _______,
    _______, _______,  _______,     _______,   _______, _______, _______, _______, _______, _______, _______, _______
  )

// WIP
//   [_MACRO] = LAYOUT_ortho_4x12_bocaj(
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     _______, KC_XCD,  KC_VSC,  KC_WEB,  KC_TRM,  _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//   )

};

// layer_state_t layer_state_set_keymap(layer_state_t state) {

// }

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case _LOWER:
        if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        break;
        return false;
    case _RAISE:
        if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        break;
    case TH_LVL:
        if (record->event.pressed) {
            keyboard_config.led_level++;
            if (keyboard_config.led_level > 4) {
                keyboard_config.led_level = 0;
            }
            planck_ez_right_led_level((uint8_t)keyboard_config.led_level * 255 / 4);
            planck_ez_left_led_level((uint8_t)keyboard_config.led_level * 255 / 4);
            eeconfig_update_kb(keyboard_config.raw);
            layer_state_set_kb(layer_state);
        }
        break;
    }
    return true;
}

// bool muse_mode = false;
// uint8_t last_muse_note = 0;
// uint16_t muse_counter = 0;
// uint8_t muse_offset = 70;
// uint16_t muse_tempo = 50;

// void encoder_update(bool clockwise) {
//   if (muse_mode) {
//     if (IS_LAYER_ON(_RAISE)) {
//       if (clockwise) {
//         muse_offset++;
//       } else {
//         muse_offset--;
//       }
//     } else {
//       if (clockwise) {
//         muse_tempo+=1;
//       } else {
//         muse_tempo-=1;
//       }
//     }
//   } else {
//     if (clockwise) {
//       #ifdef MOUSEKEY_ENABLE
//         tap_code(KC_MS_WH_DOWN);
//       #else
//         tap_code(KC_PGDN);
//       #endif
//     } else {
//       #ifdef MOUSEKEY_ENABLE
//         tap_code(KC_MS_WH_UP);
//       #else
//         tap_code(KC_PGUP);
//       #endif
//     }
//   }
// }

// void dip_switch_update_user(uint8_t index, bool active) {
//     switch (index) {
//         case 0: {
// #ifdef AUDIO_ENABLE
//             static bool play_sound = false;
// #endif
//             if (active) {
// #ifdef AUDIO_ENABLE
//                 if (play_sound) { PLAY_SONG(plover_song); }
// #endif
//                 layer_on(_ADJUST);
//             } else {
// #ifdef AUDIO_ENABLE
//                 if (play_sound) { PLAY_SONG(plover_gb_song); }
// #endif
//                 layer_off(_ADJUST);
//             }
// #ifdef AUDIO_ENABLE
//             play_sound = true;
// #endif
//             break;
//         }
//         case 1:
//             if (active) {
//                 muse_mode = true;
//             } else {
//                 muse_mode = false;
//             }
//     }
// }

// void matrix_scan_user(void) {
// #ifdef AUDIO_ENABLE
//     if (muse_mode) {
//         if (muse_counter == 0) {
//             uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//             if (muse_note != last_muse_note) {
//                 stop_note(compute_freq_for_midi_note(last_muse_note));
//                 play_note(compute_freq_for_midi_note(muse_note), 0xF);
//                 last_muse_note = muse_note;
//             }
//         }
//         muse_counter = (muse_counter + 1) % muse_tempo;
//     } else {
//         if (muse_counter) {
//             stop_all_notes();
//             muse_counter = 0;
//         }
//     }
// #endif
// }
