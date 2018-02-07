#include "holberton.h"

/**
 * main - print Holberton and new line
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	char *holb = "Holberton";

	while (*holb != '\0')
	{
		_putchar(*holb);
		holb++;
	}
	_putchar('\n');

	return (0);
}
