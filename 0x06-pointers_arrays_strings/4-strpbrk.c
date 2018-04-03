#include "holberton.h"
#define NULL ((void*)0)

/**
 * _strpbrk - find the first occurrence of a byte from string accept
 * in string s
 * @s: string to be evaluated
 * @accept: string of matching bytes
 *
 * Return: pointer to first occurrence, or pointer to NULL if none
 */
char *_strpbrk(char *s, char *accept)
{
	char *ptr = accept;

	while (*s != '\0')
	{
		ptr = accept;
		while (*ptr != '\0')
		{
			if (*s == *ptr)
				return (s);

			ptr++;
		}

		s++;
	}

	return (NULL);
}
