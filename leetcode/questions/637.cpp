vector<double> averageOfLevels(TreeNode *root)
{

    queue<TreeNode *> q;
    q.push(root);
    vector<double> ans;
    double curr = 0;

    while (!q.empty())
    {
        int n = q.size();
        curr = 0;
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            curr += node->val;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        ans.push_back(curr / n);
    }
    return ans;
}