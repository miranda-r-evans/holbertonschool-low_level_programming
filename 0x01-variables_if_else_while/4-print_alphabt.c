#include <stdio.h>

/**
 * main - prints all letters of alphabet except q and e
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	char *alpha = "abcdfghijklmnoprstuvwxyz";

	while (*alpha != '\0')
	{
		putchar(*alpha);
		alpha++;
	}
	putchar('\n');

	return (0);
}
