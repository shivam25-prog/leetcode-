// LeetCode-style solution in C (DFS)

void dfs(int** isConnected, int n, int* visited, int city) {
    visited[city] = 1;
    for (int neighbor = 0; neighbor < n; neighbor++) {
        if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
            dfs(isConnected, n, visited, neighbor);
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