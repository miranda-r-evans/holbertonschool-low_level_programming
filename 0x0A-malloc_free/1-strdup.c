#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - allocates a space in memory for a copy of a string
 * @str: string a copy is made of
 *
 * Return: a pointer to the copy, or NULL if failure
 */
char *_strdup(char *str)
{
	char *array = NULL;
	char *array_cpy;

	if (str == NULL)
		return (NULL);

	array = malloc(sizeof(str));
	if (array == NULL)
		return (NULL);

	array_cpy = array;

	while (*str != '\0')
	{
		*array_cpy = *str;
		array_cpy++;
		str++;
	}

	return (array);
}
