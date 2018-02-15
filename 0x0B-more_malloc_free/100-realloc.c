#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr = NULL;
	char *ptr_cpy;
	unsigned int i;

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
		*ptr_cpy = *(char *)ptr;
		ptr_cpy++;
		ptr = ptr + sizeof(char);
	}

	free(ptr); //do i need to reset this first?

	return (new_ptr);
}
