#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to initialize matrix
void initMatrix(int graph[MAX][MAX], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
}

// Add edge (Undirected Graph)
void addEdge(int graph[MAX][MAX], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Print adjacency matrix
void printMatrix(int graph[MAX][MAX], int vertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    initMatrix(graph, vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printMatrix(graph, vertices);

    return 0;
}