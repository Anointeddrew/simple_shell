#include "shell.h"

/**
 * read_command - reads command received
 * @command: command to be read
 * @size: size of string of command
 * Return: void
 */

void read_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			drew_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			drew_print("error while reading inputs\n");
			exit(EXIT_FAILURE);
		}
	}

	command[strcspn(command, "\n")] = '\0';
}
