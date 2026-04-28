#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // avoids overflow

        if (arr[mid] == target) {
            return mid;  // element found
        }
        else if (arr[mid] < target) {
            low = mid + 1;  // search right half
        }
        else {
            high = mid - 1; // search left half
        }
    }

    return -1;  // element not found
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}