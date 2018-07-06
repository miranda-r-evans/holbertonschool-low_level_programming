#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates a binary tree to the right
 * @tree: root of tree/subtree to be rotated
 *
 * Return: new root of tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->left == NULL)
	{
		return (tree);
	}

	new_root = tree->left;
	tree->left = new_root->right;

	if (tree->left != NULL)
	{
		tree->left->parent = tree;
	}

	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
		{
			tree->parent->left = new_root;
		}
		else
		{
			tree->parent->right = new_root;
		}
	}

	new_root->parent = tree->parent;
	new_root->right = tree;
	tree->parent = new_root;

	return (new_root);
}
