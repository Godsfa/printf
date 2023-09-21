#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: The variable number of arguments
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            putchar(*format);
            count++;
        }
        else
        {
            format++;
            if (*format == 'd')
            {
                int num = va_arg(args, int);
                printf("%d", num);
                count++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                printf("%s", str);
                count += strlen(str);
            }
            else if (*format == '%')
            {
                putchar('%');
                count++;
            }
          
        }
        format++;
    }

    va_end(args);
    return count;
}
