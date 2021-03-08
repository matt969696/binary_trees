#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node
 * Return: the height, otherwise 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int hl, hr;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	hl = binary_tree_height(tree->left);
	hr = binary_tree_height(tree->right);
	if (hl > hr)
		return (hl + 1);
	else
		return (hr + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: the pointer to the root node
 * Return: 1, or 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int hl, hr, pl, pr;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	hl = binary_tree_height(tree->left);
	hr = binary_tree_height(tree->right);
	pl = binary_tree_is_perfect(tree->left);
	pr = binary_tree_is_perfect(tree->right);
	if (pl == 1 && pr == 1 && hl == hr)
		return (1);
	return (0);
}
