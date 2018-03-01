#include "lists.h"

/**
 * free_list - frees and linked list
 * @head: pointer to beginning of list
 */
void free_list(list_t *head)
{
	list_t *l_ptr = head;

	while (head != NULL)
	{
		l_ptr = head->next;
		free(head->str);
		free(head);
		head = l_ptr;
	}
}
