#include <stdio.h>

/**
 * main - print all agruments to program
 * @argc: number of elements in argv
 * @argv: arguments to program
 *
 * Return: 0 (Always Success)
 */
int main(__attribute__((unused))int argc, char *argv[])
{
	while (*argv != NULL)
	{
		printf("%s\n", *argv);
		argv++;
	}

	return (0);
}
