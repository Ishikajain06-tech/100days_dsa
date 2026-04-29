#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Check if we can place k cows with at least 'dist' distance
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1; // first cow
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
        if (count >= k)
            return 1; // possible
    }
    return 0; // not possible
}

// Main function to find largest minimum distance
int aggressiveCows(int stalls[], int n, int k) {
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;
            low = mid + 1;  // try bigger distance
        } else {
            high = mid - 1; // reduce distance
        }
    }
    return ans;
}

int main() {
    int stalls[] = {1, 2, 4, 8, 9};
    int n = sizeof(stalls) / sizeof(stalls[0]);
    int k = 3;

    int result = aggressiveCows(stalls, n, k);
    printf("Maximum minimum distance = %d\n", result);

    return 0;
}