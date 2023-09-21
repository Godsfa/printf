#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>

int print_char(va_list args);
int print_string(va_list args);
int print_number(va_list args);
int print_number_recursive(unsigned int n);
int custom_printf(const char *format, ...);

#endif
