#include "holberton.h"
#define NULL ((void*)0)

/**
 * _strchr - finds the first occurence of a character in a string
 * @s: string to be evaluated
 * @c: character to be searched for
 *
 * Return: pointer to first occurrence of c
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);

		s++;
	} while (*(s - 1) != '\0');

	return (NULL);
}
