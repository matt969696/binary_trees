#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: pointer to the root node
 * Return: the size, otherwise 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_node_complete - Check if is a complete
 * @tree: the pointer to the node
 * @index: the index number
 * @size: size of the binary tree
 * Return: 1 if it is, 0 otherwise
 */

int binary_node_complete(const binary_tree_t *tree, int index, int size)
{
	int cl, cr;

	if (tree == NULL)
		return (1);
	if (index >= size)
		return (0);
	cl = binary_node_complete(tree->left, 2 * index + 1, size);
	cr = binary_node_complete(tree->right, 2 * index + 2, size);
	if (cl == 1 && cr == 1)
		return (1);
	return (0);

}

/**
 * binary_tree_is_complete - Check if a binary tree is complete
 * @tree: pointer to the root
 * Return: 1 if is complete, otherwise 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	return (binary_node_complete(tree, 0, binary_tree_size(tree)));
}
