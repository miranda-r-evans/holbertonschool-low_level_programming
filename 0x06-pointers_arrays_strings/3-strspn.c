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
	char *accSt = accept;

	while (*s != '\0')
	{
		accept = accSt;
		while (*accept != '\0')
		{
			if (*s == *accept)
			{
				i++;
				break;
			}

			accept++;
		}
		if (*accept == '\0')
			return (i);

		s++;
	}

	return (i);
}
