#include "binary_trees.h"
/**
 * check_sub_tree_Left - check_sub_tree_Left
 * @n: n
 * @max: max
 * Return: int
 */
int check_sub_tree_Left(const binary_tree_t *n, int max)
{
	int left = 0;
	int right = 0;

	if (n == NULL)
	{
		return (1);
	}
	else
	{
		if (n->n >= max)
			return (0);
		left = check_sub_tree_Left(n->left, max);
		right = check_sub_tree_Left(n->right, max);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}
/**
 * check_sub_tree_Right - check_sub_tree_Right
 * @n: n
 * @min: min
 * Return: int
 */
int check_sub_tree_Right(const binary_tree_t *n, int min)
{
	int left = 0;
	int right = 0;

	if (n == NULL)
	{
		return (1);
	}
	else
	{
		if (n->node <= min)
			return (0);
		left = check_sub_tree_Right(n->left, min);
		right = check_sub_tree_Right(n->right, min);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - binary_tree_is_bst
 * @tree: tree
 * Return: int
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int v = 0;
	int left = 2;
	int right = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		v = check_sub_tree_Left(tree->left, tree->n);
		if (v == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		v = check_sub_tree_Right(tree->right, tree->n);
		if (v == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}
	return (1);
}
