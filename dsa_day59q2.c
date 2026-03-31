#include <stdlib.h>

// Definition for a binary tree node
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder array
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Recursive function to build tree
struct TreeNode* build(int* inorder, int* postorder, int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    // Root from postorder
    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = createNode(rootVal);

    // If only one node
    if (start == end)
        return root;

    // Find root in inorder
    int inIndex = findIndex(inorder, start, end, rootVal);

    // Build right subtree first
    root->right = build(inorder, postorder, inIndex + 1, end, postIndex);
    root->left  = build(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Main function
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1;
    return build(inorder, postorder, 0, inorderSize - 1, &postIndex);
}
