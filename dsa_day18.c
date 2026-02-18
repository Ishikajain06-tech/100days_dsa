#include <stdio.h>

void rotate(int arr[], int n, int k) {
    int temp[n];
    
    k = k % n;   
    
    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }
    
    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 2;

    rotate(arr, n, k);

    printf("Rotated Array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
