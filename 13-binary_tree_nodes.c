#include "binary_trees.h"

void traverse(const binary_tree_t *tree, size_t *counter);
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t counter = 0;
	traverse(tree, &counter);
	return (counter);
}

void traverse(const binary_tree_t *tree, size_t *counter)
{
	if (!tree)
		return;
	if (tree->left || tree->right)
		(*counter)++;
	traverse(tree->left, counter);
	traverse(tree->right, counter);
}
