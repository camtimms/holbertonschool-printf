#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
* get_print_func - Function pointer to find the right function to use
*
* @c: Format specifier character from printf string argument
*
* Description: Goes through an array and returns the matching function to the
* format specifer
* Return: Success (0)
*/
int (*get_print_func(char c))(va_list)
{
        format_s print_f[] = {
        {'c', print_c},
        {'s', print_s},
        {'%', print_percent},
        {'d', print_d},
        {'i', print_i},
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
