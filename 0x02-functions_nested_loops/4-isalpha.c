#include "holberton.h"

/**
 * _isalpha - checks if a character is a letter
 * @c: character to be checked
 *
 * Return: 1 if letter, 0 if otherwise
 */
int _isalpha(int c)
{
	int k;

	for (k = 97; k < 123; k++)
	{
		if (k == c)
			return (1);
	}
	for (k = 65; k < 91; k++)
	{
		if (k == c)
			return (1);
	}
	return (0);
}
