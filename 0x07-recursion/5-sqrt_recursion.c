#include "holberton.h"

/**
 * stop - find the value of input from main minus the square root of input
 * @stop_value: a value to be checked for the desired stopping point
 * @i: incremented value used to find stopping point
 *
 * Return: 1 if stopping point is found, -1 if stop_value is not the value we
 * want to stop at
 */
int stop(int stop_value, int i)
{
	if (i * (i - 1) < stop_value)
		i = stop(stop_value, i + 1);

	if (i == 1)
		return (1);

	if (i * (i - 1) == stop_value)
		return (1);

	if (i * (i - 1) > stop_value)
		return (-1);

	return (-1);
}

/**
 * find_sr - finds the square root of input from main, or the next lowest
 * square root if input does not have a natural square root
 * @n: input number to be evaluated
 *
 * Return: square root
 */
int find_sr(int n)
{
	int i;
	int j = 1;

	if (n == 0)
		return (0);
	else if (n < 0)
		return (-1);

	i = stop(n, 2);

	if (i == 1)
		return (0);

	j += find_sr(n - 1);

	return (j);
}

/**
 * _sqrt_recursion - finds the square root of a number
 * @n: number we find the square root of
 *
 * Return: square root, or -1 if no natural square root
 */
int _sqrt_recursion(int n)
{
	int i = find_sr(n);

	if (i > 0 && i * i == n)
		return (i);
	else if (i > 0 && i * i != n)
		return (-1);
	else
		return (i);
}
