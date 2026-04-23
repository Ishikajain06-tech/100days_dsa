#include <stdio.h>

// Lower Bound: first index where arr[i] >= target
int lowerBound(int arr[], int n, int target) {
    int low = 0, high = n;  // notice high = n

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low; // index of lower bound
}

// Upper Bound: first index where arr[i] > target
int upperBound(int arr[], int n, int target) {
    int low = 0, high = n;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= target)
            low = mid + 1;
        else
            high = mid;
    }
    return low; // index of upper bound
}

int main() {
    int arr[] = {1, 2, 4, 4, 4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4;

    int lb = lowerBound(arr, n, target);
    int ub = upperBound(arr, n, target);

    printf("Lower Bound index: %d\n", lb);
    printf("Upper Bound index: %d\n", ub);

    return 0;
}