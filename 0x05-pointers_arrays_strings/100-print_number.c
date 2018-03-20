#include "holberton.h"
#include <limits.h>

#define TRUE 1
#define FALSE 0

/**
 * print_number - prints and int to stdout
 * @n: int to be printed
 */
void print_number(int n)
{
	int is_min = FALSE;
	int i_mask = 1000000000;
	int digit = 0;

	if (n == INT_MIN)
	{
		_putchar('-');
		n = INT_MAX;
		is_min = TRUE;
	}

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	while (i_mask > 9 && digit == 0)
	{
		digit = n / i_mask;
		n %= i_mask;
		i_mask /= 10;
	}

	if (digit != 0)
		_putchar(digit + '0');

	while (i_mask > 9)
	{
		digit = n / i_mask;
		_putchar(digit + '0');
		n %= i_mask;
		i_mask /= 10;
	}

	if (is_min == TRUE)
		n += 1;

	_putchar(n + '0');
}
