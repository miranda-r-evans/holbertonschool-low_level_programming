#include <stdio.h>

/**
 * print_diagsums - print the diagonal sums of a square, multidimensional array
 * @a: array to be evaluated
 * @size: the number of rows or columns in the array
 */
void print_diagsums(int *a, int size)
{
	int n;
	long int i = 0;
	long int j = 0;
	int *j_array = a + size - 1;

	for (n = 0; n < size; n++)
	{
		i += *a;
		j += *j_array;
		a += size + 1;
		j_array += size - 1;
	}

	printf("%ld, %ld\n", i, j);
}
