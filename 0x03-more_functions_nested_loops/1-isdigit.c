#include "holberton.h"

/**
 * _isdigit - checks if a number is a digit from 0 to 9
 * @c: number to be checked
 *
 * Return: 1 if digit, 0 if otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
