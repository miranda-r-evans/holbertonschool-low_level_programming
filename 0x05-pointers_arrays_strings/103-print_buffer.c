#include <stdio.h>

/**
 * print_buffer - print the contents of a buffer
 * and '.' for elements not printable
 * @b: buffer to be printed
 * @size: size of the buffer
 */
void print_buffer(char *b, int size)
{
	int i;
	int j;
	int k;
	int posit = 0;
	char *cpy = b;


	for (i = 0; i < size; i += 10)
	{
		printf("%#08x: ", posit);
		posit += 10;
		if (size - i < 10)
			k = size % 10;
		else
			k = 10;
		for (j = 0; j < k; j++, cpy++)
		{
			if (*cpy < 16)
				printf("0");
			printf("%0x", *cpy);
			if (j % 2 == 1)
				printf(" ");
		}
		for (; j < 10; j++)
		{
			printf("  ");
			if (j % 2 == 1)
				printf(" ");
		}
		cpy -= k;
		for (j = 0; j < k; j++, cpy++)
		{
			if (*cpy >= 32 && *cpy <= 126)
				printf("%c", *cpy);
			else
			printf(".");
		}
		printf("\n");
	}
}
