#include <stdio.h>

/**
 * main - print combinations of two digit numbers
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	int i = 0;
	int j;
	int fi;
	int se;
	int th;
	int fo;

	while (i < 100)
	{
		fi = i / 10;
		se = i % 10;
		j = 0;

		while (j < 100)
		{
			th = j / 10;
			fo = j % 10;
			if ((fi < th) || ((fi == th) && (se < fo)))
			{
				putchar(fi + '0');
				putchar(se + '0');
				putchar(' ');
				putchar(th + '0');
				putchar(fo + '0');
				if (!(fi == 9 && se == 8))
				{
					putchar(',');
					putchar(' ');
				}
			}
			j++;
		}
		i++;
	}
	putchar('\n');

	return (0);
}
