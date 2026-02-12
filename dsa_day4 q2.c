#include <stdio.h>

int removeElement(int nums[], int size, int val) {
    int k = 0;   

    for (int i = 0; i < size; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
