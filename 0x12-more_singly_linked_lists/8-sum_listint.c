#include "lists.h"

/**
 * sum_listint - finds the sum of the values stored int the linked list
 * @head: beginning of list
 *
 * Return: sum of the values
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *ptr = head;

	while (ptr != NULL)
	{
		sum += ptr->n;
		ptr = ptr->next;
	}

	return (sum);
}
