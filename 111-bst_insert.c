#include "binary_trees.h"

/**
 * bst_insert - Insets a value in a Binary Search Tree
 * @tree: double pointer to the root node
 * @value: the value to store
 * Return: pointer to the created node
 */

bst_t *bst_insert_full(bst_t *tree, bst_t *parent, int value)
{
	bst_t *new;

	if (tree == NULL)
	{
		new = malloc(sizeof(bst_t));
		if (new == NULL)
			return (NULL);
		new->n = value;
		new->parent = parent;
		new->left = NULL;
		new->right = NULL;
		return (new);
	}
	else if (value == tree->n)
		return (NULL);
	else if (value < tree->n)
		return (bst_insert_full(tree->left, tree, value));
	else
		return (bst_insert_full(tree->right, tree, value));
}

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;

	if (*tree == NULL)
        {
		new = malloc(sizeof(bst_t));
                if (new == NULL)
                        return (NULL);
                new->n = value;
                new->parent = NULL;
                new->left = NULL;
                new->right = NULL;
		*tree = new;
                return (new);
        }
	return (bst_insert_full(*tree, NULL, value));

}
