#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void BFS(int graph[MAX][MAX], int vertices, int start) {
    int visited[MAX] = {0};

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < vertices; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices = 5;

    int graph[MAX][MAX] = {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };

    printf("BFS Traversal: ");
    BFS(graph, vertices, 0);

    return 0;
}
