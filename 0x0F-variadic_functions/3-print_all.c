#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * sep_printer - prints separators between inputs
 * @format: format of inputs
 * @j: index of format
 * @_bool: determines if loop should run
 */
void sep_printer(const char * const format, unsigned int j, int _bool)
{
	while (format[j] != '\0' && _bool == 0)
	{
		if (format[j] == 'c' || format[j] == 'i' ||
		     format[j] == 'f' || format[j] == 's')
		{
			printf(", ");
			break;
		}
		j++;
	}
}

/**
 * print_all - prints all input
 * @format: format of the input
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	unsigned int j;
	char *holder;
	int _bool = 0;

	va_start(ap, format);
	while (format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
			printf("%c", (char)va_arg(ap, int));
			break;
		case 'i':
			printf("%d", va_arg(ap, int));
			break;
		case 'f':
			printf("%f", va_arg(ap, double));
			break;
		case 's':
			holder = va_arg(ap, char *);
			if (holder != NULL)
				printf("%s", holder);
			else
				printf("(nil)");
			break;
		default:
			_bool = 1;
			break;
		}
		j = i + 1;
		sep_printer(format, j, _bool);
		_bool = 0;
		i++;
	}
	printf("\n");

	va_end(ap);
}
