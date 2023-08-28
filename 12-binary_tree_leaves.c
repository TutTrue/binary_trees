#include "binary_trees.h"

void traverse(const binary_tree_t *tree, size_t *counter);
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t no_leaves = 0;

	traverse(tree, &no_leaves);

	return (no_leaves);
}

void traverse(const binary_tree_t *tree, size_t *counter)
{
	if (!tree)
		return;
	if (!tree->left && !tree->right)
		(*counter)++;
	traverse(tree->left, counter);
	traverse(tree->right, counter);
}
