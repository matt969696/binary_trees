#include "binary_trees.h"
/**
 * findmin - Finds the minimum root
 * @root: pointer to the tree
 * Return: the minimum
 */

bst_t *findmin(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
/**
 * bst_remove - Removes a node from a BST
 * @root: pointer to the root node
 * @value: value to remove in the tree
 * Return: pointer to the new root node
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *parent;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			tmp = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(tmp);
		}
		else
		{
			tmp = findmin(root->right);
			root->n = tmp->n;
			root->right = bst_remove(root->right, tmp->n);
		}
	}
	return (root);
}
