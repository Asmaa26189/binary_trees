#include "binary_trees.h"
/**
 * aux_sort - create the tree using the half element of the array
 * @parent: parent of the node to create
 * @array: sorted array
 * @begin: position where the array starts
 * @last: position where the array ends
 * Return: tree created
 */
a_s *aux_sort(a_s *parent, int *array, int begin, int last)
{
	a_s *root;
	binary_tree_s *aux;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_s *)parent, array[mid]);
		if (aux == NULL)
			return (NULL);
		root = (a_s *)aux;
		root->left = aux_sort(root, array, begin, mid - 1);
		root->right = aux_sort(root, array, mid + 1, last);
		return (root);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - create a alv tree from sorted array
 * @array: sorted array
 * @size: size of the sorted array
 * Return: alv tree form sorted array
 */
a_s *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
