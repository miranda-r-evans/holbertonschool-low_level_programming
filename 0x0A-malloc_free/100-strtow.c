#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * find_words - helper function to find how many words in string
 * @str: string to be evaluated
 *
 * Return: number of words in string
 */
int find_words(char *str)
{
	int words = 0;

	while (*str == ' ')
		str++;

	while (*str != '\0')
	{
		if (*str == ' ')
		{
			*str = '\0';
			words++;
			str++;
			while (*str == ' ')
				str++;
		}
		else
			str++;
	}
	if (*(str - 1) != ' ')
		words++;

	return (words);
}

int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (-1);

	while (*s != '\0')
	{
		i++;
		s++;
	}

	return (i);
}

char *_strdup(char *old_str)
{
	char *new_str = malloc(_strlen(old_str) + 1);
	char *ptr;

	if (new_str == NULL)
		return (NULL);

	ptr = new_str;

	while (*old_str != '\0')
	{
		*ptr = *old_str;
		old_str++;
		ptr++;
	}

	*ptr = '\0';

	return (new_str);
}

/**
 * strtow - convert a string of words into an array of words
 * @str: string to be converted
 *
 * Return: a pointer to the array, or NULL if failure
 */
char **strtow(char *str)
{
	char **array;
	char **a_ptr;
	char *new_str;
	int len;
	int i;

	if (str == NULL || *str == '\0')
		return (NULL);

	new_str = _strdup(str);

	len = find_words(new_str);

	array = malloc(len + 1);
	if (array == NULL)
		return (NULL);

	a_ptr = array;

	while (*new_str == ' ')
		new_str++;

	*array = new_str;

	for (i = 1; i < len; i++)
	{
		while (*new_str != '\0')
			new_str++;

		new_str++;

		while (*new_str == ' ')
			new_str++;

		a_ptr++;

		*a_ptr = new_str;
	}

	a_ptr++;

	*a_ptr = NULL;

	return (array);
}
