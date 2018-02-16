#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * len_finder - finds length of input strings
 * @s1_cpy: first string to be evaluated
 * @s2_cpy: second string to be evaluated, until n characters
 * @n: limit on how many characters from s2 need to be evaluated
 *
 * Return: length of s1
 */
int len_finder(char *s1_cpy, char *s2_cpy, unsigned int n)
{
	int len;
	unsigned int i;

	for (len = 0; *s1_cpy != '\0'; len++)
		s1_cpy++;

	for (i = 0; *s2_cpy != '\0' && i < n; len++)
	{
		i++;
		s2_cpy++;
	}

	return (len);
}

/**
 * string_nconcat - concatenates two strings
 * @s1: string to be concatenated
 * @s2: string to be concatenated, up to n characters
 * @n: limit on how many characters from s2 to be copied
 *
 * Return: pointer to new string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s1_cpy = s1;
	char *s2_cpy = s2;
	char _var = '\0';
	char *str = NULL;
	char *str_st;
	int len;
	unsigned int i;

	if (s1 == NULL)
		s1_cpy = &_var;
	if (s2 == NULL)
		s2_cpy = &_var;

	len = len_finder(s1_cpy, s2_cpy, n);

	str = malloc(len + 1);
	if (str == NULL)
		return NULL;

	str_st = str;

	while (*s1_cpy != '\0')
	{
		*str = *s1_cpy;
		str++;
		s1_cpy++;
	}

	for (i = 0; *s2_cpy != '\0' && i < n; i++)
	{
		*str = *s2_cpy;
		str++;
		s2_cpy++;
	}

	*str = '\0';

	return (str_st);
}
