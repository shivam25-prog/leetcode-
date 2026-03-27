/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloc'ed, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    // Queue for BFS
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int* result = (int*)malloc(2000 * sizeof(int));
    *returnSize = 0;

    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

            // If it's the last node in this level, add to result
            if (i == levelSize - 1) {
                result[*returnSize] = node->val;
                (*returnSize)++;
            }

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
    }

    return result;
}