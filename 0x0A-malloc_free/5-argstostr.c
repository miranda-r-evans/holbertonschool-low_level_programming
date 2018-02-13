#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - concatenates av inputs into a string, separated by new lines
 * @ac: number of elements in av
 * @av: input from main
 *
 * Return: a pointer to the new string
 */
char *argstostr(int ac, char **av)
{
	int i;
	int j;
	int len = 0;
	char *str = NULL;
	char *str_cpy;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			;

		len += j + 1;
	}

	len++;

	str = malloc(sizeof(char) * len);

	if (str == NULL)
		return (NULL);

	str_cpy = str;

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			*str_cpy = av[i][j];
			str_cpy++;
		}
		*str_cpy = '\n';
		str_cpy++;
	}

	*str_cpy = '\0';

	return (str);
}
