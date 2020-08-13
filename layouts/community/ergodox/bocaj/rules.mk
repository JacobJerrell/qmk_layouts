BOOTMAGIC_ENABLE   = lite
TAP_DANCE_ENABLE   = no
COMMAND_ENABLE     = no  # Commands for debug and configuration
CONSOLE_ENABLE     = no
SPACE_CADET_ENABLE = no
KEY_LOCK_ENABLE    = yes

ifeq ($(strip $(KEYBOARD)), ergodox_ez)
    RGBLIGHT_ENABLE            = no
    RGB_MATRIX_ENABLE          = no
    RGBLIGHT_TWINKLE           = no
    INDICATOR_LIGHTS           = no
    RGBLIGHT_STARTUP_ANIMATION = no
    PIMORONI_TRACKBALL_ENABLE  = no
    MOUSEKEY_ENABLE            = yes
endif

UNICODE_ENABLE     = no
UNICDOEMAP_ENABLE  = no

DEBOUNCE_TYPE     = eager_pr
