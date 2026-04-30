#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int count[], Pair temp[]) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;  // one smaller element moved ahead
        } else {
            temp[k++] = arr[i];
            count[arr[i].idx] += rightCount;
            i++;
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i];
        count[arr[i].idx] += rightCount;
        i++;
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }
}

void mergeSort(Pair arr[], int left, int right, int count[], Pair temp[]) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, count, temp);
    mergeSort(arr, mid + 1, right, count, temp);
    merge(arr, left, mid, right, count, temp);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (numsSize == 0) return NULL;

    int* count = (int*)calloc(numsSize, sizeof(int));
    Pair* arr = (Pair*)malloc(numsSize * sizeof(Pair));
    Pair* temp = (Pair*)malloc(numsSize * sizeof(Pair));

    // Initialize pairs
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, 0, numsSize - 1, count, temp);

    free(arr);
    free(temp);

    return count;
}
