#include "lists.h"

/**
 * free_listint2 - frees and list and sets head to NULL
 * @head: pointer to pointer to beginning of list
 */
void free_listint2(listint_t **head)
{
	listint_t *ptr;
	listint_t *temp = NULL;

	if (head == NULL)
		return;

	ptr = *head;

	while (ptr != NULL)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}

	*head = NULL;
}
