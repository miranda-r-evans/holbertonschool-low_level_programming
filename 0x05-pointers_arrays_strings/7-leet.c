#include "holberton.h"

/**
 * leet - convert string to leet speak
 * @str: string to be evaluated
 *
 * Return: pointer to string
 */
char *leet(char *str)
{
	char *p = str;
	char letA[] = {'a', 'A', 'e', 'E', 'o', 'O', 't', 'T', 'l', 'L'};
	char numA[] = {'4', '4', '3', '3', '0', '0', '7', '7', '1', '1'};
	char *letCount = &letA[0];
	char *numCount = &numA[0];
	char *letStart = letCount;
	char *numStart = numCount;

	while (*str)
	{
		while (*letCount)
		{
			if (*str == *letCount)
				*str = *numCount;

			letCount++;
			numCount++;
		}
		letCount = letStart;
		numCount = numStart;
		str++;
	}

	return (p);
}
