#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int x, y;
} Node;

Node queue[MAX];
int front = 0, rear = 0;

void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

Node dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    int fresh = 0;

    // Directions: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Step 1: Add all rotten oranges to queue
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                enqueue(i, j);
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    // If no fresh oranges
    if (fresh == 0) return 0;

    int minutes = 0;

    // Step 2: BFS
    while (!isEmpty()) {
        int size = rear - front;
        int infected = 0;

        for (int i = 0; i < size; i++) {
            Node curr = dequeue();

            for (int d = 0; d < 4; d++) {
                int nx = curr.x + dx[d];
                int ny = curr.y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    enqueue(nx, ny);
                    fresh--;
                    infected = 1;
                }
            }
        }

        if (infected) minutes++;
    }

    // Step 3: Check if any fresh left
    return (fresh == 0) ? minutes : -1;
}
