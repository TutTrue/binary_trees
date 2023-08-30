#include "binary_trees.h"

/**
 * bst_insert - insert a node in a bst
 * @tree: root
 * @value: value to insert
 * Return: bst_t pointer
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!*tree)
	{
		*tree = (bst_t *)binary_tree_node(NULL, value);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			(*tree)->left = binary_tree_node(NULL, value);
			(*tree)->left->parent = *tree;
			return ((*tree)->left);
		}
		return (bst_insert(&(*tree)->left, value));
	}
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			(*tree)->right = binary_tree_node(NULL, value);
			(*tree)->right->parent = *tree;
			return ((*tree)->right);
		}
		return (bst_insert(&(*tree)->right, value));
	}
	return (NULL);
}
