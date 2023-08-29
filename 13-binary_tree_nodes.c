#include "binary_trees.h"

void traverse(const binary_tree_t *tree, size_t *counter);
/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a tree
 * @tree: the root of the tree
 * Return: number of nodes with at least 1 child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t counter = 0;

	traverse(tree, &counter);
	return (counter);
}

/**
 * traverse - get the number of nodes that have at least 1 child
 * @tree: the root of the tree
 * @counter: pointer to a var to store number of nodes
 */
void traverse(const binary_tree_t *tree, size_t *counter)
{
	if (!tree)
		return;
	if (tree->left || tree->right)
		(*counter)++;
	traverse(tree->left, counter);
	traverse(tree->right, counter);
}
