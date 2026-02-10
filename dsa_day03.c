#include <stdio.h>

int main() {
    int n, key, i;
    int count = 0;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        count++;              
        if(arr[i] == key) {
            printf("Element found at position %d\n", i + 1);
            printf("Number of comparisons = %d\n", count);
            return 0;
        }
    }

    printf("Element not found\n");
    printf("Number of comparisons = %d\n", count);

    return 0;
}
