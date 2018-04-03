#include "holberton.h"

/**
 * cap_string - capitalized the first letter of every word in a string
 * @str: string to be evaluated
 *
 * Return: pointer to string
 */
char *cap_string(char *str)
{
	char *ptr = str;
	int _bool = 1;

	while (*ptr)
	{
		if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n'
		    || *ptr == ',' || *ptr == ';' || *ptr == '.'
		    || *ptr == '!' || *ptr == '?' || *ptr == '"'
		    || *ptr == '(' || *ptr == ')' || *ptr == '{'
		    || *ptr == '}')
			_bool = 1;
		else if (_bool == 1 && *ptr >= 'a' && *ptr <= 'z')
		{
			*ptr -= 32;
			_bool = 0;
		}
		else
			_bool = 0;

		ptr++;
	}

	return (str);
}
