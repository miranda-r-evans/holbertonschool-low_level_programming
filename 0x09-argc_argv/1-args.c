#include <stdio.h>

/**
 * main - print out number of arguments passed to program
 * @argc: number of elements in argv
 * @argv: arguments being passed to program
 *
 * Return: 0 (Always Success)
 */
int main(int argc, __attribute__((unused))char *argv[])
{
	printf("%d\n", argc - 1);

	return (0);
}
