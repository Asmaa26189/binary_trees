#include "binary_trees.h"
/**
 * array_to_bst - array_to_bst
 * @array: array
 * @size: size
 * Return: bst_t
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t index = 0;
	bst_t *rt;

	rt = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; index < size; index++)
	{
		if (index == 0)
		{
			bst_insert(&rt, array[index]);
		}
		else
		{
			bst_insert(&rt, array[index]);
		}
	}
	return (rt);
}
