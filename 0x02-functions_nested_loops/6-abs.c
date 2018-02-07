#include "holberton.h"

/**
 * _abs - returns absolute value of a number
 * @c: number to be evaluated
 *
 * Return: the absolute value
 */
int _abs(int c)
{
	if (c > -1)
		return (c);
	else
		return (c * -1);
}
