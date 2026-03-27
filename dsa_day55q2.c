#include <stdio.h>
#include <stdlib.h>

// Definition for binary tree node
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

// Queue for BFS
struct Queue {
    struct TreeNode* data[2000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->rear == 1999) return;
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    struct TreeNode* temp = q->data[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Main function
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int* result = (int*)malloc(sizeof(int) * 1000); // max nodes
    int count = 0;

    while (!isEmpty(&q)) {
        int size = q.rear - q.front + 1;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(&q);

            // last node of this level
            if (i == size - 1) {
                result[count++] = node->val;
            }

            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }
    }

    *returnSize = count;
    return result;
}
