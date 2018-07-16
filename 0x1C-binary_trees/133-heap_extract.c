#include "binary_trees.h"

/**
 * find_last node - finds last node in tree
 * @root: root of current subtree
 * @height: used to determine if we are on the last level of tree
 *
 * Return: last node
 */
heap_t *find_last_node(heap_t *root, size_t height)
{
	heap_t *left;
	heap_t *right;

	if (root == NULL)
	{
		return (NULL);
	}

	if (height == 0 && binary_tree_height(root) == height)
	{
		return (root);
	}

	right = find_last_node(root->right, height - 1);
	if (right != NULL)
	{
		return (right);
	}

	left = find_last_node(root->left, height - 1);
	if (left != NULL)
	{
		return (left);
	}

	return (NULL);
}

/**
 * replace - replaces one node with another
 * @to_del: node to be deleted
 * @to_rep: node to replace deleted with (or NULL)
 */
void replace(bst_t *to_del, bst_t *to_rep)
{
	if (to_rep != NULL)
	{
		if (to_rep->parent->left == to_rep)
		{
			if (to_rep->left != NULL)
			{
				to_rep->parent->left = to_rep->left;
				to_rep->left->parent = to_rep->parent;
			}
			else if (to_rep->right != NULL)
			{
				to_rep->parent->left = to_rep->right;
				to_rep->right->parent = to_rep->parent;
			}
			else
			{
				to_rep->parent->left = NULL;
			}
		}
		else
		{
			if (to_rep->left != NULL)
			{
				to_rep->parent->right = to_rep->left;
				to_rep->left->parent = to_rep->parent;
			}
			else if (to_rep->right != NULL)
			{
				to_rep->parent->right = to_rep->right;
				to_rep->right->parent = to_rep->parent;
			}
			else
			{
				to_rep->parent->right = NULL;
			}
		}

		to_rep->parent = to_del->parent;
		to_rep->left = to_del->left;
		to_rep->right = to_del->right;
	}

	if (to_del->parent != NULL)
	{
		if (to_del->parent->left == to_del)
		{
			to_del->parent->left = to_rep;
		}
		else
		{
			to_del->parent->right = to_rep;
		}
	}

	if (to_del->left != NULL)
	{
		to_del->left->parent = to_rep;
	}
	if (to_del->right != NULL)
	{
		to_del->right->parent = to_rep;
	}

	free(to_del);
}

heap_t *switch_up(heap_t *node);

/**
 * heap_extract - extracts root of tree
 * @root: root of tree
 *
 * Return: value of old root
 */
int heap_extract(heap_t **root)
{
	heap_t *parent;
	heap_t *child;
	heap_t *last_node;
	size_t height = binary_tree_height(*root);
	int extract_val;

	if (root == NULL || *root == NULL)
	{
		return (0);
	}

	child = *root;

	extract_val = child->n;

	while (child != NULL)
	{
		parent = child;
		if (parent->left != NULL)
		{
			if (parent->right != NULL && parent->left->n < parent->right->n)
			{
				parent->n = parent->right->n;
				child = parent->right;
			}
			else
			{
				parent->n = parent->left->n;
				child = parent->left;
			}
		}
		else 
		{
			child = NULL;
		}
	}

	last_node = find_last_node(*root, height);

	if (last_node == *root)
	{
		free (*root);
		*root = NULL;
		return (extract_val);
	}

	if (last_node == parent)
	{
		replace(parent, NULL);
		return (extract_val);
	}

	replace(parent, last_node);

	switch_up(last_node);

	return (extract_val);
}
