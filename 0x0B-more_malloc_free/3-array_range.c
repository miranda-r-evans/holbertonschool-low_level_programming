#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * array_range - creates an array of ints from min to max
 * @min: minimum value in array
 * @max: maximum value in array
 *
 * Return: pointer to array, or NULL if failure
 */
int *array_range(int min, int max)
{
	int *ptr = NULL;
	int *ptr_cpy;

	if (min > max)
		return (NULL);

	ptr = malloc(sizeof(int) * (max - min + 1));

	if (ptr == NULL)
		return (NULL);

	ptr_cpy = ptr;

	for (; min <= max; min++)
	{
		*ptr_cpy = min;
		ptr_cpy++;
	}

	return (ptr);
}
