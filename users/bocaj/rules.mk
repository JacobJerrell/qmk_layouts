SRC += bocaj.c \
       process_records.c

LEADER_ENABLE = yes
KEY_LOCK_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes

TAP_DANCE_ENABLE = no
AUTO_SHIFT_ENABLE = no
CONSOLE_ENABLE = no
SWAP_HANDS_ENABLE = no

ifneq ($(strip $(NO_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
        SRC += secrets.c
    endif
    ifeq ($(strip $(NO_SECRETS)), lite)
        OPT_DEFS += -DNO_SECRETS
    endif
endif

ifeq ($(strip $(MACROS_ENABLED)), yes)
    OPT_DEFS += -DMACROS_ENABLED
endif

EXTRAFLAGS += -flto
