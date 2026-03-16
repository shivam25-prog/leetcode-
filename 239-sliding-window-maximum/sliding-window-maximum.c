#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    
    int* deque = (int*)malloc(sizeof(int) * numsSize); // store indices
    int front = 0, rear = -1;

    for (int i = 0; i < numsSize; i++) {
        // Remove indices out of window
        if (front <= rear && deque[front] <= i - k) {
            front++;
        }

        // Remove smaller values from back
        while (front <= rear && nums[deque[rear]] < nums[i]) {
            rear--;
        }

        // Add current index
        deque[++rear] = i;

        // Record max once window is full
        if (i >= k - 1) {
            result[i - k + 1] = nums[deque[front]];
        }
    }

    free(deque);
    return result;
}