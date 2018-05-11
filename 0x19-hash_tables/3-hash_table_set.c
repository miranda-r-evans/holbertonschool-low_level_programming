#include "hash_tables.h"

/**
 * hash_table_set - adds a new key/value pair to the hash table,
 * or updates an existing one
 * @ht: the hash table
 * @key: key used for retrieving value
 * @value: value to be added
 *
 * Return: 1 if Success, 0 if failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node_ptr;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
	{
		return (0);
	}

	index = key_index((const unsigned char *)key, ht->size);

	node_ptr = ht->array[index];

	if (node_ptr == NULL)
	{
		node_ptr = malloc(sizeof(hash_node_t));
		if (node_ptr == NULL)
		{
			return (0);
		}
		node_ptr->key = strdup(key);
		node_ptr->value = strdup(value);
		node_ptr->next = NULL;
		ht->array[index] = node_ptr;
	}
	else
	{
		while (node_ptr->next != NULL &&
		       strcmp(node_ptr->key, key) != 0)
		{
			node_ptr = node_ptr->next;
		}

		if (strcmp(node_ptr->key, key) == 0)
		{
			free(node_ptr->value);
			node_ptr->value = strdup(value);
		}
		else
		{
			node_ptr->next = malloc(sizeof(hash_node_t));
			if (node_ptr->next == NULL)
			{
				return (0);
			}
			node_ptr = node_ptr->next;
			node_ptr->key = strdup(key);
			node_ptr->value = strdup(value);
			node_ptr->next = NULL;
		}
	}

	return (1);
}
