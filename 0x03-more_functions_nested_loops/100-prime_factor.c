#include <stdio.h>

/**
 * main - find larges prime factor of 612852475143
 *
 * Return: 0 (Always Success)
 */
int main(void)
{

	unsigned long int input = 612852475143;
	unsigned long int n = 2;

	while (n < input)
	{
		if (input % n == 0)
		{
			input = input / n;
			n = 1;
		}
		n++;
	}
	printf("%lu\n", input);

	return (0);
}
