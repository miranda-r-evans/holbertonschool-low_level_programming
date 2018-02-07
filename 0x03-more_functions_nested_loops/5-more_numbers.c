#include "holberton.h"

/**
 * more_numbers - prints 0 to 14, 10 times, and a new line
 */
void more_numbers(void)
{
	int i;
	int j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (j > 9)
				_putchar(1 + '0');

			_putchar(j % 10 + '0');
		}
		_putchar('\n');
	}
}
