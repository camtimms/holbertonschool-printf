#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct format_specifiers - Struct to hold the format specifier and it's
 * associated function
 *
 * @c: The format specifier character
 * @f: The function associated
 */
typedef struct format_specifiers
{
	char c;
	int (*f)(va_list);
} format_s;

int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_percent(va_list args);

int (*get_print_func(char c))(va_list);

#endif
