/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, 
                                      struct TreeNode* p, 
                                      struct TreeNode* q) {
    while (root != NULL) {
        // If both p and q are smaller than root, go left
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        }
        // If both p and q are greater than root, go right
        else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        }
        else {
            // Found the split point → this is the LCA
            return root;
        }
    }
    return NULL; // safety check
}