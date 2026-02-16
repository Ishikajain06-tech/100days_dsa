#include <stdio.h>

int diagonalSum(int matrix[][100], int n) {
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += matrix[i][i];

        sum += matrix[i][n - i - 1];
    }

    if(n % 2 == 1) {
        sum -= matrix[n/2][n/2];
    }

    return sum;
}

int main() {
    int n;
    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    int matrix[100][100];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int result = diagonalSum(matrix, n);
    printf("Diagonal Sum = %d\n", result);

    return 0;
}
