#include "binary_trees.h"

/**
 * traverse_rows - counts rows of tree
 * @tree: tree to be evaluated
 *
 * Return: rows, or 0 on failure
 */
int traverse_rows(const binary_tree_t *tree)
{
	int left;
	int right;

	if (tree == NULL)
	{
		return (0);
	}

	left = traverse_rows(tree->left);
	right = traverse_rows(tree->right);

	if (left > right)
	{
		return (left + 1);
	}

	return (right + 1);
}

/**
 * binary_tree_balance - finds balance factor of tree
 * @tree: tree to be evaluated
 *
 * Return: balance factor, 0 on failure
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left;
	int right;

	if (tree == NULL)
	{
		return (0);
	}

	left = traverse_rows(tree->left);
	right = traverse_rows(tree->right);

	return (left - right);
}
