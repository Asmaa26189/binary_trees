#include "binary_trees.h"
/**
 * tree_is_perfect - tree_is_perfect
 * @tree: tree
 * Return: int
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int x = 0;
	int y = 0;

	if (tree->left && tree->right)
	{
		x = 1 + tree_is_perfect(tree->left);
		y = 1 + tree_is_perfect(tree->right);
		if (y == x && y != 0 && x != 0)
			return (y);
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
	int rslt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		rslt = tree_is_perfect(tree);
		if (rslt != 0)
		{
			return (1);
		}
		return (0);
	}
}
