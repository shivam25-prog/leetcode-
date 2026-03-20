int dfs(struct TreeNode* node, int isLeft) {
    if (!node) return 0;

    if (isLeft && !node->left && !node->right)
        return node->val;

    return dfs(node->left,  1)             
         + dfs(node->right, 0);            
}

int sumOfLeftLeaves(struct TreeNode* root) {
    return dfs(root, 0);                   
}