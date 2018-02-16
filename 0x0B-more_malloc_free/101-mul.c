#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * create_array - create an array of size size, initialized with a char c
 * @size: size of the array
 * @c: character array is initialized with
 *
 * Return: a pointer to the array, or NULL is failure
 */
char *create_array(unsigned int size, char c)
{
	char *array = NULL;
	unsigned int i;
	char *array_cpy;

	if (size == 0)
		return (NULL);

	array = malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);
	array_cpy = array;

	for (i = 0; i < size; i++)
	{
		*array_cpy = c;
		array_cpy++;
	}

	return (array);
}

/**
 * mult - multiplies two number strings
 * @prd: where the product is stored
 * @tmp: used for calculating product
 * @len1: length of first factor
 * @len2: length of second factor
 * @av: command line input
 *
 * Return: pointer to character array containing product
 */
char *mult(char *prd, char *tmp, int len1, int len2, char **av)
{
	int i, j, k, l = 0;
	int digit, d1, d2, carry = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		k = len1 + len2 - 1;
		for (j = len2 - 1; j >= -1; j--)
		{
			d1 = av[1][i] - '0';
			d2 = av[2][j] - '0';
			if (j >= 0)
				digit = d1 * d2 + carry;
			else
				digit = carry;
			if (digit > 9)
			{
				carry = digit / 10;
				digit = digit % 10;
			}
			else
				carry = 0;
			tmp[k] = digit + '0';
			k--;
		}
		for (j = len2 + len1 - 1; j >= 0; j--)
		{
			digit = tmp[j] - '0' + prd[j - l] - '0' + carry;
			if (digit > 9)
			{
				carry = digit / 10;
				digit = digit % 10;
			}
			else
				carry = 0;
			prd[j - l] = digit + '0';
		}
		l++;
	}

	return (prd);
}

/**
 * print_prod - prints the product of multiplying
 * @prod: array where product is stored
 * @len1: length of first factor
 * @len2: length of second factor
 */
void print_prod(char *prod, int len1, int len2)
{
	int i;

	for (i = 0; prod[i] == '0'; i++)
		;
	for (; i < len1 + len2; i++)
	{
		_putchar(prod[i]);
	}
	_putchar('\n');
}

/**
 * main - multiplies two number strings from input
 * @ac: number of elements in av
 * @av: inputs from command line, numbs to be multiplied
 *
 * Return: 0 (Always Success)
 */
int main(int ac, char **av)
{
	int len1, len2;
	char *temp = NULL; char *prod = NULL;

	if (ac != 3)
	{
		_putchar('E'); _putchar('r'); _putchar('r'); _putchar('o');
		_putchar('r'); _putchar('\n'); exit(98);
	}
	for (len1 = 0; av[1][len1] != '\0'; len1++)
		if (av[1][len1] < '0' || av[1][len1] > '9')
		{
			_putchar('E'); _putchar('r'); _putchar('r');
			_putchar('o'); _putchar('r'); _putchar('\n'); exit(98);
		}
	for (len2 = 0; av[2][len2] != '\0'; len2++)
		if (av[2][len2] < '0' || av[2][len2] > '9')
		{
			_putchar('E'); _putchar('r'); _putchar('r');
			_putchar('o'); _putchar('r'); _putchar('\n'); exit(98);
		}
	temp = create_array(len1 + len2 + 1, '0');
	if (temp == NULL)
		exit(98);
	prod = create_array(len1 + len2 + 1, '0');
	if (prod == NULL)
		exit(98);

	prod = mult(prod, temp, len1, len2, av);

	print_prod(prod, len1, len2);
	free(prod);
	free(temp);

	return (0);
}
