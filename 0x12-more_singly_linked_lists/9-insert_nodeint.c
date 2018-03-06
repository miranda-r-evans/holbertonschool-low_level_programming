#include "lists.h"

/**
 * insert_nodeint_at_index - insert a node at a given index in the linked list
 * @head: pointer to pointer to beginning of list
 * @idx: the given index
 * @n: value of node to be inserted
 *
 * Return: pointer to new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new;
	listint_t *ptr = *head;
	unsigned int i = 1;

	if (head == NULL || *head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	ptr = *head;

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
