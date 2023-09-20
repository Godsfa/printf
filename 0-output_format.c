#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - Prints a character.
 * @args: The list of arguments.
 *
 * Return: The number of characters printed.
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (write(1, &c, 1));
}

/**
 * print_string - Prints a string.
 * @args: The list of arguments.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int i;

    if (!str)
        str = "(null)";

    for (i = 0; str[i]; i++)
        ;

    return (write(1, str, i));
}
