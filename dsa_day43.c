#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Queue for level order construction
struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[++front];
}

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Level order construction
struct Node* buildTree() {
    int data;
    
    printf("Enter root value (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    struct Node* root = createNode(data);
    enqueue(root);

    while (front != rear) {
        struct Node* temp = dequeue();

        printf("Enter left child of %d (-1 for no node): ", temp->data);
        scanf("%d", &data);
        if (data != -1) {
            temp->left = createNode(data);
            enqueue(temp->left);
        }

        printf("Enter right child of %d (-1 for no node): ", temp->data);
        scanf("%d", &data);
        if (data != -1) {
            temp->right = createNode(data);
            enqueue(temp->right);
        }
    }

    return root;
}

// Inorder traversal to verify tree
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = buildTree();

    printf("Inorder Traversal:\n");
    inorder(root);

    return 0;
}