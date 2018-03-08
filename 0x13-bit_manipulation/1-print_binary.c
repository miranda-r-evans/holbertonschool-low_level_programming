#include "holberton.h"

void print_binary(unsigned long int n)
{
	unsigned long int cpy = (double)n;
	unsigned long int count = 1;
	unsigned long int remain;
	double div = 0.5;

	while (cpy > 1)
	{
		write(1, "1", 1);

		while (count * 2 <= cpy)
			count *= 2;

		remain = cpy - count;
		count *= div;
		while (count > remain && count > 1)
		{
			write(1, "0", 1);
			count *= div;
		}

		cpy = remain;
	}

	if (cpy == 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}
