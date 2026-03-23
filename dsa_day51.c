#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert in BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Search in BST
struct TreeNode* searchBST(struct TreeNode* root, int key) {
    while (root != NULL) {
        if (root->val == key)
            return root;
        else if (key < root->val)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// Main function
int main() {
    struct TreeNode* root = NULL;

    // Insert elements
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 12);
    insert(root, 20);

    int key = 12;

    struct TreeNode* result = searchBST(root, key);

    if (result != NULL)
        printf("Element %d found in BST\n", key);
    else
        printf("Element %d not found in BST\n", key);

    return 0;
}