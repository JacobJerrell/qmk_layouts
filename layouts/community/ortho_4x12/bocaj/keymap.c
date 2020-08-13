#include "bocaj.h"

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif

#ifdef BACKLIGHT_ENABLE
enum planck_keycodes {
    BACKLIT = NEW_SAFE_RANGE,
    TH_LVL,
};

#else
#    define BACKLIT OSM(MOD_LSFT)
enum planck_keycodes {
    TH_LVL = NEW_SAFE_RANGE,
};
#endif

/*
 * Tap/Hold Wrapper
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |Shift | Cmd  | Alt  |      |      | Alt  | Cmd  |Shift |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |      |      |      |      |      |      |      |      | Ctrl |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |             |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
#define LAYOUT_ortho_4x12_bocaj(...) WRAPPER_planck_bocaj(__VA_ARGS__)

/*
 * Base Alphanumeric Wrapper + Tap/Hold Wrapper
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |      |      |      |      |      |      |      |      |      |      |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Tab |      |      |      |      | HYPR | MEH  |      |      |      |      |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      | XXX  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lead |Mouse |  Up  | Left |BkSpc |    Space    |Enter |Right | Down | XXX  | XXX  |
 * `-----------------------------------------------------------------------------------'
 */
#define LAYOUT_ortho_4x12_bocaj_base(...) WRAPPER_planck_bocaj_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ortho_4x12_bocaj_base(
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
  ),

  [_COLEMAK] = LAYOUT_ortho_4x12_bocaj_base(
    _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
    _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
    _________________COLEMAK_L3________________, _________________COLEMAK_R3________________
  ),

  [_DVORAK] = LAYOUT_ortho_4x12_bocaj_base(
    _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
    _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
    _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
  ),

  [_WORKMAN] = LAYOUT_ortho_4x12_bocaj_base(
    _________________WORKMAN_L1________________, _________________WORKMAN_R1________________,
    _________________WORKMAN_L2________________, _________________WORKMAN_R2________________,
    _________________WORKMAN_L3________________, _________________WORKMAN_R3________________
  ),

  [_NORMAN] = LAYOUT_ortho_4x12_bocaj_base(
    _________________NORMAN_L1_________________, _________________NORMAN_L1_________________,
    _________________NORMAN_L2_________________, _________________NORMAN_R2_________________,
    _________________NORMAN_L3_________________, _________________NORMAN_R3_________________
  ),

  [_MALTRON] = LAYOUT_ortho_4x12_bocaj_base(
    _________________MALTRON_L1________________, _________________MALTRON_R1________________,
    _________________MALTRON_L2________________, _________________MALTRON_R2________________,
    _________________MALTRON_L3________________, _________________MALTRON_R3________________
  ),

  [_EUCALYN] = LAYOUT_ortho_4x12_bocaj_base(
    _________________EUCALYN_L1________________, _________________EUCALYN_R1________________,
    _________________EUCALYN_L2________________, _________________EUCALYN_R2________________,
    _________________EUCALYN_L3________________, _________________EUCALYN_R3________________
  ),

  [_CARPLAX] = LAYOUT_ortho_4x12_bocaj_base(
    _____________CARPLAX_QFMLWY_L1_____________, _____________CARPLAX_QFMLWY_R1_____________,
    _____________CARPLAX_QFMLWY_L2_____________, _____________CARPLAX_QFMLWY_R2_____________,
    _____________CARPLAX_QFMLWY_L3_____________, _____________CARPLAX_QFMLWY_R3_____________
  ),

  [_MODS] = WRAPPER_ortho_4x12(
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    KC_LSFT, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, KC_RSFT,
    _______, _______, _______, _______, _______,      _______,      _______, _______, _______, _______, _______
  ),

  [_LOWER] = LAYOUT_ortho_4x12_bocaj(
    KC_GRV,  _______, _______, KC_UP,   _______, KC_MINS, KC_EQUAL, KC_7, KC_8,   KC_9,    KC_BSLS, KC_EQUAL,
    KC_DEL,  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_LPRN, KC_RPRN,  KC_4, KC_5,   KC_6,    KC_ASTR, _______, 
    _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC,  KC_1, KC_2,   KC_3,    KC_PLUS, _______,
    TT_MSE,  _______, _______, _______, _______,      _______,      KC_0, KC_DOT, KC_COMM, _______, _______
  ),


  [_MOUSE] = WRAPPER_ortho_4x12(
    _______, _______, _______, KC_WH_D, _______, _______,  _______, _______, KC_MS_U, _______, _______, _______,
    _______, _______, KC_WH_L, KC_WH_U, KC_WH_R, _______,  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_BTN1,      _______,      KC_BTN2, _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT_ortho_4x12_bocaj(
    KC_TILD, _________________RAISE_L1__________________, _________________RAISE_R1__________________, KC_EQUAL,
    KC_DEL,  _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
    _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
  ),

  [_ADJUST] = WRAPPER_ortho_4x12(
    KC_MAKE, _________________ADJUST_L1_________________, _________________ADJUST_R1_________________, KC_RST,
    VRSN,    _________________ADJUST_L2_________________, _________________ADJUST_R2_________________, EEP_RST,
    TH_LVL,  _________________ADJUST_L3_________________, _________________ADJUST_R3_________________, RGB_IDL,
    HPT_TOG, _______, _______, _______, _______,     KC_NUKE,   _______, _______, _______, _______, TG_MODS
  )

};
// clang-format on

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef BACKLIGHT_ENABLE
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
#    ifdef BACKLIGHT_ENABLE
                backlight_step();
#    endif
            } else {
                unregister_code(KC_RSFT);
            }
            break;
#endif
#ifdef KEYBOARD_planck_ez
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
#endif
    }
    return true;
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        default:
            return true;
    }
}

#ifdef RGB_MATRIX_ENABLE

// clang-format off
void suspend_power_down_keymap(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_keymap(void) {
    rgb_matrix_set_suspend_state(false);
}
// clang-format on

void rgb_matrix_indicators_user(void) {
    uint8_t this_mod = get_mods();
    uint8_t this_led = host_keyboard_leds();
    uint8_t this_osm = get_oneshot_mods();
    bool    is_ez;
#    ifdef KEYBOARD_planck_ez
    is_ez = true;
#    endif

    if (g_suspend_state || !rgb_matrix_config.enable) return;

#    if defined(RGBLIGHT_ENABLE)
    if (!userspace_config.rgb_layer_change)
#    else
    if (userspace_config.rgb_layer_change)
#    endif
    {
        switch (get_highest_layer(layer_state)) {
            case _MOUSE:
                rgb_matrix_layer_helper(HSV_ORANGE, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _RAISE:
                rgb_matrix_layer_helper(HSV_BLUE, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _LOWER:
                rgb_matrix_layer_helper(HSV_GREEN, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _ADJUST:
                rgb_matrix_layer_helper(HSV_RED, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            default: {
                bool mods_enabled = IS_LAYER_ON(_MODS);
                switch (get_highest_layer(default_layer_state)) {
                    case _QWERTY:
                        rgb_matrix_layer_helper(HSV_CYAN, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                    case _COLEMAK:
                        rgb_matrix_layer_helper(HSV_MAGENTA, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                    case _DVORAK:
                        rgb_matrix_layer_helper(HSV_SPRINGGREEN, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                    case _WORKMAN:
                        rgb_matrix_layer_helper(HSV_CORAL, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                    case _NORMAN:
                        rgb_matrix_layer_helper(HSV_GOLDENROD, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                    case _MALTRON:
                        rgb_matrix_layer_helper(HSV_YELLOW, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                    case _EUCALYN:
                        rgb_matrix_layer_helper(HSV_PINK, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                    case _CARPLAX:
                        rgb_matrix_layer_helper(HSV_BLUE, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                }
                break;
            }
        }
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            rgb_matrix_set_color(is_ez ? 41 : 42, 0x00, 0xFF, 0xFF);
            break;
        case _COLEMAK:
            rgb_matrix_set_color(is_ez ? 41 : 42, 0xFF, 0x00, 0xFF);
            break;
        case _DVORAK:
            rgb_matrix_set_color(is_ez ? 41 : 42, 0x00, 0xFF, 0x00);
            break;
        case _WORKMAN:
            rgb_matrix_set_color(is_ez ? 41 : 42, 0xD9, 0xA5, 0x21);
            break;
    }

    if ((this_mod | this_osm) & MOD_MASK_SHIFT || this_led & (1 << USB_LED_CAPS_LOCK)) {
        if (!layer_state_cmp(layer_state, _ADJUST)) {
            rgb_matrix_set_color(24, 0x00, 0xFF, 0x00);
        }
        rgb_matrix_set_color(36, 0x00, 0xFF, 0x00);
    }
    if ((this_mod | this_osm) & MOD_MASK_CTRL) {
        rgb_matrix_set_color(25, 0xFF, 0x00, 0x00);
        rgb_matrix_set_color(34, 0xFF, 0x00, 0x00);
        rgb_matrix_set_color(37, 0xFF, 0x00, 0x00);
    }
    if ((this_mod | this_osm) & MOD_MASK_GUI) {
        rgb_matrix_set_color(39, 0xFF, 0xD9, 0x00);
    }
    if ((this_mod | this_osm) & MOD_MASK_ALT) {
        rgb_matrix_set_color(38, 0x00, 0x00, 0xFF);
    }
}

void matrix_init_keymap(void) {
#    ifdef KEYBOARD_planck_light
    writePinLow(D6);
#    endif
    // rgblight_mode(RGB_MATRIX_MULTISPLASH);
}
#else  // RGB_MATRIX_INIT

void matrix_init_keymap(void) {
#    if !defined(CONVERT_TO_PROTON_C) && !defined(KEYBOARD_planck)
    setPinOutput(D5);
    writePinHigh(D5);

    setPinOutput(B0);
    writePinHigh(B0);
#    endif
}
#endif  // RGB_MATRIX_INIT

#ifdef ENCODER_ENABLE
void encoder_update(bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _RAISE:
            clockwise ? tap_code(KC_VOLD) : tap_code(KC_VOLU);
            break;
        case _LOWER:
#    ifdef RGB_MATRIX_ENABLE
            clockwise ? rgb_matrix_step() : rgb_matrix_step_reverse();
#    else
            clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
#    endif
            break;
        case _ADJUST:
#    ifdef AUDIO_CLICKY
            clockwise ? clicky_freq_up() : clicky_freq_down();
#    endif
            break;
        default:
            clockwise ? tap_code(KC_DOWN) : tap_code(KC_UP);
    }
#    ifdef AUDIO_CLICKY
    clicky_play();
#    endif
}
#endif  // ENCODER_ENABLE

#ifdef KEYBOARD_planck_rev6
void dip_update(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                audio_on();
            } else {
                audio_off();
            }
            break;
        case 1:
            if (active) {
                clicky_on();
            } else {
                clicky_off();
            }
            break;
        case 2:
            keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = active;
            break;
        case 3:
            userspace_config.nuke_switch = active;
            break;
    }
}
#endif  // KEYBOARD_planck_rev6

#ifdef KEYBOARD_planck_ez
layer_state_t layer_state_set_keymap(layer_state_t state) {
    planck_ez_left_led_off();
    planck_ez_right_led_off();
    switch (get_highest_layer(state)) {
        case _LOWER:
            planck_ez_left_led_on();
            break;
        case _RAISE:
            planck_ez_right_led_on();
            break;
        case _ADJUST:
            planck_ez_right_led_on();
            planck_ez_left_led_on();
            break;
        default:
            break;
    }
    return state;
}
#endif
