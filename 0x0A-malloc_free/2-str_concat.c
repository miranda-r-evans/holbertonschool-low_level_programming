#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: a pointer to the new string, or NULL if failure
 */
char *str_concat(char *s1, char *s2)
{
	char *array = NULL;
	char *array_cpy;

	if (s1 == NULL)
		*s1 = '\0';

	if (s2 == NULL)
		*s2 = '\0';

	array = malloc(sizeof(s1) + sizeof(s2));
	if (array == NULL)
		return (NULL);
	array_cpy = array;

	while (*s1 != '\0')
	{
		*array_cpy = *s1;
		array_cpy++;
		s1++;
	}

	while (*s2 != '\0')
	{
		*array_cpy = *s2;
		array_cpy++;
		s2++;
	}

	*array_cpy = '\0';

	return (array);
}
