#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    // Create a binary tree
    root = binary_tree_node(NULL, 50);
    root->left = binary_tree_node(root, 30);
    root->right = binary_tree_node(root, 70);
    root->left->left = binary_tree_node(root->left, 20);
    root->left->right = binary_tree_node(root->left, 40);
    root->right->left = binary_tree_node(root->right, 60);
    root->right->right = binary_tree_node(root->right, 80);
    root->left->left->left = binary_tree_node(root->left->left, 10);
    root->left->left->right = binary_tree_node(root->left->left, 25);
    root->left->right->left = binary_tree_node(root->left->right, 35);
    root->left->right->right = binary_tree_node(root->left->right, 45);
    root->right->left->left = binary_tree_node(root->right->left, 55);
    root->right->left->right = binary_tree_node(root->right->left, 65);
    root->right->right->left = binary_tree_node(root->right->right, 75);
    root->right->right->right = binary_tree_node(root->right->right, 85);

    // Print the binary tree structure
    printf("Binary Tree Structure:\n");
    binary_tree_print(root);

    // Perform level-order traversal
    printf("Level-Order Traversal:\n");
    binary_tree_levelorder(root, &print_num);

    // Clean up
    binary_tree_delete(root);
    return (0);
}
