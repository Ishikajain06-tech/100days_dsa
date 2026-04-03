#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
void dfs(int** rooms, int roomsSize, int* roomsColSize, int room, bool* visited) {
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int nextRoom = rooms[room][i];
        if (!visited[nextRoom]) {
            dfs(rooms, roomsSize, roomsColSize, nextRoom, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));

    // Start from room 0
    dfs(rooms, roomsSize, roomsColSize, 0, visited);

    // Check if all rooms are visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            free(visited);
            return false;
        }
    }

    free(visited);
    return true;
}
