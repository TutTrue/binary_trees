#include "binary_trees.h"

size_t get_size(binary_tree_t *tree, size_t *counter);
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size = 0, right_size = 0;

	if (tree == NULL)
		return (0);
	left_size = get_size(tree->left, &left_size);
	right_size = get_size(tree->right, &right_size);


	return 1 + right_size + left_size;
}

size_t get_size(binary_tree_t *tree, size_t *counter)
{
	if (!tree)
		return 0;
	(*counter)++;
	get_size(tree->left, counter);
	get_size(tree->right, counter);
	return (*counter);
}
