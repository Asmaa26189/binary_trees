#include "binary_trees.h"
/**
 * binary_tree_nodes - binary_tree_nodes
 * @tree: tree
 * Return: size_t
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	size_t  n = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		n += ((tree->left || tree->right) ? 1 : 0);
		n += binary_tree_nodes(tree->left);
		n += binary_tree_nodes(tree->right);
		return (n);
	}
}
