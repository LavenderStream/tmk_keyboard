#include "keymap_common.h"
#include "action_layer.h"

#define DEFAULT_LAYER 0
#define SHIFT_LAYER 1
#define FN_LAYER 2

const action_t PROGMEM fn_actions[32] = {
    [0] = ACTION_LAYER_TAP_KEY(FN_LAYER, KC_SPACE),
    [2] = ACTION_LAYER_MODS(SHIFT_LAYER, MOD_LSFT),
    //[5] = ACTION_BACKLIGHT_TOGGLE(),
    //[6] = ACTION_BACKLIGHT_DECREASE(),
    //[7] = ACTION_BACKLIGHT_INCREASE(),
};

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: Default layer */
    [DEFAULT_LAYER] = KEYMAP_ANSI(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  \
        FN2, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT, \
        LCTL,LGUI,LALT,          FN0,                     LEFT,DOWN,UP,  RGHT),
    /* 1: Shift layer: Shift + Esc -> Tilde */
    [SHIFT_LAYER] = KEYMAP_ANSI(
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
    /* 2: Fn layer */
    [FN_LAYER] = KEYMAP_ANSI(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,  \
        NO,  NO,  UP,  NO,  NO,  NO,  NO,  NO,  INS, NO,  PSCR,SLCK,PAUS,NO,   \
        TRNS,LEFT,DOWN,RGHT,ESC, GRV, LEFT,DOWN,UP,  RGHT,BSPC,NO,       TRNS, \
        TRNS,NO,  DEL, HOME,END, SPC, PGDN,PGUP,NO,  NO,  NO,            TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
};

/*
    KEYMAP_ANSI(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
*/
