# **Prototype**

```c
#include "main.h"
int _printf(const char *format, ...);
```

# DESCRIPTION

The _printf function is a custom implementation of the standard C printf function. It processes format specifiers in a string and outputs the corresponding values to the standard output (stdout).

It supports a limited set of format specifiers and does not handle advanced printf features like width, precision, or flag characters. It processes simple format specifiers such as %c, %s, %d, and %i, and prints them accordingly.

# FORMAT SPECIFIERS

%s: Print a string.

%%: Print a literal percent sign.

%d: Print a decimal (base 10) integer.

%i: Print an integer in decimal (base 10). This specifier is treated the same as %d.

# FUNCTION DETAILS

`_printf` - Print formatted output

```c
int _printf(const char *format, ...);
```

**Parameters**:

- `format`: A string containing zero or more format specifiers.
- `...`: A variable number of arguments corresponding to the format specifiers in the `format` string.
- **Return**:
    - Returns the number of characters printed (excluding the null byte used to end the string).
    - Returns `1` if an invalid format specifier is encountered.
- **Description**:
`_printf` processes the format string, looking for format specifiers. It then fetches the corresponding arguments and prints them in the correct format. Unsupported specifiers will return `1`.

`print_c` - Print a character

```c
int print_c(va_list args);
```

- **Parameters**:
    - `args`: The variadic argument list, which holds a character to print.
- **Return**:
    - Returns `0` after printing the character.
- **Description**:
This function prints an ASCII character passed as a variadic argument.

`print_s` - Print a string

```c
int print_s(va_list args);
```

- **Parameters**:
    - `args`: The variadic argument list, which holds a string to print.
- **Return**:
    - Returns `0` after printing the string.
- **Description**:
This function prints a string. If the string is `NULL`, it prints `(null)` instead.

`print_percent` - Print a percent sign (`%`)

```c
int print_percent(va_list args);
```

- **Parameters**:
    - `args`: The variadic argument list (not used in this function, but kept to maintain consistency).
- **Return**:
    - Returns `0` after printing the percent sign.
- **Description**:
This function prints the `%` character.

`print_d` - Print a decimal (base 10) integer

```c
int print_d(va_list args);
```

- **Parameters**:
    - `args`: The variadic argument list, which holds an integer to print.
- **Return**:
    - Returns the number of digits printed.
- **Description**:
This function prints an integer in base 10. It handles negative integers by printing the  sign and converting the number to its positive counterpart for easier processing. It uses a divisor method to print each digit of the integer.

`print_i` - Print an integer in decimal (base 10)

```c
int print_i(va_list args);
```

- **Parameters**:
    - `args`: The variadic argument list, which holds an integer to print.
- **Return**:
    - Returns the number of digits printed.
- **Description**:
This function prints an integer in base 10. It is identical to `print_d`, as `%i` and `%d` are treated the same.

`get_print_func` - Get the appropriate print function for a format specifier

```c
int (*get_print_func(char c))(va_list);
```

- **Parameters**:
    - `c`: A character representing a format specifier (e.g., `%c`, `%s`, `%d`).
- **Return**:
    - Returns a pointer to the function that handles the given format specifier.
    - If no matching specifier is found, it returns `NULL`.
- **Description**:
This function returns the corresponding function pointer for the format specifier `c` by searching an array of format-specifier-function pairs.

## EXAMPLES

```c
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    _printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    _printf("Unknown:[%r]\n");
    return (0);
}
```

```csharp
Expected Output:

Let's try to printf a simple sentence.
Length:[39, 39]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
String:[I am a string !]
Address:[0x7ffe637541f0]
Percent:[%]
Len:[12]
Unknown:[%r]
```

## COMPILATION

To compile the program, you can use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format main.h test_main.c format_specifiers.c _printf.c -o printf_test
```

## AUTHOR

This implementation was created by Cam Timms and William Rennie, contributed by Tas as part of a project for learning purposes and is not a part of the standard C library.

## LICENSE

This projects code is free to use and modify under the MIT License.

SEE ALSO
printf (3) - Standard C library function for formatted output
stdarg.h - Standard header for handling variadic functions
