#include "lists.h"

/**
 * print_listint - function to print a linked list of ints
 * @h: beginning of linked list
 *
 * Return: length of list
 */
size_t print_listint(const listint_t *h)
{
	size_t elmnts = 0;
	const listint_t *ptr = h;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		elmnts++;
		ptr = ptr->next;
	}

	return (elmnts);
}
