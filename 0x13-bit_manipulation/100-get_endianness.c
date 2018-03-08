#include "holberton.h"

int get_endianness(void)
{
	unsigned int x = 1;
	char *ptr = (char *)&x;

	if (*ptr == 1)
		return (1); /* little endian */

	return (0); /* big endian */
}
