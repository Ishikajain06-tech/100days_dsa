#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    
    // Step 1: Create distance matrix
    int dist[n][n];

    // Initialize matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INT_MAX / 2; // avoid overflow
        }
    }

    // Step 2: Fill edges
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Step 3: Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Step 4: Find city with minimum reachable neighbors
    int minCount = INT_MAX;
    int resultCity = -1;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                count++;
            }
        }

        // Step 5: Choose smallest count, break ties by larger index
        if (count <= minCount) {
            minCount = count;
            resultCity = i;
        }
    }

    return resultCity;
}
