#include "lists.h"

/**
 * add_nodeint - adds a node to the beginning of a list
 * @head: pointer to pointer to the first node
 * @n: value of node to be added
 *
 * Return: pointer to new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		return (*head);
	}

	new->next = *head;
	*head = new;

	return (*head);
}
