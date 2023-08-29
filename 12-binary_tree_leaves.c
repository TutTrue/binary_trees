#include "binary_trees.h"

void traverse(const binary_tree_t *tree, size_t *counter);
/**
 * binary_tree_leaves - get the number of leaves of the tree
 * @tree: the root of the tree
 * Return: number of leaves of a tree
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t no_leaves = 0;

	traverse(tree, &no_leaves);

	return (no_leaves);
}

/**
 * traverse - traverse the tree and increment the counter if leave node
 * @tree: the root of the tree
 * @counter: the counter that stores the number of the leaves
 */
void traverse(const binary_tree_t *tree, size_t *counter)
{
	if (!tree)
		return;
	if (!tree->left && !tree->right)
		(*counter)++;
	traverse(tree->left, counter);
	traverse(tree->right, counter);
}
