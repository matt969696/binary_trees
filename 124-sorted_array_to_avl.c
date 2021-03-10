#include "binary_trees.h"



/**
 * sorted_insert - recursively builds a AVL from a sorted array
 * @parent: pointer to the parent node
 * @parray: input array
 * @start: starting array index
 * @end: ending array index
 * Return: pointer to the root node of the created AVL, or NULL on failure
 */


avl_t *sorted_insert(avl_t *parent, int *array, int start, int end)
{
	int k, pivot;
	avl_t *new;

	if (start > end)
		return (NULL);
	k = 1;
	while (k * 3 <= (end - start + 1))
		k = k * 2;
	if (end - start + 1 <= 2)
		pivot = start;
	else
		pivot = start + k - 1;

	new = binary_tree_node(parent, array[pivot]);
	if (new == NULL)
		return (NULL);
	new->left = sorted_insert(new, array, start, pivot - 1);
	new->right = sorted_insert(new, array, pivot + 1, end);
	return (new);

}





/**
 * sorted_array_to_avl - builds a AVL from a sorted array
 * @array: input array
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL, or NULL on failure
 */


avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (sorted_insert(NULL, array, 0, (int)size - 1));
}
