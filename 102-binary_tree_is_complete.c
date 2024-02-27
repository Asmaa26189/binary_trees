#include "binary_trees.h"
/**
 * new_node - new_node
 * @node: node
 * Return: link_t
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *n_new;

	n_new =  malloc(sizeof(link_t));
	if (n_new == NULL)
	{
		return (NULL);
	}
	n_new->node = node;
	n_new->next = NULL;

	return (n_new);
}
/**
 * free_q - free_q
 * @hd: hd
 */
void free_q(link_t *hd)
{
	link_t *tmp_n;

	while (hd)
	{
		tmp_n = hd->next;
		free(hd);
		hd = tmp_n;
	}
}
/**
 * _push - _push
 * @node: node
 * @hd: hd
 * @tl: tl
 */
void _push(binary_tree_t *node, link_t *hd, link_t **tl)
{
	link_t *n_new;

	n_new = new_node(node);
	if (n_new == NULL)
	{
		free_q(hd);
		exit(1);
	}
	(*tl)->next = n_new;
	*tl = n_new;
}
/**
 * _pop - _pop
 * @hd: hd
 */
void _pop(link_t **hd)
{
	link_t *tmp_n;

	tmp_n = (*hd)->next;
	free(*hd);
	*hd = tmp_n;
}
/**
 * binary_tree_is_complete - binary_tree_is_complete
 * @tree: tree
 * Return: int
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *hd;
	link_t *tl;
	int flg = 0;

	if (tree == NULL)
	{
		return (0);
	}
	hd = tl = new_node((binary_tree_t *)tree);
	if (hd == NULL)
	{
		exit(1);
	}
	while (hd != NULL)
	{
		if (hd->node->left != NULL)
		{
			if (flg == 1)
			{
				free_q(hd);
				return (0);
			}
			_push(hd->node->left, hd, &tl);
		}
		else
			flg = 1;
		if (hd->node->right != NULL)
		{
			if (flg == 1)
			{
				free_q(hd);
				return (0);
			}
			_push(hd->node->right, hd, &tl);
		}
		else
			flg = 1;
		_pop(&hd);
	}
	return (1);
}
