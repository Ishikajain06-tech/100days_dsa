#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool dfs(int graph[MAX][MAX], int visited[], int recStack[], int node, int vertices) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] == 1) {
            // If not visited
            if (!visited[i]) {
                if (dfs(graph, visited, recStack, i, vertices))
                    return true;
            }
            // If visited and in recursion stack → cycle
            else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[node] = 0; // remove from stack
    return false;
}

bool hasCycle(int graph[MAX][MAX], int vertices) {
    int visited[MAX] = {0};
    int recStack[MAX] = {0};

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (dfs(graph, visited, recStack, i, vertices))
                return true;
        }
    }
    return false;
}

int main() {
    int vertices = 4;

    int graph[MAX][MAX] = {
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
        {0,1,0,0}  // creates a cycle
    };

    if (hasCycle(graph, vertices))
        printf("Cycle Detected\n");
    else
        printf("No Cycle\n");

    return 0;
}