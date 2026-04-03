#include <stdio.h>
#include <stdlib.h>

// Definition for binary tree node
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

int cameras = 0;

// DFS function
int dfs(struct TreeNode* root) {
    if (root == NULL)
        return 2; // Null nodes are covered

    int left = dfs(root->left);
    int right = dfs(root->right);

    // If any child is not covered → place camera
    if (left == 0 || right == 0) {
        cameras++;
        return 1; // This node has a camera
    }

    // If any child has camera → this node is covered
    if (left == 1 || right == 1) {
        return 2;
    }

    // Otherwise, this node is not covered
    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;

    // If root is not covered, place camera
    if (dfs(root) == 0)
        cameras++;

    return cameras;
}
