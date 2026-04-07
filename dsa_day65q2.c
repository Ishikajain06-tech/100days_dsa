#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

// Adjacency list
int adj[MAX][MAX];
int adjSize[MAX];

// DFS function
bool dfs(int node, int parent, int visited[]) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }
    }
    return false;
}

bool isCycle(int edges[][2], int E, int V) {
    int visited[MAX] = {0};

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        adjSize[i] = 0;
    }

    // Build graph
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u; // undirected
    }

    // Check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited))
                return true;
        }
    }

    return false;
}
