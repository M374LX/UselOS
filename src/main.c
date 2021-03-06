/*
 *  UselOS
 *  By M-374 LX <http://m374lx.users.sourceforge.net/>
 *  
 *  main.c - The entry point after "start.s"
 */

#include "types.h"

#include "ioports.h"
#include "console.h"
#include "screen.h"

void ush_main();

void main()
{
	const char* welcome =
	"Welcome to UselOS, the useless operating system\n"
	"Written by M-374 LX <http://m374lx.users.sourceforge.net/>\n\n";

	console_clear();

	console_setcolor(COLOR_GREEN);
	console_print(welcome);

	ush_main();
}

