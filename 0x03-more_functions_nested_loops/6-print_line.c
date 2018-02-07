#include "holberton.h"

/**
 * print_line - prints a line of n underscores
 * @n: number of underscores
 */
void print_line(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
