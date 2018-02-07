#include "holberton.h"

/**
 * _atoi - convert string to int
 * @s: string to be converted
 *
 * Return: the int that has been converted
 */
int _atoi(char *s)
{
	int n = 1;
	int _bool = 1;
	int s_int;

	while (*s)
	{
		if (_bool == 0 && (*s > '9' || *s < '0'))
			break;
		if (*s == '-')
			n = -n;
		if (*s >= '0' && *s <= '9' && _bool == 1)
		{
			s_int = *s - 48;
			n *= s_int;
			_bool = 0;
		}
		else if (*s >= '0' && *s <= '9')
		{
			s_int = *s - 48;
			if (n >= 0)
				n = (n * 10) + s_int;
			else
				n = (n * 10) - s_int;
		}
		s++;
	}

	if (_bool == 1)
		return (0);

	return (n);
}
