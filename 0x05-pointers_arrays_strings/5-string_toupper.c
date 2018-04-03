#include "holberton.h"

/**
 * string_toupper - converts lowercase into uppercase in a string
 * @str: string to be evaluated
 *
 * Return: pointer to string
 */
char *string_toupper(char *str)
{
	char *ptr = str;

	while (*ptr != '\0')
	{
		if (*ptr >= 'a' && *ptr <= 'z')
			*ptr -= 32;
		ptr++;
	}

	return (str);
}
