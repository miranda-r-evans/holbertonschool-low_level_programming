#include <stdio.h>

/**
 * main - prints all letters of alphabet
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	char *alpha = "abcdefghijklmnopqrstuvwxyz";

	while (*alpha != '\0')
	{
		putchar(*alpha);
		alpha++;
	}
	putchar('\n');

	return (0);
}
