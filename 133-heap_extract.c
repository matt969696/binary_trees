#include "binary_trees.h"


/**
 * binary_tree_size2 - Measures the size of a binary tree
 * @tree: pointer to the root node
 * Return: the size, otherwise 0
 */

size_t binary_tree_size2(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size2(tree->left) + binary_tree_size2(tree->right));
}



/**
 * heap_find_node2 - Finds the node corresponding to number
 * @root: pointer to the root
 * @number: index of the node to find
 * Return: pointer to the node
 */

heap_t *heap_find_node2(heap_t *root, size_t number)
{
	size_t parentn, dir;

	if (number == 0)
		return (root);

	parentn = (number - 1) / 2;
	dir = (number - 1) % 2;

	if (dir == 0)
		return (heap_find_node2(root, parentn)->left);
	return (heap_find_node2(root, parentn)->right);
}




/**
 * heap_rebalance2 - rebalance an HEAP tree if needed
 * @new: pointer to the new node
 * @parent: pointer to the new parent
 * Return: parent
 */

heap_t *heap_rebalance2(heap_t *new, heap_t *parent)
{
	int tmp;

	tmp = new->n;
	new->n = parent->n;
	parent->n = tmp;
	return (parent);
}


/**
 * heap_find_max - find the maximum child if greater than node
 * @node: pointer to the new node
 * Return: pointer to the max, NULL if not found
 */

heap_t *heap_find_max(heap_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->left == NULL)
		return (NULL);
	if (node->right == NULL)
	{
		if (node->left->n <= node->n)
			return (NULL);
		return (node->left);
	}
	if (node->right->n > node->left->n && node->right->n > node->n)
		return (node->right);
	if (node->left->n > node->right->n && node->left->n > node->n)
		return (node->left);
	return (NULL);
}



/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node
 * Return: value extracted if ok, 0 if fails
 */


int heap_extract(heap_t **root)
{
	size_t size;
	int doswap = 1;
	int value;
	heap_t *node;
	heap_t *new, *succ;

	if (root == NULL)
		return (0);
	if (*root == NULL)
		return (0);

	size = binary_tree_size2(*root);
	node = heap_find_node2(*root, size - 1);
	value = (*root)->n;
	if (size == 1)
	{
		free(node);
		*root = NULL;
		return (value);
	}
	(*root)->n = node->n;
	if (size % 2 == 1)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	new = *root;
	while (doswap == 1)
	{
		succ = heap_find_max(new);
		if (succ == NULL)
			doswap = 0;
		else
			new = heap_rebalance2(new, succ);
	}

	return (value);
}
