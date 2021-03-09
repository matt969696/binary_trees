#include "binary_trees.h"


/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: input array
 * @size: number of elements in the array
 * Return: pointer to the root node of the created BST, or NULL on failure
 */


bst_t *array_to_bst(int *array, size_t size)
{
	int i;
	bst_t *new = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < (int)size; i++)
		bst_insert(&new, array[i]);

	return (new);
}
