#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = *matrixColSize;
    int* result = (int*)malloc(m * n * sizeof(int));
    *returnSize = 0;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; i++) {
            result[(*returnSize)++] = matrix[top][i];
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++) {
            result[(*returnSize)++] = matrix[i][right];
        }
        right--;

        // Traverse from right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[(*returnSize)++] = matrix[bottom][i];
            }
            bottom--;
        }

        // Traverse from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[(*returnSize)++] = matrix[i][left];
            }
            left++;
        }
    }

    return result;
}