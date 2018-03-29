#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  _strlen - returns length of a string
 * @s: string to be evaluated
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	if (s == NULL)
		return (0);

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: a pointer to the new string, or NULL if failure
 */
char *str_concat(char *s1, char *s2)
{
	int len = _strlen(s1) + _strlen(s2);
	char *dest = malloc(len + 1);
	char *ptr = dest;

	if (s1 != NULL)
	{
		while (*s1 != '\0')
		{
			*ptr = *s1;
			ptr++;
			s1++;
		}
	}

	if (s2 != NULL)
	{
		while (*s2 != '\0')
		{
			*ptr = *s2;
			ptr++;
			s2++;
		}
	}

	*ptr = '\0';

	return (dest);
}
