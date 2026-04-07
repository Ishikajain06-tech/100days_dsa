#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 2000

int adj[MAX][MAX];
int adjSize[MAX];

// DFS to detect cycle
bool dfs(int node, int visited[], int recStack[]) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; // cycle found
        }
    }

    recStack[node] = 0; // backtrack
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    int visited[MAX] = {0};
    int recStack[MAX] = {0};

    // initialize adjacency list
    for (int i = 0; i < numCourses; i++) {
        adjSize[i] = 0;
    }

    // build graph: b -> a
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][adjSize[b]++] = a;
    }

    // check all nodes (important for disconnected graph)
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack))
                return false; // cycle → cannot finish
        }
    }

    return true; // no cycle
}
