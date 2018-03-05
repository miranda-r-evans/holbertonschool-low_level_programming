#include "lists.h"

int pop_listint(listint_t **head)
{
	int ret = (*head)->n;
	listint_t *to_del = *head;

	*head = (*head)->next;
	free(to_del);
	return (ret);
}
