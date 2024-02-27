#include "binary_trees.h"

/**
 * binary_tree_height_b - binary_tree_height_b
 * @tree: tree
 * Return: size_t
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t l_bt = 0;
	size_t r_bt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l_bt = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
			r_bt = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
		}
		return ((l_bt > r_bt) ? l_bt : r_bt);
	}
}

/**
 * binary_tree_balance - binary_tree_balance
 * @tree: tree
 * Return: int
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0;
	int left = 0;
	int ttl = 0;

	if (tree)
	{
		left = ((int)binary_tree_height_b(tree->left));
		right = ((int)binary_tree_height_b(tree->right));
		ttl = left - right;
	}
	return (ttl);
}
