#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _calloc - creates an array and initializes it to 0
 * @nmemb: how many elements in array
 * @size: size of elements in array
 *
 * Return: pointer to array, or NULL if failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr = NULL;
	char *ptr_cpy;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	ptr_cpy = ptr;

	for (i = 0; i < nmemb * size; i++)
	{
		*ptr_cpy = 0;
		ptr_cpy++;
	}

	return (ptr);
}
