#include "holberton.h"

/**
 * _strcmp - compare two string
 * @s1: string to be compared
 * @s2: string to be compared
 *
 * Return: difference between strings
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		else
		{
			s1++;
			s2++;
		}
	}

	return (0);
}
