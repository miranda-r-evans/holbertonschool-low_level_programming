#include <stdio.h>

/**
 * main - print 1 to 100, substituting Fizz for multiples of 3
 * and Buzz for multiples of 5
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
			printf("Fizz");
		if (i % 5 == 0)
			printf("Buzz");
		if (i % 3 != 0 && i % 5 != 0)
			printf("%d", i);
		if (i != 100)
			printf(" ");
	}
	printf("\n");

	return (0);
}
