void countNodes(TreeNode *root, int &ans, int maxTillNow)
{
    if (!root)
        return;
    if (root->val >= maxTillNow)
    {
        ans++;
        maxTillNow = root->val;
    }

    countNodes(root->left, ans, maxTillNow);
    countNodes(root->right, ans, maxTillNow);
}

int goodNodes(TreeNode *root)
{
    int ans = 0;
    countNodes(root, ans, root->val);
    return ans;
}