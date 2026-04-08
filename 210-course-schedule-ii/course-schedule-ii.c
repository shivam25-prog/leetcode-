#include <stdio.h>
#include <stdlib.h>

// Queue implementation
typedef struct {
    int* data;
    int front, rear, size;
} Queue;

Queue* createQueue(int n) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(n * sizeof(int));
    q->front = 0;
    q->rear = 0;
    q->size = n;
    return q;
}

void enqueue(Queue* q, int val) {
    q->data[q->rear++] = val;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Main function required by LeetCode
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    // adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));
    int* indegree = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int)); // worst case
    }

    // build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;
        indegree[a]++;
    }

    // queue for BFS
    Queue* q = createQueue(numCourses);
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) enqueue(q, i);
    }

    int* order = (int*)malloc(numCourses * sizeof(int));
    int idx = 0;

    while (!isEmpty(q)) {
        int course = dequeue(q);
        order[idx++] = course;

        for (int j = 0; j < adjSize[course]; j++) {
            int neigh = adj[course][j];
            indegree[neigh]--;
            if (indegree[neigh] == 0) enqueue(q, neigh);
        }
    }

    if (idx == numCourses) {
        *returnSize = numCourses;
        return order;
    } else {
        *returnSize = 0;
        return NULL; // cycle → impossible
    }
}