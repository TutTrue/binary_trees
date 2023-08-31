#include "binary_trees.h"

/**
 * binary_tree_is_complete - binary tree is complete
 * @tree: root node
 * Return: 1 is complete otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (binary_tree_is_full(tree))
	{
		return (1);
	}
	if (tree->left && !tree->right)
	{
		if (tree->left->parent)
			if (tree->left->parent->parent)
				if (tree->left->parent->parent->right)
				{

					return (binary_tree_is_leaf(tree->left->parent->parent->right));
				}
	}
	return (binary_tree_is_complete(tree->left) &&
			binary_tree_is_complete(tree->right));
}
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: root node
 * Return: 1 is_full otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if ((!tree->left && tree->right) ||
		(!tree->right && tree->left))
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
}

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: parent of node
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || (node->left || node->right))
		return (0);

	return (1);
}
