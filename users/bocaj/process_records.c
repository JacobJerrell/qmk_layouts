#include "bocaj.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (process_record_keymap(keycode, record)) {

        if (record->event.pressed) {
            switch (keycode) {
                case MC_WRKM...MC_QWRT:
                    set_single_persistent_default_layer(keycode - MC_WRKM);
                    layer_move(0);
                    break;
                    return false;
                case MC_ARRW:
                    SEND_STRING("->");
                    break;
                    return false;
            }
        } else {
            switch (keycode) {
                case MC_LOCK:
                    // layer_move(0);
                    tap_code16(LCTL(LGUI(KC_Q)));
                    break;
                    return false;
            }
        }

    }
    return true;
}
