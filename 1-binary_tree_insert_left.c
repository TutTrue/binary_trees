#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: parent of node
 * @value: int value
 * Return: node pinter
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *cur_left;

	if (parent == NULL)
		return (NULL);
	cur_left = parent->left;

	parent->left = binary_tree_node(parent, value);
	if (parent->left == NULL)
		return (NULL);

	if (cur_left)
		cur_left->parent = parent->left;
	parent->left->left = cur_left;

	return (parent->left);
}
