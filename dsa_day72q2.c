#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXN 20

int n;
int dp[MAXN][1 << MAXN];

// Recursive function
int solve(int mask, int pos, int cost[MAXN][MAXN]) {
    // If all cities visited, return to start
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    // If already computed
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int ans = INT_MAX;

    // Try all unvisited cities
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = cost[pos][city] +
                         solve(mask | (1 << city), city, cost);

            if (newAns < ans) {
                ans = newAns;
            }
        }
    }

    return dp[pos][mask] = ans;
}

// Main TSP function
int tsp(int cost[MAXN][MAXN], int size) {
    n = size;

    // Initialize DP table
    memset(dp, -1, sizeof(dp));

    // Start from city 0, mask = 1 (only city 0 visited)
    return solve(1, 0, cost);
}

// Driver code
int main() {
    int cost[MAXN][MAXN] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int size = 4;

    int result = tsp(cost, size);

    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
