void helper(vector<string> &result, TreeNode *root, string path)
{
    if (!root->left && !root->right)
    {
        result.push_back(path);
        return;
    }

    if (root->left)
        helper(result, root->left, path + "->" + to_string(root->left->val));
    if (root->right)
        helper(result, root->right, path + "->" + to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    helper(result, root, to_string(root->val));
    return ans;
}