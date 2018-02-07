#include <stdio.h>

/**
 * main - print alphabet in lowercase, then uppercase
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	while (*alpha != '\0')
	{
		putchar(*alpha);
		alpha++;
	}
	putchar('\n');

	return (0);
}
