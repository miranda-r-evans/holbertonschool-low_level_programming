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
	char *start = str;

	for (i = 0; *str != '\0'; i++)
	{
		str++;
	}
	str = start;

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

	int _strlen(char *str);

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
