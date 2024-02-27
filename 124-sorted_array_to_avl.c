#include "binary_trees.h"
/**
 * aux_sort - aux_sort
 * @parent: parent
 * @array: array
 * @begin: begin
 * @last: last
 * Return: avl_t
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *rt;
	binary_tree_t *a_x;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		a_x = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (a_x == NULL)
			return (NULL);
		rt = (avl_t *)a_x;
		rt->left = aux_sort(rt, array, begin, mid - 1);
		rt->right = aux_sort(rt, array, mid + 1, last);
		return (rt);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - sorted_array_to_avl
 * @array: array
 * @size: size
 * Return: avl_t
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
