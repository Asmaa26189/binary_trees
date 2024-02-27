#include "binary_trees.h"

/**
 * heap_to_sorted_array - heap_to_sorted_array
 * @heap: heap
 * @size: size
 * Return: int
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *arr;
	int ex = 0;
	int i = 0;
	size_t heap_size;

	if (!heap)
		return (NULL);
	heap_size = binary_tree_size(heap);
	*size = heap_size;
	arr = malloc(heap_size * sizeof(int));
	if (!arr)
		return (NULL);
	while (heap)
	{
		ex = heap_extract(&heap);
		arr[i] = ex;
		i++;
	}
	return (arr);
}
