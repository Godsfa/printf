#include "main.h"

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
_printf("Let's try to printf a simple sentence.\n");
_printf("Negative:[%d]\n", -762534);
_printf("Character:[%c]\n", 'H');
_printf("String:[%s]\n", "I am a string !");
_printf("Unknown:[%r]\n");
_printf("%b\n", 98);
return (0);
}
