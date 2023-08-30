#include "binary_trees.h"
#include <stdio.h>
bst_t *FindMin(bst_t *root);
/*void swapNodes(bst_t *A, bst_t *B);*/
void swapNodesn(bst_t *A, bst_t *B);

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
			swapNodesn(root, min);
			/*printf("%d\n", root->n);
			printf("%d\n", root->parent->n);
			printf("%d\n", root->parent->parent->n);
			printf("%d\n", root->parent->parent->parent->n);
			printf("-----------------------");*/
			/*binary_tree_print(min);*/
			bst_remove(min->parent, min->n);
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
/*void swapNodes(bst_t *A, bst_t *B) {
    if (A->parent != NULL) {
        if (A->parent->left == A) {
            A->parent->left = B;
        } else {
            A->parent->right = B;
        }
    }

    if (B->parent != NULL) {
        if (B->parent->left == B) {
            B->parent->left = A;
        } else {
            B->parent->right = A;
        }
    }

    // Swap the parent pointers
    bst_t *tempParent = A->parent;
    A->parent = B->parent;
    B->parent = tempParent;

    // Swap the left and right child pointers
    bst_t *tempLeft = A->left;
    A->left = B->left;
    B->left = tempLeft;

    bst_t *tempRight = A->right;
    A->right = B->right;
    B->right = tempRight;
}*/
void swapNodesn(bst_t *A, bst_t *B)
{
    int temp = A->n;

    A->n = B->n;
    B->n = temp;
}
