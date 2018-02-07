#include "holberton.h"

/**
 * string_toupper - converts lowercase into uppercase in a string
 * @str: string to be evaluated
 *
 * Return: pointer to string
 */
char *string_toupper(char *str)
{
	char *p = str;

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}

	return (p);
}
