#include "holberton.h"

/**
 * print_last_digit - prints and returns last digit of a number
 * @n: number to be evaluated
 *
 * Return: the last digit
 */
int print_last_digit(int n)
{
	int i = n % 10;

	if (i < 0)
		i *= -1;

	_putchar(i + '0');

	return (i);
}
