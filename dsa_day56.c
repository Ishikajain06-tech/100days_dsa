/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to check mirror
int isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    // Both NULL → symmetric
    if (t1 == NULL && t2 == NULL)
        return 1;

    // One NULL → not symmetric
    if (t1 == NULL || t2 == NULL)
        return 0;

    // Check values and recursive mirror condition
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Main function
int isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}