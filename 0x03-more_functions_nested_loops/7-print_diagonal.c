#include "holberton.h"

/**
 * print_diagonal - uses a backslash and increasing spaces to print a diagonal
 * @n: how many rows long the diagonal should be
 */
void print_diagonal(int n)
{
	int i;
	int j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			_putchar(' ');
		}
		_putchar('\\');
		_putchar('\n');
	}
	if (i <= 0)
		_putchar('\n');
}
