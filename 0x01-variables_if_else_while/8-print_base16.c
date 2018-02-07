#include <stdio.h>

/**
 * main - print hexdecimal numbers
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	char *hex = "0123456789abcdef";

	while (*hex != '\0')
	{
		putchar(*hex);
		hex++;
	}
	putchar('\n');

	return (0);
}
