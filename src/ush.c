/*
 *  UselOS
 *  By M-374 LX <http://m374lx.users.sourceforge.net/>
 *  
 *  ush.c - USH, the command shell
 */

#include "types.h"

#include "console.h"
#include "keyboard.h"

#define NUM_COMMANDS		4
#define MAX_COMMAND_LENGTH	32
#define MAX_COMMAND_ARGS	16
#define MAX_ARG_LENGTH		8

//Prototypes of the commands, implemented in "ush_commands.c"
void command_clear(u8 argc, char** argv);
void command_echo(u8 argc, char** argv);
void command_help(u8 argc, char** argv);
void command_reboot(u8 argc, char** argv);

u8 strcmp(char* str1, char* str2)
{
	u8 i;

	while (1)
	{
		if (str1[i] != str2[i])
		{
			return 1;
		}

		if (str1[i] == 0 || str2[i] == 0)
		{
			break;
		}

		i++;
	}

	return 0;
}

//Returns the offset from which the next argument should be read
u8 read_arg(char* src, char* dst)
{
	u8 offset = 0;

	while (*src == ' ')
	{
		src++;
		offset++;
	}

	while (*src != ' ' && *src != 0)
	{
		*dst = *src;

		src++;
		dst++;
		offset++;
	}

	*dst = 0;

	return offset;
}

void execute_command(char* command)
{
	const struct
	{
		char* command;
		void (*func)(u8 argc, char** argv);
	} COMMANDS[] =
	{
		"clear", command_clear,
		"echo", command_echo,
		"help", command_help,
		"reboot", command_reboot
	};

	u8 arg = 0;
	u8 arg_start = 0;
	char args[MAX_COMMAND_ARGS + 1][MAX_ARG_LENGTH];

	while (1)
	{
		arg_start += read_arg(&command[arg_start], args[arg]);

		if (args[arg][0] == 0)
		{
			break;
		}

		arg++;
	}

	console_putch('\n');

	if (args[0][0] != 0)
	{
		u8 argc;
		char* argv[MAX_COMMAND_ARGS];
		u8 i;

		for (i = 0; i < MAX_COMMAND_ARGS; i++)
		{
			if (args[i][0] == 0)
			{
				break;
			}

			argv[i] = args[i];
		}

		argc = i;

		for (i = 0; i < NUM_COMMANDS; i++)
		{
			if (strcmp(args[0], COMMANDS[i].command) == 0)
			{
				COMMANDS[i].func(argc, argv);
				break;
			}
		}

		if (i >= NUM_COMMANDS)
		{
			console_print("Invalid command: ");
			console_print(args[0]);
			console_print("\n\n");
		}
	}

	console_print("Command: ");
}

void ush_main()
{
	u8 last_key = 0;

	char command[MAX_COMMAND_LENGTH + 1] = "";
	u8 command_length = 0;

	console_setcolor(COLOR_LIGHT_GREY);
	console_print("Welcome to USH, the useless command shell\n");
	console_print("For a list of commands, type \"help\"\n\nCommand: ");

	while (1)
	{
		u8 key = keyboard_read();

		if (key > 0 && key < 0x80 && key != last_key)
		{
			u8 map_entry = keyboard_map_entry(key);

			if (map_entry == '\n')
			{
				command[command_length] = 0;

				execute_command(command);

				command_length = 0;
			}
			else if (map_entry == '\b')
			{
				if (command_length > 0)
				{
					command_length--;
					command[command_length] = 0;

					console_putch(map_entry);
				}
			}
			else if (map_entry >= 0x20 && map_entry <= 0x7E)
			{
				if (command_length < MAX_COMMAND_LENGTH)
				{
					command[command_length] = map_entry;
					command_length++;

					console_putch(map_entry);
				}
			}
		}

		last_key = key;
	}
}

