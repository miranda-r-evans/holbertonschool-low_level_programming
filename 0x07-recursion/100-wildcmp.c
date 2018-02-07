#include "holberton.h"
#include <stdio.h>
char *iterate_thru_star(char *s2)
{
	s2++;

	if (*s2 == '*')
		s2 = iterate_thru_star(s2);

	return (s2);
}

char *iterate_after(char *s1, char *s2)
{
	if (*s1 != '\0' && *s1 != *s2)
	{
		s1++;
		s1 = iterate_after(s1, s2);
	}

	return (s1);
}

int wildcmp(char *s1, char *s2)
{
	int i;

	if (*s1 != *s2 && *s2 != '*')
		return (0);

	if (*s2 == '*')
	{
		s2 = iterate_thru_star(s2);
		s1 = iterate_after(s1, s2);
/*		printf("s1 = %c, s2 = %c\n", *s1, *s2);*/
	}

	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s1 == '\0' || *s2 == '\0')
		return (0);

	i = wildcmp(s1 + 1, s2 + 1);

	return (i);
}
