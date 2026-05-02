#include <stdio.h>
#include <stdlib.h>

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int max = 0;

    // Find max value in arr1
    for (int i = 0; i < arr1Size; i++) {
        if (arr1[i] > max)
            max = arr1[i];
    }

    // Frequency array
    int* count = (int*)calloc(max + 1, sizeof(int));

    // Count elements in arr1
    for (int i = 0; i < arr1Size; i++) {
        count[arr1[i]]++;
    }

    // Result array
    int* result = (int*)malloc(arr1Size * sizeof(int));
    int index = 0;

    // Place elements in order of arr2
    for (int i = 0; i < arr2Size; i++) {
        while (count[arr2[i]] > 0) {
            result[index++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    // Place remaining elements in ascending order
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            result[index++] = i;
            count[i]--;
        }
    }

    free(count);

    *returnSize = arr1Size;
    return result;
}
