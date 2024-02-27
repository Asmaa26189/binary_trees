#include "binary_trees.h"
/**
 * bst_search - bst_search
 * @tree: tree
 * @value: value
 * Return: bst_t
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *fnd;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		fnd = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		fnd = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (fnd);
}
