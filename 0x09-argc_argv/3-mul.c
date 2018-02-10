#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiply two numbers from argv
 * @argc: number of elements in argv
 * @argv: numbers to be multiplied
 *
 * Return: 0 if Success, 1 if two and only two numbers are supplied
 */
int main(int argc, char *argv[])
{
	int i;
	int j;
	int k;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	argv++;
	i = atoi(*argv);
	argv++;
	j = atoi(*argv);
	k = i * j;

	printf("%d\n", k);

	return (0);
}
