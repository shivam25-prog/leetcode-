/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// LeetCode-style solution in C (BFS)

#include <stdbool.h>

typedef struct {
    int r, c;
} Point;

bool inBounds(int r, int c, int m, int n) {
    return r >= 0 && r < m && c >= 0 && c < n;
}

int** floodFill(int** image, int imageSize, int* imageColSize,
                int sr, int sc, int color,
                int* returnSize, int** returnColumnSizes) {

    int m = imageSize;
    int n = *imageColSize;
    int originalColor = image[sr][sc];

    if (originalColor == color) {
        *returnSize = m;
        *returnColumnSizes = imageColSize;
        return image;
    }

    // Simple queue using arrays
    Point queue[m * n];
    int front = 0, rear = 0;

    // Start from (sr, sc)
    queue[rear++] = (Point){sr, sc};
    image[sr][sc] = color;

    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (front < rear) {
        Point p = queue[front++];
        for (int i = 0; i < 4; i++) {
            int nr = p.r + directions[i][0];
            int nc = p.c + directions[i][1];
            if (inBounds(nr, nc, m, n) && image[nr][nc] == originalColor) {
                image[nr][nc] = color;
                queue[rear++] = (Point){nr, nc};
            }
        }
    }

    *returnSize = m;
    *returnColumnSizes = imageColSize;
    return image;
}