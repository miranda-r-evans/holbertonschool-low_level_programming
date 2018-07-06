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
 * binary_tree_height - finds height of binary tree
 * @tree: tree to be evaluated
 *
 * Return: height of tree, or 0 on failure
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int rows = traverse_rows(tree);

	if (rows == 0)
	{
		return (0);
	}

	return (rows - 1);
}

/**
 * check_for_leaves - checks that all leaves are on the right
 * of the lowest level
 * @tree: tree to be evaluated
 * @depth: depth node should be at
 * @height: height of tree
 * @no_more_child: boolean keeps track if there should be
 * no more leaves in last level
 *
 * Return: TRUE if tree may be complete, false if not
 */
int check_for_leaves(const binary_tree_t *tree, size_t depth,
		     size_t height, int *no_more_child)
{
	if (tree->left == NULL)
	{
		if (tree->right == NULL)
		{
			if (depth == height && *no_more_child == FALSE)
			{
				return (TRUE);
			}
			if (depth == height - 1)
			{
				if (*no_more_child == FALSE)
				{
					*no_more_child = TRUE;
				}
				return (TRUE);
			}

			return (FALSE);
		}

		return (FALSE);
	}
	if (tree->right == NULL)
	{
		if (depth == height - 1 && *no_more_child == FALSE)
		{
			*no_more_child = TRUE;
			return (TRUE);
		}

		return (FALSE);
	}

	if (check_for_leaves(tree->left, depth + 1, height, no_more_child) == TRUE &&
	    check_for_leaves(tree->right, depth + 1, height, no_more_child) == TRUE)
	{
		return (TRUE);
	}

	return (FALSE);
}

/**
 * binary_tree_is_complete - checks if level except last are filled
 * and last level's nodes are as far left as possible
 * @tree: tree to be evaluated
 *
 * Return: 1 if complete, 0 if not/failure
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t height = binary_tree_height(tree);
	int no_more_child = FALSE;

	if (tree == NULL)
	{
		return (0);
	}

	if (height == 0)
	{
		return (1);
	}

	return (check_for_leaves(tree, 0, height, &no_more_child));
}
