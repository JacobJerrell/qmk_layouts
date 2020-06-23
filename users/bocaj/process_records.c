#include "bocaj.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

void tap(uint16_t keycode) { register_code(keycode); unregister_code(keycode); };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (process_record_keymap(keycode, record)) {

        if (record->event.pressed) {
            switch (keycode) {
                case KC_EPRM:
                    eeconfig_init();
                    break;
                case KC_VRSN:
                    SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                    break;
                case MC_WRKM...MC_QWRT:
                    set_single_persistent_default_layer(keycode - MC_WRKM);
#ifdef KEYBOARD_ergodox_ez
                    layer_move(0);
#endif // KEYBOARD_ergodox_ez
                    break;
                case MC_ARRW:
                    SEND_STRING("->");
                    break;
            }
        } else {
            switch (keycode) {
                case MC_LOCK:
                    layer_move(0);
                    SEND_STRING(SS_LCTRL(SS_LGUI("q")));
                    break;
            }
        }

    }
    return true;
}
