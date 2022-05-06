void markparent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (curr->left)
        {
            q.push(curr->left);
            parent[curr->left] = curr;
        }
        if (curr->right)
        {
            q.push(curr->right);
            parent[curr->right] = curr;
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parent;
    markparent(root, parent);

    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;

    int lvl = 0;
    while (!q.empty())
    {
        int n = q.size();
        if (lvl == k)
            break;
        lvl++;

        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left && !visited[node->left])
            {
                q.push(node->left);
                visited[node->left] = true;
            }
            if (node->right && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right] = true;
            }
            if (parent[node] && !visited[parent[node]])
            {
                q.push(parent[node]);
                visited[parent[node]] = true;
            }
        }
    }

    vector<int> result;
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        result.push_back(node->val);
    }

    return result;
}