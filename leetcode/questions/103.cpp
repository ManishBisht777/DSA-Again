vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (!root)
    {
        return result;
    }

    queue<TreeNode *> que;
    bool LtoR = true;

    que.push(root);

    while (!que.epmty())
    {
        int size = que.size();
        vector<int> row(size);

        for (int i = 0; i < size; i++)
        {
            Treenode *node = que.front();
            que.pop();

            int idx = LtoR ? i : size - 1 - i;

            row[idx] = node->val;

            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
        LtoR = !LtoR;
        result.push_back(row);
    }
}