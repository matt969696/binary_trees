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

/**
 * binary_avl - Check if AVL
 * @tree: pointer
 * @min: minimum int
 * @max: maximum int
 * Return: 1 if is AVL, 0 otherwise
 */

int binary_avl(const binary_tree_t *tree, int min, int max)
{
	int bl, br, balance;

	if (tree == NULL)
		return (1);
	if (tree->n > max || tree->n < min)
		return (0);
	balance = binary_tree_balance(tree);
	if (balance < -1 || balance > 1)
		return (0);
	bl = binary_avl(tree->left, min, tree->n - 1);
	br = binary_avl(tree->right, tree->n + 1, max);
	if (bl == 1 && br == 1)
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - Check if is a valid AVL
 * @tree: pointer to the root node
 * Return: 1 if is a valid AVL, 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_avl(tree, INT_MIN, INT_MAX));

}
