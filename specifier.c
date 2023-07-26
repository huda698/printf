#include "main.h"

/**
 * get_specifier - find format function.
 * @s: string.
 * Return: number of bytes.
 */

int (*get_specifier(char *s)) (va_list az, params_t *params)
{
	specifier_t specifier[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"u", print_unsigned},
		{"p", print_address},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifier[i].specifier)
	{
		if (*s == specifier[i].specifier[0])
		{
			return (specifier[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print - find format function.
 * @s: string.
 * @params: parameter struct.
 * @az: pointer argument.
 * Return: number of bytes.
 */

int get_print(char *s, va_list az, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(az, params));
	return (0);
}

/**
 * get_flag - find flags.
 * @s: string.
 * @params: parameter struct.
 * Return: flag.
 */

int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
		i = params->plus = 1;
		break;
		case '-':
		i = params->minus = 1;
		break;
		case '0':
		i = params->zero = 1;
		break;
		case ' ':
		i = params->space = 1;
		break;
		case '#':
		i = params->hashtag = 1;
		break;
	}
	return (i);
}

/**
 * get_modifier - find modifier.
 * @s: string.
 * @params: parameter struct.
 * Return: modifier.
 */

int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modif = 1;
			break;
		case 'l':
			i = params->l_modif = 1;
			break;
	}
	return (i);
}

/**
 * get_width - find the width.
 * @s: string.
 * @params: parameter struct.
 * @az: pointer argument.
 * Return: s.
 */

char *get_width(char *s, params_t *params, va_list az)
{
	int w = 0;

	if (*s == '*')
	{
		w = va_arg(az, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			w = w * 10 + (*s++ - '0');
	}
	params->width = w;
	return (s);
}
