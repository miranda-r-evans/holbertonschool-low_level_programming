#include "hash_tables.h"

#define TRUE 0
#define FALSE 1

/**
 * zero_shash_table - sets values in table's array to 0
 * @table: table to be set
 * @size: size of array
 */
void zero_shash_table(shash_table_t *table, unsigned long int size)
{
	shash_node_t **ptr = table->array;
	unsigned long int i;

	for (i = 0; i < size; i++)
	{
		*ptr = NULL;
		ptr++;
	}
}

/**
 * shash_table_create - creates a new hash table
 * @size: size of hash table to be created
 *
 * Return: the new table, or NULL if error occurred
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ret = malloc(sizeof(shash_table_t));

	if (ret == NULL)
	{
		return (NULL);
	}

	ret->array = malloc(sizeof(shash_node_t *) * size);
	if (ret->array == NULL)
	{
		free(ret);
		return (NULL);
	}

	zero_shash_table(ret, size);

	ret->size = size;

	ret->shead = NULL;

	ret->stail = NULL;

	return (ret);
}

/**
 * set_sorted_list - inserts a node into the sorted list of the hash table,
 * based on key value
 * @ht: the hash table
 * @unset_node: node to be inserted
 */
void set_sorted_list(shash_table_t *ht, shash_node_t *unset_node)
{
	shash_node_t *node_ptr = ht->shead;

	if (ht->shead == NULL)
	{
		ht->shead = unset_node;
		ht->stail = unset_node;
		return;
	}

	while (node_ptr->snext != NULL &&
	       strcmp(node_ptr->key, unset_node->key) < 0)
	{
		node_ptr = node_ptr->snext;
	}

	if (strcmp(node_ptr->key, unset_node->key) < 0)
	{
		node_ptr->snext = unset_node;
		unset_node->snext = NULL;
		unset_node->sprev = node_ptr;
		ht->stail = unset_node;
		return;
	}

	unset_node->snext = node_ptr;
	unset_node->sprev = node_ptr->sprev;
	if (node_ptr->sprev == NULL)
	{
		ht->shead = unset_node;
	}
	else
	{
		node_ptr->sprev->snext = unset_node;
	}
	node_ptr->sprev = unset_node;
}

/**
 * shash_table_set - adds a new key/value pair to the hash table,
 * or updates an existing one
 * @ht: the hash table
 * @key: key used for retrieving value
 * @value: value to be added
 *
 * Return: 1 if Success, 0 if failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL ||
	    ht->size == 0)
	{
		return (0);
	}

	index = key_index((const unsigned char *)key, ht->size);

	new_node = ht->array[index];

	if (new_node != NULL)
	{
		while (new_node->next != NULL &&
		       strcmp(new_node->key, key) != 0)
		{
			new_node = new_node->next;
		}

		if (strcmp(new_node->key, key) == 0)
		{
			free(new_node->value);
			new_node->value = strdup(value);
			return (1);
		}
		new_node->next = malloc(sizeof(hash_node_t));
		new_node = new_node->next;
	}
	else
	{
		new_node = malloc(sizeof(shash_node_t));
		ht->array[index] = new_node;
	}
	if (new_node == NULL)
	{
		return (0);
	}
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;

	set_sorted_list(ht, new_node);

	return (1);
}

/**
 * shash_table_get - retrieves a value, using a key
 * @ht: hash table containing key/value pair
 * @key: key used to find the value
 *
 * Return: the value if success, NULL if failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node_ptr;

	if (ht == NULL || key == NULL || *key == '\0' || ht->size == 0)
	{
		return (NULL);
	}

	index = key_index((const unsigned char *)key, ht->size);

	node_ptr = ht->array[index];

	while (node_ptr != NULL)
	{
		if (strcmp(node_ptr->key, key) == 0)
		{
			return (node_ptr->value);
		}
		node_ptr = node_ptr->snext;
	}

	return (NULL);
}

/**
 * shash_table_print - prints the hash table in Python dictionary format,
 * in alphabetical order
 * @ht: hash table to be printed
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node_ptr = ht->shead;
	int is_first = TRUE;

	if (ht == NULL)
	{
		return;
	}

	if (ht->size == 0)
	{
		printf("{}\n");
		return;
	}

	printf("{");

	while (node_ptr != NULL)
	{
		if (is_first == FALSE)
		{
			printf(", '%s': '%s'", node_ptr->key, node_ptr->value);
		}
		else
		{
			printf("'%s': '%s'", node_ptr->key, node_ptr->value);
			is_first = FALSE;
		}

		node_ptr = node_ptr->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - prints the hash table in Python dictionary format,
 * in reverse alphabetical order
 * @ht: hash table to be printed
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node_ptr = ht->stail;
	int is_first = TRUE;

	if (ht == NULL)
	{
		return;
	}

	if (ht->size == 0)
	{
		printf("{}\n");
		return;
	}

	printf("{");

	while (node_ptr != NULL)
	{
		if (is_first == FALSE)
		{
			printf(", '%s': '%s'", node_ptr->key, node_ptr->value);
		}
		else
		{
			printf("'%s': '%s'", node_ptr->key, node_ptr->value);
			is_first = FALSE;
		}

		node_ptr = node_ptr->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - frees a hash table
 * @ht: table to be freed
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node_ptr = ht->shead;
	shash_node_t *tmp;

	if (ht == NULL)
	{
		return;
	}

	if (ht->size == 0)
	{
		free(ht);
		return;
	}

	while (node_ptr != NULL)
	{
		tmp = node_ptr;
		node_ptr = node_ptr->snext;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}

	free(ht->array);

	free(ht);
}
