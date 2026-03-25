#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Binary Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Queue Node (stores tree node + horizontal distance)
struct QNode {
    struct TreeNode* node;
    int hd;
};

// Queue structure
struct Queue {
    int front, rear;
    struct QNode arr[MAX];
};

// Create new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Enqueue
void enqueue(struct Queue* q, struct TreeNode* node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

// Dequeue
struct QNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Vertical Order Traversal
void verticalOrder(struct TreeNode* root) {
    if (root == NULL) return;

    // Array to store nodes by horizontal distance
    int result[2 * MAX][MAX];
    int count[2 * MAX] = {0};

    int offset = MAX; // To handle negative HD

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root, 0);

    while (!isEmpty(&q)) {
        struct QNode temp = dequeue(&q);
        struct TreeNode* curr = temp.node;
        int hd = temp.hd + offset;

        result[hd][count[hd]++] = curr->val;

        if (curr->left)
            enqueue(&q, curr->left, temp.hd - 1);

        if (curr->right)
            enqueue(&q, curr->right, temp.hd + 1);
    }

    // Print vertical order
    for (int i = 0; i < 2 * MAX; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
}

// Driver Code
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}