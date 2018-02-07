#include "holberton.h"

/**
 * infinite_add - add two numbers that are stored as strings
 * @n1: first string to be added
 * @n2: second string to be added
 * @r: buffer in which sum will be stored
 * @size_r: size of the buffer
 *
 * I know the lack of spacing is ugly but holberton has a size limit on
 * functions that is inconvenient for complex work
 *
 * Return: pointer to r if sum can be stored in buffer, 0 otherwise
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	char *rSt = r; char *n1St = n1; char *n2St = n2;
	int sum; int carry = 0; char n1Store = '1'; char n2Store = '1';

	while (*n1)
		n1++;
	while (*n2)
		n2++;
	r = r + size_r - 1; *r = '\0'; r--; n1--; n2--;
	while (r >= rSt)
	{
		if (n1Store == '0' && n2Store == '0')
			sum = n1Store + n2Store + carry - '0' - '0';
		else if (n1Store == '0' && n2Store != '0')
			sum = n1Store + *n2 + carry - '0' - '0';
		else if (n2Store == '0' && n1Store != '0')
			sum = *n1 + n2Store + carry - '0' - '0';
		else
			sum = *n1 + *n2 + carry - '0' - '0';
		if (sum > 9)
		{
			carry = 1; sum = sum - 10; }
		else
			carry = 0;
		*r = sum + '0';
		if (r > rSt && !(n1 == n1St && n2 == n2St && carry == 0))
			r--;
		else if (r >= rSt && n1 == n1St && n2 == n2St && carry == 0)
			return (r);
		else if (r == rSt && !(n1 == n1St && n2 == n2St && carry == 0))
			return (0);
		if (n1 == n1St)
			n1Store = '0';
		else
			n1--;
		if (n2 == n2St)
			n2Store = '0';
		else
			n2--;
	}
	return (r);
}
