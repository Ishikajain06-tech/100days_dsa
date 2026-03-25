#include <stdio.h>
#include <stdlib.h>
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

// Queue implementation
#define MAX 2000

struct TreeNode* queue[MAX];
int front = 0, rear = 0;

void enqueue(struct TreeNode* node) {
    queue[rear++] = node;
}

struct TreeNode* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int** result = (int**)malloc(MAX * sizeof(int*));
    *returnColumnSizes = (int*)malloc(MAX * sizeof(int));
    
    *returnSize = 0;

    enqueue(root);

    while (!isEmpty()) {
        int levelSize = rear - front;

        // Allocate space for current level
        result[*returnSize] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue();

            result[*returnSize][i] = node->val;

            if (node->left)
                enqueue(node->left);
            if (node->right)
                enqueue(node->right);
        }

        (*returnSize)++;
    }

    return result;
}
