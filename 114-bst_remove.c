#include "binary_trees.h"
/**
 * successor - successor
 * @node: node
 * Return: int
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 * two_children - two_children
 * @root: root
 * Return: int
 */
int two_children(bst_t *root)
{
	int new_value = 0;

	new_value = successor(root->right);
	root->n = new_value;
	return (new_value);
}
/**
 *remove_type - remove_type
 *@root: root
 *Return: int
 */
int remove_type(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (two_children(root));
}
/**
 * bst_remove - bst_remove
 * @root: root
 * @value: value
 * Return: bst_t
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int tp = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		tp = remove_type(root);
		if (tp != 0)
			bst_remove(root->right, tp);
	}
	else
		return (NULL);
	return (root);
}
