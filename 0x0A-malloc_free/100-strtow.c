#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * find_words - helper function to find how many words in string
 * @str: string to be evaluated
 *
 * Return: number of words in string
 */
int find_words(char *str)
{
	int words = 0;
	char *strCpy = str;

	while (*strCpy != '\0')
	{
		if (strCpy == str && *strCpy != ' ')
			words++;
		else if (*strCpy != ' ' && *strCpy != '\0' &&  *(strCpy - 1)
			== ' ')
			words++;

		strCpy++;
	}

	return (words);
}

/**
 * strtow - convert a string of words into an array of words
 * @str: string to be converted
 *
 * Return: a pointer to the array, or NULL if failure
 */
char **strtow(char *str)
{
	char **array = NULL; char *strCpy = str;
	int words = 0; int i; int j; int len;

	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}
	words = find_words(str);
	if (words == 0)
		return (NULL);

	array = malloc(sizeof(char *) * (words + 1));
	if (array == NULL)
		return (NULL);

	strCpy = str;
	for (i = 0; i < words; i++)
	{
		while (*strCpy == ' ')
			strCpy++;
		for (len = 0; *strCpy != ' ' && *strCpy != '\0'; len++)
			strCpy++;

		array[i] = malloc(sizeof(char) * (len + 1));
		if (array[i] == NULL)
		{
			i--;
			for (; i <= 0; i--)
				free(array[i]);
			free(array);
			return (NULL);
		}
		strCpy -= len;
		for (j = 0; j < len; j++)
		{
			array[i][j] = *strCpy;
			strCpy++;
		}
	}
	return (array);
}
