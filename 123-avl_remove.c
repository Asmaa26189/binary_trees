#include "binary_trees.h"

/**
 * bal - bal
 * @tree: tree
 * Return: void
 */
void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
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
 *remove_type - remove_type
 *@root: root
 *Return: int
 */
int remove_type(bst_t *root)
{
	int n_value = 0;

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
	{
		n_value = successor(root->right);
		root->n = n_value;
		return (n_value);
	}
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

/**
 * avl_remove - avl_remove
 * @root: root
 * @value: value
 * Return: avl_t
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *rt_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (rt_a == NULL)
		return (NULL);
	bal(&rt_a);
	return (rt_a);
}
