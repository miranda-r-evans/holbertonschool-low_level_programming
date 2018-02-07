#include "holberton.h"

/**
 * iterate_thru_star - iterates through s2 until it gets to a
 * non-asterisk value
 * @s2: the string with an asterisk(s) in it
 *
 * Return: a pointer to the next non-asterisk value
 */
char *iterate_thru_star(char *s2)
{
	s2++;

	if (*s2 == '*')
		s2 = iterate_thru_star(s2);

	return (s2);
}

/**
 * iterate_after - iterates through s1 until it finds a match for s2
 * @s1: the string we are iterating through
 * @s2: the string we are finding a match for (after an asterisk)
 *
 * Return: a pointer to the matching value in s1
 */
char *iterate_after(char *s1, char *s2)
{
	if (*s1 != '\0' && *s1 != *s2)
	{
		s1++;
		s1 = iterate_after(s1, s2);
	}

	return (s1);
}

/**
 * wildcmp - matches two strings, one of which may have wildcard asterisks
 * @s1: first string, no asterisks
 * @s2: second string, may have asterisks
 *
 * Return: 1 if string is identical, 0 if not
 */
int wildcmp(char *s1, char *s2)
{
	int i = 0;

	if (*s1 != *s2 && *s2 != '*')
		return (0);

	if (*s2 == '*')
	{
		s2 = iterate_thru_star(s2);
		s1 = iterate_after(s1, s2);
	}

	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s1 == '\0' || *s2 == '\0')
		return (0);

	i = wildcmp(s1 + 1, s2 + 1);

	if (i == 0)
		i = wildcmp(s1 + 2, s2 - 1);

	return (i);
}
