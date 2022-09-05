vector<vector<int>> levelOrder(Node *root)
{

    vector<vector<int>> ans;
    if (!root)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        vector<int> lvl;

        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            lvl.push_back(curr->val);

            for (auto child : curr->children)
            {
                q.push(child);
            }
        }
        ans.push_back(lvl);
    }
    return ans;
}