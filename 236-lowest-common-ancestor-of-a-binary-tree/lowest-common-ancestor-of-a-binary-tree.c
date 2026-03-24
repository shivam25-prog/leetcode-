/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // Base case: if root is NULL or matches p or q
    if (root == NULL || root == p || root == q) {
        return root;
    }
    
    // Search left and right subtrees
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    // If both sides return non-null, root is the LCA
    if (left != NULL && right != NULL) {
        return root;
    }
    
    // Otherwise return whichever side is non-null
    return (left != NULL) ? left : right;
}