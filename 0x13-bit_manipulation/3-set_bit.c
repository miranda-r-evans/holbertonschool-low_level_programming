#include "holberton.h"

/**
 * set_bit - sets the value of a bit to 0 at a given index in the binary
 * representation of a number
 * @n: number to be evaluated
 * @index: bit to be set
 *
 * Return: 1 if successful, -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int i = 0;
	unsigned long int cpy = *n;
	unsigned long int count = 1;
	unsigned long int remain = 0;

	while (count * 2 <= cpy || i <= index)
	{
		i++;
		count *= 2;
	}

	if (cpy > count)
		remain = cpy - count;

	while (i >= index)
	{
		if (i == index)
		{
			if (cpy == count + remain || count <= remain)
				return (1);

			*n += count;
			return (1);
		}
		if (count <= remain)
		{
			cpy = remain;
			remain = cpy - count;
		}

		i--;
		count /= 2;
	}

	return (-1);
}
