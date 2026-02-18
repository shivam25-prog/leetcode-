/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* answer = (int*)malloc(numsSize * sizeof(int));
    
    // Step 1: Prefix products
    int prefix = 1;
    for (int i = 0; i < numsSize; i++) {
        answer[i] = prefix;
        prefix *= nums[i];
    }
    
    // Step 2: Suffix products
    int suffix = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }
    
    return answer;
}