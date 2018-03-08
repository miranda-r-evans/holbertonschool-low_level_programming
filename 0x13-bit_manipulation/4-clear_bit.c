#include "holberton.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index in the binary
 * representation of a number
 * @n: number to be evaluated
 * @index: index of bit to be evaluated
 *
 * Return: 1 if successful, -1 if failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int count = 1;
	unsigned int i = 0;

	while (count <= ULONG_MAX >> 1 && (count * 2 <= *n || i <= index))
	{
		i++;
		count = count << 1;
	}

	while (i >= index)
	{
		if (i == index)
		{
			if ((count & *n) > 0)
				*n -= count;

			return (1);
		}
		i--;
		count = count >> 1;
	}

	return (-1);
}
