#include "holberton.h"
#include <stdio.h>

/**
 * print_to_98 - prints from a given number to 98
 * @n: number to be printed from
 *
 * Return: none
 */
void print_to_98(int n)
{
	int i;

	if (n < 98)
		for (i = n; i < 98; i++)
			printf("%d, ", i);

	else if (n > 98)
		for (i = n; i > 98; i--)
			printf("%d, ", i);

	printf("98\n");
}
