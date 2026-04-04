#include <stdlib.h>

// DFS helper function
void dfs(int** image, int rows, int cols, int r, int c, int oldColor, int newColor) {
    // Boundary check
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return;

    // If pixel is not the original color, skip
    if (image[r][c] != oldColor)
        return;

    // Fill color
    image[r][c] = newColor;

    // Explore 4 directions
    dfs(image, rows, cols, r + 1, c, oldColor, newColor);
    dfs(image, rows, cols, r - 1, c, oldColor, newColor);
    dfs(image, rows, cols, r, c + 1, oldColor, newColor);
    dfs(image, rows, cols, r, c - 1, oldColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize,
                int sr, int sc, int color,
                int* returnSize, int** returnColumnSizes) {

    int rows = imageSize;
    int cols = imageColSize[0];

    int oldColor = image[sr][sc];

    // If color is same, no need to process
    if (oldColor != color) {
        dfs(image, rows, cols, sr, sc, oldColor, color);
    }

    // Set return values
    *returnSize = rows;

    *returnColumnSizes = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        (*returnColumnSizes)[i] = cols;
    }

    return image;
}
