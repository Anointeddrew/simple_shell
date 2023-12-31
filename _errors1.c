#include "shell.h"

/**
 * _errstoint - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */

int _errstoint(char *s)
{
	int j = 0;
	unsigned long int outcome = 0;

	if (*s == '+')
		s++;/* why does this make main return 255? */
                 	for (j = 0; s[j] != '\0'; j++)

			{
				if (s[j] >= '0' && s[j] <= '9')
				{
					outcome *= 10;
					outcome += (s[j] - '0');
					if (outcome > INT_MAX)
						return (-1);
				}
				else
					return (-1);
			}
	return (outcome);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */

void print_error(info_t *info, char *estr)
{
	print_inputs(info->fname);
	print_inputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	print_inputs(": ");
	print_inputs(info->argv[0]);
	print_inputs(": ");
	print_inputs(estr);
}

/**
 * print_deci - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */

int print_deci(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + current / j);
			count++;
		}
		current %= j;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_num - converter function
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */

char *convert_num(long int num, int base, int flags)
{
	static char *array;
	static char buffer[65];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
		} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */

void remove_comments(char *buf)
{
	int j;

	for (j = 0; buf[j] != '\0'; j++)
		if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
		{
			buf[j] = '\0';
			break;
		}
}
