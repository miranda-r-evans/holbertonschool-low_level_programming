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

/**
 * iterate_to_sr - check if the values until and including the square root of n
 * are factors of n
 * @n: the number from input from main we want to check if prime
 * @sr: approximate square root of n
 * @i: the iterator that we check n against
 *
 * Return: 1 if prime, 0 if not prime
 */
int iterate_to_sr(int n, int sr, int i)
{
	int j;

	if (i <= sr)
	{
		if (n % i == 0)
			return (0);

		j = iterate_to_sr(n, sr, i + 1);

		if (j == 0)
			return (0);
	}

	return (1);
}

/**
 * is_prime_number - checks to see if a number is prime
 * @n: input from main that we are checking
 *
 * Return: 1 if prime, 0 if not
 */
int is_prime_number(int n)
{
	int sr = _sqrt_recursion(n);

	if (n < 0)
		return (0);

	if (sr * sr == n)
		return (0);

	if (sr * sr != n)
		sr++;

	return (iterate_to_sr(n, sr, 2));
}
