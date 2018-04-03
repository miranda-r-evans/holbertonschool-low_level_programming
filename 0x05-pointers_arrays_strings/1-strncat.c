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
	char *ptr = dest;

	while (*ptr != '\0')
	{
		ptr++;
	}

	for (i = 0; i < n; i++)
	{
		if (*src != '\0')
		{
			*ptr = *src;
			ptr++;
			src++;
		}
	}

	*ptr = '\0';

	return (dest);
}
