#include <stdio.h>

/**
 * print_buffer - print the contents of a buffer
 * and '.' for elements not printable
 * @b: buffer to be printed
 * @size: size of the buffer
 */
void print_buffer(char *b, int size)
{
	char *end = b + size;
	int posit = 0;
	int i;

	if (size == 0)
		printf("\n");
	else
		while (b < end)
		{
			printf("%#08x: ", posit);
			posit += 10;

			for (i = 1; i <= 10; i++)
			{
				if (b < end && *b < 16)
					printf("0");
				if (b < end)
					printf("%0x", *b);
				if (i % 2 == 0)
					printf(" ");
				if (b >= end)
					printf("  ");
				b++;
			}
			b -= 10;

			for (i = 1; i <= 10; i++)
			{
				if (b < end && *b >= 32 && *b <= 126)
					printf("%c", *b);
				else if (b < end)
					printf(".");
				else
					break;
				b++;
			}
			printf("\n");
		}
}
