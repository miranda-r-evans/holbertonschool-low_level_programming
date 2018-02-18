#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _print_err - prints error and exits program
 */
void _print_err(void)
{
/* I apologize for how ridiculously this code is written. */
/* It's because of holberton function length maximums. */

	_putchar('E'); _putchar('r'); _putchar('r');
	_putchar('o'); _putchar('r'); _putchar('\n');
	exit(98);
}

/**
 * _strlen - counts string length and calls print_err if there is a problem
 * @str: string thats length is counted
 *
 * Return: string length
 */
int _strlen(char *str)
{
	int len;

	for (len = 0; *str != '\0'; len++)
	{
		if (*str > '9' || *str < '0')
			_print_err();

		str++;
	}

	return (len);
}

/**
 * print_prod - prints product of the multiplication
 * @prod: product that is printed
 * @len1: used for printing
 * @len2: used for printing
 */
void print_prod(char *prod, int len1, int len2)
{
	int i = 0;

	while (*prod == '0' && i < len1 + len2)
	{
		i++;
		prod++;
	}
	for (; i < len1 + len2 + 1; i++)
	{
		_putchar(*prod);
		prod++;
	}
	_putchar('\n');
}

/**
 * mult - multiplies two strings
 * @s1_st: c
 * @s1_cpy: d
 * @s1_end: e
 * @s2_st: f
 * @s2_cpy: g
 * @prod_st: h
 * @temp_st: i
 * @prod_cpy: j
 * @temp_cpy: k
 * @prod_end: l
 * @s2_end: m
 * @temp_end: o
 */
void mult(char *s1_st, char *s1_cpy,
	  char *s1_end, char *s2_st, char *s2_cpy, char *prod_st, char *temp_st,
	  char *prod_cpy, char *temp_cpy, char *prod_end,
	  char *temp_end)
{
	int digit, carry = 0;

	while (s2_cpy >= s2_st)
	{
		s2_cpy--; temp_cpy = temp_end - 1; s1_cpy = s1_end - 1;
		while (s1_cpy >= s1_st)
		{
			digit = (*s1_cpy - '0') * (*s2_cpy - '0') + carry;
			if (digit > 9)
			{
				carry = digit / 10; digit = digit % 10;
			}
			else
				carry = 0;
			*temp_cpy = digit + '0'; temp_cpy--;
			if (s1_cpy == s1_st)
				break;
			s1_cpy--;
		}
		*temp_cpy = carry + '0'; carry = 0; temp_cpy = temp_end - 1;
		if (prod_end > prod_st)
			prod_end--;
		prod_cpy = prod_end;
		while (temp_cpy >= temp_st)
		{
			digit = (*temp_cpy - '0') + (*prod_cpy - '0') + carry;
			if (digit > 9)
			{
				carry = 1; digit = digit % 10;
			}
			else
				carry = 0;
			*prod_cpy = digit + '0';
			if (prod_cpy == prod_st || temp_cpy == temp_st)
				break;
			temp_cpy--; prod_cpy--;
		}
		if (s2_cpy == s2_st)
			break;
	}
}

/**
 * main - multiplies the numbers given from input
 * @ac: number of elements in av
 * @av: input from command line
 *
 * Return: 0 (Always Success)
 */
int main(int ac, char **av)
{
	int len1, len2;
	char *s1_st = av[1];
	char *s1_cpy = s1_st;
	char *s1_end;
	char *s2_st = av[2];
	char *s2_cpy = s2_st;
	char *s2_end;
	char *prod_st = NULL;
	char *temp_st = NULL;
	char *prod_cpy;
	char *temp_cpy;
	char *prod_end;
	char *temp_end;

	if (ac != 3)
		_print_err();
	len1 = _strlen(s1_cpy); s1_end = s1_st + len1; len2 = _strlen(s2_cpy);
	s2_end = s2_st + len2; prod_st = malloc(len1 + len2 + 2);
	if (prod_st == NULL)
		_print_err();
	temp_st = malloc(len1 + len2 + 2);
	if (temp_st == NULL)
		_print_err();
	prod_cpy = prod_st; prod_end = prod_st + len1 + len2 + 1;
	while (prod_cpy < prod_end)
	{
		*prod_cpy = '0'; prod_cpy++;
	}
	*prod_cpy = '\0'; temp_cpy = temp_st;
	temp_end = temp_st + len1 + len2 + 1;
	while (temp_cpy < temp_end)
	{
		*temp_cpy = '0'; temp_cpy++;
	}
	*temp_cpy = '\0'; s2_cpy = s2_end;
	mult(s1_st, s1_cpy, s1_end, s2_st, s2_cpy,
	     prod_st, temp_st, prod_cpy, temp_cpy, prod_end, temp_end);
	prod_cpy = prod_st; print_prod(prod_cpy, len1, len2);
	free(prod_st); free(temp_st);
	return (0);
}
