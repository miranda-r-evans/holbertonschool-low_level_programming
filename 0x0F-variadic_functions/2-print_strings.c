#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_strings - prints string from input
 * @separator: separator printed inbetween input
 * @n: number of inputs to print
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	char *holder;
	const char *sep = "";

	if (n == 0)
		exit(0);

	if (separator != NULL)
		sep = separator;

	va_start(ap, n);

	for (i = 1; i < n; i++)
	{
		holder = va_arg(ap, char *);
		if (holder != NULL)
			printf("%s%s", holder, sep);
		else
			printf("(nil)%s", sep);
	}

	holder = va_arg(ap, char *);
	if (holder != NULL)
		printf("%s\n", holder);
	else
		printf("(nil)\n");

	va_end(ap);
}
