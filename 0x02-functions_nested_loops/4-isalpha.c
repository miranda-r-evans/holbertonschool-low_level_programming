#include "holberton.h"

/**
 * _isalpha - checks if a character is a letter
 * @c: character to be checked
 *
 * Return: 1 if letter, 0 if otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);

	return (0);
}
