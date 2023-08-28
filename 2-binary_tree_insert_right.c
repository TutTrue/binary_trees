#include "binary_trees.h"

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *cur_right;

	if (parent == NULL)
		return (NULL);
	cur_right = parent->right;

	parent->right = binary_tree_node(parent, value);
	if (parent->right == NULL)
		return (NULL);

	if (cur_right)
		cur_right->parent = parent->right;
	parent->right->right = cur_right;

	return (parent->right);
}
