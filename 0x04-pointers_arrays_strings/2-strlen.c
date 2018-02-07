#include "holberton.h"

/**
 *  _strlen - returns length of a string
 * @s: string to be evaluated
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
