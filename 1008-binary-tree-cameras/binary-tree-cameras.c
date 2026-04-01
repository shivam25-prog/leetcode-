/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int cameras;

int dfs(struct TreeNode* root) {
    if (!root) return 2; // null nodes are considered covered

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 0 || right == 0) {
        cameras++;
        return 1; // place camera here
    }
    if (left == 1 || right == 1) {
        return 2; // covered by child’s camera
    }
    return 0; // not covered
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if (dfs(root) == 0) {
        cameras++; // root not covered, add camera
    }
    return cameras;
}