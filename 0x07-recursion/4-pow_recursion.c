#include "holberton.h"

/**
 * _pow_recursion - return x to the power of y
 * @x: number to be multiplied
 * @y: exponent
 *
 * Return: x to the power of y, or -1 if y is lower than 0
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);

	if (y == 0)
		return (1);

	if (y > 0)
		x *= _pow_recursion(x, y - 1);

	return (x);
}
