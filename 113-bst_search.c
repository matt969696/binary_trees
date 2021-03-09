#include "binary_trees.h"


/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node
 * @value: value to search in the tree
 * Return: pointer to the node containing value, NULL if error or not found
 */


bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);
	if (tree->n > value)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
