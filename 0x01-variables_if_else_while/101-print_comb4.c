#include <stdio.h>

/**
 * main - print combinations of three digits
 * digits not repeated in same combo
 * digits in different order not printed
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	int i = 0;
	int f;
	int s;
	int t;

	while (i < 800)
	{
		f = i / 100;
		s = (i % 100) / 10;
		t = i % 10;

		if (f != s && f != t && s != t)
		{
			if (f < s && s < t)
			{
				putchar(f + '0');
				putchar(s + '0');
				putchar(t + '0');
				if (i != 789)
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
