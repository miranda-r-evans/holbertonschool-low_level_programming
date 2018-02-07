#include "holberton.h"

/**
 * _strcat - concatenate two strings
 * @dest: first string, appended to
 * @src: second string, appended from
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*dest)
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (p);
}
