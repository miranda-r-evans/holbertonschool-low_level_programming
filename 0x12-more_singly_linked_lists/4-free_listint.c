#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: beginning of list
 */
void free_listint(listint_t *head)
{
	listint_t *ptr = head;
	listint_t *temp = NULL;

	while (ptr != NULL)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
}
