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
 * Retrurn: Success (0)
 */
 
int _printf(const char *format, ...)
{
    va_list = args;
    int (*get_print_func(char *s))(char *);
    int i = 0;
    
    va_start(args, format);
    
    while(format[i] != '\0')
    {
        if (format[i] == '%')
        {
            print_function = get_print_func(format[i + 1]);
            print_function(args);
        }
        i++;
    }
    
    
    
    va_end(args);
    
    
    return (0);
}
