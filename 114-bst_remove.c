#include "binary_trees.h"
#include <stdio.h>
bst_t *FindMin(bst_t *root);
void swapNodes(bst_t *root, bst_t *min);

/*bst_t *bst_remove(bst_t *root, int value)
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
    if (rm_node->parent->left == rm_node)
        rm_node->parent->left = root;
    else
        rm_node->parent->right = root;
    if (root != NULL)
        root->parent = rm_node->parent;
    free(rm_node);
}
else if (root->right == NULL)
{
    rm_node = root;
    root = root->left;
    if (rm_node->parent->left == rm_node)
        rm_node->parent->left = root;
    else
        rm_node->parent->right = root;
    if (root != NULL)
        root->parent = rm_node->parent;
    free(rm_node);
}*/
		/*else if (root->left == NULL)
		{
			rm_node = root;
			root = root->right;
			root->parent = rm_node->parent;
			root->parent->left = root;
			free(rm_node);
		}
		else if (root->right == NULL)
		{
			rm_node = root;
			root = root->left;
			root->parent = rm_node->parent;
			root->parent->right = root;
			free(rm_node);
		}*/
		/*else
		{

			 
			min = FindMin(root->right);

			swapNodes(root, min);
			root->parent->left = NULL;
			free(root);
			root = min;

		}
	}
	return (root);
}*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *min, *temp;
    if (root == NULL)
        return root;

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            if (root->parent != NULL)
            {
                if (root->parent->left == root)
                    root->parent->left = temp;
                else
                    root->parent->right = temp;
                if (temp != NULL)
                    temp->parent = root->parent;
            }
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            if (root->parent != NULL)
            {
                if (root->parent->left == root)
                    root->parent->left = temp;
                else
                    root->parent->right = temp;
                if (temp != NULL)
                    temp->parent = root->parent;
            }
            free(root);
            return temp;
        }
        else
        {
            min = FindMin(root->right);
            root->n = min->n;
            root->right = bst_remove(root->right, min->n);
        }
    }

    return root;
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
