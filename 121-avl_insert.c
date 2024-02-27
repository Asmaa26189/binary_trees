#include "binary_trees.h"

/**
 * r_insert_node - r_insert_node
 * @tree: tree
 * @parent: parent
 * @n_new: n_new
 * @nval: nval
 * Return: avl_t
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **n_new, int nval)
{
	int b_val;

	if (*tree == NULL)
		return (*n_new = binary_tree_node(parent, nval));
	if ((*tree)->n > nval)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, n_new, nval);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < nval)
	{
		(*tree)->right = r_insert_node(&(*tree)->right, *tree, n_new, nval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	b_val = binary_tree_balance(*tree);
	if (b_val > 1 && (*tree)->left->n > nval)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (b_val > 1 && (*tree)->left->n < nval)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (b_val < -1 && (*tree)->right->n < nval)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (b_val < -1 && (*tree)->right->n > nval)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
/**
 * avl_insert - avl_insert
 * @tree: tree
 * @value: value
 * Return: avl_t
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *n_new = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	r_insert_node(tree, *tree, &n_new, value);
	return (n_new);
}
