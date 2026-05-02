#include <stdio.h>

// Swap function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (Lomuto)
int partition(int nums[], int low, int high) {
    int pivot = nums[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {
            swap(&nums[i], &nums[j]);
            i++;
        }
    }

    swap(&nums[i], &nums[high]);
    return i;
}

// Quickselect
int quickSelect(int nums[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(nums, low, high);

        if (pi == k)
            return nums[pi];
        else if (pi < k)
            return quickSelect(nums, pi + 1, high, k);
        else
            return quickSelect(nums, low, pi - 1, k);
    }
    return -1;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int targetIndex = numsSize - k;  // convert to kth smallest
    return quickSelect(nums, 0, numsSize - 1, targetIndex);
}
