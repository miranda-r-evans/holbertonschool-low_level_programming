#include "holberton.h"

/**
 * print_times_table - prints times tables of a number, up to 15
 * @n: number of times table
 *
 * Return: none
 */
void print_times_table(int n)
{
	int i;
	int j;
	int k;

	if (n < 16 && n > -1)
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				k = i * j;

				if (k > 99)
				{
					_putchar(k / 100 + '0');
					_putchar((k % 100) / 10 + '0');
				}
				else if (k > 9)
				{
					_putchar(' ');
					_putchar(k / 10 + '0');
				}
				else if (j != 0)
				{
					_putchar(' ');
					_putchar(' ');
				}

				_putchar(k % 10 + '0');

				if (j < n)
				{
					_putchar(',');
					_putchar(' ');
				}

			}
			_putchar('\n');
		}
	}
}
