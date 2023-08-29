#include "binary_trees.h"
/**
 * binary_tree_rotate_right - rotate the tree to the right
 * @tree: root node
 * Return: the new parent
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *parent;
	if (!tree || !tree->left)
		return (tree);
	parent = tree->left;
	tree->left = parent->right;
	parent->right = tree;
	tree->parent = parent;

	return (parent);
} 