#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

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
 * Return: Success (0), Failure (-1)
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
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			print_function = get_print_func(format[i + 1]);
			if (print_function == NULL)
				return (-1);

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