#include "holberton.h"

/**
 * _memset - replace the bytes in a buffer with the constant byte b
 * n times
 * @s: buffer to be changed
 * @b: byte to replace bytes in buffer
 * @n: how many bytes to replace
 *
 * Return: pointer to buffer
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;
	char *ptr = s;

	for (i = 0; i < n; i++)
	{
		*s = b;
		s++;
	}

	return (ptr);
}
