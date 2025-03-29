#include "main.h"
#include <stdio.h>
#include <stdlib.h>

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
	return (1);
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
	char *s = va_arg(args, char *);
	int i;

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
		putchar(s[i]);

	return (i);
}


/**
* print_percent - Print a percent sign
*
* @args: Variadic argument which to keep inputs in struct consistant and
* so argument is incremented when this is encountered
*
* Description: Prints a percent sign (%)
* Return: Success (0)
*/
int print_percent(va_list args)
{
	(void) args;
	putchar('%');
	return (1);
}

/**
 * print_d - Prints an integer
 *
 * @args: Variadic argument which contains an int
 *
 * Description: Prints an base 10 integer
 * Return: Length of digits printed (i)
 */

int print_d(va_list args)
{

	int num = va_arg(args, int);
	int i = 0;
	unsigned int n;
	unsigned int temp = num;
	int divisor = 1;

	if (num < 0)
	{
		putchar('-');
		n = -((unsigned int) num);
		i++;
	}
	else
		n = num;

	temp = n;

	while (temp / divisor >= 10)
		divisor = divisor * 10;

	while (divisor > 0)
	{
		putchar((n / divisor) + '0');
		n %= divisor;
		divisor = divisor / 10;
		i++;
	}
	return (i);
}

/**
 * print_i - Passes the int into print_d
 *
 * @args: Varidatic argument which can contain decimal, octal or hexdecimal
 * numbers
 *
 * Description: Hex and Oct nums are already converted to decimal on
 * compilation.so no conversion needs to be done. Function just calls and
 * passes args to print_d.
 * Return: Length of characters printed (i) or fail (-1)
 */

int print_i(va_list args)
{
	return (print_d(args));
}
