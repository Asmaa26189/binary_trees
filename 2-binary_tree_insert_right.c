#include "binary_trees.h"
/**
 * binary_tree_insert_right - binary_tree_insert_right
 * @parent: parent
 * @value: value
 * Return: binary_tree_t
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *n_new;

	if (parent == NULL)
	{
		return (NULL);
	}

	n_new = binary_tree_node(parent, value);
	if (n_new == NULL)
	{
		return (NULL);
	}
	if (parent->right != NULL)
	{
		n_new->right = parent->right;
		parent->right->parent = n_new;
	}
	parent->right = n_new;
	return (n_new);
}
