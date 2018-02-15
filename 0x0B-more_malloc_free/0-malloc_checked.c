#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * malloc_checked - allocated memory using malloc
 * @b: an int representing how much space to malloc
 *
 * Return: a pointer to the created space, or 98 if malloc fails
 */
void *malloc_checked(unsigned int b)
{
	int *a = NULL;

	a = malloc(b);

	if (a == NULL)
		exit(98);

	return (a);
}
