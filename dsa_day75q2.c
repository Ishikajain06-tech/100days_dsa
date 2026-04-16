#include <stdio.h>
#include <stdlib.h>

#define UNCOLORED -1

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* color = (int*)malloc(graphSize * sizeof(int));

    // Initialize all nodes as uncolored
    for (int i = 0; i < graphSize; i++) {
        color[i] = UNCOLORED;
    }

    // Queue for BFS
    int* queue = (int*)malloc(graphSize * sizeof(int));

    for (int start = 0; start < graphSize; start++) {

        // If already colored, skip
        if (color[start] != UNCOLORED)
            continue;

        // Start BFS
        int front = 0, rear = 0;
        queue[rear++] = start;
        color[start] = 0;  // First color

        while (front < rear) {
            int node = queue[front++];

            // Traverse all adjacent nodes
            for (int i = 0; i < graphColSize[node]; i++) {
                int neighbor = graph[node][i];

                // If not colored, color it opposite
                if (color[neighbor] == UNCOLORED) {
                    color[neighbor] = 1 - color[node];
                    queue[rear++] = neighbor;
                }
                // If same color, not bipartite
                else if (color[neighbor] == color[node]) {
                    free(color);
                    free(queue);
                    return false;
                }
            }
        }
    }

    free(color);
    free(queue);
    return true;
}
