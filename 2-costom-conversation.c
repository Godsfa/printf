#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable number of arguments
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            putchar(*format);
            printed_chars++;
        }
        else
        {
            format++;
            if (*format == '\0')
                break;

            if (*format == 'c')
            {
                char c = va_arg(args, int);
                putchar(c);
                printed_chars++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    putchar(*str);
                    str++;
                    printed_chars++;
                }
            }
            else if (*format == '%')
            {
                putchar('%');
                printed_chars++;
            }
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                int num_chars = 0;

              
                if (num < 0)
                {
                    putchar('-');
                    printed_chars++;
                    num = -num;
                }

               
                while (num > 0)
                {
                    int digit = num % 10;
                    putchar('0' + digit);
                    printed_chars++;
                    num /= 10;
                }

            
                if (num_chars == 0)
                {
                    putchar('0');
                    printed_chars++;
                }
            }
            else if (*format == 'b')
            {
              
                unsigned int num = va_arg(args, unsigned int);
                int binary_digits[32];
                int num_chars = 0;

                for (int i = 0; i < 32; i++)
                {
                    binary_digits[i] = num % 2;
                    num /= 2;
                    num_chars++;
                }

                for (int i = num_chars - 1; i >= 0; i--)
                {
                    putchar('0' + binary_digits[i]);
                    printed_chars++;
                }
            }
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}
