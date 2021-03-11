#include "binary_trees.h"


/**
 * array_to_heap - builds a Binary Search Tree from an array
 * @array: input array
 * @size: number of elements in the array
 * Return: pointer to the root node of the created HEAP, or NULL on failure
 */


heap_t *array_to_heap(int *array, size_t size)
{
	int i;
	heap_t *new = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < (int)size; i++)
		heap_insert(&new, array[i]);

	return (new);
}
