#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints how many coins are needed to make an amount of change
 * @argc: number of elements in argv
 * @argv: change to be evaluated
 *
 * Return: 0 if success, 1 if not and amount of change input
 */
int main(int argc, char *argv[])
{
	int q;
	int d;
	int n;
	int t;
	int c;
	int change;
	int change_left;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	argv++;
	change = atoi(*argv);

	if (change < 0)
	{
		printf("0\n");
		return (0);
	}

	q = change / 25;
	change_left = change - q * 25;

	d = change_left / 10;
	change_left -= d * 10;

	n = change_left / 5;
	change_left -= n * 5;

	t = change_left / 2;
	change_left -= t * 2;

	c = change_left;

	printf("%d\n", q + d + n + t + c);

	return (0);
}
