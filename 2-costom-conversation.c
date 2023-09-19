#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
* print_binary - Prints the binary representation of an unsigned integer
* @num: The unsigned integer to print in binary
*
* Return: The number of characters printed
*/

int print_binary(unsigned int num)
{
int count = 0;
int bits[32];
int i;

if (num == 0)
return (putchar('0'));

while (num > 0)
{
bits[count++] = num % 2;
num /= 2;
}

for (i = count - 1; i >= 0; i--)
{
putchar(bits[i] + '0');
}

return (count);
}

