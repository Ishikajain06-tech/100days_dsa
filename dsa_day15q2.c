#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    int *rowZero = (int *)calloc(rows, sizeof(int));
    int *colZero = (int *)calloc(cols, sizeof(int));

    // Step 1: Mark rows and columns that have zero
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 0) {
                rowZero[i] = 1;
                colZero[j] = 1;
            }
        }
    }

    // Step 2: Set elements to zero
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(rowZero[i] == 1 || colZero[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }

    free(rowZero);
    free(colZero);
}
