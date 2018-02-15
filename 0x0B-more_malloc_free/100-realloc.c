#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _realloc - reallocates memory that has previously been malloc'd
 * @ptr: old ptr we are reallocating
 * @old_size: size of old memory we are reallocating
 * @new_size: size of new memory we want to reallocate
 *
 * Return: pointer to new memory, or NULL if failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr = NULL;
	char *ptr_cpy;
	unsigned int i;
	char *old_ptr = (char *)ptr;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	if (ptr == NULL)
		return (new_ptr);

	ptr_cpy = new_ptr;

	for (i = 0; i < old_size; i++)
	{
		*ptr_cpy = *old_ptr;
		ptr_cpy++;
		old_ptr++;
	}

	free(ptr);

	return (new_ptr);
}
