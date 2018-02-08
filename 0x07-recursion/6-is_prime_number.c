#include "holberton.h"

/**
 * up_to_sr - iterates up to the approximate square root and checks if i is
 * a factor of n
 * @n: the number we are checking if prime
 * @i: the iterator we are checking for being the approximate square root of
 * or factor of n
 *
 * Return: 1 if prime, 0 if not
 */
int up_to_sr(int n, int i)
{
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
	if (i * i < n)
		return (up_to_sr(n, i + 1));

	return (1);
}

/**
 * is_prime_number - checks for edge cases and calls the square root/ factor
 * function
 * @n: the number we are checking if prime
 *
 * Return: 1 if prime, 0 if not
 */
int is_prime_number(int n)
{
	if (n == 1)
		return (0);
	if (n == 0)
		return (0);
	if (n < 0)
		return (0);

	return (up_to_sr(n, 2));
}
