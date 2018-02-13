#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * I apologize for the lack of spacing - holberton checker reqs
 *
 * Return: a pointer to the new string, or NULL if failure
 */
char *str_concat(char *s1, char *s2)
{
	char *array = NULL;
	char *array_cpy;
	int len = 0;
	char *s1_cpy = s1;
	char *s2_cpy = s2;

	if (s1 == NULL)
	{
		s1_cpy = malloc(sizeof(char));
		*s1_cpy = '\0';
	}
	if (s2 == NULL)
	{
		s2_cpy = malloc(sizeof(char));
		*s2_cpy = '\0';
	}
	array_cpy = s1_cpy;
	for (; *array_cpy != '\0'; len++)
		array_cpy++;
	array_cpy = s2_cpy;
	for (; *array_cpy != '\0'; len++)
		array_cpy++;
	array = malloc(sizeof(char) * (len + 1));
	if (array == NULL)
		return (NULL);
	array_cpy = array;
	while (*s1_cpy != '\0')
	{
		*array_cpy = *s1_cpy;
		array_cpy++;
		s1_cpy++;
	}
	while (*s2_cpy != '\0')
	{
		*array_cpy = *s2_cpy;
		array_cpy++;
		s2_cpy++;
	}
	*array_cpy = '\0';
	return (array);
}
