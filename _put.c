#include "main.h"

/**
 * _puts - print string with new line.
 *
 * @str: string.
 *
 * Return: the length of string.
 */

int _puts(char *str)
{
	char *c = str;

	while (*str)
		_putchar(*str++);
	return (str - c);
}

/**
 * _putchar - print character to stdout.
 *
 * @c: character.
 *
 * Return: 1 (Success), -1 (Error).
 */

int _putchar(int c)
{
	static int j;
	static char buff[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || j >= OUTPUT_BUF_SIZE)
	{
		write(1, buff, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buff[j++] = c;
	return (1);
}
