#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "holberton.h"

/**
 * custom_printf - Custom printf function.
 * @format: The format string.
 * @...: The list of arguments.
 *
 * Return: The number of characters printed.
 */
int custom_printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'c')
                count += print_char(args);
            else if (format[i] == 's')
                count += print_string(args);
            else if (format[i] == 'd' || format[i] == 'i')
                count += print_number(args);
            else
            {
                write(1, &format[i - 1], 1);
                write(1, &format[i], 1);
                count += 2;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}
