#include "shell.h"

/**
 * drew_print - print the information to the standard output
 * @info: string containing the information
 * Return: void
 */

void drew_print(const char *info)
{
	write(STDOUT_FILENO, info, strlen(info));
}
