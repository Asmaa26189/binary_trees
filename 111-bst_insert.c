#include "binary_trees.h"
/**
 * bst_insert - insert nodes in order to create a BST tree
 * @tree: tree to create with type BST
 * @value: value of node to insert
 * Return: BST tree
 */
b_s *bst_insert(b_s **tree, int value)
{
	b_s *new, *temp;
	binary_tree_s *aux;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		aux = binary_tree_node((binary_tree_s *)(*tree), value);
		new = (b_s *)aux;
		*tree = new;
	}
	else
	{
		temp = *tree;
		if (value < temp->n)
		{
			if (temp->left)
				new = bst_insert(&temp->left, value);
			else
			{
				aux = binary_tree_node((binary_tree_s *)temp, value);
				new = temp->left = (b_s *)aux;
			}
		}
		else if (value > temp->n)
		{
			if (temp->right)
				new = bst_insert(&temp->right, value);
			else
			{
				aux = binary_tree_node((binary_tree_s *)temp, value);
				new = temp->right = aux;
			}
		}
		else
			return (NULL);
	}
	return (new);
}
