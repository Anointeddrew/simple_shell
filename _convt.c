#include "shell.h"


/**
 * _isinteract - returns true if shell is in interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */

int _isinteract(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimet - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */

int is_delimet(char c, char *delim)
{
	while (*delim)

		if (*delim++ == c)
			return (1);

	return (0);
}

/**
 * _alphabet - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _alphabet(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);

	else
		return (0);
}

/**
 * _stoint - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _stoint(char *s)
{
	int j, sign = 1, flag = 0, output;

	unsigned int result = 0;

	for (j = 0; s[j] != '\0' && flag != 2; j++)
	{
		if (s[j] == '-')
			sign *= -1;


		if (s[j] >= '0' && s[j] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;


	return (output);
}
