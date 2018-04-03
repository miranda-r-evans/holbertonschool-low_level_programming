#include "holberton.h"

/**
 * print_rev - print string in reverse
 * @s: string to be printed
 */
void print_rev(char *s)
{
	char *ptr = s;

	while (*ptr != '\0')
	{
		ptr++;
	}

	while (ptr != s)
	{
		ptr--;
		_putchar(*ptr);
	}

	_putchar('\n');
}
