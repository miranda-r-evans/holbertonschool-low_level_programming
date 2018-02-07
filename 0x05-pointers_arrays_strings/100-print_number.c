#include "holberton.h"

/**
 * check_neg - prints a '-' if negative and returns absolute value
 * @n: number to be checked
 *
 * Return: absolute value of n as an unsigned int
 */
unsigned int check_neg(int n)
{
	unsigned int x;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	x = n;

	return (x);
}

/**
 * make_i - obtain value for i
 * @x: the number that the value of i will be based on
 *
 * Return: the value of i
 */
unsigned int make_i(unsigned int x)
{
	unsigned int i = 1;

	while (i < x)
	{
		if (i < 1000000000)
			i *= 10;
		else
			break;
	}

	return (i);
}

/**
 * print_number - print an int
 * @n: int to be printed
 */
void print_number(int n)
{
	unsigned int i;
	unsigned int j;
	unsigned int x;
	unsigned int k;

	unsigned int check_neg(int n);
	unsigned int make_i(unsigned int x);

	x = check_neg(n);

	i = make_i(x);

	if (x >= 1000000000)
	{
		_putchar(x / 1000000000 + '0');
		_putchar((x % 1000000000) / 100000000 + '0');
	}
	k = i;

	while (i > 1)
	{
		if (i == x)
			j = x / i;
		else if (i == k)
			j = (x / (i / 10));
		else
			j = (x % i) / (i / 10);

		if (j <= 9)
			_putchar(j + '0');
		if (i == x || x == 0)
			_putchar(0 + '0');
		i = i / 10;
	}
	if (x == 0)
		_putchar(0 + '0');
	if (x == 1)
		_putchar(1 + '0');
}
