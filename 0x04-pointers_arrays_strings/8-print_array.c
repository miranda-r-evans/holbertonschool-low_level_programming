#include "holberton.h"
#include <stdio.h>

/**
 * print_array - print n elements of an array
 * @a: array to be printed
 * @n: number of elements to be printed
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", *a);
		if (i < n - 1)
			printf(", ");
		a++;
	}
	printf("\n");
}
