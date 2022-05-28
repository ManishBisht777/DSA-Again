void dfs(int node, vector<int> &tin, vector<int> &low,
         int parent, vector<vector<int>> &adj,
         vector<bool> &vis,
         vector<vector<int>> &ans)
{
    static int time = 0;
    vis[node] = 1;
    tin[node] = low[node] = time++;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;

        if (!vis[it])
        {
            dfs(it, tin, low, node, adj, vis, ans);
            low[node] = min(low[it], low[node]);
            if (low[it] > tin[node])
                ans.push_back({node, it});
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{

    vector<bool> vis(n, false);
    vector<int> mit(n, 0), low(n, 0);
    vector<vector<int>> adj(n, vector<int>()), ans;

    // make adj list
    for (auto it : connections)
    {
        adj[it.front()].push_back(it.back());
        adj[it.back()].push_back(it.front());
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, mit, low, -1, adj, vis, ans);
        }
    }

    return ans;
}