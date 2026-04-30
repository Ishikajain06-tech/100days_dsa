#include <stdio.h>

// Check if we can ship within given days
int canShip(int* weights, int n, int days, int capacity) {
    int currentWeight = 0;
    int requiredDays = 1;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weights[i] > capacity) {
            requiredDays++;
            currentWeight = 0;
        }
        currentWeight += weights[i];
    }

    return requiredDays <= days;
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int maxWeight = 0, sum = 0;

    // Find range
    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > maxWeight)
            maxWeight = weights[i];
        sum += weights[i];
    }

    int low = maxWeight;
    int high = sum;
    int ans = sum;

    // Binary search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canShip(weights, weightsSize, days, mid)) {
            ans = mid;
            high = mid - 1;  // try smaller capacity
        } else {
            low = mid + 1;   // need bigger capacity
        }
    }

    return ans;
}
