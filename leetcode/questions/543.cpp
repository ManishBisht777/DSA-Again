int ans = 0;

int heightTree(TreeNode *root)
{
    if (!root)
        return 0;

    int lh = heightTree(root->left);
    int rh = heightTree(root_ > right);

    ans = max(ans, lh + rh);

    return 1 + max(lh, rh);
}

int diameter(TreeNode *root)
{
    if (!roor)
        return NULL;

    heightTree(root);

    return ans;
}