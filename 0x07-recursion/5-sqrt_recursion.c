#include "holberton.h"

/**
 * count_to_sr - iterates from i to the square root of n
 * @n: number we find the square root of
 * @i: iterator to check for square root
 *
 * Return: i if square root, -1 if no natural square root
 */
int count_to_sr(int n, int i)
{
	if (i * i == n)
		return (i);

	if (i * i < n)
		return (count_to_sr(n, i + 1));

	if (i * i > n)
		return (-1);

	return (i);
}

/**
 * _sqrt_recursion - checks for edge cases and calls function to find
 * square root
 * @n: number we find the square root of
 *
 * Return: the square root, or -1 if no natural square root
 */
int _sqrt_recursion(int n)
{
	if (n == 1)
		return (1);

	if (n == 0)
		return (0);

	if (n < 0)
		return (-1);

	return (count_to_sr(n, 2));
}
