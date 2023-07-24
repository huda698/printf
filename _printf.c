#include "main.h"

/**
 * _printf - prints everything.
 *
 * @format: string format.
 *
 * Return: number of bytes.
 */

int _printf(const char *format, ...)
{
	int net = 0;
	va_list az;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(az, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, az);
		if (*p != '%')
		{
			net += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
			p++;
		p = get_width(p, &params, az);
		p = get_precision(p, &params, az);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			net += print_from_to(start, p,
					params.l_modif || params.h_modif ? p - 1 : 0);
		else
			net += get_print(p, az, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(az);
	return (net);
}
