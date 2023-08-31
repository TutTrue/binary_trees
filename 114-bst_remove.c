#include "binary_trees.h"
#include <stdio.h>
bst_t *FindMin(bst_t *root);
void swapNodes(bst_t *root, bst_t *min);
//void swapNodesn(bst_t *root, bst_t *min);

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *rm_node, *min;
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
			root->parent = rm_node->parent;
			root->parent->right = root;
			free(rm_node);
		}
		else if (root->right == NULL)
		{
			rm_node = root;
			root = root->left;
			root->parent = rm_node->parent;
			root->parent->right = root;
			free(rm_node);
		}
		else
		{

			 /*printf("%d\n", min_node_r->n);
			 printf("%d\n", root->n);
			 tmp = min_node_r->parent;
			 tmp->left = NULL;
			 root->right->parent = min_node_r;
			 min_node_r->parent = root->parent;
			 min_node_r->left = root->left;
			 min_node_r->right = root->right;
			 root = min_node_r;*/

			min = FindMin(root->right);

			/*tmp = min_node_r->parent;
			min_node_r->parent = root->parent;
			root->parent = tmp;
			tmp->left = root;
			tmp = min_node_r->right;
			tmp->parent = min_node_r;
			min_node_r->right = root->right;
			root->right = tmp;
			min_node_r->left = root->left;
			root->left= NULL;*/
			/*tmp = min->parent;
			tmp->parent = min;
			min->parent = root->parent;
			root->parent = tmp;
			tmp = root->right;
			root->right = min->right;
			min->right = tmp;
			tmp->parent = min;
			tmp = root->left;
			root->left =min->left;
			min->left = tmp;
			if (tmp)
				tmp->parent = min;*/
			/*printf("%d\n", root->n);
			printf("%d\n", root->parent->n);
			printf("%d\n", root->parent->parent->n);
			//printf("%d\n", root->parent->parent->parent->n);
			printf("%d\n", min->right->parent->n);
			printf("-----------------------\n");
			printf("%d\n", min->left->n);
			printf("%d\n", min->left->parent->n);
			printf("-----------------------\n");
			printf("%p\n", (void *)min->parent);
			printf("-----------------------\n");
			printf("%d\n", min->right->left->n);
			printf("%d\n", min->right->left->parent->n);
			printf("%p\n", (void *)min->right->left->left);
			printf("%p\n", (void *)min->right->left->right);
			printf("-----------------------\n");
			printf("-----------------------\n");
			//printf("%d\n", min->left->parent->n);
			binary_tree_print(min);
			printf("-----------------------\n");
			printf("-----------------------\n");
			printf("%d\n", min->right->left->n);
			printf("%p\n", (void *)min->right->left->left);
			printf("%p\n", (void *)min->right->left->right);
			printf("%d\n", min->right->left->parent->n);
			printf("-----------------------\n");
			printf("%d\n", min->n);
			printf("%d\n", min->left->n);
			printf("%d\n", min->right->n);
			printf("%p\n", (void *)min->parent);
			printf("-----------------------\n");
			printf("%d\n", min->right->n);
			printf("%d\n", min->right->left->n);
			printf("%d\n", min->right->right->n);
			printf("%d\n", min->right->parent->n);
			printf("%p\n", (void *)min->right->parent);
			printf("-----------------------\n");
			printf("%d\n", min->left->n);
			printf("%d\n", min->left->left->n);
			printf("%d\n", min->left->right->n);
			printf("%d\n", min->left->parent->n);
			printf("%p\n", (void *)min->left->parent);
			printf("-----------------------\n");
			printf("%d\n", root->n);
			printf("-----------------------\n");*/
			swapNodes(root, min);
			root->parent->left = NULL;
			free(root);
			root = min;

			//return (bst_remove(min, root->n));
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

void swapNodes(bst_t *root, bst_t *min)
{
	bst_t *tempParent, *tempLeft, *tempRight;

	if (root->parent != NULL)
	{
		if (root->parent->left == root)
			root->parent->left = min;
		else
			root->parent->right = min;
        }
	
	if (min->parent != NULL)
	{
		if (min->parent->left == min)
			min->parent->left = root;
		else
			min->parent->right = root;
        }

	tempParent = root->parent;
	root->parent = min->parent;
	min->parent = tempParent;

	tempLeft = root->left;
	root->left = min->left;
	min->left = tempLeft;

	tempRight = root->right;
	root->right = min->right;
	min->right = tempRight;

	min->right->parent = min;
	min->left->parent = min;
}
/*void swapNodesn(bst_t *root, bst_t *min)
{
    int temp = root->n;

    root->n = min->n;
    min->n = temp;
}*/
