#include "holberton.h"

/**
 * get_bit - returns the value of a bit at a given index in the binary
 * representation of a number
 * @n: number to be evaluated
 * @index: index of bit
 *
 * Return: 1 or 0 depending on value of bit, or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i = 0;
	unsigned long int cpy = n;
	unsigned int count = 1;
	unsigned int remain;

	while (count * 2 <= cpy)
	{
		i++;
		count *= 2;
	}

	remain = cpy - count;

	while (i >= index)
	{
		if (i == index)
		{
			if (cpy == count + remain || count <= remain)
				return (1);
			else
				return (0);
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
