#include <stdio.h>

/**
 * main - print combinations of digits from 01 to 89
 * digits not repeated in same combo
 * reverse of combinations not printed
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	int i = 0;
	int f;
	int s;

	while (i < 100)
	{
		f = i / 10;
		s = i % 10;

		if (f != s)
		{
			if ((f * 10 + s) < (s * 10 + f))
			{
				putchar(f + '0');
				putchar(s + '0');
				if (i != 89)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
		i++;
	}
	putchar('\n');

	return (0);
}
