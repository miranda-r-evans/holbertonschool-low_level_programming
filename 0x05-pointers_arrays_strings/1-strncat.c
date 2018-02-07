#include "holberton.h"

/**
 * _strncat - concatenate strings until second string reaches n characters
 * @dest: first string, appended to
 * @src: second string, appended onto dest
 * @n: how many characters of src will be appended to dest
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	char *p = dest;

	while (*dest)
	{
		dest++;
	}

	for (i = 0; i < n; i++)
	{
		if (*src)
		{
			*dest = *src;
			dest++;
			src++;
		}
	}
	*dest = '\0';

	return (p);
}
