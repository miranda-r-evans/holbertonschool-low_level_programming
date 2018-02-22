#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - takes two numbers and a mathematical operator from input and prints
 * the result
 * @ac: number of input string from command line
 * @av: input from command line
 *
 * Return: 0 (Always Success)
 */
int main(int ac, char **av)
{
	int a;
	int b;
	char *s = av[2];
	int c;

	if (ac != 4)
	{
		printf("Error\n");
		exit(98);
	}

	if (av[2][1] != '\0')
	{
		printf("Error\n");
		exit(98);
	}

	a = atoi(av[1]);
	b = atoi(av[3]);

	if ((*get_op_func(s)) != NULL)
		c = (*get_op_func(s))(a, b);
	else
	{
		printf("Error\n");
		exit(99);
	}

	printf("%d\n", c);

	return (0);
}
