#ifndef MAIN_H
#define MAIN_H

/**
 * struct format - Struct format
 *
 * @c: The format specifier character
 * @f: The function associated
 */
typedef struct format
{
	char c;
	int (*f)(void *);
}format;

int _printf(const char *format, ...);
int print_c(int n);
int print_s(char *s);
int print_percent(void);

int (*get_print_func(char c))(char *);

#endif
