#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
* _printf - Custom printf function
* @format: Format string
*
* Return: Number of characters printed (excluding the null byte)
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
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);

printed_chars += printf("%d", num);
}
else if (*format == '%')
{
putchar('%');
printed_chars++;
}
}
format++;
}

va_end(args);
return( printed_chars);
}
