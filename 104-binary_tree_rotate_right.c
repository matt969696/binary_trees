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

	if (tree->parent != NULL)
	{
		if (tree->parent->left != NULL && tree->parent->left->n == tree->n)
			tree->parent->left = tree->left;
		else
			tree->parent->right = tree->left;
	}


	tmp = tree->left;
	tmp2 = tmp->right;
	tmp->parent = tree->parent;
	tree->left = tmp2;
	if (tmp2 != NULL)
		tmp2->parent = tree;
	tree->parent = tmp;
	tmp->right = tree;
	return (tmp);
}
