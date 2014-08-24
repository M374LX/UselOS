/*
 *  UselOS
 *  By M-374 LX <http://m374lx.users.sourceforge.net/>
 *  
 *  keyboard.h - Functions to read the keyboard
 */

#ifndef USELOS_KEYBOARD
#define USELOS_KEYBOARD

#include "types.h"

enum
{
	KEY_LSHIFT = 0x89,
	KEY_RSHIFT = 0x89,
	KEY_LCTRL,
	KEY_LALT,

	KEY_CAPSLOCK,
	KEY_SCROLLLOCK,
	KEY_NUMLOCK,

	KEY_ESC,

	KEY_F1,
	KEY_F2,
	KEY_F3,
	KEY_F4,
	KEY_F5,
	KEY_F6,
	KEY_F7,
	KEY_F8,
	KEY_F9,
	KEY_F10,
	KEY_F11,
	KEY_F12,

	KEY_HOME,
	KEY_END,
	KEY_PGUP,
	KEY_PGDOWN,
	KEY_INS,
	KEY_DEL,

	KEY_UP,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_DOWN,
};

u8 keyboard_read();
u8 keyboard_map_entry(u8 key);

#endif

