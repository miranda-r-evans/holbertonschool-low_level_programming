#include <stdio.h>

/**
 * main - print sum of multiples of 3 and 5 below 1024
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	unsigned long int sum = 0;
	unsigned long int mult = 0;
	int i;

	for (i = 0; mult < 1024; i++)
	{
		sum += mult;
		mult = i * 3;
	}

	mult = 0;

	for (i = 0; mult < 1024; i++)
	{
		if ((mult % 3) != 0)
		{
			sum += mult;
		}
		mult = i * 5;
	}

	printf("%lu\n", sum);

	return (0);
}
