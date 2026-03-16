#include <stdio.h>
#include <stdlib.h>

// Swap helper
void swap(int *a, int *b) {
    int tmp = *a; *a = *b; *b = tmp;
}

// Heapify down (min-heap)
void heapifyDown(int *heap, int size, int i) {
    int smallest = i;
    int left = 2*i + 1, right = 2*i + 2;
    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

// Heapify up
void heapifyUp(int *heap, int i) {
    while (i > 0) {
        int parent = (i-1)/2;
        if (heap[i] < heap[parent]) {
            swap(&heap[i], &heap[parent]);
            i = parent;
        } else break;
    }
}

// Structure for KthLargest
typedef struct {
    int *heap;
    int size;
    int capacity;
    int k;
} KthLargest;

// Create object
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * k);
    obj->size = 0;
    obj->capacity = k;
    obj->k = k;

    for (int i = 0; i < numsSize; i++) {
        if (obj->size < k) {
            obj->heap[obj->size++] = nums[i];
            heapifyUp(obj->heap, obj->size-1);
        } else if (nums[i] > obj->heap[0]) {
            obj->heap[0] = nums[i];
            heapifyDown(obj->heap, obj->size, 0);
        }
    }
    return obj;
}

// Add new score
int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size++] = val;
        heapifyUp(obj->heap, obj->size-1);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj->heap, obj->size, 0);
    }
    return obj->heap[0]; // kth largest
}

// Free memory
void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}