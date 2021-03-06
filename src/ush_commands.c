/*
 *  UselOS
 *  By M-374 LX <http://m374lx.users.sourceforge.net/>
 *  
 *  ush_commands.c - Implementation of each USH command
 */

#include "types.h"
#include "console.h"
#include "ioports.h"

void command_clear(u8 argc, char** argv)
{
	console_clear();
}

void command_echo(u8 argc, char** argv)
{
	u8 i;

	for (i = 1; i < argc; i++)
	{
		char* arg = argv[i];

		if (i > 1)
		{
			console_putch(' ');
		}

		console_print(argv[i]);
	}

	console_print("\n\n");
}

void command_help(u8 argc, char** argv)
{
	console_print("clear\necho\nhelp\nreboot\n\n");
}

void command_reboot(u8 argc, char** argv)
{
	while (inb(PS2_STATUS_PORT) & PS2_OUTPUT_FULL)
	{
	}

	outb(PS2_STATUS_PORT, CPU_REBOOT);
}
