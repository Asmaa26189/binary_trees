#include "binary_trees.h"

/**
 * swap_right - swap_right
 * @node: node
 * @parent: parent
 */
void swap_right(heap_t *node, heap_t *parent)
{
	heap_t *a_x;
	heap_t *a_x2;

	a_x = parent->left;
	a_x2 = parent->parent;

	parent->right = node->right;
	if (node->right)
		node->right->parent = parent;
	parent->left = node->left;
	if (node->left)
		node->left->parent = parent;

	node->right = parent;
	node->left = a_x;
	if (a_x)
		a_x->parent = node;
	parent->parent = node;
	node->parent = a_x2;
	if (a_x2 && parent == a_x2->left)
		a_x2->left = node;
	else if (a_x2 && parent == a_x2->right)
		a_x2->right = node;
}

/**
 * swap_left - swap_left
 * @node: node
 * @parent: parent
 */
void swap_left(heap_t *node, heap_t *parent)
{
	heap_t *a_x;
	heap_t *a_x2;

	a_x = parent->right;
	a_x2 = parent->parent;

	parent->right = node->right;
	if (node->right)
		node->right->parent = parent;
	parent->left = node->left;
	if (node->left)
		node->left->parent = parent;

	node->left = parent;
	node->right = a_x;
	if (a_x)
		a_x->parent = node;
	parent->parent = node;
	node->parent = a_x2;
	if (a_x2 && parent == a_x2->left)
		a_x2->left = node;
	else if (a_x2 && parent == a_x2->right)
		a_x2->right = node;
}
/**
 * height - height
 * @tree: tree
 * Return: int
 */
int height(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (tree == NULL)
		return (-1);

	left = height(tree->left);
	right = height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * binary_tree_is_perfect - binary_tree_is_perfect
 * @tree: tree
 * Return: int
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree && height(tree->left) == height(tree->right))
	{
		if (height(tree->left) == -1)
			return (1);

		if ((tree->left && !((tree->left)->left) && !((tree->left)->right))
		    && (tree->right && !((tree->right)->left) && !((tree->right)->right)))
			return (1);

		if (tree && tree->left && tree->right)
			return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}

	return (0);
}

/**
 * swap - swap
 * @node: node
 */
void swap(const heap_t *node)
{
	heap_t *parent;

	parent = node->parent;

	while (node->parent && node->n > node->parent->n)
	{
		parent = node->parent;
		if (node == parent->right)
		{
			swap_right((heap_t *)node, parent);
		}
		else if (node == parent->left)
		{
			swap_left((heap_t *)node, parent);
		}
	}
}

/**
 * heap_insert - heap_insert
 * @value: value
 * @root: root
 * Return: heap_t
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *n_node;
	heap_t **rt_right = &((*root)->right);
	heap_t **rt_left = &((*root)->left);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if (binary_tree_is_perfect(*root) || !binary_tree_is_perfect((*root)->left))
	{
		if ((*root)->left)
			n_node = heap_insert(rt_left, value);
		else
		{
			n_node = (*root)->left = binary_tree_node(*root, value);
			swap(n_node);
		}
	}
	else
	{
		if ((*root)->right)
			n_node = heap_insert(rt_right, value);
		else
		{
			n_node = (*root)->right = binary_tree_node(*root, value);
			swap(n_node);
		}
	}

	if (n_node->parent == NULL && (*root)->parent != NULL &&
	    !((*root)->parent->parent))
		*root = n_node;
	return (n_node);
}
