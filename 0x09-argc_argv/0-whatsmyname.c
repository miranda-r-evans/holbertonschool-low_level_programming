#include <stdio.h>

/**
 * main - print name of compiled file
 * @argc: number of elements in argv
 * @argv: name of file being compiled
 *
 * Return: 0 (Always Success)
 */
int main(__attribute__((unused))int argc, char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}
