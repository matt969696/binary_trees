#include "binary_trees.h"

/**
 * binary_bst - Check if BST
 * @tree: pointer
 * @min: minimum int
 * @max: maximum int
 * Return: 1 if is BST, 0 otherwise
 */

int binary_bst(const binary_tree_t *tree, int min, int max)
{
	int bl, br;

	if (tree == NULL)
		return (1);
	if (tree->n > max || tree->n < min)
		return (0);
	bl = binary_bst(tree->left, min, tree->n - 1);
	br = binary_bst(tree->right, tree->n + 1, max);
	if (bl == 1 && br == 1)
		return (1);
	return (0);
}

/**
 * binary_tree_is_bst - Check if is a valid Binary Search Tree
 * @tree: pointer to the root node
 * Return: 1 if is a valid BST, 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_bst(tree, INT_MIN, INT_MAX));

}
