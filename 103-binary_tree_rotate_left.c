#include "binary_trees.h"
/**
 * binary_tree_rotate_left - Perfoms a left-rotation
 * @tree: pointer to the root node
 * Return: pointer to the new root node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp, *tmp2;

	if (tree == NULL)
		return (NULL);
	if (tree->right == NULL)
		return (NULL);
	tmp = tree->right;
	tmp2 = tmp->left;
	tree->right = tmp2;
	tree->parent = tmp;
	tmp->left = tree;
	tmp->parent = NULL;
	return (tmp);
}
