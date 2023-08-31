#include "binary_trees.h"
#include <stdio.h>
/*
14-binary_tree_balance.c
103-binary_tree_rotate_left.c
104-binary_tree_rotate_right.c
0-binary_tree_node.c
*/
/**
 * avl_insert - insert a node in a avl
 * @tree: root
 * @value: value to insert
 * Return: avl_t pointer
 */
void helper(avl_t *tree);
avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (!*tree)
	{
		*tree = (avl_t *)binary_tree_node(NULL, value);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			if ((*tree)->parent)
				helper((*tree)->parent);
			return ((*tree)->left);
		}
		return (avl_insert(&(*tree)->left, value));
	}
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			if ((*tree)->parent)
				helper((*tree)->parent);
			return ((*tree)->right);
		}
		return (avl_insert(&(*tree)->right, value));
	}

	return (NULL);
}

void helper(avl_t *tree)
{

	int blf = 0;

	blf = binary_tree_balance(tree);
	if (-1 > blf || 1 < blf)
	{

		if (blf == -2)
		{
			if (tree->right->right)
			{
				tree = binary_tree_rotate_left(tree);
			}
			else
			{
				tree->right = binary_tree_rotate_right(tree->right);
				tree = binary_tree_rotate_left(tree);
			}
		}
		else if (blf == 2)
		{
			printf("####################\n\n\n");
			printf("blf = %d\n", blf);
			binary_tree_print(tree);
			printf("####################\n\n\n");
			if (tree->left->left)
			{
				tree = binary_tree_rotate_right(tree);
			}
			else
			{
				tree->left = binary_tree_rotate_left(tree->left);
				tree = binary_tree_rotate_right(tree);
			}
			printf("####################\n\n\n");
			printf("blf = %d\n", blf);
			binary_tree_print(tree);
			printf("####################\n\n\n");
		}
	}
}
