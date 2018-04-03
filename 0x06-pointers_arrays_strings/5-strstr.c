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
	char *ndPtr = needle;
	char *hayHold = haystack;

	while (*haystack != '\0')
	{
		nPtr = needle;
		haystack = hayHold;

		while (*nPtr != '\0')
		{
			if (*haystack == *nPtr)
			{
				nPtr++;
				haystack++;
			}
			else
				break;
		}

		if (*nPtr == '\0')
			return (hayHold);

		hayHold++;
	}

	return (NULL);
}
