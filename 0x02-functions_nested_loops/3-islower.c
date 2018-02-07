#include "holberton.h"

/**
 * _islower - checks if a character is lowercase
 * @c: the character to be checked
 *
 * Return: 1 if lowercase, 0 if not
 */
int _islower(int c)
{
	int m = 0;
	int k;

	for (k = 97; k < 123; k++)
	{
		if (k == c)
			m = 1;
	}
	return (m);
}
