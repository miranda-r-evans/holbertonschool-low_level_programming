#include "holberton.h"

/**
 * print_alphabet_x10 - prints a to z 10 times
 *
 * Return: none
 */
void print_alphabet_x10(void)
{
	int j;

	for (j = 0; j < 10; j++)
	{
		int i;

		for (i = 0; i < 26; i++)
		{
			_putchar(97 + i);
		}
		_putchar('\n');
	}
}
