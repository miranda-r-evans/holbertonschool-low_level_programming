#include <stdio.h>

/**
 * main - print first 50 Fibonacci
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	int i;
	long int j = 1;
	long int temp;
	long int k = 1;

	for (i = 0; i < 50; i++)
	{
		printf("%ld", j);
		if (i < 49)
			printf(", ");
		else
			printf("\n");

		temp = j;
		j = j + k;
		k = temp;
	}

	return (0);
}
