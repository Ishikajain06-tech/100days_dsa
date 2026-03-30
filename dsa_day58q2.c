
    int val;
    struct TreeNode *left;
    struct TreeNode *right;


// Helper pointer to track previous node
struct TreeNode* prev = NULL;

void flatten(struct TreeNode* root) {
    if (root == NULL)
        return;

    // Process right subtree first
    flatten(root->right);

    // Then left subtree
    flatten(root->left);

    // Rewire pointers
    root->right = prev;
    root->left = NULL;

    // Move prev to current node
    prev = root;
}
