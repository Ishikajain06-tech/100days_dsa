#include <stdio.h>
#include <stdlib.h>

// Function for Topological Sort using Kahn's Algorithm
int* topoSort(int V, int** adj, int* adjSize, int* returnSize) {
    
    int* indegree = (int*)calloc(V, sizeof(int));
    
    // Step 1: Calculate indegree
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adjSize[i]; j++) {
            indegree[adj[i][j]]++;
        }
    }

    // Queue
    int* queue = (int*)malloc(V * sizeof(int));
    int front = 0, rear = 0;

    // Step 2: Push nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int* topo = (int*)malloc(V * sizeof(int));
    int count = 0;

    // Step 3: BFS
    while (front < rear) {
        int node = queue[front++];
        topo[count++] = node;

        for (int i = 0; i < adjSize[node]; i++) {
            int neighbor = adj[node][i];
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }

    // Step 4: Check cycle
    if (count != V) {
        *returnSize = 0;  // cycle exists
        return NULL;
    }

    *returnSize = V;
    return topo;
}