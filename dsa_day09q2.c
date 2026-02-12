#include <stdio.h>

void reverseString(char* s, int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}
