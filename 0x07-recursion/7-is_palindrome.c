#include "holberton.h"

/**
 *  _strlen_recursion - returns the length of a string
 * @s: string to be evaluated
 *
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{
	int i = 0;

	if (*s != '\0')
	{
		i = 1;
		i += _strlen_recursion(s + 1);
	}

	return (i);
}

/**
 * check_pal - iterates through the first half of s and checks it against
 * the second half of s
 * @s: the string to be checked
 * @len: the length of s
 * @i: iterator used to check s
 *
 * Return: 1 if letters match, 0 if they do not
 */
int check_pal(char *s, int len, int i)
{
	int j = 1;

	if (i <= len / 2)
		j = check_pal(s, len, i + 1);

	if (*(s + i) == *(s + len - 1 - i) && j == 1)
		return (1);

	return (0);
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to be checked
 *
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(char *s)
{
	int i = 0;
	int len = _strlen_recursion(s);

	return (check_pal(s, len, i));
}
