#include "holberton.h"

/**
 * leet - convert string to leet speak
 * @str: string to be evaluated
 *
 * Return: pointer to string
 */
char *leet(char *str)
{
	char *ptr = str;
	char letA[] = {'a', 'A', 'e', 'E', 'o', 'O', 't', 'T', 'l', 'L', '\0'};
	char numA[] = {'4', '4', '3', '3', '0', '0', '7', '7', '1', '1', '\0'};
	char *letCount = letA;
	char *numCount = numA;

	while (*ptr != '\0')
	{
		while (*letCount != '\0')
		{
			if (*ptr == *letCount)
				*ptr = *numCount;

			letCount++;
			numCount++;
		}

		letCount = letA;
		numCount = numA;
		ptr++;
	}

	return (str);
}
