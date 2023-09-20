#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_number_recursive - Recursively prints a number.
 * @n: The number to print.
 *
 * Return: The number of characters printed.
 */
int print_number_recursive(unsigned int n);

/**
 * print_number - Prints a number.
 * @args: The list of arguments.
 *
 * Return: The number of characters printed.
 */
int print_number(va_list args)
{
    int n = va_arg(args, int);
    unsigned int num;
    int count = 0;

    char c;

    if (n < 0)
    {
        count += write(1, "-", 1);
        num = -n;
    }
    else
        num = n;

    if (num / 10)
        count += print_number_recursive(num / 10);

    c = (char)(num % 10 + '0');
    count += write(1, &c, 1);

    return (count);
}

/**
 * print_number_recursive - Recursively prints a number.
 * @n: The number to print.
 *
 * Return: The number of characters printed.
 */
int print_number_recursive(unsigned int n)
{
    int count = 0;

    char c;

    if (n / 10)
        count += print_number_recursive(n / 10);

    c = (char)(n % 10 + '0');
    count += write(1, &c, 1);

    return (count);
}
