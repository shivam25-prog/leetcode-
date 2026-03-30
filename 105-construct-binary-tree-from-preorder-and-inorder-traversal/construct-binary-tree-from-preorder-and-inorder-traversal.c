struct TreeNode* buildTreeHelper(int preorder[], int inorder[], int start, int end, int *preIndex, int size)
{
    if(start > end)
        return NULL;

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = preorder[*preIndex];
    node->left = node->right = NULL;

    (*preIndex)++;

    int inIndex;
    for(int i = start; i <= end; i++)
    {
        if(inorder[i] == node->val)
        {
            inIndex = i;
            break;
        }
    }

    node->left = buildTreeHelper(preorder, inorder, start, inIndex - 1, preIndex, size);
    node->right = buildTreeHelper(preorder, inorder, inIndex + 1, end, preIndex, size);

    return node;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, inorderSize - 1, &preIndex, inorderSize);
}