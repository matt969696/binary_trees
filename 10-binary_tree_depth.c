#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node
 * @tree: pointer to the node
 * Return: the depth, otherwise 0.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->parent == NULL)
		return (0);
	else
		return (binary_tree_depth(tree->parent) + 1);

}
