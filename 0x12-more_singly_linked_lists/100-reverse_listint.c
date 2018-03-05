#include "lists.h"

listint_t *reverse_listint(listint_t **head)
{
	listint_t *aft_t = NULL;
	listint_t *bef_t = NULL;

	while (*head != NULL)
	{
		aft_t = (*head)->next;
		if (bef_t != NULL)
			(*head)->next = bef_t;
		else
			(*head)->next = NULL;
		bef_t = *head;
		*head = aft_t;
	}
	*head = bef_t;

	return (*head);
}
