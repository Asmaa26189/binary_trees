#include "binary_trees.h"
/**
 * binary_tree_depth - binary_tree_depth
 * @tree: tree
 * Return: size_t
 */
size_t binary_tree_depth(const binary_tree_s *tree)
{
	size_t value = ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
    return value;
}
