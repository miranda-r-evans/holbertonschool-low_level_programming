#include <stdio.h>

/**
 * main - prints all letters of alphabet
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	char alpha;

	for (alpha = 'a'; alpha <= 'z'; alpha++)
		putchar(alpha);

	putchar('\n');

	return (0);
}
