#include "main.h"

/**
 * parser - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @function_list: A list of all the posible functions.
 * @arg: A list containing all the argumentents passed to the program.
 * Return: A total count of the characters printed.
 */
int parser(const char *format, conver_t function_list[], va_list arg)
{
	int i, j, r_val, to_print;

	to_print = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%') 
		{
			for (j = 0; function_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == function_list[j].sym[0])
				{
					r_val = function_list[j].f(arg);
					if (r_val == -1)
						return (-1);
					to_print += r_val;
					break;
				}
			}
			if (function_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					output(format[i]);
					output(format[i + 1]);
					to_print = to_print + 2;
				}
				else
					return (-1);
			}
			i = i + 1; 
		}
		else
		{
			output(format[i]); 
			to_print++;
		}
	}
	return (to_print);
}
