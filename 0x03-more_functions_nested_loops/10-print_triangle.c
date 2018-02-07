#include "holberton.h"

/**
 * print_triangle - uses pound signs to print a triangle
 * @size: size of triangle
 */
void print_triangle(int size)
{
	int p;
	int s;
	int c1;
	int c2;

	for (p = 1; p <= size; p++)
	{
		s = size - p;
		for (c1 = 0; c1 < s; c1++)
			_putchar(' ');

		for (c2 = 0; c2 < p; c2++)
			_putchar('#');

		_putchar('\n');
	}
	if (size <= 0)
		_putchar('\n');
}
