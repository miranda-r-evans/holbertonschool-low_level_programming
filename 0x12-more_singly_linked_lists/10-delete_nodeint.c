#include "lists.h"

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *ptr = *head;
	listint_t *temp;
	unsigned int i = 1;

	if (index == 0 && ptr != NULL)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
		return (1);
	}

	while (ptr != NULL)
	{
		if (i == index)
		{
			temp = ptr->next;
			if (temp == NULL)
				return (-1);
			ptr->next = temp->next;
			free(temp);
			return (1);
		}
		ptr = ptr->next;
		i++;
	}

	return (-1);
}
