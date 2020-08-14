#pragma once
#include "bocaj.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
// #define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
#define WRAPPER_ergodox_pretty(...)          LAYOUT_ergodox_pretty(__VA_ARGS__)
// #define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
// #define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
// #define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
// #define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
// #define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)
#define WRAPPER_ortho_4x12(...)              LAYOUT_planck_mit(__VA_ARGS__)

/*
  Ergodox EZ Wrappers
*/
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
/*
  Planck EZ Wrappers
*/
#define WRAPPER_planck_bocaj( \
  K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, \
  K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, \
  K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C,  \
  K31, K32, K33, K34, K35,    K36,   K37, K38, K39, K3A, K3B  \
)\
  WRAPPER_ortho_4x12( \
    K01,       K02,        K03,        K04,            K05,        K06,         K07,            K08,        K09,        K0A,        K0B,  K0C, \
    K11,       K12,  SFT_T(K13), GUI_T(K14),     ALT_T(K15),       K16,         K17,     ALT_T(K18), GUI_T(K19), SFT_T(K1A),       K1B,  K1C, \
    K21, CTL_T(K22),       K23,        K24,            K25,        K26,         K27,            K28,        K29,        K2A,  CTL_T(K2B), K2C, \
    K31,       K32,        K33,        K34, LT(_LOWER, K35),              K36,       LT(_RAISE, K37),       K38,        K39,        K3A,  K3B )

#define WRAPPER_planck_bocaj_base( \
 K01, K02, K03, K04, K05,      K06, K07, K08, K09, K0A, \
 K11, K12, K13, K14, K15,      K16, K17, K18, K19, K1A, \
 K21, K22, K23, K24, K25,      K26, K27, K28, K29, K2A  \
) \
  WRAPPER_planck_bocaj( \
    KC_ESC,  K01,     K02,   K03,     K04,        K05,        K06,  K07,      K08,      K09,     K0A,     KC_MINS, \
    KC_TAB,  K11,     K12,   K13,     K14,  ALL_T(K15), MEH_T(K16), K17,      K18,      K19,     K1A,     KC_QUOT, \
    KC_LSFT, K21,     K22,   K23,     K24,        K25,        K26,  K27,      K28,      K29,     K2A,     KC_TRNS, \
    KC_LEAD, _______, KC_UP, KC_LEFT, KC_BSPC,          KC_SPC,      KC_ENTER, KC_RIGHT, KC_DOWN, KC_TRNS, KC_TRNS  \
  )

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________       KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________DVORAK_L1_________________        KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define _________________DVORAK_L2_________________        KC_A,    KC_O,    KC_E,   KC_U,     KC_I
#define _________________DVORAK_L3_________________        KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define _________________DVORAK_R1_________________        KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _________________DVORAK_R2_________________        KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define _________________DVORAK_R3_________________        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z


#define ________________DVORAK_AU_L1_______________        KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define ________________DVORAK_AU_L2_______________        KC_O,    KC_A,    KC_E,   KC_I,     KC_U
#define ________________DVORAK_AU_L3_______________        KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define ________________DVORAK_AU_R1_______________        KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define ________________DVORAK_AU_R2_______________        KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define ________________DVORAK_AU_R3_______________        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z

#define _________________WORKMAN_L1________________       KC_Q,    KC_D,    KC_R,   KC_W,     KC_B
#define _________________WORKMAN_L2________________       KC_A,    KC_S,    KC_H,   KC_T,     KC_G
#define _________________WORKMAN_L3________________       KC_Z,    KC_X,    KC_M,   KC_C,     KC_V

#define _________________WORKMAN_R1________________       KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN
#define _________________WORKMAN_R2________________       KC_Y,    KC_N,    KC_E,    KC_O,    KC_I
#define _________________WORKMAN_R3________________       KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________NORMAN_L1_________________       KC_Q,    KC_W,    KC_D,    KC_F,    KC_K
#define _________________NORMAN_L2_________________       KC_A,    KC_S,    KC_E,    KC_T,    KC_G
#define _________________NORMAN_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________NORMAN_R1_________________       KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN
#define _________________NORMAN_R2_________________       KC_Y,    KC_N,    KC_I,    KC_O,    KC_U
#define _________________NORMAN_R3_________________       KC_P,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________MALTRON_L1________________       KC_Q,    KC_P,    KC_Y,    KC_C,    KC_B
#define _________________MALTRON_L2________________       KC_A,    KC_N,    KC_I,    KC_S,    KC_F
#define _________________MALTRON_L3________________       KC_SCLN, KC_SLSH, KC_J,    KC_G,    KC_COMM

#define _________________MALTRON_R1________________       KC_V,    KC_M,    KC_U,    KC_Z,    KC_L
#define _________________MALTRON_R2________________       KC_D,    KC_T,    KC_D,    KC_O,    KC_R
#define _________________MALTRON_R3________________       KC_DOT,  KC_W,    KC_K,    KC_MINS, KC_X


#define _________________EUCALYN_L1________________       KC_SLSH, KC_COMM, KC_DOT,  KC_F,    KC_Q
#define _________________EUCALYN_L2________________       KC_A,    KC_O,    KC_E,    KC_I,    KC_U
#define _________________EUCALYN_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_W

#define _________________EUCALYN_R1________________       KC_M,    KC_R,    KC_D,    KC_Y,    KC_P
#define _________________EUCALYN_R2________________       KC_G,    KC_T,    KC_K,    KC_S,    KC_N
#define _________________EUCALYN_R3________________       KC_B,    KC_H,    KC_J,    KC_L,    KC_SCLN


#define _____________CARPLAX_QFMLWY_L1_____________       KC_Q,    KC_F,    KC_M,    KC_L,    KC_W
#define _____________CARPLAX_QFMLWY_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _____________CARPLAX_QFMLWY_L3_____________       KC_Z,    KC_V,    KC_G,    KC_C,    KC_X

#define _____________CARPLAX_QFMLWY_R1_____________       KC_Y,    KC_U,    KC_O,    KC_B,    KC_J
#define _____________CARPLAX_QFMLWY_R2_____________       KC_I,    KC_A,    KC_E,    KC_H,    KC_SCLN
#define _____________CARPLAX_QFMLWY_R3_____________       KC_P,    KC_K,    KC_COMM, KC_DOT,  KC_SLSH


#define _____________CARPLAX_QGMLWB_L1_____________       KC_Q,    KC_G,    KC_M,    KC_L,    KC_W
#define _____________CARPLAX_QGMLWB_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _____________CARPLAX_QGMLWB_L3_____________       KC_Z,   KC_X,    KC_C,    KC_F,    KC_J

#define _____________CARPLAX_QGMLWB_R1_____________       KC_B,    KC_Y,    KC_U,    KC_V,    KC_SCLN
#define _____________CARPLAX_QGMLWB_R2_____________       KC_I,    KC_A,    KC_E,    KC_O,    KC_H
#define _____________CARPLAX_QGMLWB_R3_____________       KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH


#define _____________CARPLAX_QGMLWY_L1_____________       KC_Q,    KC_G,    KC_M,    KC_L,    KC_W
#define _____________CARPLAX_QGMLWY_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _____________CARPLAX_QGMLWY_L3_____________       KC_Z,   KC_X,    KC_C,    KC_V,    KC_J

#define _____________CARPLAX_QGMLWY_R1_____________       KC_Y,    KC_F,    KC_U,    KC_B,    KC_SCLN
#define _____________CARPLAX_QGMLWY_R2_____________       KC_I,    KC_A,    KC_E,    KC_O,    KC_H
#define _____________CARPLAX_QGMLWY_R3_____________       KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________WHITE_R1__________________       KC_V,    KC_Y,    KC_D,    KC_COMM, KC_QUOT
#define _________________WHITE_R2__________________       KC_A,    KC_T,    KC_H,    KC_E,    KC_B
#define _________________WHITE_R3__________________       KC_P,    KC_K,    KC_G,    KC_W,    KC_Q

#define _________________WHITE_L1__________________       KC_INT1, KC_J,    KC_M,    KC_L,    KC_U
#define _________________WHITE_L2__________________       KC_MINS, KC_C,    KC_S,    KC_N,    KC_O  // KC_I
#define _________________WHITE_L3__________________       KC_X,    KC_R,    KC_F,    KC_DOT,  KC_Z


#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ___________________BLANK___________________        _______, _______, _______, _______, _______

#define _________________RAISE_L1__________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC
#define _________________RAISE_L2__________________        ________________NUMBER_LEFT________________
#define _________________RAISE_L3__________________        ___________________BLANK___________________

#define _________________RAISE_R1__________________        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _________________RAISE_R2__________________        ________________NUMBER_RIGHT_______________
#define _________________RAISE_R3__________________        ___________________BLANK___________________

#define _________________ADJUST_L1_________________        RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG
#define _________________ADJUST_L2_________________        KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT, MG_NKRO
#define _________________ADJUST_L3_________________        RGB_RMOD,RGB_HUD,RGB_SAD, RGB_VAD, KC_RGB_T

#define _________________ADJUST_R1_________________        ___________________BLANK___________________
#define _________________ADJUST_R2_________________        CG_SWAP, WORKMAN, QWERTY,  COLEMAK, DVORAK
#define _________________ADJUST_R3_________________        MU_TOG , CK_TOGG, AU_ON,   AU_OFF,  CG_NORM

// clang-format on
