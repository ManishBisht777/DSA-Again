int curr_sum = 0;

void travel(TreeNode *root)
{
    if (!root)
        return;

    if (root->right)
        travel(root->right);
    curr_sum += root->val;
    root->val = curr_sum;

    if (root->left)
        travel(root->left);
}

TreeNode *convertBST(TreeNode *root)
{
    travel(root);
    return root;
}