#include "binary_trees.h"
/*prototypes*/
int low(binary_tree_t *tree, int n);
int high(binary_tree_t *tree, int n);
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: root node
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	binary_tree_t *current;

	if (tree == NULL)
		return (0);
	current = (binary_tree_t *)tree;
	while (current)
	{
		if (!low(current->left, current->n) || !high(current->right, current->n))
			return (0);
		current = current->left;
	}
	current = (binary_tree_t *)tree;
	while (current)
	{
		if (!low(current->left, current->n) || !high(current->right, current->n))
			return (0);
		current = current->right;
	}
	return (1);
}

/**
 * low - checks numbers in tree lower than n or not
 * @tree: root node
 * @n: parent value
 * Return: 1 if lower 0 otherwise
 */
int low(binary_tree_t *tree, int n)
{
	if (!tree)
		return (1);
	if (!tree->right && !tree->left)
		return (1);
	if (tree->left)
		if (tree->left->n > n)
			return (0);
	if (tree->right)
		if (tree->right->n > n)
			return (0);
	low(tree->left, n);
	low(tree->right, n);
	return (1);
}
/**
 * high - checks numbers in tree lower than n or not
 * @tree: root node
 * @n: parent value
 * Return: 1 if higher 0 otherwise
 */
int high(binary_tree_t *tree, int n)
{
	if (!tree)
		return (1);
	if (!tree->right && !tree->left)
		return (1);
	if (tree->left)
		if (tree->left->n < n)
			return (0);
	if (tree->right)
		if (tree->right->n < n)
			return (0);

	high(tree->left, n);
	high(tree->right, n);
	return (1);
}
