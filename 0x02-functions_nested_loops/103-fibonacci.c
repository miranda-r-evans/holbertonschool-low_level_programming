#include <stdio.h>

/**
 * main - print sum of Fibonacci whose values <= 4000000
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	int i = 1;
	unsigned long int j = 1;
	unsigned long int temp;
	unsigned long int sum = 0;

	while (i < 4000001)
	{
		if (i % 2 == 0)
			sum += i;

		temp = i;
		i += j;
		j = temp;

	}

	printf("%lu\n", sum);

	return (0);
}
