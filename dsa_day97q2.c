#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMeetingRooms(int* start, int* end, int n) {
    // Sort both arrays
    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    int i = 0, j = 0;
    int rooms = 0, maxRooms = 0;

    while (i < n) {
        if (start[i] < end[j]) {
            rooms++;   // need new room
            i++;
        } else {
            rooms--;   // free a room
            j++;
        }

        if (rooms > maxRooms)
            maxRooms = rooms;
    }

    return maxRooms;
}

// Driver code
int main() {
    int start[] = {0, 5, 15};
    int end[]   = {30, 10, 20};
    int n = sizeof(start) / sizeof(start[0]);

    printf("Minimum rooms required = %d\n", minMeetingRooms(start, end, n));

    return 0;
}
