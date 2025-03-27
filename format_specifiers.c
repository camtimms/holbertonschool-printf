#include "main.h"
#include <stdio.h>

/**
* print_c - Print an ASCII chacater
*
* @args: Variadic argument of a ASCII Character
*
* Description: Prints an ASCII chacater using an input of a variadic argument
* and casting it to an int which putchar can use to print
* Return: Success (0)
*/
int print_c(va_list args)
{
	char c = va_arg(args, int);

	putchar(c);
	return (0);
}

/**
* print_s - Print a string
*
* @args: Variadic argument list containing a string
*
* Description: Prints a string (s) by casting it from a varadic argument list
* Return: Success (0)
*/
int print_s(va_list args)
{
	char *s = va_args(args, char *);
	int i;

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
		putchar(s[i]);

	return (0);
}


/**
* print_percent - Print a percent sign
*
* Description: Prints a percent sign (%)
* Return: Success (0)
*/
int print_percent(void)
{
	(void)args;
	putchar('%');
	return (0);
}

/**
* get_print_func - Function pointer to find the right function to use
*
* @c: Format specifier character from printf string argument
*
* Description: Goes through an array and returns the matching function to the
* format specifer
* Return: Success (0)
*/
int (*get_print_func(char c))(char *)
{
	format_s print_f[] = {
	{'c', (int (*)(void *))print_c},
	{'s', print_s},
	{'%', print_percent},
	{'\0', NULL}
	};

	int i = 0;

	while (print_f[i].c != '\0')
	{
		if (c == print_f[i].c)
			return (print_f[i].f);
		i++;
	}

	return (NULL);
}

