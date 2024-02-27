#include "binary_trees.h"
/**
 * binary_tree_insert_left - binary_tree_insert_left
 * @parent: parent
 * @value: value
 * Return: binary_tree_s
 */
binary_tree_s *binary_tree_insert_left(binary_tree_s *parent, int value)
{
	binary_tree_s *n_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	n_node = binary_tree_node(parent, value);
	if (n_node == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		n_node->left = parent->left;
		parent->left->parent = n_node;
	}
	parent->left = n_node;
	return (n_node);
}
