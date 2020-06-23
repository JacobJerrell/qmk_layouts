#pragma once

/* Personal Configuration */
#define LEADER_TIMEOUT 250
#define LEADER_PER_KEY_TIMING

#define IGNORE_MOD_TAP_INTERRUPT
#define PREVENT_STUCK_MODIFIERS
#define PERMISSIVE_HOLD
#undef RETRO_TAPPING

/* Save firmware space */
#ifndef NO_DEBUG
    #define NO_DEBUG
#endif // !NO_DEBUG

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
    #define NO_PRINT
#endif // !NO_PRINT

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Disable unused and unneeded features to reduce on firmware size */
#ifdef LOCKING_SUPPORT_ENABLE
#    undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#    undef LOCKING_RESYNC_ENABLE
#endif
