#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * _strlen - finds length of a string
 * @str: string to be evaluated
 *
 * Return: the length of the string
 */
int _strlen(char *str)
{
	int i = 0;

	while (*str != '\0')
	{
		i++;
		str++;
	}

	return (i);
}

/**
 * pr_err - prints error message and exits
 */
void pr_err(void)
{
	write(2, "Error\n", 6);
	exit(98);
}

/**
 * _memclr - sets the values of an int buffer to 0
 * @buf: buffer
 * @len: length of buffer
 */
void _memclr(int **buf, int len)
{
	int i;
	int *ptr = *buf;

	for (i = 0; i < len; i++)
	{
		*ptr = 0;
		ptr++;
	}
}

/**
 * dig_n_car - evaluates a digit to see if it needs to be carried
 * @dig: pointer to digit, value is set to new digit value
 *
 * Return: the carried value
 */
int dig_n_car(int *dig)
{
	int car;

	if (*dig > 9)
	{
		car = *dig / 10;
		*dig %= 10;
	}
	else
		car = 0;

	return (car);
}

/**
 * mul - multiplies the values stored in two strings
 * @n1: first string
 * @n2: second string
 *
 * Return: pointer to a buffer storing the product
 */
int *mul(char *n1, char *n2)
{
	int digit, carry = 0, place = 1, len1, len2, n1i, n2i;
	int *buf = NULL, *b_ptr;
	char *n1_ptr, *n2_ptr;

	len1 = _strlen(n1);
	len2 = _strlen(n2);
	buf = malloc(sizeof(int) * (len1 + len2));
	if (buf == NULL)
		pr_err();
	_memclr(&buf, len1 + len2);
	n1_ptr = n1 + (len1 - 1);
	n1i = *n1_ptr - '0';
	while (n1_ptr >= n1)
	{
		carry = 0;
		b_ptr = buf + (len1 + len2 - place);
		n2_ptr = n2 + (len2 - 1);
		n2i = *n2_ptr - '0';
		while (n2_ptr >= n2)
		{
			if (*n1_ptr > '9' || *n1_ptr < '0' || *n2_ptr > '9' || *n2_ptr < '0')
			{
				printf("%c %c\n", *n1_ptr, *n2_ptr);
				free(buf);
				pr_err();
			}
			digit = n1i * n2i + carry;
			carry = dig_n_car(&digit);
			*b_ptr += digit;
			carry += dig_n_car(b_ptr);
			if (b_ptr == buf)
				break;
			if (n2_ptr != n2)
			{
				n2i = *(n2_ptr - 1) - '0';
				n2_ptr--;
			}
			else
				n2i = 0;
			b_ptr--;
		}
		carry = dig_n_car(b_ptr);
		if (n1_ptr != n1)
		{
			n1i = *(n1_ptr - 1) - '0';
			n1_ptr--;
		}
		else
			break;
		place++;
	}

	return (buf);
}

/**
 * main - multiplies two numbers from input
 * @ac: number of values from input
 * @av: values from input
 *
 * Return: 0 (Always Success)
 */
int main(int ac, char **av)
{
	int len1, len2, i;
	int *prod;
	int *cpy;
	char dig[] = " ";

	if (ac != 3)
		pr_err();
	len1 = _strlen(av[1]);
	len2 = _strlen(av[2]);
	prod = mul(av[1], av[2]);
	cpy = prod;
	for (i = 0; i < len1 + len2 - 1 && *cpy == 0; i++, cpy++)
		;
	for (; i < len1 + len2; i++, cpy++)
	{
		*dig = *cpy + '0';
		write(1, dig, 1);
	}
	write(1, "\n", 1);

	free(prod);
	return (0);
}

