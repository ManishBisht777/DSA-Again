void helper(Node *root, int lvl, vector<int> &ans)
{
    if (!root)
        return;

    if (lvl == ans.size())
        ans.push_back(root->data);

    helper(root->left, lvl + 1, ans);
    helper(root->right, lvl + 1, ans);
}

vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans;
    helper(root, 0, ans);
    return ans;
}