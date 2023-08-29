#include "binary_trees.h"

int getHeight(const binary_tree_t *tree);

/**
 * binary_tree_balance - get a balance fator of a node
 * @tree: the root of the tree
 * Return: the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	return (getHeight(tree->left) - getHeight(tree->right));
}
/**
 * getHeight - get the height of the tree
 * @tree: the root of the tree
 * Return: height of the tree
 */
int getHeight(const binary_tree_t *tree)
{
    if (tree == NULL)
        return -1;

    int leftHeight = getHeight(tree->left);
    int rightHeight = getHeight(tree->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}
