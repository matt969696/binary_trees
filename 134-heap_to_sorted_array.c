#include "binary_trees.h"

/**
 * binary_tree_size3 - Measures the size of a binary tree
 * @tree: pointer to the root node
 * Return: the size, otherwise 0
 */

size_t binary_tree_size3(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size3(tree->left) + binary_tree_size3(tree->right));
}




/**
 * heap_to_sorted_array - converts a Max Heap to a sorted array of integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: sorted array of integers
 */


int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int extract;
	size_t i;
	int *sorted;

	if (heap == NULL)
		return (NULL);
	*size = binary_tree_size3(heap);

	if (*size == 0)
		return (NULL);


	sorted = malloc((*size) * sizeof(int));

	for (i = 0; i < *size; i++)
	{

		extract = heap_extract(&heap);
		sorted[i] = extract;
	}

	return (sorted);
}
