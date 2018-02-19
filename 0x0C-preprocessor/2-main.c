#include <stdio.h>

/**
 * main - prints the name of the file this is compiled from
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	printf(__FILE__);
	printf("\n");

	return (0);
}
