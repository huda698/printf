#include "main.h"

/**
 * _isdigit - checkes digit.
 * @c: character.
 * Return: 1 (digit), 0 (otherwise).
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - calculate the length of string.
 * @s: string.
 * Return: length of string.
 */

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - print numbers.
 * @str: string.
 * @params: parameter struct.
 * Return: number printed.
 */

int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int ng = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (ng)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (ng)
		*--str = '-';
	if (!params->minus)
	{
		return (right_shift(str, params));
	}
	else
	{
		return (left_shift(str, params));
	}
}

/**
 * right_shift - print right shift numbers.
 * @str: string.
 * @params: parameter string.
 * Return: number printed.
 */

int right_shift(char *str, params_t *params)
{
	unsigned int i = _strlen(str), ng, ng1, n = 0;
	char pad = ' ';

	if (params->zero && !params->minus)
		pad = '0';
	ng = ng1 = (!params->unsign && *str == '-');
	if (ng && i < params->width && pad == '0' && !params->minus)
		str++;
	else
		ng = 0;
	if ((params->plus && !ng1) || (!params->plus && params->space && !ng1))
		i++;
	if (ng && pad == '0')
		n += _putchar('-');
	if (params->plus && !ng1 && pad == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus && params->space && !ng1 &&
			!params->unsign && params->zero)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad);
	if (ng && pad == ' ')
		n += _putchar('-');
	if (params->plus && !ng1 && pad == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus && params->space && !ng1 &&
			!params->unsign && !params->zero)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * left_shift - print left shift numbers.
 * @str: string.
 * @params: parameter struct.
 * Return: number printed.
 */

int left_shift(char *str, params_t *params)
{
	unsigned int i = _strlen(str), ng, ng1, n = 0;
	char pad = ' ';

	if (params->zero && !params->minus)
		pad = '0';
	ng = ng1 = (!params->unsign && *str == '-');
	if (ng && i < params->width && pad == '0' && !params->minus)
		str++;
	else
		ng = 0;
	if (params->plus && !ng1 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space && !ng1 && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad);
	return (n);
}
