#include "main.h"
#include <stdio.h>
#include <stdarg.h>

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
	va_list = args;
	int (*get_print_func(char *s))(char *);
	int i = 0;

	if (!format)
		exit(98);

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != NULL)
		{
			print_function = get_print_func(format[i + 1]);
			if (print_function == NULL)
				exit(98);
			print_function(va_arg(args, char *));
			
			i = i + 2;
		}
		i++;
		putchar(format[i]);
	}

	va_end(args);
	return (0);
}
