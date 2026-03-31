/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

struct TreeNode* buildTreeHelper(int* inorder, int inStart, int inEnd,
                                 int* postorder, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return NULL;

    // Root is the last element in postorder
    int rootVal = postorder[postEnd];
    struct TreeNode* root = newNode(rootVal);

    // Find root index in inorder
    int rootIndex = findIndex(inorder, inStart, inEnd, rootVal);

    int leftSize = rootIndex - inStart;

    // Build left and right subtrees
    root->left = buildTreeHelper(inorder, inStart, rootIndex - 1,
                                 postorder, postStart, postStart + leftSize - 1);

    root->right = buildTreeHelper(inorder, rootIndex + 1, inEnd,
                                  postorder, postStart + leftSize, postEnd - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    return buildTreeHelper(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}