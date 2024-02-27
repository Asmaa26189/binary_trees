#include "binary_trees.h"

/**
 * binary_tree_rotate_left - binary_tree_rotate_left
 * @tree: tree
 * Return: binary_tree_t
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pv;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	pv = tree->right;
	tree->right = pv->left;
	if (pv->left != NULL)
	{
		pv->left->parent = tree;
	}
	pv->left = tree;
	pv->parent = tree->parent;
	tree->parent = pv;
	return (pv);
}
