#include "holberton.h"

/**
 * puts2 - prints every other value in a string;
 * @str: string to be printed
 */
void puts2(char *str)
{
	int _bool = 1;

	while (*str != '\0')
	{
		if (_bool == 1)
		{
			_putchar(*str);
			_bool = 0;
		}
		else
			_bool = 1;

		str++;
	}
	_putchar('\n');
}
