#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS function
void dfs(int graph[MAX][MAX], int n, int node) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, n, i);
        }
    }
}

int main() {
    int n = 5;

    // Example graph (adjacency matrix)
    int graph[MAX][MAX] = {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };

    dfs(graph, n, 0);

    return 0;
}