#include "binary_trees.h"
/**
 * binary_tree_size - binary_tree_size
 * @tree: tree
 * Return: size_t
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;
	size_t r_size = 0;
	size_t l_size = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		l_size = binary_tree_size(tree->left);
		r_size = binary_tree_size(tree->right);
		size = r_size + l_size + 1;
	}
	return (size);
}
