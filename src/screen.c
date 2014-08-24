/*
 *  UselOS
 *  By M-374 LX <http://m374lx.users.sourceforge.net/>
 *  
 *  screen.c - Functions to access the screen directly
 */

#include "screen.h"

#define VIDEO_MEM ((u16*)0xB8000)

void screen_clear()
{
	u32 i;

	for (i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
	{
		VIDEO_MEM[i] = 0 | (DEFAULT_COLOR << 8);
	}
}

void screen_scrolldown()
{
	u16 i;

	for (i = 0; i < SCREEN_WIDTH * (SCREEN_HEIGHT - 1); i++)
	{
		VIDEO_MEM[i] = VIDEO_MEM[i + SCREEN_WIDTH];
	}

	for (; i < (SCREEN_WIDTH * SCREEN_HEIGHT); i++)
	{
		VIDEO_MEM[i] = 0 | (DEFAULT_COLOR << 8);
	}
}

void screen_setchar(u8 x, u8 y, char ch, u8 color)
{
	VIDEO_MEM[y * SCREEN_WIDTH + x] = ch | (color << 8);
}

