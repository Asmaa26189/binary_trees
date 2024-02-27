#include "binary_trees.h"
/**
 * binary_tree_leaves - binary_tree_leaves
 * @tree: tree
 * Return: size_t
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lf = 0;
	size_t l_s = 0;
	size_t r_s = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		l_s = binary_tree_leaves(tree->left);
		r_s = binary_tree_leaves(tree->right);
		lf = l_s + r_s;
		return ((!l_s && !r_s) ? lf + 1 : lf + 0);
	}
}
