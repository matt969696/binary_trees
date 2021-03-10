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
 * heap_find_node - Finds the node corresponding to number
 * @root: pointer to the root
 * @number: index of the node to find
 * Return: pointer to the node
 */

heap_t *heap_find_node(heap_t *root, size_t number)
{
	size_t parentn, dir;

	if (number == 0)
		return (root);

	parentn = (number - 1) / 2;
	dir = (number - 1) % 2;

	if (dir == 0)
		return (heap_find_node(root, parentn)->left);
	return (heap_find_node(root, parentn)->right);
}




/**
 * heap_rebalance - rebalance an HEAP tree if needed
 * @new: pointer to the new node
 * @parent: pointer to the new parent
 * Return: parent
 */

heap_t *heap_rebalance(heap_t *new, heap_t *parent)
{
	int tmp;

	tmp = new->n;
	new->n = parent->n;
	parent->n = tmp;
	return (parent);
}


/**
 * heap_rebalance2 - rebalance an HEAP tree if needed
 * @root: pointer to the root of the tree
 * @new: pointer to the new node
 * @parent: pointer to the new parent
 * Return: None
 */

void heap_rebalance2(heap_t **root, heap_t *new, heap_t *parent)
{
	heap_t *tmp, *tmp2;

	tmp = parent->parent;
	new->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == parent)
			tmp->left = new;
		else
			tmp->right = new;
	}
	if (parent->left == new)
	{
		tmp2 = parent->right;
		parent->right = new->right;
		if (parent->right != NULL)
			parent->right->parent = new;
		parent->left = new->left;
		if (parent->left != NULL)
			parent->left->parent = new;
		new->left = parent;
		parent->parent = new;
		new->right = tmp2;
		if (new->right != NULL)
			new->right->parent = new;
	}
	else
	{
		tmp2 = parent->left;
		parent->right = new->right;
		if (parent->right != NULL)
			parent->right->parent = new;
		parent->left = new->left;
		if (parent->left != NULL)
			parent->left->parent = new;
		new->right = parent;
		parent->parent = new;
		new->left = tmp2;
		if (new->left != NULL)
			new->left->parent = new;
	}
	if (new->parent == NULL)
		*root = new;
}




/**
 * heap_insert - Insets a value in a HEAP
 * @tree: double pointer to the root node
 * @value: the value to store
 * Return: pointer to the created node
 */


heap_t *heap_insert(heap_t **tree, int value)
{
	size_t size;
	int doswap = 1;
	heap_t *new, *parent;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}

	size = binary_tree_size(*tree);
	parent = heap_find_node(*tree, (size - 1) / 2);
	new = binary_tree_node(parent, value);
	if (size % 2 == 1)
		parent->left = new;
	else
		parent->right = new;
	if (new == NULL)
		return (NULL);

	while (doswap == 1 && parent != NULL)
	{
		if (parent->n >= new->n)
			doswap = 0;
		else
		{
			new = heap_rebalance(new, parent);
			parent = new->parent;
		}
	}

	return (new);
}
