#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("Enter order of square matrix: ");
    scanf("%d", &n);
    
    int matrix[n][n];
    
    printf("Enter elements of matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int isSymmetric = 1;   
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
    }
    
    if(isSymmetric)
        printf("Matrix is Symmetric\n");
    else
        printf("Matrix is Not Symmetric\n");
    
    return 0;
}
