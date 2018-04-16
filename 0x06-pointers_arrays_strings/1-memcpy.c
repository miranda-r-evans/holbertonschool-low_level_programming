#include "holberton.h"

/**
 * _memcpy - copy the bytes from one buffer to another
 * @dest: buffer where bytes are copied to
 * @src: buffer where bytes are copied from
 * @n: how many bytes to copy
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	char *ptr = dest;

	for (i = 0; i < n; i++)
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	return (dest);
}
