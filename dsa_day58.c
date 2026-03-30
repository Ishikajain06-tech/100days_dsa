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

// Helper function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find index of value in inorder array
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Recursive function to build tree
struct TreeNode* buildTreeHelper(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    // Pick current node from preorder
    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = newNode(rootVal);

    // If this node has no children
    if (inStart == inEnd)
        return root;

    // Find root in inorder
    int inIndex = search(inorder, inStart, inEnd, rootVal);

    // Build left and right subtrees
    root->left = buildTreeHelper(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTreeHelper(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

// Main function
struct TreeNode* buildTree(int preorder[], int inorder[], int size) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, size - 1, &preIndex);
}