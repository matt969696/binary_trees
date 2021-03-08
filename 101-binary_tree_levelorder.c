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
 * binary_level_print - print line of all nodes
 * @tree: pointer to the node
 * @func: pointer to a function
 * @l: the level
 * Return: Nothing
 */

void binary_level_print(const binary_tree_t *tree, void (*func)(int), size_t l)
{
	if (tree == NULL)
		return;
	if (l == 1)
		(*func)(tree->n);
	else if (l > 1)
	{
		binary_level_print(tree->left, func, l - 1);
		binary_level_print(tree->right, func, l - 1);
	}
}

/**
 * binary_tree_levelorder - Using level-order traversal
 * @tree: pointer to the root
 * @func: pointer to a function
 * Return: Nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || (*func) == NULL)
		return;

	height = binary_tree_height(tree) + 1;
	for (i = 1; i <= height; i++)
		binary_level_print(tree, func, i);
}
