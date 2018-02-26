#include "variadic_functions.h"

/**
 * pr_str - prints a string
 * @str: string to be printed
 */
void pr_str(char *str)
{
	if (str != NULL)
	{
		printf("%s", str);
		return;
	}

	printf("(nil)");
}

/**
 * print_all - prints all input
 * @format: format of the input
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *holder, *sep0 = "", *sep1 = ", ";

	if (format == NULL || *format == '\0')
		printf("(nil)");
	va_start(ap, format);
	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
			printf("%s", sep0);
			sep0 = sep1;
			printf("%c", (char)va_arg(ap, int));
			break;
		case 'i':
			printf("%s", sep0);
			sep0 = sep1;
			printf("%d", va_arg(ap, int));
			break;
		case 'f':
			printf("%s", sep0);
			sep0 = sep1;
			printf("%f", va_arg(ap, double));
			break;
		case 's':
			printf("%s", sep0);
			sep0 = sep1;
			holder = va_arg(ap, char *);
			pr_str(holder);
			break;
		default:
			break;
		}
		i++;
	}
	printf("\n");
	va_end(ap);
}
