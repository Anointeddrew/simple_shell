#include "shell.h"

/**
 * exec_command - executes command passed
 * @command: string containing the command
 * Return: void
 */

void exec_command(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		drew_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *args[150];
		int arg_count = 0;

		char *token = strtok((char *)command, " ");

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count = NULL];

		execlp(args[0], args);

		drew_print("Error executing command.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
