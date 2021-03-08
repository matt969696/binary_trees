#include "binary_trees.h"

/**
 * binary_tree_postorder - Using post-order traversal
 * @tree: the three to traverse
 * @func: pointer to a function to call
 * Return: Nothing.
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || (*func) == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	(*func)(tree->n);
}
