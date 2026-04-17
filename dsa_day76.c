#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS traversal
void dfs(int v) {
    visited[v] = 1;
    struct Node* temp = adj[v];

    while (temp != NULL) {
        int neighbor = temp->vertex;
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
        temp = temp->next;
    }
}

// Count connected components
int countComponents(int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    return count;
}

int main() {
    int n = 5; // number of vertices

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Example graph
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(3, 4);

    int result = countComponents(n);
    printf("Number of connected components: %d\n", result);

    return 0;
}