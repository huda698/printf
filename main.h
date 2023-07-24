#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameter - parameters struct.
 *
 * @unsign: flag if unsigned value.
 * @plus: plus_flag specified.
 * @space: space_flag specified.
 * @hashtag: hash_flag specified.
 * @zero: zero_flag specified.
 * @minus: minus_flag specified.
 * @width: width specified.
 * @precision: precision specified.
 * @h_modif: h_modifier specified.
 * @l_modif: l_modifier specified.
 */

typedef struct parameter
{
	unsigned int unsign       : 1;
	unsigned int plus         : 1;
	unsigned int space        : 1;
	unsigned int hashtag      : 1;
	unsigned int zero         : 1;
	unsigned int minus        : 1;
	unsigned int width        : 1;
	unsigned int precision    : 1;
	unsigned int h_modif      : 1;
	unsigned int l_modif      : 1;
} params_t;

/**
 * struct specifier - struct token.
 *
 * @specf: format token.
 * @f: function associated.
 */

typedef struct specifier
{
	char *specf;
	int (*f)(va_list, params_t *);
} specf_t;

/* _put.c */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c */
int print_char(va_list az, params_t *params);
int print_int(va_list az, params_t *params);
int print_string(va_list az, params_t *params);
int print_percent(va_list az, params_t *params);
int print_S(va_list az, params_t *params);

/* number.c */
char *convert(long int num, int base, int flag, params_t *params);
int print_unsigned(va_list az, params_t *params);
int print_address(va_list az, params_t *params);

/* specifier.c */
int (*get_specifier(char *s)) (va_list az, params_t *params);
int get_print(char *s, va_list az, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list az);

/* convert_number.c */
int print_hex(va_list az, params_t *params);
int print_Hex(va_list az, params_t *params);
int print_binary(va_list az, params_t *params);
int print_octal(va_list az, params_t *params);

/* simple_printers.c */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list az, params_t *params);
int print_rot13(va_list az, params_t *params);

/* print_number.c */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int right_shift(char *str, params_t *params);
int left_shift(char *str, params_t *params);

/* params.c */
void init_params(params_t *params, va_list az);

/* string_fields.c */
char *get_precision(char *p, params_t *params, va_list az);

/* _printf.c */
int _printf(const char *format, ...);
#endif