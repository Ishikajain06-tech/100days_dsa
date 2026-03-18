void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}
void preorder(struct TreeNode* root) {
    if (root == NULL) return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct TreeNode* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}
#include <stdlib.h>

struct Queue {
    struct TreeNode* data[1000];
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

void levelOrder(struct TreeNode* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct TreeNode* node = dequeue(&q);
        printf("%d ", node->val);

        if (node->left)
            enqueue(&q, node->left);
        if (node->right)
            enqueue(&q, node->right);
    }
}