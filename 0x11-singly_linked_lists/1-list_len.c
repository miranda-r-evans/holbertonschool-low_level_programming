#include "lists.h"

/**
 * list_len - finds the length of a linked list
 * @h: pointer to first entry in list
 *
 * Return: length of list (as a size_t)
 */
size_t list_len(const list_t *h)
{
	size_t elmnts = 0;

	const list_t *l_ptr = h;

	while (1)
	{
		if (l_ptr != NULL)
			elmnts++;
		else
			break;

		l_ptr = l_ptr->next;
	}

	return (elmnts);
}
