/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* mirrorTree(struct TreeNode* root) {
    if (root == NULL)
        return NULL;

    // Swap left and right children
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);

    return root;
}