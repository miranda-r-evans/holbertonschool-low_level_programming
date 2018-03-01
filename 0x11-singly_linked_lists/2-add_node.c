#include "lists.h"

/**
 * _strlen - finds the length of a string
 * @str: string to be evaluated
 *
 * Return: length of str
 */
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

/**
 * add_node - adds an entry to the beginning of a linked list
 * @head: pointer to beginning of list
 * @str: content of entry to be added
 *
 * Return: pointer to beginning of list
 */
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
