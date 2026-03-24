struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while (root != NULL) {
        if (root->val == val)
            return root;          // Found the node

        if (val < root->val)
            root = root->left;    // Go left
        else
            root = root->right;   // Go right
    }
    return NULL; // Not found
}
