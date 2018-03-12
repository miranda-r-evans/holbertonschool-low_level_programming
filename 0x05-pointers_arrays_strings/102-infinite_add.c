#include "holberton.h"

/**
 * infinite_add - add two numbers that are stored as strings
 * @n1: first string to be added
 * @n2: second string to be added
 * @r: buffer in which sum will be stored
 * @size_r: size of the buffer
 *
 * Return: pointer to r if sum can be stored in buffer, 0 otherwise
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int digit, carry = 0, n1i, n2i;
	char *rPtr = r + (size_r - 1), *n1Ptr = n1, *n2Ptr = n2;

	while (*(n1Ptr + 1) != '\0')
		n1Ptr++;
	while (*(n2Ptr + 1) != '\0')
		n2Ptr++;
	*rPtr = '\0';
	rPtr--;
	n1i = *n1Ptr - 48;
	n2i = *n2Ptr - 48;
	while (rPtr >= r)
	{
		digit = n1i + n2i + carry;
		if (digit > 9)
		{
			carry = 1;
			digit -= 10;
		}
		else
			carry = 0;
		*rPtr = digit + 48;
		if (rPtr == r || (carry == 0 && n1Ptr == n1 && n2Ptr == n2))
			break;

		rPtr--;
		if (n1Ptr != n1)
			n1i = *(n1Ptr - 1) - 48;
		else
			n1i = 0;
		if (n1Ptr > n1)
			n1Ptr--;
		if (n2Ptr != n2)
			n2i = *(n2Ptr - 1) - 48;
		else
			n2i = 0;
		if (n2Ptr > n2)
			n2Ptr--;
	}
	if (carry != 0 || n1Ptr != n1 || n2Ptr != n2)
		return (0);
	return (rPtr);
}
