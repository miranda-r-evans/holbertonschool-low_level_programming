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
	if (n < 0)
		return (-1);

	i = stop(n, 2);

	if (i == 1)
		return (0);

	j += find_sr(n - 1);

	return (j);
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
	int sr = find_sr(n);

	if (n < 0)
		return (0);

	if (sr * sr == n)
		return (0);
	if (sr * sr != n)
		sr++;

	return (iterate_to_sr(n, sr, 2));
}
