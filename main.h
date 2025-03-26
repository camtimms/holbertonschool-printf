#ifndef MAIN_H
#define MAIN_H

/**
 * struct format - Struct format
 *
 * @format_c: The format specifier character
 * @f: The function associated
 */
typedef struct format
{
	char *format_c;
	int (*f)(int a, int b);
};

int _printf(const char *format, ...);
char *convert_c(int n);
char *convert_s(char *s);
char *convert_percent(void);

char *(*get_print_func(char c))(void);

#endif
