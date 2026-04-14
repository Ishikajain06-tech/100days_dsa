#include <stdio.h>
#include <stdlib.h>

int findParent(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = findParent(parent, parent[x]); // Path compression
    return parent[x];
}

void unionSet(int parent[], int rank[], int x, int y) {
    int px = findParent(parent, x);
    int py = findParent(parent, y);

    if (px == py) return;

    // Union by rank
    if (rank[px] < rank[py]) {
        parent[px] = py;
    } else if (rank[px] > rank[py]) {
        parent[py] = px;
    } else {
        parent[py] = px;
        rank[px]++;
    }
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int n = edgesSize;

    int* parent = (int*)malloc((n + 1) * sizeof(int));
    int* rank = (int*)calloc((n + 1), sizeof(int));

    // Initialize DSU
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        if (pu == pv) {
            // Cycle detected → redundant edge
            result[0] = u;
            result[1] = v;
        } else {
            unionSet(parent, rank, u, v);
        }
    }

    *returnSize = 2;
    return result;
}
