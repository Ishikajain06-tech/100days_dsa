#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Structure for hash table
struct Hash {
    int sum;
    int index;
};

int maxLen(int arr[], int n) {
    struct Hash hash[MAX];
    int hashSize = 0;

    int sum = 0, max_length = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: If sum is 0, update max_length
        if (sum == 0) {
            max_length = i + 1;
        }

        // Check if sum already exists
        int found = 0;
        for (int j = 0; j < hashSize; j++) {
            if (hash[j].sum == sum) {
                int length = i - hash[j].index;
                if (length > max_length)
                    max_length = length;
                found = 1;
                break;
            }
        }

        // If not found, store it
        if (!found) {
            hash[hashSize].sum = sum;
            hash[hashSize].index = i;
            hashSize++;
        }
    }

    return max_length;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Largest subarray length with zero sum: %d\n", maxLen(arr, n));
    return 0;
}