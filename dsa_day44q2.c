#include <stdlib.h>

// Helper function
void preorderHelper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    result[(*index)++] = root->val;   // Root
    preorderHelper(root->left, result, index);  // Left
    preorderHelper(root->right, result, index); // Right
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 1000); // enough space
    int index = 0;

    preorderHelper(root, result, &index);

    *returnSize = index;
    return result;
}
