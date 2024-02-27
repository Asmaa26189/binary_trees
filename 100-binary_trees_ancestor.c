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
	binary_tree_t *p_b_t;
	binary_tree_t *q_b_t;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)second);
	}

	p_b_t = first->parent;
	q_b_t = second->parent;
	if (p_b_t == NULL || first == q_b_t || (!p_b_t->parent && q_b_t))
	{
		return (binary_trees_ancestor(first, q_b_t));
	}
	else if (q_b_t == NULL || p_b_t == second || (!q_b_t->parent && p_b_t))
	{
		return (binary_trees_ancestor(p_b_t, second));
	}
	return (binary_trees_ancestor(p_b_t, q_b_t));
}
