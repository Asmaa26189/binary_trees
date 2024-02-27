#include "binary_trees.h"

/**
 * binary_trees_ancestor - binary_trees_ancestor
 * @first: first
 * @second: second
 * Return: binary_tree_t
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *p_binary_tree;
	binary_tree_t *q_binary_tree;

	if (first == NULL)
	{
		return (NULL);
	}
	if (second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	p_binary_tree = first->parent;
	q_binary_tree = second->parent;
	if (p_binary_tree == NULL || first == q_binary_tree || (!p_binary_tree->parent && q_binary_tree))
	{
		return (binary_trees_ancestor(first, q_binary_tree));
	}
	else if (q_binary_tree == NULL || p_binary_tree == second || (!q_binary_tree->parent && p_binary_tree))
	{
		return (binary_trees_ancestor(p_binary_tree, second));
	}
	return (binary_trees_ancestor(p_binary_tree, q_binary_tree));
}
