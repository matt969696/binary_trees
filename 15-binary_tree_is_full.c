#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: pointer to the root node
 * Return: 1, otherwise 0.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int fl, fr;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	fl = binary_tree_is_full(tree->left);
	fr = binary_tree_is_full(tree->right);
	if (fl == 1 && fr == 1)
		return (1);
	return (0);
}
