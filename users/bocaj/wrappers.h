#pragma once
#include "bocaj.h"

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
// #if (!defined(LAYOUT) && defined(KEYMAP))
// #    define LAYOUT KEYMAP
// #endif

// /* Keymap Wrapper Helpers */

// #define KEYMAP_wrapper(...) LAYOUT(__VA_ARGS__)
// #define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

// MARK: Ergodox
#define WRAPPER_ergodox_pretty(...) LAYOUT_ergodox_pretty(__VA_ARGS__)

#define WRAPPER_ergodox_bocaj(                                           \
    L00,L01,L02,L03,L04,L05,L06,           R00,R01,R02,R03,R04,R05,R06,  \
    L10,L11,L12,L13,L14,L15,L16,           R10,R11,R12,R13,R14,R15,R16,  \
    L20,L21,L22,L23,L24,L25,                   R21,R22,R23,R24,R25,R26,  \
    L30,L31,L32,L33,L34,L35,L36,           R30,R31,R32,R33,R34,R35,R36,  \
    L40,L41,L42,L43,L44,                           R42,R43,R44,R45,R46,  \
                            L55,L56,   R50,R51,                          \
                                L54,   R52,                              \
                        L53,L52,L51,   R55,R54,R53 )                     \
  WRAPPER_ergodox_pretty( \
      L00,       L01,        L02,        L03,        L04,  L05, L06,                R00,  R01,       R02,        R03,        R04,       R05,  R06, \
      L10,       L11,        L12,        L13,        L14,  L15, L16,                R10,  R11,       R12,        R13,        R14,       R15,  R16, \
      L20,       L21,  SFT_T(L22), GUI_T(L23), ALT_T(L24), L25,                           R21, ALT_T(R22), GUI_T(R23), SFT_T(R24),      R25,  R26, \
      L30, CTL_T(L31),       L32,        L33,        L34,  L35, ALL_T(L36),   MEH_T(R30), R31,       R32,        R33,        R34, CTL_T(R35), R36, \
      L40,       L41,        L42,        L43,        L44,                                            R42,        R43,        R44,       R45,  R46, \
                                                         L55,L56, /* <- LHS/RHS -> */ R50,R51,                                                     \
                                                             L54, /* <- LHS/RHS -> */ R52,                                                         \
                                         LT(_LOWER, L53),L52,L51, /* <- LHS/RHS -> */ R55,R54,LT(_RAISE, R53)                                      \
)

// MARK: Planck
#define WRAPPER_ortho_4x12(...) LAYOUT_ortho_4x12(__VA_ARGS__)

#define WRAPPER_planck_bocaj( \
  K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, \
  K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, \
  K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C,  \
  K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C  \
)\
  WRAPPER_ortho_4x12( \
    K01,       K02,        K03,        K04,        K05,        K06,        K07,        K08,             K09,        K0A,        K0B,  K0C, \
    K11,       K12,  SFT_T(K13), GUI_T(K14), ALT_T(K15), ALL_T(K16), MEH_T(K17), ALT_T(K18),      GUI_T(K19), SFT_T(K1A),       K1B,  K1C, \
    K21, CTL_T(K22),       K23,        K24,        K25,        K26,        K27,        K28,             K29,        K2A,  CTL_T(K2B), K2C, \
    K31, ALL_T(K32),       K33,        K34,  LT(_LOWER, K35),  K36,        K37,  LT(_RAISE, K38),       K39,        K3A,  MEH_T(K3B), K3C \
  )

/* Keymap Blocks */

// Standard Block Length: ___________________________________________________________
#define ________________QWERTY_LHS1________________ KC_Q, KC_W, KC_E, KC_R, KC_T
#define ________________QWERTY_LHS2________________ KC_A, KC_S, KC_D, KC_F, KC_G
#define ________________QWERTY_LHS3________________ KC_Z, KC_X, KC_C, KC_V, KC_B

#define ________________QWERTY_RHS1________________ KC_Y, KC_U, KC_I, KC_O, KC_P
#define ________________QWERTY_RHS2________________ KC_H, KC_J, KC_K, KC_L, KC_SCLN
#define ________________QWERTY_RHS3________________ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH

#define _______________WORKMAN_LHS_1_______________ KC_Q, KC_D, KC_R, KC_W, KC_B
#define _______________WORKMAN_LHS_2_______________ KC_A, KC_S, KC_H, KC_T, KC_G
#define _______________WORKMAN_LHS_3_______________ KC_Z, KC_X, KC_M, KC_C, KC_V

#define _______________WORKMAN_RHS_1_______________ KC_J, KC_F, KC_U, KC_P, KC_SCLN
#define _______________WORKMAN_RHS_2_______________ KC_Y, KC_N, KC_E, KC_O, KC_I
#define _______________WORKMAN_RHS_3_______________ KC_K, KC_L, KC_COMM, KC_DOT, KC_SLASH


#define ________________NUMBERS_LHS________________ KC_1, KC_2, KC_3, KC_4, KC_5
#define ________________NUMBERS_RHS________________ KC_6, KC_7, KC_8, KC_9, KC_0
#define ________________SYMBOLS_LHS________________ KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT
#define ________________SYMBOLS_RHS________________ KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN

// Transparent Blocks
#define ________________________ERGO_THUMBS________________________ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
