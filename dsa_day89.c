#include <stdio.h>
#include <limits.h>

// Check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (pagesSum + arr[i] > maxPages) {
            students++;
            pagesSum = arr[i];

            if (students > m)
                return 0;
        } else {
            pagesSum += arr[i];
        }
    }

    return 1;
}

int allocatePages(int arr[], int n, int m) {
    if (m > n) return -1;

    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    int low = maxVal;
    int high = sum;
    int result = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1; // try smaller value
        } else {
            low = mid + 1;
        }
    }

    return result;
}

// Driver code
int main() {
    int arr[] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;

    printf("Minimum pages = %d\n", allocatePages(arr, n, m));
    return 0;
}