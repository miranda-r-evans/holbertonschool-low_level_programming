#include <stdio.h>
#include <stdlib.h>

/**
 * main - add numbers
 * @argc: number of elements in argv
 * @argv: numbers to be added
 *
 * Return: 0 if success, 1 if input contains non-numbers
 */
int main(int argc, char *argv[])
{
	char **array_cpy; char *argv_cpy; int sum = 0; int temp; int i;

	if (argc == 0)
		printf("0\n");
	else
	{
		argv++;
		array_cpy = argv;
		while (*array_cpy != NULL)
		{
			argv_cpy = *array_cpy;
			while (*argv_cpy != '\0')
			{
				if (*argv_cpy >= '0' && *argv_cpy <= '9')
					argv_cpy++;
				else if (*argv_cpy == '-' && *(argv_cpy + 1) >=
					 '0' && *(argv_cpy + 1) <= '9')
					argv_cpy++;
				else
				{
					printf("Error\n");
					return (1);
				}
			}
			array_cpy++;
		}
	}
	array_cpy = argv;
	for (i = 1; i < argc; i++)
	{
		temp = atoi(*array_cpy);
		sum += temp;
		array_cpy++;
	}
	printf("%d\n", sum);

	return (0);
}
