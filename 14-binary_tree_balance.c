#include "binary_trees.h"

int getHeight(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree)
{
	return (getHeight(tree->left) - getHeight(tree->right));
}
int getHeight(const binary_tree_t *tree)
{
    if (tree == NULL)
        return -1;

    int leftHeight = getHeight(tree->left);
    int rightHeight = getHeight(tree->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}
