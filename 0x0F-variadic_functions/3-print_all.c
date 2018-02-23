#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_all - prints all input
 * @format: format of the input
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
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
		if (format[i + 1] != '\0' && _bool == 0)
			printf(", ");

		_bool = 0;
		i++;
	}
	printf("\n");

	va_end(ap);
}
