#include "holberton.h"
#define NULL ((void*)0)

/**
 * _strstr - find one string inside another string
 * @haystack: string in which a substring is found
 * @needle: substring that is searched for
 *
 * Return: pointer to location of needle inside haystack, or NULL if none
 */
char *_strstr(char *haystack, char *needle)
{
	char *ndSt = needle;
	char *hayHold = haystack;

	while (*haystack != '\0')
	{
		needle = ndSt;
		haystack = hayHold;
		while (*needle != '\0')
		{
			if (*haystack == *needle)
			{
				needle++;
				haystack++;
			}
			else
				break;
		}
		if (*needle == '\0')
			return (hayHold);
		hayHold++;
	}

	return (NULL);
}
