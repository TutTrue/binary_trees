#include "binary_trees.h"
#include <stdio.h>
bst_t *FindMin(bst_t *root);

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *rm_node, *tmp, *min_node_r;
	if (root == NULL)
		return (root);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			rm_node = root;
			root = root->right;
			free(rm_node);
		}
		else if (root->right == NULL)
		{
			rm_node = root;
			root = root->left;
			free(rm_node);
		}
		else
		{

			// printf("%d\n", min_node_r->n);
			// printf("%d\n", root->n);
			// tmp = min_node_r->parent;
			// tmp->left = NULL;
			// root->right->parent = min_node_r;
			// min_node_r->parent = root->parent;
			// min_node_r->left = root->left;
			// min_node_r->right = root->right;
			// root = min_node_r;

			min_node_r = FindMin(root->right);

			tmp = min_node_r->parent;
			min_node_r->parent = root->parent;
			root->parent = tmp;
			tmp = min_node_r->right;
			min_node_r->right = root->right;
			root->right = tmp;
			min_node_r->left = root->left;
			root->left= NULL;
			binary_tree_print(min_node_r);
		}
	}
	return (root);
}

/**
 * FindMin - find minimum in a tree.
 * @tree: the root of the tree
 * @value: value
 * Return: pointer to a node that has the value
 */
bst_t *FindMin(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return root;
}
