#include "main.h"

/**
 * init_params - clear fields and reset buf.
 *
 * @params: struct parameters.
 *
 * @az: argument pointer.
 */

void init_params(params_t *params, va_list az)
{
	params->unsign = 0;
	params->plus = 0;
	params->space = 0;
	params->hashtag = 0;
	params->zero = 0;
	params->minus = 0;
	params->width = 0;
	params->precision = UINT_MAX;
	params->h_modif = 0;
	params->l_modif = 0;
	(void)az;
}
