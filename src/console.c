/*
 *  UselOS
 *  By M-374 LX <http://m374lx.users.sourceforge.net/>
 *
 *  console.c - Funcions that implement a typical console
 */

#include "console.h"

#include "types.h"
#include "ioports.h"

//Position of the cursor in the screen
static u32 cursor_x;
static u8  cursor_y;

static u8 color;

void _update_cursor_pos()
{
	u16 pos = cursor_y * SCREEN_WIDTH + cursor_x;

	outb(0x3D4, 0x0F);
	outb(0x3D5, (u8)(pos & 0xFF));

	outb(0x3D4, 0x0E);
	outb(0x3D5, (u8)((pos >> 8) & 0xFF));
}

void console_clear()
{
	screen_clear();

	cursor_x = 0;
	cursor_y = 0;

	color = DEFAULT_COLOR;

	_update_cursor_pos();
}

void console_setcolor(u8 c)
{
	color = c;
}

void console_putch(char ch)
{
	if (ch == '\n')
	{
		cursor_x = 0;
		cursor_y++;
	}
	else if (ch == '\b')
	{
		if (cursor_x > 0)
		{
			cursor_x--;

			screen_setchar(cursor_x, cursor_y, 0, color);
		}
	}
	else
	{
			screen_setchar(cursor_x, cursor_y, ch, color);

			cursor_x++;

			if (cursor_x >= SCREEN_WIDTH)
			{
				cursor_x -= SCREEN_WIDTH;
				cursor_y++;
			}
	}

	if (cursor_y >= SCREEN_HEIGHT)
	{
		cursor_y = SCREEN_HEIGHT - 1;
		screen_scrolldown();
	}

	_update_cursor_pos();
}

void console_print(const char* str)
{
	u32 i = 0;

	while (str[i] != 0)
	{
		console_putch(str[i]);
		i++;
	}
}

