#include "binary_trees.h"
/**
 * binary_tree_height - binary_tree_height
 * @tree: tree
 * Return: size_t
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_b_t = 0;
	size_t r_b_t = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l_b_t = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			r_b_t = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((l_b_t > r_b_t) ? l_b_t : r_b_t);
	}
}
/**
 * binary_tree_depth - binary_tree_depth
 * @tree: tree
 * Return: size_t
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node - linked_node
 * @hd: hd
 * @tree: tree
 * @lvl: lvl
 * Return: void
 */
void linked_node(link_t **hd, const binary_tree_t *tree, size_t lvl)
{
	link_t *n_w;
	link_t *a_x;

	n_w = malloc(sizeof(link_t));
	if (n_w == NULL)
	{
		return;
	}
	n_w->n = lvl;
	n_w->node = tree;
	if (*hd == NULL)
	{
		n_w->next = NULL;
		*hd = n_w;
	}
	else
	{
		a_x = *hd;
		while (a_x->next != NULL)
		{
			a_x = a_x->next;
		}
		n_w->next = NULL;
		a_x->next = n_w;
	}
}
/**
 * recursion - recursion
 * @hd: hd
 * @tree: tree
 * Return: void
 */
void recursion(link_t **hd, const binary_tree_t *tree)
{
	size_t lvl = 0;

	if (tree != NULL)
	{
		lvl = binary_tree_depth(tree);
		linked_node(hd, tree, lvl);
		recursion(hd, tree->left);
		recursion(hd, tree->right);
	}
}
/**
 * binary_tree_levelorder - binary_tree_levelorder
 * @tree: tree
 * @func: func
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *hd;
	link_t *a_x;
	size_t hght = 0;
	size_t cnt = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		hght = binary_tree_height(tree);
		hd = NULL;
		recursion(&hd, tree);
		while (cnt <= hght)
		{
			a_x = hd;
			while (a_x != NULL)
			{
				if (cnt == a_x->n)
				{
					func(a_x->node->n);
				}
				a_x = a_x->next;
			}
			cnt++;
		}
		while (hd != NULL)
		{
			a_x = hd;
			hd = hd->next;
			free(a_x);
		}
	}
}
