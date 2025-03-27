#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 *_printf - Prints a string based on the format
 *
 * @format: String to format
 *
 * Description: Pritns a string and looks for the
 * format specifier '%' then uses the next character
 * to add in the additional arguments in order based
 * on the format specifier.
 *
 * Retrurn: Success (0), Failure (-1)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int (*print_function)(void *);
	int i = 0;

	if (!format)
		return(-1);

	va_start(args, format);
	
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			print_function = get_print_func(format[i + 1]);
			if (print_function == NULL)
				return (-1);
			print_function(va_arg(args, char *));
			
			i = i + 2;
		}
		else
		{	
			putchar(format[i]);
		}
		i++;
	}

	va_end(args);
	return (0);
}
