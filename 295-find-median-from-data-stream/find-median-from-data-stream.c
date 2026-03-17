#include <stdlib.h>

typedef struct {
    int *maxHeap;
    int *minHeap;
    int maxSize, minSize;
    int capacity;
} MedianFinder;

// Swap
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Create
MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    
    obj->capacity = 100000;  // safe limit
    obj->maxHeap = (int*)malloc(sizeof(int) * obj->capacity);
    obj->minHeap = (int*)malloc(sizeof(int) * obj->capacity);
    
    obj->maxSize = 0;
    obj->minSize = 0;
    
    return obj;
}

// Max heap insert
void insertMax(MedianFinder* obj, int val) {
    int i = obj->maxSize++;
    obj->maxHeap[i] = val;

    while (i > 0 && obj->maxHeap[(i - 1)/2] < obj->maxHeap[i]) {
        swap(&obj->maxHeap[i], &obj->maxHeap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

// Min heap insert
void insertMin(MedianFinder* obj, int val) {
    int i = obj->minSize++;
    obj->minHeap[i] = val;

    while (i > 0 && obj->minHeap[(i - 1)/2] > obj->minHeap[i]) {
        swap(&obj->minHeap[i], &obj->minHeap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

// Extract max
int extractMax(MedianFinder* obj) {
    int val = obj->maxHeap[0];
    obj->maxHeap[0] = obj->maxHeap[--obj->maxSize];

    int i = 0;
    while (2*i + 1 < obj->maxSize) {
        int largest = i;
        int l = 2*i + 1, r = 2*i + 2;

        if (l < obj->maxSize && obj->maxHeap[l] > obj->maxHeap[largest])
            largest = l;
        if (r < obj->maxSize && obj->maxHeap[r] > obj->maxHeap[largest])
            largest = r;

        if (largest == i) break;

        swap(&obj->maxHeap[i], &obj->maxHeap[largest]);
        i = largest;
    }
    return val;
}

// Extract min
int extractMin(MedianFinder* obj) {
    int val = obj->minHeap[0];
    obj->minHeap[0] = obj->minHeap[--obj->minSize];

    int i = 0;
    while (2*i + 1 < obj->minSize) {
        int smallest = i;
        int l = 2*i + 1, r = 2*i + 2;

        if (l < obj->minSize && obj->minHeap[l] < obj->minHeap[smallest])
            smallest = l;
        if (r < obj->minSize && obj->minHeap[r] < obj->minHeap[smallest])
            smallest = r;

        if (smallest == i) break;

        swap(&obj->minHeap[i], &obj->minHeap[smallest]);
        i = smallest;
    }
    return val;
}

// Add number
void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->maxSize == 0 || num <= obj->maxHeap[0]) {
        insertMax(obj, num);
    } else {
        insertMin(obj, num);
    }

    // Balance
    if (obj->maxSize > obj->minSize + 1) {
        insertMin(obj, extractMax(obj));
    } else if (obj->minSize > obj->maxSize) {
        insertMax(obj, extractMin(obj));
    }
}

// Find median
double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxSize == obj->minSize) {
        return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
    }
    return obj->maxHeap[0];
}

// Free memory
void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}