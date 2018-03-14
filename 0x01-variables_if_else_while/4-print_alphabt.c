#include <stdio.h>

/**
 * main - print alphabet in lowercase, then uppercase
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	char alpha;

	for (alpha = 'a'; alpha <= 'z'; alpha++)
	{
		if (alpha != 'q' && alpha != 'e')
			putchar(alpha);
	} 

	putchar('\n');

	return (0);
}
