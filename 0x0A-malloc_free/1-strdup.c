#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strlen - finds length of a string
 * @s: string to be measured
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);

	while (*s != '\0')
	{
		i++;
		s++;
	}

	return (i);
}

/**
 * _strdup - allocates a space in memory for a copy of a string
 * @str: string a copy is made of
 *
 * Return: a pointer to the copy, or NULL if failure
 */
char *_strdup(char *str)
{
	char *new_str = NULL;
	char *new_ptr;
	int len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);

	new_ptr = new_str;

	while (*str != '\0')
	{
		*new_ptr = *str;
		new_ptr++;
		str++;
	}

	*new_ptr = '\0';

	return (new_str);
}
