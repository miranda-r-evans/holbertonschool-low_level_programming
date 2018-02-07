#include "holberton.h"

/**
 * times_table - prints the 9 times table
 *
 * Return: none
 */
void times_table(void)
{
	int i;
	int j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (i * j > 9)
				_putchar(i * j / 10 + '0');
			else if (j != 0)
				_putchar(' ');

			_putchar(i * j % 10 + '0');
			if (j != 9)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
