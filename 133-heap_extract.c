#include "binary_trees.h"

/**
 * max - max
 * @tree: tree
 * Return: heap_t
 */
heap_t *max(heap_t *tree)
{
	heap_t *cur;
	heap_t *left;
	heap_t *right;

	if (!tree->left)
		return (tree);
	left = max(tree->left);
	if (left->n > tree->n)
		cur = left;
	else
		cur = tree;
	if (tree->right)
	{
		right = max(tree->right);
		if (right->n > cur->n)
			cur = right;
		else
			cur = tree;
	}
	return (cur);
}

/**
 * recurse_extract - recurse_extract
 * @tree: tree
 */
void recurse_extract(heap_t *tree)
{
	heap_t *sub;
	heap_t *right = NULL;

	if (!tree->left)
		return;
	sub = max((tree)->left);
	if (tree->right)
		right = max(tree->right);
	if (right && right->n > sub->n)
		sub = right;
	tree->n = sub->n;
	if (!sub->left)
	{
		if (sub->parent && sub->parent->left == sub)
			sub->parent->left = NULL;
		if (sub->parent && sub->parent->right == sub)
			sub->parent->right = NULL;
		free(sub);
	}
	else
		recurse_extract(sub);
}

/**
 * heap_extract - heap_extract
 * @root: root
 * Return: int
 */
int heap_extract(heap_t **root)
{
	int val;

	if (!*root)
		return (0);
	val = (*root)->n;
	if (!(*root)->left)
	{
		val = (*root)->n;
		free(*root);
		*root = NULL;
		return (val);
	}
	recurse_extract(*root);
	return (val);
}
