#include "binary_trees.h"

void binary_tree_levelorder_helper(const binary_tree_t *tree,
								   void (*func)(int));
/**
 * binary_tree_levelorder - traverse the tree in post order
 * @tree: the root of the tree
 * @func: a func that will be fired on the data of each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_levelorder_helper(tree, func);
}
/**
 * binary_tree_levelorder_helper - traverse the tree in post order
 * @tree: the root of the tree
 * @func: a func that will be fired on the data of each node
 */
void binary_tree_levelorder_helper(const binary_tree_t *tree,
								   void (*func)(int))
{
	if (tree == NULL)
		return;

	if (tree->left)
		func(tree->left->n);
	if (tree->right)
		func(tree->right->n);
	if (tree->left)
		binary_tree_levelorder_helper(tree->left, func);
	if (tree->right)
		binary_tree_levelorder_helper(tree->right, func);
}
