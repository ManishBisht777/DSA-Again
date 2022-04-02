vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;

    recurssion(root, 0, ans);
    return ans;
}

void recurssion(TreeNode *root, int level, vector<int> &ans)
{
    if (!root)
        return;

    if (ans.size() == level)
        ans.push_back(root->val);
    recurssion(root->right, level + 1, ans);
    recurssion(root->left, level + 1, ans);
}