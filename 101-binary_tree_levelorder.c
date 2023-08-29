#include "binary_trees.h"

/**
 * binary_tree_postorder - traverse the tree in post order
 * @tree: the root of the tree
 * @func: a func that will be fired on the data of each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	
	if (tree->parent == NULL)
		func(tree->n);
	if(tree->left)
		func(tree->left->n);
	if (tree->right)
		func(tree->right->n);
	binary_tree_levelorder(tree->left, func);
	binary_tree_levelorder(tree->right, func);
	
	
}
