#include "binary_trees.h"
/**
 * binary_tree_depth - the depth of the tree
 * @tree: the root node
 * Return: the depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *cur_parent;
	size_t depth = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);
	cur_parent = tree->parent;
	while (cur_parent)
	{
		depth++;
		cur_parent = cur_parent->parent;
	}

	return (depth);
}
