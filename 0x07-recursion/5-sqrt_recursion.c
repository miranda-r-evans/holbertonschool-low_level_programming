#include "holberton.h"

int _sqrt_recursion(int n)
{
	int i = 1;

	if (n / i == i - 1)
		return i;
		i += _sqrt_recursion(n - 1);

	return (i);
}
