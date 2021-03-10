#include "binary_trees.h"
/**
 * findmin - Finds the minimum root
 * @root: pointer to the tree
 * Return: the minimum
 */

avl_t *findmin(avl_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * avl_removefirst - Removes a node from a AVL before rebalancing
 * @root: pointer to the root node
 * @value: value to remove in the tree
 * Return: pointer to the new root node
 */

avl_t *avl_removefirst(avl_t *root, int value)
{
	avl_t *tmp, *parent;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		root->left = avl_removefirst(root->left, value);
	else if (value > root->n)
		root->right = avl_removefirst(root->right, value);
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
			root->right = avl_removefirst(root->right, tmp->n);
		}
	}
	return (root);
}


/**
 * avl_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node
 * @value: value to search in the tree
 * Return: pointer to the node containing value, NULL if error or not found
 */


avl_t *avl_search(const avl_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((avl_t *)tree);
	if (tree->n > value)
		return (avl_search(tree->left, value));
	return (avl_search(tree->right, value));
}



/**
 * avl_rebalance2 - rebalance an AVL tree if needed
 * @root: pointer to the root of the tree
 * @tree: pointer to the node to be rebalanced
 * Return: pointer to the new root
 */

avl_t *avl_rebalance2(avl_t *root, avl_t *tree)
{
	int balance;

	balance = binary_tree_balance(tree);
	if (balance > 1)
	{
		if (binary_tree_balance(tree->left) >= 0)
		{
			if (root == tree)
				root = tree->left;
			binary_tree_rotate_right(tree);
		}
		else
		{
			if (root == tree)
				root = tree->left->right;
			binary_tree_rotate_left(tree->left);
			binary_tree_rotate_right(tree);
		}
	}
	if (balance < -1)
	{
		if (binary_tree_balance(tree->right) <= 0)
		{
			if (root == tree)
				root = tree->right;
			binary_tree_rotate_left(tree);
		}
		else
		{
			if (root == tree)
				root = tree->right->left;
			binary_tree_rotate_right(tree->right);
			binary_tree_rotate_left(tree);
		}
	}
	return (root);
}



/**
 * avl_remove - Removes a node from a AVL
 * @root: pointer to the root node
 * @value: value to remove in the tree
 * Return: pointer to the new root node
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *ancestor;

	if (root == NULL)
		return (NULL);

	ancestor = avl_search(root, value);
	if (ancestor != NULL)
		ancestor = ancestor->parent;

	root = avl_removefirst(root, value);

	while (ancestor != NULL)
	{
		root = avl_rebalance2(root, ancestor);
		ancestor = ancestor->parent;
	}

	return (root);
}
