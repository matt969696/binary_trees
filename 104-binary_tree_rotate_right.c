#include "binary_trees.h"
/**
 * binary_tree_rotate_right - Perfoms a right-rotation
 * @tree: pointer to the root node
 * Return: pointer to the new root node
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp, *tmp2;

	if (tree == NULL)
		return (NULL);
	if (tree->left == NULL)
		return (NULL);
	tmp = tree->left;
	tmp2 = tmp->right;
	tree->left = tmp2;
	tree->parent = tmp;
	tmp->right = tree;
	tmp->parent = NULL;
	return (tmp);
}
