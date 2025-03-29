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
 * print_i - Converts hexadecimal and octal numbers and prints them
 *
 * @args: Varidatic argument which can contain decimal, octal or hexdecimal
 * numbers
 *
 * Description: Converts hexadecimal and octal numbers and prints them.
 * kstrtoint converts any base number to a decimal int.
 * Return: Length of characters printed (i) or fail (-1)
 */

int print_i(va_list args)
{
	char *input_num = va_arg(args, char *);
	int num = 0;
	int scan_check = 0;
	int i = 0;
	int divisor = 1;
	unsigned int n;
	unsigned int temp;

	/* Convert base to decimal */
	if (!input_num)
		return (-1);
	if (input_num[0] == '0' && input_num[1] == 'x')
		scan_check = sscanf(input_num, "%x", &num);
	else if (input_num[0] == '0' && input_num[1] != '\0')
		scan_check = sscanf(input_num, "%o", &num);
	else
		scan_check = sscanf(input_num, "%d", &num);
	if (scan_check != 1)
		return (-1);

	/* Print decimal int */
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
