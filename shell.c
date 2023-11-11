#include "shell.h"

/**
 * main - check the code
 *
 * Return: Always 0
 */

int main(void)
{
	char command[150];

	while (true)
	{
		drew_print("drew_shell$");
		read_command(command, sizeof(command));
		exec_command(command);
	}

	return (0);
}
