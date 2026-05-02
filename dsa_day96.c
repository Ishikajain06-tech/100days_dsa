c#include <stdio.h>
#include <stdlib.h>

// Merge function that also counts inversions
int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;     // left subarray
    int j = mid + 1;  // right subarray
    int k = left;
    int invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);  // count inversions
        }
    }

    // Copy remaining elements
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back to original array
    for (int i = left; i <= right; i++)
        arr[i] = temp[i];

    return invCount;
}

// Recursive merge sort with inversion count
int mergeSort(int arr[], int temp[], int left, int right) {
    int invCount = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSort(arr, temp, left, mid);
        invCount += mergeSort(arr, temp, mid + 1, right);
        invCount += merge(arr, temp, left, mid, right);
    }

    return invCount;
}

// Main function
int countInversions(int arr[], int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    int result = mergeSort(arr, temp, 0, n - 1);
    free(temp);
    return result;
}

// Driver code
int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Number of inversions = %d\n", countInversions(arr, n));

    return 0;
}