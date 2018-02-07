#include "holberton.h"

/**
 * rot13 - encrypt a string to rot13
 * @str: string to be encrypted
 *
 * Return: pointerr to string
 */
char *rot13(char *str)
{
	char *p = str;
	char alph[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *alphC = &alph[0];
	char *rotC = &rot[0];
	char *alphStart = alphC;
	char *rotStart = rotC;

	while (*str)
	{
		while (*alphC)
		{
			if (*str == *alphC)
			{
				*str = *rotC;
				break;
			}
			alphC++;
			rotC++;
		}
		alphC = alphStart;
		rotC = rotStart;
		str++;
	}

	return (p);
}
