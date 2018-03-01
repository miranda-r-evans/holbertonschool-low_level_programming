#include "lists.h"

int _strlen(const char *str)
{
	const char *cpy = str;
	int i = 0;

	while (*cpy != '\0')
	{
		i++;
		cpy++;
	}

	return (i);
}

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));
	list_t *l_ptr = *head;

	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	new->len = _strlen(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}

	while (l_ptr->next != NULL)
	{
		l_ptr = l_ptr->next;
	}

	l_ptr->next = new;

	return (new);
}
