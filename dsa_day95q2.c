#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2)
        return 0;

    int minVal = INT_MAX, maxVal = INT_MIN;

    // Find min and max
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < minVal) minVal = nums[i];
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    if (minVal == maxVal)
        return 0;

    // Compute bucket size
    int gap = (maxVal - minVal) / (numsSize - 1);
    if ((maxVal - minVal) % (numsSize - 1) != 0)
        gap++;

    int bucketSize = (maxVal - minVal) / gap + 1;

    int* bucketMin = (int*)malloc(bucketSize * sizeof(int));
    int* bucketMax = (int*)malloc(bucketSize * sizeof(int));
    int* used = (int*)calloc(bucketSize, sizeof(int));

    // Initialize
    for (int i = 0; i < bucketSize; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    // Fill buckets
    for (int i = 0; i < numsSize; i++) {
        int index = (nums[i] - minVal) / gap;

        if (!used[index]) {
            bucketMin[index] = nums[i];
            bucketMax[index] = nums[i];
            used[index] = 1;
        } else {
            if (nums[i] < bucketMin[index]) bucketMin[index] = nums[i];
            if (nums[i] > bucketMax[index]) bucketMax[index] = nums[i];
        }
    }

    // Compute maximum gap
    int maxGap = 0;
    int prevMax = minVal;

    for (int i = 0; i < bucketSize; i++) {
        if (!used[i]) continue;

        if (bucketMin[i] - prevMax > maxGap)
            maxGap = bucketMin[i] - prevMax;

        prevMax = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);
    free(used);

    return maxGap;
}
