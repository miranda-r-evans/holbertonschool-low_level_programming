#include "holberton.h"

/**
 * cap_string - capitalized the first letter of every word in a string
 * @str: string to be evaluated
 *
 * Return: pointer to string
 */
char *cap_string(char *str)
{
	char *p = str;
	int _bool = 1;

	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
			_bool = 1;
		else if (*str == ',' || *str == ';' || *str == '.')
			_bool = 1;
		else if (*str == '!' || *str == '?' || *str == '"')
			_bool = 1;
		else if (*str == '(' || *str == ')' || *str == '{')
			_bool = 1;
		else if (*str == '}')
			_bool = 1;
		else if (_bool == 1 && *str >= 'a' && *str <= 'z')
		{
			*str -= 32;
			_bool = 0;
		}
		else
			_bool = 0;

		str++;
	}

	return (p);
}
