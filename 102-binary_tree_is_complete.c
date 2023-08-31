#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: root node
 * Return: 1 is_full otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if ((!tree->left && tree->right))
		return (0);
	if ((!tree->left && !tree->right))
		return (1);
	return (binary_tree_is_complete(tree->left) &&
			binary_tree_is_complete(tree->right));
}
