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
	unsigned long int count = 1;
	unsigned int i = 0;

	if (index > sizeof(long int) * 8)
		return (-1);

	while (count * 2 <= n && count <= ULONG_MAX >> 1)
	{
		i++;
		count = count << 1;
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

	return (0);
}
