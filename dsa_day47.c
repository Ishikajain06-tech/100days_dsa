/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    // Base case
    if (root == NULL)
        return 0;

    // Recursively find height of left and right subtrees
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    // Return the maximum of both + 1 (for current node)
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}