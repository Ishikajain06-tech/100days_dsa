#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool dfs(int graph[MAX][MAX], int visited[], int node, int parent, int vertices) {
    visited[node] = 1;

    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] == 1) {
            // If not visited, recurse
            if (!visited[i]) {
                if (dfs(graph, visited, i, node, vertices))
                    return true;
            }
            // If visited and not parent → cycle
            else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(int graph[MAX][MAX], int vertices) {
    int visited[MAX] = {0};

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (dfs(graph, visited, i, -1, vertices))
                return true;
        }
    }
    return false;
}

int main() {
    int vertices = 5;

    int graph[MAX][MAX] = {
        {0,1,0,0,0},
        {1,0,1,1,0},
        {0,1,0,0,0},
        {0,1,0,0,1},
        {0,0,0,1,0}
    };

    if (hasCycle(graph, vertices))
        printf("Cycle Detected\n");
    else
        printf("No Cycle\n");

    return 0;
}