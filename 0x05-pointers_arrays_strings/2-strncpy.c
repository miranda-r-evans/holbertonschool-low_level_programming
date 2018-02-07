#include "holberton.h"

/**
 * _strncpy - copy characters from src to dest until n characters
 * @dest: string that is being written
 * @src: string that is being copied
 * @n: number of characters from src to be copied
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;
	char *p = dest;

	for (i = 0; i < n; i++)
	{
		if (*src)
		{
			*dest = *src;
			src++;
		}
		else
		{
			*dest = '\0';
		}
		dest++;
	}

	return (p);
}
