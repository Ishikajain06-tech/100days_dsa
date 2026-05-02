#include <stdio.h>

// Function to check if boards can be painted with given maxTime
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (currentTime + arr[i] <= maxTime) {
            currentTime += arr[i];
        } else {
            painters++;
            currentTime = arr[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

// Main function to find minimum time
int painterPartition(int arr[], int n, int k) {
    int low = arr[0], high = 0;

    // Find max and sum
    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, k, mid)) {
            result = mid;
            high = mid - 1;  // try smaller time
        } else {
            low = mid + 1;   // increase time
        }
    }

    return result;
}

// Driver code
int main() {
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    printf("Minimum time to paint boards = %d\n", painterPartition(arr, n, k));

    return 0;
}