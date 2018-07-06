#include "binary_trees.h"

/**
 * binary_tree_node - creates a node for a binary tree
 * @parent: parent of node
 * @value: value of node
 *
 * Return: pointer to new node, NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	return (new_node);
}
