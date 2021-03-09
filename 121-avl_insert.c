#include "binary_trees.h"
/**
 * avl_insert_full - Inserts a value in a AVL
 * @tree: pointer to the node
 * @parent: parent of the node to insert
 * @value: the value to store
 * Return: pointer to the created node
 */

avl_t *avl_insert_full(avl_t *tree, avl_t *parent, int value)
{
	avl_t *new;

	if (tree == NULL)
	{
		new = binary_tree_node(parent, value);
		if (parent->n > new->n)
			parent->left = new;
		else
			parent->right = new;
		return (new);
	}
	else if (value == tree->n)
		return (NULL);
	else if (value < tree->n)
		return (avl_insert_full(tree->left, tree, value));
	else
		return (avl_insert_full(tree->right, tree, value));
}


/**
 * avl_rebalance - rebalance an AVL tree if needed
 * @root: pointer to the root of the tree
 * @tree: pointer to the node to be rebalanced
 * @value: inserted value
 * Return: Nothing
 */

void avl_rebalance(avl_t **root, avl_t *tree, int value)
{
	int balance;

	balance = binary_tree_balance(tree);
	if (balance > 1)
	{
		if (tree->left->n > value)
		{
			if (*root == tree)
				*root = tree->left;
			binary_tree_rotate_right(tree);
		}
		else
		{
			if (*root == tree)
				*root = tree->left->right;
			binary_tree_rotate_left(tree->left);
			binary_tree_rotate_right(tree);
		}
	}
	if (balance < -1)
	{
		if (tree->right->n < value)
		{
			if (*root == tree)
				*root = tree->right;
			binary_tree_rotate_left(tree);
		}
		else
		{
			if (*root == tree)
				*root = tree->right->left;
			binary_tree_rotate_right(tree->right);
			binary_tree_rotate_left(tree);
		}
	}
}


/**
 * avl_insert - Insets a value in a AVL
 * @tree: double pointer to the root node
 * @value: the value to store
 * Return: pointer to the created node
 */


avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new, *ancestor;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}
	new = avl_insert_full(*tree, NULL, value);

	if (new == NULL)
		return (NULL);

	ancestor = new->parent;

	while (ancestor != NULL)
	{
		avl_rebalance(tree, ancestor, value);
		ancestor = ancestor->parent;
	}

	return (new);
}
