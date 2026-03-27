#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Queue structure for BFS
struct Queue {
    struct TreeNode* data[100];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->rear == 99) return;
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct TreeNode* temp = q->data[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Function to print right view
void rightView(struct TreeNode* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int size = q.rear - q.front + 1;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = dequeue(&q);

            // Last node of the level
            if (i == size - 1) {
                printf("%d ", curr->val);
            }

            if (curr->left) enqueue(&q, curr->left);
            if (curr->right) enqueue(&q, curr->right);
        }
    }
}
