#include <stdlib.h>

// Mapping original → cloned
struct Node* original[1000];
struct Node* cloned[1000];
int size = 0;

// Find if node already cloned
struct Node* getClonedNode(struct Node* node) {
    for (int i = 0; i < size; i++) {
        if (original[i] == node)
            return cloned[i];
    }
    return NULL;
}

// Store mapping
void storeMapping(struct Node* node, struct Node* clone) {
    original[size] = node;
    cloned[size] = clone;
    size++;
}

// DFS function
struct Node* dfs(struct Node* node) {
    if (node == NULL)
        return NULL;

    // If already cloned
    struct Node* existing = getClonedNode(node);
    if (existing != NULL)
        return existing;

    // Create new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = node->val;
    newNode->numNeighbors = node->numNeighbors;

    // Allocate neighbors array
    newNode->neighbors = (struct Node**)malloc(
        node->numNeighbors * sizeof(struct Node*)
    );

    // Store mapping BEFORE recursion
    storeMapping(node, newNode);

    // Clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        newNode->neighbors[i] = dfs(node->neighbors[i]);
    }

    return newNode;
}

// Main function
struct Node *cloneGraph(struct Node *s) {
    size = 0;
    return dfs(s);
}
