#include "holberton.h"

/**
 * reverse_array - reverse an array of ints
 * @a: the array to be reversed
 * @n: number of elements in array
 */
void reverse_array(int *a, int n)
{
	int *start = a;
	int temp;
	int i;

	for (i = 0; i < n; i++)
	{
		a++;
	}
	a--;

	while (a > start)
	{
		temp = *start;
		*start = *a;
		*a = temp;
		start++;
		a--;
	}
}
