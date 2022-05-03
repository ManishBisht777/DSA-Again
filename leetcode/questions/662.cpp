int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;

    unsigned int ans = 0;

    queue<pair<TreeNode *, unsigned int>> q;
    q.push({root, 1});

    while (!q.empty())
    {
        unsigned int min = q.front().second;
        unsigned int size = q.size();
        unsigned int first, last;

        for (int i = 0; i < size; i++)
        {
            unsigned int curridx = q.front().second - min;
            TreeNode *node = q.front().first;
            q.pop();

            if (i == 0)
                first = curridx;
            if (i == size - 1)
                last = curridx;

            if (node->left)
                q.push({node->left, curridx * 2});
            if (node->right)
                q.push({node->right, curridx * 2 + 1});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}