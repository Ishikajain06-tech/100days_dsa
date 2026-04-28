int canFinish(int* piles, int pilesSize, int h, int k) {
    int hours = 0;

    for (int i = 0; i < pilesSize; i++) {
        hours += (piles[i] + k - 1) / k;  // ceil division

        if (hours > h)  // early stop
            return 0;
    }

    return 1;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1, high = 0;

    // find max pile
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > high)
            high = piles[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canFinish(piles, pilesSize, h, mid)) {
            ans = mid;
            high = mid - 1;  // try smaller speed
        } else {
            low = mid + 1;   // increase speed
        }
    }

    return ans;
}
