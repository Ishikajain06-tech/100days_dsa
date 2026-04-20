#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Stack
int stack[MAX], top = -1;

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

// DFS for filling stack
void dfs1(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;

    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs1(graph, temp->data, visited);
        }
        temp = temp->next;
    }

    stack[++top] = v;
}

// DFS for transpose graph
void dfs2(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;

    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs2(graph, temp->data, visited);
        }
        temp = temp->next;
    }
}

// Create transpose graph
struct Graph* transposeGraph(struct Graph* graph) {
    struct Graph* tGraph = (struct Graph*)malloc(sizeof(struct Graph));
    tGraph->V = graph->V;

    for (int i = 0; i < graph->V; i++) {
        tGraph->adj[i] = NULL;
    }

    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adj[i];
        while (temp) {
            addEdge(tGraph, temp->data, i); // reverse edge
            temp = temp->next;
        }
    }

    return tGraph;
}

// Kosaraju Algorithm
int kosaraju(int V, int edges[][2], int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    for (int i = 0; i < V; i++) {
        graph->adj[i] = NULL;
    }

    // Build graph
    for (int i = 0; i < E; i++) {
        addEdge(graph, edges[i][0], edges[i][1]);
    }

    int visited[MAX] = {0};

    // Step 1: Fill stack
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(graph, i, visited);
        }
    }

    // Step 2: Transpose graph
    struct Graph* tGraph = transposeGraph(graph);

    // Step 3: DFS using stack order
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    int scc = 0;

    while (top != -1) {
        int v = stack[top--];

        if (!visited[v]) {
            dfs2(tGraph, v, visited);
            scc++;
        }
    }

    return scc;
}

// Driver code
int main() {
    int V = 5;
    int edges[][2] = {
        {1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}
    };
    int E = 5;

    printf("Number of Strongly Connected Components: %d\n", kosaraju(V, edges, E));

    return 0;
}
