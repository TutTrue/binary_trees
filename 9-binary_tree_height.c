#include "binary_trees.h"

size_t get_height(binary_tree_t *tree, size_t *counter);
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);
	left_height = get_height(tree->left, &left_height);
	right_height = get_height(tree->right, &right_height);

	if (left_height > right_height)
		return left_height;

	return right_height;
}

size_t get_height(binary_tree_t *tree, size_t *counter)
{
	if (!tree)
		return 0;
	(*counter)++;
	get_height(tree->left, counter);
	get_height(tree->right, counter);
	return (*counter);
}
