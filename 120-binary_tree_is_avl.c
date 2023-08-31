#include "binary_trees.h"
#include <stdio.h>

int binary_tree_is_avl_helper(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to tree node
 * Return: return 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	return (binary_tree_is_avl_helper(tree));
}

/**
 * binary_tree_is_avl_helper - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to tree node
 * Return: return 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl_helper(const binary_tree_t *tree)
{
	size_t height_left, height_right;
	int balance_factor;

	if (tree == NULL)
		return (1);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);
	balance_factor = (int)height_left - (int)height_right;

	if (balance_factor >= -1 && balance_factor <= 1 &&
		binary_tree_is_avl_helper(tree->left) &&
		binary_tree_is_avl_helper(tree->right))
		return (1);

	return (0);
}

/**
 * binary_tree_height - height of a binary tree
 * @tree: pointer to tree node
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}
