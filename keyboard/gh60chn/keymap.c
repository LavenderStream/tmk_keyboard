#include "keymap_common.h"
#include "action_layer.h"

#define DEFAULT_LAYER 0
#define SHIFT_LAYER 1
#define FN_LAYER 2

enum function_id {
    FN_KEY_DEFAULT_LAYER,
    FN_KEY_FN_LAYER,
};

const action_t PROGMEM fn_actions[32] = {
    [0] = ACTION_FUNCTION(FN_KEY_DEFAULT_LAYER),
    [1] = ACTION_FUNCTION(FN_KEY_FN_LAYER),
    [2] = ACTION_LAYER_MODS(SHIFT_LAYER, MOD_LSFT),
    [5] = ACTION_BACKLIGHT_TOGGLE(),
    [6] = ACTION_BACKLIGHT_DECREASE(),
    [7] = ACTION_BACKLIGHT_INCREASE(),
};

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: Default layer */
    [DEFAULT_LAYER] = KEYMAP_ANSI(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
        FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  \
        FN2, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          UP,   \
        LCTL,LGUI,LALT,          SPC,                     FN0, LEFT,DOWN,RGHT),
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
        FN1, LEFT,DOWN,RGHT,NO,  NO,  LEFT,DOWN,UP  ,RGHT,HOME,PGUP,     TRNS, \
        TRNS,NO,  NO,  FN6, FN5, FN7, NO,  NO,  NO,  END, PGDN,          RSFT, \
        TRNS,TRNS,TRNS,          TRNS,                    FN1, RALT,RGUI,RCTL),
};

inline static void layer_set(uint8_t layer, bool state) {
    if (state) layer_on(layer);
    else layer_off(layer);
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    static bool fn_locked = false;
    bool pressed = record->event.pressed;

    switch (id) {
    case FN_KEY_DEFAULT_LAYER:
        if (!fn_locked) {
            layer_set(FN_LAYER, pressed);
        } else {
            if (pressed) {
                fn_locked = false;
                layer_off(FN_LAYER);
                // LED off
                DDRB &= ~(1<<2);
                PORTB &= ~(1<<2);
            }
        }
        break;
    case FN_KEY_FN_LAYER:
        if (!fn_locked) {
            if (pressed) {
                fn_locked = true;
                layer_on(FN_LAYER);
                // LED on
                DDRB |= (1<<2);
                PORTB &= ~(1<<2);
            }
        } else {
            layer_set(FN_LAYER, !pressed);
        }
        break;
    }
}

/*
void hook_late_init(void) {
    xprintf("hook_late_init: %d\n", layer_state);
}
void hook_layer_change(uint32_t layer_state) {
    xprintf("hook_layer_change: %d\n", layer_state);
}
*/

/*
    KEYMAP_ANSI(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
*/
