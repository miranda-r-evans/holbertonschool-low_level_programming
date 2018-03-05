#include "lists.h"


/**
 * add_nodeint_end - adds a node to the end of a linked list
 * @head: beginning of list
 * @n: value of node
 *
 * Return: pointer to new node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new = malloc(sizeof(listint_t));
	listint_t *ptr = *head;

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}

	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	ptr->next = new;

	return (new);
}
