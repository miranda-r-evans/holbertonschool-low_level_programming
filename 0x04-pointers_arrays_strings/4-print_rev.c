#include "holberton.h"

/**
 * print_rev - print string in reverse
 * @s: string to be printed
 */
void print_rev(char *s)
{
	char *start = s;

	while (*s != '\0')
	{
		s++;
	}

	while (s != start)
	{
		s--;
		_putchar(*s);
	}
	_putchar('\n');
}
