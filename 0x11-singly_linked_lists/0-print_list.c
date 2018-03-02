#include "lists.h"

/**
 * print_itoa - converts a number to a string and prints it
 * @pain_in_a: number to convert and print
 */
void print_itoa(unsigned int pain_in_a)
{
	unsigned int dec = 1000000000;
	char buffer[11];
	char *iter = buffer;
	unsigned int digit;

	while (dec != 0)
	{
		digit = pain_in_a / dec;
		pain_in_a %= dec;
		dec /= 10;
		*iter = digit + '0';
		iter++;
	}

	*iter = '\0';
	iter = buffer;

	while (*iter == '0' && *(iter + 1) != '\0')
		iter++;

	while (*iter != '\0')
	{
		write(1, iter, 1);
		iter++;
	}
}

/**
 * print_struct - prints the length of the string in the struct and the string
 * @list: pointer to struct to print
 */
void print_struct(const list_t *list)
{
	char *c_ptr = list->str;

	if (c_ptr == NULL)
	{
		write(1, "[0] (nil)", 9);
		return;
	}

	write(1, "[", 1);
	print_itoa(list->len);
	write(1, "] ", 2);

	while (*c_ptr != '\0')
	{
		write(1, c_ptr, 1);
		c_ptr++;
	}
}

/**
 * print_list - prints the strings in all the entries in the linked list
 * @h: pointer to linked list
 *
 * Return: size of linked list
 */
size_t print_list(const list_t *h)
{
	size_t elmnts = 0;
	const list_t *l_ptr = h;

	while (l_ptr != NULL)
	{
       		print_struct(l_ptr);

		l_ptr = l_ptr->next;
		elmnts++;
		write(1, "\n", 1);
	}

	return (elmnts);
}
