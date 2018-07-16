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
 * find_insert_point - finds first empty area to insert at
 * @root: root of current subtree
 * @tree_height: used to determine if we are on the last level of tree
 *
 * Return: parent that node will be inserted under
 */
heap_t *find_insert_point(heap_t *root, size_t tree_height)
{
	size_t branch_height = binary_tree_height(root);
	heap_t *tmp;

	if (root->right == NULL)
	{
		if (root->left == NULL)
		{
			if (branch_height < tree_height)
			{
				return (root);
			}

			return (NULL);
		}

		return (root);
	}

	tmp = find_insert_point(root->left, tree_height - 1);
	if (tmp != NULL)
	{
		return (tmp);
	}

	tmp = find_insert_point(root->right, tree_height - 1);
	if (tmp != NULL)
	{
		return (tmp);
	}

	return (NULL);
}

/**
 * switch_up - swaps a node's value with its parent if its value is bigger
 * @node: node to be swapped
 *
 * Return: node with original value
 */
heap_t *switch_up(heap_t *node)
{
	int tmp;

	if (node->parent != NULL && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;

		return (switch_up(node->parent));
	}

	return (node);
}

/**
 * heap_insert - inserts a value into a max heap
 * @root: root of tree
 * @value: value of new node
 *
 * Return: inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t height;
	heap_t *insert_point;
	heap_t *new_node;

	if (root == NULL)
	{
		return (NULL);
	}

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	height = binary_tree_height(*root);
	insert_point = find_insert_point(*root, height);

	if (insert_point == NULL)
	{
		insert_point = *root;
		while (insert_point->left != NULL)
		{
			insert_point = insert_point->left;
		}
	}

	if (insert_point->left == NULL)
	{
		new_node = binary_tree_node(insert_point, value);
		insert_point->left = new_node;
	}
	else
	{
		new_node = binary_tree_node(insert_point, value);
		insert_point->right = new_node;
	}

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node = switch_up(new_node);

	if (new_node->parent == NULL)
	{
		*root = new_node;
	}

	return (new_node);
}
