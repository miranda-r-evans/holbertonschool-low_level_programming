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

list_t *add_node(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));

	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	new->len = _strlen(str);
	new->next = *head;
	*head = new;

	return (*head);
}
