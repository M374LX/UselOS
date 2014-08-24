/*
 *  UselOS
 *  By M-374 LX <http://m374lx.users.sourceforge.net/>
 *
 *  console.h - Funcions that implement a typical console
 */

#ifndef USELOS_CONSOLE
#define USELOS_CONSOLE

#include "types.h"

#include "screen.h"

void console_clear();

void console_setcolor(u8 c);

void console_putch(char ch);
void console_print(const char* str);

#endif

