#include <stdio.h>

/**
 * main - print first 98 fibonacci numbers
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	int i;
	unsigned long int m = 1;
	unsigned long int temp0;
	unsigned long int o = 1;
	unsigned long int p;
	unsigned long int temp1;
	unsigned long int s;

	for (i = 0; i < 98; i++)
	{
		if (i < 91)
		{
		printf("%lu, ", m);
		temp0 = m, m = temp0 + o, o = temp0;
		}
		else if (i == 91)
		{
			p = m / 1000000000;
			m = m % 1000000000;
			printf("%lu%lu, ", p, m);
			s = o / 1000000000;
			o = o % 1000000000;
		}
		else if (i > 91)
		{
			temp1 = p;
			temp0 = m;
			p = p + s;
			m = m + o;
			s = temp1;
			o = temp0;
			p = p + m / 1000000000;
			m = m % 1000000000;
			printf("%lu%lu", p, m);
			if (i != 97)
				printf(", ");
		}
	}
	printf("\n");
	return (0);
}
