#include "binary_trees.h"
/**
 * bst_insert - bst_insert
 * @tree: tree
 * @value: value
 * Return: bst_t
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *n_new;
	bst_t *tmp;
	binary_tree_t *a_x;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		a_x = binary_tree_node((binary_tree_t *)(*tree), value);
		n_new = (bst_t *)a_x;
		*tree = n_new;
	}
	else
	{
		tmp = *tree;
		if (value < tmp->n)
		{
			if (tmp->left)
				n_new = bst_insert(&tmp->left, value);
			else
			{
				a_x = binary_tree_node((binary_tree_t *)tmp, value);
				n_new = tmp->left = (bst_t *)a_x;
			}
		}
		else if (value > tmp->n)
		{
			if (tmp->right)
				n_new = bst_insert(&tmp->right, value);
			else
			{
				a_x = binary_tree_node((binary_tree_t *)tmp, value);
				n_new = tmp->right = a_x;
			}
		}
		else
			return (NULL);
	}
	return (n_new);
}
