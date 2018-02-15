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

int main(int ac, char **av)
{
	long long int len1;
	long long int len2;
	long long int i;
	long long int j;
	long long int k;
	long long int l = 0;
	int digit;
	int d1;
	int d2;
	int carry = 0;
	char *temp;
	char *sum;

	if (ac != 3)
	{
		printf("Error\n");
		exit (98);
	}

	for (len1 = 0; av[1][len1] != '\0'; len1++)
		if (av[1][len1] < '0' || av[1][len1] > '9')
		{
			printf("Error\n");
			exit (98);
		}

	for (len2 = 0; av[2][len2] != '\0'; len2++)
		if (av[2][len2] < '0' || av[2][len2] > '9')
		{
			printf("Error\n");
			exit (98);
		}

	temp = create_array(len1 + len2 + 1, '0');

	sum = create_array(len1 + len2 + 1, '0');

	for (i = len1 -1; i >= 0; i--)
	{
		k = len1 + len2 -1;

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
			temp[k] = digit + '0';
			k--;
		}

		for (j = len2 + len1 - 1; j >= 0; j--)
		{
			digit = temp[j] - '0' + sum[j - l] - '0' + carry;
			if (digit > 9)
			{
				carry = digit / 10;
				digit = digit % 10;
			}
			else
				carry = 0;

			sum[j - l] = digit + '0';
		}

		l++;
	}

	for (i = 0; sum[i] == '0'; i++)
		;
	for (; i < len1 + len2; i++)
	{
		_putchar(sum[i]);
	}
	_putchar('\n');

	free(sum);
	free(temp);

	return (0);
}
