#include "lists.h"

/**
 * listint_len - returns the length of the linked list
 * @h: linked list
 *
 * Return: length of linked list
 */
size_t listint_len(const listint_t *h)
{
	const listint_t *ptr = h;
	size_t elmnts = 0;

	while (ptr != NULL)
	{
		elmnts++;
		ptr = ptr->next;
	}

	return (elmnts);
}
