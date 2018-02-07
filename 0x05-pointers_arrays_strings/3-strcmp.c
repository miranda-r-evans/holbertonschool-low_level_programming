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
	int r = 0;

	while (*s1 || *s2)
	{
		if (*s1 != *s2)
		{
			r = *s1 - *s2;
			break;
		}
		else
		{
			s1++;
			s2++;
		}
	}

	return (r);
}
