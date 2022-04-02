vector<int> topView(Node *root)
{
    vector<int> ans;

    map<int, int> mp;
    queue<pair<Node *, int>> todo;

    todo.push({root, 0});

    while (!todo.empty())
    {
        auto it = todo.front();
        todo.pop();

        Node *node = it.first;
        int line = it.second;

        mp[line] = node->data;

        if (node->left)
            todo.push({node->left, line - 1});
        if (node->right)
            todo.push({node->right, line + 1});
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}