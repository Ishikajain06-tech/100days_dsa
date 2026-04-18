#include <stdio.h>
#include <stdlib.h>

int timeCounter = 0;

// DFS function
void dfs(int u, int parent, int* disc, int* low,
         int** adj, int* adjSize,
         int** result, int* returnSize) {

    disc[u] = low[u] = timeCounter++;

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];

        if (v == parent)
            continue;

        if (disc[v] == -1) {
            dfs(v, u, disc, low, adj, adjSize, result, returnSize);

            // Update low value
            if (low[v] < low[u])
                low[u] = low[v];

            // Check for bridge
            if (low[v] > disc[u]) {
                result[*returnSize] = (int*)malloc(2 * sizeof(int));
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                (*returnSize)++;
            }
        } else {
            // Back edge
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                          int* connectionsColSize,
                          int* returnSize,
                          int** returnColumnSizes) {

    // Step 1: Create adjacency list
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(connectionsSize * sizeof(int));
    }

    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    // Step 2: Initialize discovery & low arrays
    int* disc = (int*)malloc(n * sizeof(int));
    int* low  = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    // Step 3: Prepare result arrays
    int** result = (int**)malloc(connectionsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(connectionsSize * sizeof(int));
    *returnSize = 0;

    // Step 4: Run DFS for all components
    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) {
            dfs(i, -1, disc, low, adj, adjSize, result, returnSize);
        }
    }

    // Step 5: Set column sizes
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}
