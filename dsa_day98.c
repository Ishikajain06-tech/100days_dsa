#include <stdio.h>
#include <stdlib.h>

// Interval structure
struct Interval {
    int start;
    int end;
};

// Comparator for sorting by start time
int compare(const void* a, const void* b) {
    struct Interval* i1 = (struct Interval*)a;
    struct Interval* i2 = (struct Interval*)b;
    return i1->start - i2->start;
}

// Function to merge intervals
struct Interval* mergeIntervals(struct Interval arr[], int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Sort intervals
    qsort(arr, n, sizeof(struct Interval), compare);

    // Allocate result array
    struct Interval* result = (struct Interval*)malloc(n * sizeof(struct Interval));
    int index = 0;

    // Initialize first interval
    result[index] = arr[0];

    for (int i = 1; i < n; i++) {
        // If overlapping
        if (arr[i].start <= result[index].end) {
            if (arr[i].end > result[index].end)
                result[index].end = arr[i].end;
        } else {
            // No overlap → add new interval
            index++;
            result[index] = arr[i];
        }
    }

    *returnSize = index + 1;
    return result;
}

// Driver code
int main() {
    struct Interval arr[] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n = sizeof(arr) / sizeof(arr[0]);

    int newSize;
    struct Interval* result = mergeIntervals(arr, n, &newSize);

    printf("Merged intervals:\n");
    for (int i = 0; i < newSize; i++) {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }

    free(result);
    return 0;
}