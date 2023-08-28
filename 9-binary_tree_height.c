#include "binary_trees.h"
#include <stdio.h>
size_t get_height_l(binary_tree_t *tree, size_t *counter);
size_t get_height_r(binary_tree_t *tree, size_t *counter);
size_t higher(size_t ll, size_t lr, size_t rl, size_t rr);
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t ll = 0, lr = 0, rl = 0, rr = 0;

	if (tree == NULL)
		return (0);
	ll = get_height_l(tree->left, &ll);
	lr = get_height_r(tree->left, &lr);
	rl = get_height_l(tree->right, &rl);
	rr = get_height_r(tree->right, &rr);

	return higher(ll, lr, rl, rr);
}

size_t get_height_l(binary_tree_t *tree, size_t *counter)
{
	if (!tree)
		return 0;

	get_height_l(tree->left, counter);
	(*counter)++;
	return (*counter);
}

size_t get_height_r(binary_tree_t *tree, size_t *counter)
{
	if (!tree)
		return 0;

	get_height_r(tree->right, counter);
	(*counter)++;
	return (*counter);
}

size_t higher(size_t ll, size_t lr, size_t rl, size_t rr)
{
	if (ll >= lr && ll >= rl && ll >= rr)
		return (ll);
	else if (lr >= ll && lr >= rl && lr >= rr)
		return (lr);
	else if (rl >= ll && rl >= lr && rl >= rr)
		return (rl);

	return (rr);
}
