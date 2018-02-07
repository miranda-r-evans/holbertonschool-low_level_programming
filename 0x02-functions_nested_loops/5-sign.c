#include "holberton.h"

/**
 * print_sign - prints the sign of a number
 * @c: number to be evaluated
 *
 * Return: 1 if positive, 0 if zero, -1 if negative
 */
int print_sign(int c)
{
	int rval;

	if (c > 0)
	{
		_putchar('+');
		rval = 1;
	}
	else if (c == 0)
	{
		_putchar('0');
		rval = 0;
	}
	else if (c < 0)
	{
		_putchar('-');
		rval = -1;
	}

	return (rval);
}
