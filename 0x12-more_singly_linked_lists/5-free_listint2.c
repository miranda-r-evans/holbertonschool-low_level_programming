#include "lists.h"

void free_listint2(listint_t **head)
{
	listint_t *ptr = *head;
	listint_t *temp;

	while (ptr != NULL)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}

	*head = NULL;
}
