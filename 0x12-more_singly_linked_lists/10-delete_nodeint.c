#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node at a given indez in a linked list
 * @head: pointer to pointer to beginning of linked list
 * @index: index of node to be deleted
 *
 * Return: 1 if successful, -1 if failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *ptr = NULL;
	listint_t *temp = NULL;
	unsigned int i = 1;

	if (head == NULL || *head == NULL)
		return (-1);

	ptr = *head;

	if (index == 0 && ptr != NULL)
	{
		temp = ptr->next;
		free(ptr);
		*head = temp;
		return (1);
	}

	while (ptr != NULL)
	{
		if (i == index)
		{
			temp = ptr->next;
			if (temp == NULL)
				return (-1);
			ptr->next = temp->next;
			free(temp);
			return (1);
		}
		ptr = ptr->next;
		i++;
	}

	return (-1);
}
