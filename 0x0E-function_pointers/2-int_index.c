#include <stdio.h>
#include "function_pointers.h"

/**
 * int_index - when a function performed on elements of an array returns true,
 * return the index of that array element
 * @array: array of ints function is performed on
 * @size: size of array
 * @cmp: function performed on elements of array
 *
 * Return: index where cmp returns true, or -1 if it does not
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size == 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(*array) == 1)
			return (i);

		array++;
	}

	return (-1);
}
