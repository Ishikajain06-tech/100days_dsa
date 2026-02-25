#include <stdio.h>

void moveZeroes(int nums[], int n) {
    int pos = 0;   

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[pos] = nums[i];
            pos++;
        }
    }

    while (pos < n) {
        nums[pos] = 0;
        pos++;
    } 
}
