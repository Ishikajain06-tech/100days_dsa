#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Count total nodes
int countNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check if tree is Complete Binary Tree
bool isComplete(struct TreeNode* root, int index, int totalNodes) {
    if (root == NULL)
        return true;

    if (index >= totalNodes)
        return false;

    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

// Check Min-Heap property
bool isMinHeap(struct TreeNode* root) {
    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    // Only left child exists
    if (root->right == NULL)
        return (root->val <= root->left->val) && isMinHeap(root->left);

    // Both children exist
    if (root->val <= root->left->val &&
        root->val <= root->right->val)
        return isMinHeap(root->left) && isMinHeap(root->right);

    return false;
}

// Main function to validate Min Heap
bool isValidMinHeap(struct TreeNode* root) {
    int totalNodes = countNodes(root);

    if (isComplete(root, 0, totalNodes) && isMinHeap(root))
        return true;

    return false;
}