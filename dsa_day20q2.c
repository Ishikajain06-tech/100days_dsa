#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
    *returnSize = 0;
    
    if (numsSize < 3) {
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Allocate worst-case space
    int capacity = numsSize * numsSize;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    
    for (int i = 0; i < numsSize - 2; i++) {
        
        // Skip duplicate first elements
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                
                result[*returnSize] = (int*)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                
                left++;
                right--;
                
                // Skip duplicates for second number
                while (left < right && nums[left] == nums[left - 1])
                    left++;
                
                // Skip duplicates for third number
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    
    return result;
}
