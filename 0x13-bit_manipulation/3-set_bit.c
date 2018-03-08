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
	unsigned long int count = 1;
	unsigned int i = 0;

	while (count * 2 <= *n || i <= index)
	{
		i++;
		count *= 2;
	}

	while (i >= index)
	{
		if (i == index)
		{
			if ((count & *n) == 0)
				*n += count;

			return (1);
		}
		i--;
		count /= 2;
	}

	return (-1);
}
