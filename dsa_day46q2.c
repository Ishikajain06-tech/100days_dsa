#include <stdlib.h>

// Queue structure
struct Queue {
    struct TreeNode* data[2000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->data[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->data[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** result = (int**)malloc(sizeof(int*) * 1000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int level = 0;

    while (!isEmpty(&q)) {
        int size = q.rear - q.front;   // number of nodes in current level
        
        (*returnColumnSizes)[level] = size;
        result[level] = (int*)malloc(sizeof(int) * size);

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(&q);
            result[level][i] = node->val;

            if (node->left)
                enqueue(&q, node->left);
            if (node->right)
                enqueue(&q, node->right);
        }

        level++;
    }

    *returnSize = level;
    return result;
}
