#include "main.h"

/**
 * print_char - prints character
 * @az: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list az, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(az, int);

	if (params->minus)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->miuns)
		sum += _putchar(ch);
	return (sum);
}



/**
 * print_int - prints integer
 * @az: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list az, params_t *params)
{
	long l;

	if (params->l_modif)
		l = va_arg(az, long);
	else if (params->h_modif)
		l = (short int)va_arg(az, int);
	else
		l = (int)va_arg(az, int);
	return (print_numbers(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @az: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list az, params_t *params)
{
	char *str = va_arg(az, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
	case 1:
		str = NULL_STRING;

		j = pad = _strlen(str);
		if (params->precision < pad)
			j = pad = params->precision;

		if (params->minus)
		{
			if (params->precision != UINT_MAX)
				for (i = 0, i < pad; i++)
					sum += _putchar(*str++);
			else
				sum += _puts(str);
		}
		while (j++ < params->width)
			sum += _putchar(pad_char);
		if (!params->minus)
		{
			if (params->precision != UINT_MAX)
				for (i = 0; i < pad; i++)
					sum += _putchar(*str++);
			else
				sum += _puts(str);
		}
		return (sum);
}

/**
 * print_percent - prints string
 * @az: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list az, params_t *params)
{
	(void)az;
	(void)params;
	return (_putchar('%'));
}


/**
 * print_S - custom format specifier
 * @az: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list az, params_t *params)
{
	char *str = va_arg(az, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar ('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}

	}
	return (sum);
}
