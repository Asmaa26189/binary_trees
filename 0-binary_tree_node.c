#include "binary_trees.h"

/**
 * binary_tree_node - binary_tree_node
 * @parent: parent
 * @value: value
 * Return: binary_tree_s
 */

binary_tree_s *binary_tree_node(binary_tree_s *parent, int value)
{
	binary_tree_s *new_node;

	new_node = malloc(sizeof(binary_tree_s));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
