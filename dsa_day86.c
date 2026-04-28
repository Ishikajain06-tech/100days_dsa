#include <stdio.h>

int sqrtBinarySearch(int n) {
    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid * mid == n) {
            return mid;
        }
        else if (mid * mid < n) {
            ans = mid;       // store possible answer
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;  // floor value of square root
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = sqrtBinarySearch(n);
    printf("Square root (floor value) = %d\n", result);

    return 0;
}