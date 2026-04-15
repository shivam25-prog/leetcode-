#include <stdio.h>
#include <stdbool.h>

void dfs(int** isConnected, int n, int* visited, int i) {
    visited[i] = 1;
    for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1 && !visited[j]) {
            dfs(isConnected, n, visited, j);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    int provinces = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, n, visited, i);
            provinces++;
        }
    }
    return provinces;
}