// LeetCode-style solution in C (BFS)

#include <stdbool.h>

typedef struct {
    int r, c;
} Point;

bool inBounds(int r, int c, int m, int n) {
    return r >= 0 && r < m && c >= 0 && c < n;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = *gridColSize;

    Point queue[m * n];
    int front = 0, rear = 0;
    int freshCount = 0;

    // Collect all rotten oranges initially
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Point){i, j};
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    if (freshCount == 0) return 0; // no fresh oranges

    int minutes = -1;
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (front < rear) {
        int size = rear - front;
        minutes++;
        for (int i = 0; i < size; i++) {
            Point p = queue[front++];
            for (int d = 0; d < 4; d++) {
                int nr = p.r + directions[d][0];
                int nc = p.c + directions[d][1];
                if (inBounds(nr, nc, m, n) && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    freshCount--;
                    queue[rear++] = (Point){nr, nc};
                }
            }
        }
    }

    return freshCount == 0 ? minutes : -1;
}