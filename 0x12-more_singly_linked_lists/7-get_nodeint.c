#include "lists.h"

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
