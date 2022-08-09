#include "main.h"

/**
 * _printf: Returns format string
 * @format: A stirng containing all the desired characters
 */

void _printf(const char* format, ...)
{
	char *words;
	char *letters;
	char *iterate;
	va_list arg_list;

	va_start(arg_list, format);
	for (iterate = format; *iterate != '\0'; *iterate++)
	{
		if (*iterate == NULL)
		{
			return -1;
		}
		
		if (*iterate == '%')
		{
			*iterate++;
			switch (*iterate)
			{
				case 's':
					words = va_arg(arg_list, char*);
					while (*words != '\0')
					{
						output(*words++);
					}
				break;
				case 'c':
					letters = va_arg(arg_list, char*);
					output(*letters);
				break;
			}
		}
		else 
		{
			output(*ptr);
		}
	}
	va_end(arg_list);
}	
					

