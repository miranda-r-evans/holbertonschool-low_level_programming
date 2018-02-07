#include <stdio.h>

/**
 * main - print alphabet in reverse
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	char *rev_alpha = "zyxwvutsrqponmlkjihgfedcba";

	while (*rev_alpha != '\0')
	{
		putchar(*rev_alpha);
		rev_alpha++;
	}
	putchar('\n');

	return (0);
}
