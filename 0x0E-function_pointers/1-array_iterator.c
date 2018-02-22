#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - performs a function on each member of an array
 * @array: array of elements to be evaluated
 * @size: size of array
 * @action: function to be performed on array elements
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array != NULL && size != 0 && action != NULL)
	{
		for (i = 0; i < size; i++)
		{
			action(*array);
			array++;
		}
	}
}
