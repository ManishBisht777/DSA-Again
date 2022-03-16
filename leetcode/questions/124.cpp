int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;

    maxpath(root, maxi);
    return maxi;
}

int maxpath(TreeNode *root, int &maxi)
{
    if (!root)
        return 0;

    int left = max(0, root->left);

    int right = max(0, root->right);

    maxi = max(maxi, root->val + left + right);

    return max(left, right) + root->val;
}