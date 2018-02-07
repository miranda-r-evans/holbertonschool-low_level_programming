#include "holberton.h"
#include <stdio.h>

int stop(int stop_value, int i)
{
	if (i * (i - 1) < stop_value)
		i = stop(stop_value, i + 1);

	if (i == 1)
                return (1);

	if (i * (i - 1) == stop_value)
                return (1);

	if (i * (i - 1) > stop_value)
		return (-1);

	return (-1);
}

int _sqrt_recursion(int n)
{
	int i;
	int j = 1;

	if (n == 0)
		return (0);
	else if (n < 0)
		return (-1);

	i = stop(n, 2);

	if (i == 1)
	{
		printf("stop_value = %i\n", n);
		return (0);
	}

	j += _sqrt_recursion(n - 1);

	return (j);
}
