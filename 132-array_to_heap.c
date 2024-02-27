#include "binary_trees.h"

/**
 * array_to_heap - array_to_heap
 * @array: array
 * @size: size
 * Return: heap_t
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *t;
	size_t i;

	t = NULL;

	for (i = 0; i < size; i++)
	{
		heap_insert(&t, array[i]);
	}

	return (t);
}
