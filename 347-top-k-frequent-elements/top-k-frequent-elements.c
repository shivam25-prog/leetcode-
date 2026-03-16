#include <stdio.h>
#include <stdlib.h>

// Hash map node
typedef struct {
    int key;
    int count;
} Pair;

// Compare function for qsort (descending by count)
int cmp(const void* a, const void* b) {
    return ((Pair*)b)->count - ((Pair*)a)->count;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    // Step 1: Count frequencies using simple array (since nums may be small range)
    // For general case, use hash map. Here we’ll simulate with dynamic array.
    Pair* freq = (Pair*)malloc(sizeof(Pair) * numsSize);
    int freqSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int found = 0;
        for (int j = 0; j < freqSize; j++) {
            if (freq[j].key == nums[i]) {
                freq[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            freq[freqSize].key = nums[i];
            freq[freqSize].count = 1;
            freqSize++;
        }
    }

    // Step 2: Sort by frequency
    qsort(freq, freqSize, sizeof(Pair), cmp);

    // Step 3: Collect top k
    *returnSize = k;
    int* result = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        result[i] = freq[i].key;
    }

    free(freq);
    return result;
}