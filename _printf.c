#include "main.h"

/**
* _printf - Receives the main string and all the necessary parameters to
* print a formated string
* @format: A string containing all the desired characters
* Return: A total count of the characters printed
*/

int _printf(const char *format, ...)
{
	int to_print;
	changer Spec_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL}
	};
	va_list arg;

	if (format == NULL)
		return (-1);
	va_start(arg, format);

	to_print = parser(format, Spec_list, arg);
	va_end(arg);
	return (to_print);
}
