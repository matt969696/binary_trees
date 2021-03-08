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

/**
 * binary_trees_ancestor - Finds the lowest common ancestor
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: lowest common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	size_t df, ds;
	int i;
	const binary_tree_t *treef = first, *trees = second;

	if (first == NULL || second == NULL)
		return (NULL);
	df = binary_tree_depth(first);
	ds = binary_tree_depth(second);
	for (i = 0; i + ds < df; i++)
		treef = treef->parent;
	for (i = 0; i + df < ds; i++)
		trees = trees->parent;
	while (treef != trees)
	{
		if (treef->parent == NULL || trees->parent == NULL)
			return (NULL);
		treef = treef->parent;
		trees = trees->parent;
	}
	return ((binary_tree_t *)treef);
}
