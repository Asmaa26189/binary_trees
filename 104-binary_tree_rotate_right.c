#include "binary_trees.h"

/**
 * binary_tree_rotate_right - binary_tree_rotate_right
 * @tree: tree
 * Return: binary_tree_t
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pv;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	pv = tree->left;
	tree->left = pv->right;
	if (pv->right != NULL)
	{
		pv->right->parent = tree;
	}
	pv->right = tree;
	pv->parent = tree->parent;
	tree->parent = pv;
	return (pv);
}
