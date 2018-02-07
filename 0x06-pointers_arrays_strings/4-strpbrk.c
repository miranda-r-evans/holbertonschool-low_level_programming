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
	char *accSt = accept;

	while (*s != '\0')
	{
		accept = accSt;
		while (*accept != '\0')
		{
			if (*s == *accept)
				return (s);

			accept++;
		}

		s++;
	}

	return (NULL);
}
