#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int findIndex(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build Tree
struct TreeNode* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    // Pick current root
    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = newNode(rootVal);

    // If only one node
    if (start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, rootVal);

    // Build right first, then left
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Preorder print (to verify)
void preorder(struct TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

// Driver code
int main() {
    int inorder[] = {4, 2, 5, 1, 3};
    int postorder[] = {4, 5, 2, 3, 1};
    int n = 5;

    int postIndex = n - 1;

    struct TreeNode* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Preorder of constructed tree:\n");
    preorder(root);

    return 0;
}