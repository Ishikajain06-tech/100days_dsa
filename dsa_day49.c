#include <stdio.h>
#include <stdlib.h>

// Definition of BST node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert function
struct TreeNode* insert(struct TreeNode* root, int val) {
    // If tree is empty, create new node
    if (root == NULL)
        return createNode(val);

    // If value is smaller, go left
    if (val < root->val)
        root->left = insert(root->left, val);
    // If value is greater, go right
    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}