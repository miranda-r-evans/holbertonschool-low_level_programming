#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_numbers - prints input values, with a separator
 * @separator: string to print between values
 * @n: number of values to print
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	const char *sep = "";

	if (n == 0)
		exit(0);

	if (separator != NULL)
		sep = separator;

	va_start(ap, n);

	for (i = 1; i < n; i++)
	{
		printf("%d%s", va_arg(ap, int), sep);
	}
	printf("%d\n", va_arg(ap, int));

	va_end(ap);
}
