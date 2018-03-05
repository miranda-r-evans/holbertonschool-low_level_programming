#include "lists.h"

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new = malloc(sizeof(listint_t));
	listint_t *ptr = *head;
	unsigned int i = 1;

	if (new == NULL)
		return (NULL);

	new->n = n;

	if (idx == 0 && ptr != NULL)
	{
		new->next = *head;
		*head = new;
		return (*head);
	}

	while (ptr != NULL)
	{
		if (i == idx)
		{
			new->next = ptr->next;
			ptr->next = new;
			return (new);
		}

		ptr = ptr->next;
		i++;
	}

	return (NULL);
}
