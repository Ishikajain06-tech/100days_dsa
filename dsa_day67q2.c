#include <stdlib.h>

#define MAX 2000

// Adjacency list node
struct Node {
    int v;
    struct Node* next;
};

// Graph
struct Node* adj[MAX];

// State: 0 = unvisited, 1 = visiting, 2 = visited
int state[MAX];

// Result array
int result[MAX];
int idx;

// Create node
struct Node* createNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->next = NULL;
    return node;
}

// Add edge u → v
void addEdge(int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;
}

// DFS with cycle detection
int dfs(int v) {
    if (state[v] == 1) return 0; // cycle
    if (state[v] == 2) return 1; // already done

    state[v] = 1; // visiting

    struct Node* temp = adj[v];
    while (temp) {
        if (!dfs(temp->v)) return 0;
        temp = temp->next;
    }

    state[v] = 2; // done
    result[idx--] = v; // postorder insert

    return 1;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    
    // Initialize graph
    for (int i = 0; i < numCourses; i++) {
        adj[i] = NULL;
        state[i] = 0;
    }

    // Build graph (b → a)
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        addEdge(b, a);
    }

    idx = numCourses - 1;

    // DFS for all nodes
    for (int i = 0; i < numCourses; i++) {
        if (state[i] == 0) {
            if (!dfs(i)) {
                *returnSize = 0;
                return (int*)malloc(0); // cycle → no solution
            }
        }
    }

    // Prepare answer
    int* ans = (int*)malloc(sizeof(int) * numCourses);
    for (int i = 0; i < numCourses; i++) {
        ans[i] = result[i];
    }

    *returnSize = numCourses;
    return ans;
}
