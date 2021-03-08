#include "binary_trees.h"
/**
 * binary_tree_level - Measures the level
 * @tree: the pointer to the root
 * Return: the level
 */

int binary_tree_level(const binary_tree_t *tree)
{
	int hl, hr;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	hl = binary_tree_level(tree->left);
	hr = binary_tree_level(tree->right);
	if (hl > hr)
		return (hl + 1);
	else
		return (hr + 1);
}


/**
 * binary_tree_balance - Measures the balance factor
 * @tree: pointer to the root node
 * Return: the balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_level(tree->left) - binary_tree_level(tree->right));
}
