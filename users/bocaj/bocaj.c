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

#include "bocaj.h"

__attribute__((weak)) void keyboard_pre_init_keymap(void) {}

void keyboard_pre_init_user(void) {
    keyboard_pre_init_keymap();
}

// Add reconfigurable functions here, for keymap customization
// This allows for a global, userspace functions, and continued
// customization of the keymap.  Use _keymap instead of _user
// functions in the keymaps
__attribute__((weak)) void matrix_init_keymap(void) {}

void matrix_init_user(void) {
    matrix_init_keymap();
}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

void keyboard_post_init_user(void) {
// #if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
//     keyboard_post_init_rgb();
// #endif
    keyboard_post_init_keymap();
}

__attribute__((weak)) void shutdown_keymap(void) {}

void rgb_matrix_update_pwm_buffers(void);

void shutdown_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
    rgblight_setrgb_red();
#endif  // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
#    ifdef __AVR__
    rgb_matrix_set_color_all(0xFF, 0x00, 0x00);
    rgb_matrix_update_pwm_buffers();
#    else
    rgb_matrix_sethsv_noeeprom(0, 255, 255);
    rgb_matrix_mode_noeeprom(1);
#    endif
#endif  // RGB_MATRIX_ENABLE
    shutdown_keymap();
}

__attribute__((weak)) void suspend_power_down_keymap(void) {}

void suspend_power_down_user(void) { suspend_power_down_keymap(); }

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}

void suspend_wakeup_init_user(void) { suspend_wakeup_init_keymap(); }

__attribute__((weak)) void matrix_scan_keymap(void) {}
__attribute__((weak)) void matrix_scan_secrets(void) {}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    static bool has_ran_yet;

    if (!has_ran_yet) {
        has_ran_yet = true;
        startup_user();
    }

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Website Refresh / XCode "Run"
        SEQ_ONE_KEY(KC_R) {
            SEND_STRING(SS_LGUI("r"));
        }

        // Mac copy line down (Leader -> d, d)
        SEQ_TWO_KEYS(KC_D, KC_D) {
            register_code(KC_LSHIFT);
            register_code(KC_HOME);
            unregister_code(KC_HOME);
            unregister_code(KC_LSHIFT);
            SEND_STRING(SS_LGUI("c"));
            tap(KC_END);
            tap(KC_ENTER);
            SEND_STRING(SS_LGUI("v"));
        }

        SEQ_TWO_KEYS(KC_B, KC_D) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION " Built at: " QMK_BUILDDATE);
        }

        #ifndef NO_SECRETS
        matrix_scan_secrets();
        #endif // !NO_SECRETS
    }
    matrix_scan_keymap();
}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
layer_state_t layer_state_set_user(layer_state_t state) {
    return layer_state_set_keymap(state);
}

__attribute__((weak)) layer_state_t default_layer_state_set_keymap(layer_state_t state) { return state; }

// Runs state check and changes underglow color and animation
layer_state_t default_layer_state_set_user(layer_state_t state) {
    state = default_layer_state_set_keymap(state);
#if 0
#    if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
  state = default_layer_state_set_rgb(state);
#    endif  // RGBLIGHT_ENABLE
#endif
    return state;
}

__attribute__((weak)) void led_set_keymap(uint8_t usb_led) {}

// Any custom LED code goes here.
// So far, I only have keyboard specific code,
// So nothing goes here.
void led_set_user(uint8_t usb_led) { led_set_keymap(usb_led); }

__attribute__((weak)) void eeconfig_init_keymap(void) {}

void eeconfig_init_user(void) {
    eeconfig_init_keymap();
    keyboard_init();
}
