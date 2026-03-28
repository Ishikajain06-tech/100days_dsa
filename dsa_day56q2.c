#include <stdbool.h>
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

// Helper function
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    // Both NULL → symmetric
    if (left == NULL && right == NULL)
        return true;

    // One NULL → not symmetric
    if (left == NULL || right == NULL)
        return false;

    // Check values + recursive mirror check
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Main function
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;

    return isMirror(root->left, root->right);
}
