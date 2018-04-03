#include "holberton.h"

/**
 * rev_string - reverses a string
 * @s: string to be reversed
 */
void rev_string(char *s)
{
	char *ptr = s;
	char temp;

	while (*ptr != '\0')
	{
		ptr++;
	}

	ptr--;

	while (ptr >= s)
	{
		temp = *s;
		*s = *ptr;
		*ptr = temp;
		s++;
		ptr--;
	}
}
