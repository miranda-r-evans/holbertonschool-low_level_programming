#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * len_finder - finds length of input strings
 * @s1: first string to be evaluated
 * @s2: second string to be evaluated, until n characters
 * @n: limit on how many characters from s2 need to be evaluated
 *
 * Return: length of s1 and at least part of s2
 */
int len_finder(char *s1, char *s2, unsigned int n)
{
	int len = 0;
	unsigned int i;

	if (s1 != NULL)
	{
		for (len = 0; *s1 != '\0'; len++)
			s1++;
	}

	if (s2 != NULL)
	{
		for (i = 0; *s2 != '\0' && i < n; len++)
		{
			i++;
			s2++;
		}
	}

	return (len);
}

/**
 * string_nconcat - concatenates two strings
 * @s1: string to be concatenated
 * @s2: string to be concatenated, up to n characters
 * @n: limit on how many characters from s2 to be copied
 *
 * Return: pointer to new string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str = NULL;
	char *ptr;
	int len;
	unsigned int i;

	len = len_finder(s1, s2, n);

	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);

	ptr = str;

	if (s1 != NULL)
	{
		while (*s1 != '\0')
		{
			*ptr = *s1;
			ptr++;
			s1++;
		}
	}

	if (s2 != NULL)
	{
		for (i = 0; *s2 != '\0' && i < n; i++)
		{
			*ptr = *s2;
			ptr++;
			s2++;
		}
	}

	*ptr = '\0';

	return (str);
}
