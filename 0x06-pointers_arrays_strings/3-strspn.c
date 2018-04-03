#include "holberton.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to be evaluated
 * @accept: characters in the prefix
 *
 * Return: length of the prefix substring
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0;
	char *ptr = accept;

	while (*s != '\0')
	{
		ptr = accept;
		while (*ptr != '\0')
		{
			if (*s == *ptr)
			{
				i++;
				break;
			}

			ptr++;
		}
		if (*ptr == '\0')
			return (i);

		s++;
	}

	return (i);
}
