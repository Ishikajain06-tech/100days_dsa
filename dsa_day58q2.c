#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Helper function
struct TreeNode* build(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex, int size) {
    if (inStart > inEnd)
        return NULL;

    // Root from preorder
    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = newNode(rootVal);

    // If no children
    if (inStart == inEnd)
        return root;

    // Find root in inorder
    int inIndex;
    for (inIndex = inStart; inIndex <= inEnd; inIndex++) {
        if (inorder[inIndex] == rootVal)
            break;
    }

    // Build left and right
    root->left = build(preorder, inorder, inStart, inIndex - 1, preIndex, size);
    root->right = build(preorder, inorder, inIndex + 1, inEnd, preIndex, size);

    return root;
}

// Main function
struct TreeNode* buildTree(int preorder[], int inorder[], int size) {
    int preIndex = 0;
    return build(preorder, inorder, 0, size - 1, &preIndex, size);
}
