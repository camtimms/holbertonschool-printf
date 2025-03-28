#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_func_null - Prints characters as normal if print_function fails
 *
 * @format: Original string
 * @i: Index
 *
 * Description: Prints the characters as normal if get_print_func doesn't find
 * a format specifier character
 *
 * Return: Number of charactes printed. Always (2)
 */

int print_func_null(const char *format, int i)
{
	putchar(format[i]);
	putchar(format[i + 1]);
	return (2);

}

/**
 *_printf - Prints a string based on the format
 *
 * @format: String to format
 *
 * Description: Prints a string and looks for the
 * format specifier '%' then uses the next character
 * to add in the additional arguments in order based
 * on the format specifier.
 *
 * Return: Success (strlen), Failure (-1)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int (*print_function)(va_list);
	int print_len;
	int i = 0;
	int strlen = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			print_function = get_print_func(format[i + 1]);
			if (print_function == NULL)
			{
				print_len = print_func_null(format, i);
			}
			else
				print_len = print_function(args);
			
			if (print_len < 0)
				return (-1);
			i += 2;
			strlen += print_len;
		}
		else
		{
			putchar(format[i]);
			i++;
			strlen++;
		}
	}
	va_end(args);
	return (strlen);
}
