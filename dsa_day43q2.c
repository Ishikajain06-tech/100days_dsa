#include <stdlib.h>
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

void inorder(struct TreeNode* root, int* arr, int* index){
    if(root == NULL)
        return;

    inorder(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorder(root->right, arr, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {

    int* result = (int*)malloc(100 * sizeof(int)); // enough for constraints
    int index = 0;

    inorder(root, result, &index);

    *returnSize = index;
    return result;
}
