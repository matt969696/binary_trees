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

	if (tree->parent != NULL)
	{
		if (tree->parent->right != NULL && tree->parent->right->n == tree->n)
			tree->parent->right = tree->right;
		else
			tree->parent->left = tree->right;
	}


	tmp = tree->right;
	tmp2 = tmp->left;
	tmp->parent = tree->parent;
	tree->right = tmp2;
	if (tmp2 != NULL)
		tmp2->parent = tree;
	tree->parent = tmp;
	tmp->left = tree;
	return (tmp);
}
