#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void* a, const void* b) {
    int* i1 = *(int**)a;
    int* i2 = *(int**)b;
    return i1[0] - i2[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
             int* returnSize, int** returnColumnSizes) {

    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Sort intervals by start time
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    // Allocate result (max possible = intervalsSize)
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int index = 0;

    // First interval
    result[index] = (int*)malloc(2 * sizeof(int));
    result[index][0] = intervals[0][0];
    result[index][1] = intervals[0][1];
    (*returnColumnSizes)[index] = 2;

    for (int i = 1; i < intervalsSize; i++) {
        // Overlapping case
        if (intervals[i][0] <= result[index][1]) {
            if (intervals[i][1] > result[index][1]) {
                result[index][1] = intervals[i][1];
            }
        } else {
            // New interval
            index++;
            result[index] = (int*)malloc(2 * sizeof(int));
            result[index][0] = intervals[i][0];
            result[index][1] = intervals[i][1];
            (*returnColumnSizes)[index] = 2;
        }
    }

    *returnSize = index + 1;
    return result;
}
