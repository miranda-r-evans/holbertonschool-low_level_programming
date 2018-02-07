#include "holberton.h"

/**
 * swap_int - swap values of two ints
 * @a: value to be swapped
 * @b: value to be swapped
 */
void swap_int(int *a, int *b)
{
	int temp = *a;

	*a = *b;

	*b = temp;
}
