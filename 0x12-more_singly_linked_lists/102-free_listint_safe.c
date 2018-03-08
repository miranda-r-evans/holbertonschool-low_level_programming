#include "lists.h"

/**
 * free_listint_safe - frees a list that may be in a loop
 * @h: pointer to pointer to beginning of list
 *
 * Return: size of list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t elmnts = 0;
	listint_t *temp = NULL;

	if (h == NULL || *h == NULL)
		return (0);

	while (*h != NULL)
	{
		temp = (*h)->next;
		free(*h);
		*h = temp;
		elmnts++;
	}

	h = NULL;

	return (elmnts);
}
