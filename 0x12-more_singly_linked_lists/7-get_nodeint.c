#include "lists.h"

/**
 * get_nodeint_at_index - finds the node at the given index of the list
 * @head: beginning of list
 * @index: index of the node we want to find
 *
 * Return: node at the given index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *ptr = head;

	while (ptr != NULL)
	{
		if (i == index)
			return (ptr);

		ptr = ptr->next;
		i++;
	}

	return (NULL);
}
