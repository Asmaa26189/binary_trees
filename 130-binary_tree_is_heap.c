#include "binary_trees.h"

/**
 * binary_tree_height - binary_tree_height
 * @tree: tree
 * Return: size_t
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_bt = 0;
	size_t r_bt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);
		if (tree)
		{
			l_bt = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			r_bt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
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
		left = ((int)binary_tree_height(tree->left));
		right = ((int)binary_tree_height(tree->right));
		ttl = left - right;
	}
	return (ttl);
}

/**
 * tree_is_perfect - tree_is_perfect
 * @tree: tree
 * Return: int
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int l_bt = 0;
	int r_bt = 0;

	if (tree->left && tree->right)
	{
		l_bt = 1 + tree_is_perfect(tree->left);
		r_bt = 1 + tree_is_perfect(tree->right);
		if (r_bt == l_bt && r_bt != 0 && l_bt != 0)
			return (r_bt);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - binary_tree_is_perfect
 * @tree: tree
 * Return: int
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int rsl = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		rsl = tree_is_perfect(tree);
		if (rsl != 0)
		{
			return (1);
		}
		return (0);
	}
}

/**
 * binary_tree_is_heap - binary_tree_is_heap
 * @tree: tree
 * Return: int
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int b_v;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left && tree->left->n > tree->n)
	{
		return (0);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		return (0);
	}
	if (binary_tree_is_perfect(tree))
	{
		return (1);
	}
	b_v = binary_tree_balance(tree);
	if (b_v == 0)
	{
		return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_heap(tree->right));
	}
	if (b_v == 1)
	{
		return (binary_tree_is_heap(tree->left)
			&& binary_tree_is_perfect(tree->right));
	}
	else
	{
		return (0);
	}
}
