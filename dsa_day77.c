#include <stdio.h>

#define MAX 100

int visited[MAX];

void dfs(int graph[MAX][MAX], int n, int node) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, n, i);
        }
    }
}

int isConnected(int graph[MAX][MAX], int n) {
    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Start DFS from node 0
    dfs(graph, n, 0);

    // Check if all nodes are visited
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return 0; // Not connected
        }
    }

    return 1; // Connected
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (isConnected(graph, n)) {
        printf("Graph is Connected\n");
    } else {
        printf("Graph is Not Connected\n");
    }

    return 0;
}