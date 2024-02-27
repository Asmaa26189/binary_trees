#include "binary_trees.h"

/**
 * binary_tree_size - binary_tree_size
 * @tree: tree
 * Return: size_t
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * tree_is_complete - tree_is_complete
 * @tree: tree
 * @i: i
 * @node: node
 * Return: int
 */
int tree_is_complete(const binary_tree_t *tree, int i, int node)
{
	if (tree == NULL)
		return (1);

	if (i >= node)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, node) &&
		tree_is_complete(tree->right, (2 * i) + 2, node));
}


/**
 * binary_tree_is_complete - binary_tree_is_complete
 * @tree: tree
 * Return: int
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t node;

	if (tree == NULL)
		return (0);

	node = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, node));
}

/**
 * check_parent - check_parent
 * @tree: tree
 * Return: int
 */
int check_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_heap - binary_tree_is_heap
 * @tree: tree
 * Return: int
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

