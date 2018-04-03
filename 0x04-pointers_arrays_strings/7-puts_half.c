#include "holberton.h"

/**
 * _strlen - counts length of string
 * @str: string to be counted
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; *str != '\0'; i++)
	{
		str++;
	}

	return (i - 1);
}

/**
 * puts_half - prints second half of string
 * @str: string to be printed
 */
void puts_half(char *str)
{
	int n;
	int j;

	n = _strlen(str);

	for (j = 0; *str != '\0'; j++)
	{
		if (j > n / 2)
		{
			_putchar(*str);
		}
		str++;
	}

	_putchar('\n');
}
