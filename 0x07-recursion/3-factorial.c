#include "holberton.h"

/**
 * factorial - returns the factorial of an int
 * @n: number to be evaluated
 *
 * Return: the factorial of n, or -1 if n is lower than 0
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);

	if (n > 1)
	{
		n *= factorial(n - 1);
	}

	return (n);
}
