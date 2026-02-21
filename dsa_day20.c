#include <stdio.h>
#include <stdlib.h>

#define MAX 1000   

int countZeroSumSubarrays(int arr[], int n) {
    int prefixSum = 0, count = 0;

    int hash[2 * MAX + 1] = {0};

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0)
            count++;

        if (hash[prefixSum + MAX] > 0)
            count += hash[prefixSum + MAX];

        hash[prefixSum + MAX]++;
    }

    return count;
}

int main() {
    int arr[] = {1, -1, 2, -2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Count of zero sum subarrays = %d\n", 
            countZeroSumSubarrays(arr, n));

    return 0;
}