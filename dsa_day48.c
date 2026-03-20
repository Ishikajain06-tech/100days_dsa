#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to count leaf nodes
int countLeafNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    // If it's a leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recursively count in left and right subtree
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}