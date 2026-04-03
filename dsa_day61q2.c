#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
void dfs(int** isConnected, int n, int city, bool* visited) {
    visited[city] = true;

    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(isConnected, n, i, visited);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    bool* visited = (bool*)calloc(n, sizeof(bool));
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, n, i, visited);
            provinces++;  // New province found
        }
    }

    free(visited);
    return provinces;
}
