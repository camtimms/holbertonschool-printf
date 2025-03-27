#include "main.h"
#include <stdio.h>

/**
* print_c - Print an ASCII chacater
*
* @n: ASCII value
*
* Description: Prints an ASCII chacater using
* Return: Success (0)
*/
int print_c(int n)
{
	putchar(n);
	return (0);
}

/**
* print_s - Print a string
*
* @s: Input string
*
* Description: Prints a string (s)
* Return: Success (0)
*/
int print_s(char *s)
{
	int i;

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
		putchar(*s);

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
	putchar('%');
	return (0);
}

/**
* get_print_func - Function pointer to find the right function to use
*
* @s: Format specifier character from printf string argument
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
		if (*s == *print_f[i].c) 
			return (print_f[i].f);
		i++;
	}

	return (NULL);
}

