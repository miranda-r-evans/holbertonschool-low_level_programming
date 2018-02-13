#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_array - create an array of size size, initialized with a char c
 * @size: size of the array
 * @c: character array is initialized with
 *
 * Return: a pointer to the array, or NULL is failure
 */
char *create_array(unsigned int size, char c)
{
	char *array = NULL;
	unsigned int i;
	char *array_cpy;

	if (size == 0)
		return (NULL);

	array = malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);
	array_cpy = array;

	for (i = 0; i < size; i++)
	{
		*array_cpy = c;
		array_cpy++;
	}

	return (array);
}
