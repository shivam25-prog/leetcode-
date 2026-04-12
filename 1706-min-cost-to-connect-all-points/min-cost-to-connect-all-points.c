#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int* minDist = (int*)malloc(n * sizeof(int));
    bool* inMST = (bool*)malloc(n * sizeof(bool));

    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
        inMST[i] = false;
    }

    minDist[0] = 0; // start from point 0
    int result = 0;

    for (int i = 0; i < n; i++) {
        // pick the node with smallest distance not in MST
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!inMST[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        inMST[u] = true;
        result += minDist[u];

        // update distances
        for (int v = 0; v < n; v++) {
            if (!inMST[v]) {
                int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    free(minDist);
    free(inMST);
    return result;
}