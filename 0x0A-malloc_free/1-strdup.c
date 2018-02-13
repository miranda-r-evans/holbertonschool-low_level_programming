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
	char *array_cpy = str;
	int len;

	if (str == NULL)
		return (NULL);

	for (len = 0; *array_cpy != '\0'; len++)
	{
		array_cpy++;
	}

	array = malloc(sizeof(char) * (len + 1));
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
