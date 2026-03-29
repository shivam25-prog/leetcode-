/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode* root) {
    while (root) {
        if (root->left) {
            // Find the rightmost node of the left subtree
            struct TreeNode* pre = root->left;
            while (pre->right) {
                pre = pre->right;
            }
            // Connect it to the current right subtree
            pre->right = root->right;
            // Move left subtree to the right
            root->right = root->left;
            root->left = NULL;
        }
        // Move to the next node
        root = root->right;
    }
}