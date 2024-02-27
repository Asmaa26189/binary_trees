#include "binary_trees.h"

/**
 * binary_tree_height - binary_tree_height
 * @tree: tree
 * Return: size_t
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_s = 0;
	size_t r_s = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l_s = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			r_s = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((l_s > r_s) ? l_s : r_s);
		}
}

/**
 * bal_avl - bal_avl
 * @tree: tree
 * @high: high
 * @lower: lower
 * Return: int
 */
int bal_avl(const binary_tree_t *tree, int lower, int high)
{
	size_t h_l;
	size_t h_r;
	size_t br;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < lower)
		{
			return (0);
		}
		h_l = binary_tree_height(tree->left);
		h_r = binary_tree_height(tree->right);
		br = h_l > h_r ? h_l - h_r : h_r - h_l;
		if (br > 1)
		{
			return (0);
		}
		return (bal_avl(tree->left, lower, tree->n - 1) &&
			bal_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - binary_tree_is_avl
 * @tree: tree
 * Return: int
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (bal_avl(tree, INT_MIN, INT_MAX));
}
