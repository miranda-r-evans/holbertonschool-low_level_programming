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
	unsigned int count = 1;
	unsigned int i = 0;

	while (count * 2 <= n)
	{
		i++;
		count *= 2;
	}

	while (i >= index)
	{
		if (i == index)
		{
			if ((count & n) > 0)
				return (1);
			else
				return (0);
		}

		i--;
		count = count >> 1;
	}

	return (-1);
}
