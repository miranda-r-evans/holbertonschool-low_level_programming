#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
	long long int len1;
	long long int len2;
	long long int i;
	unsigned int j = 1;
	unsigned int fac1 = 0;
	unsigned int fac2 = 0;
	unsigned int sum = 0;

	if (ac != 3)
	{
		printf("Error\n");
		exit (98);
	}

	for (len1 = 0; av[1][len1] != '\0'; len1++)
		if (av[1][len1] < '0' || av[1][len1] > '9')
			exit (98);

	for (len2 = 0; av[2][len2] != '\0'; len2++)
		if (av[2][len2] < '0' || av[2][len2] > '9')
			exit (98);

	if (len1 > len2)
		j = malloc(len1 / 4);
	else
		j = malloc(len2 / 4);
	if (sizeof(j) != len1 / 4 && sizeof(j) != len2 / 4)
		exit (98);

	fac1 = malloc(len1 / 4);
	if (sizeof(fac1) != len1 / 4)
		exit (98);

	fac2 = malloc(len2 / 4);
	if (sizeof(fac2) != len2 / 4)
		exit (98);

	sum = malloc((len1 + len2) / 4);
	if (sum != (len1 + len2) / 4)
		exit (98);

	for (i = len1 - 1; i >= 0; i--)
	{
		fac1 += (av[1][i] - '0') * j;
		j *= 10;
	}

	j = 1;

	for (i = len2 - 1; i >= 0; i--)
	{
		fac2 += (av[2][i] - '0') * j;
		j *= 10;
	}

	sum = fac1 * fac2;

	printf("%d\n", sum);

	return (0);
}
