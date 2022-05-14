// dfs approach

bool chkcycle(vector<int> adj[], vector<int> &vis, int curr, int parent)
{
    vis[curr] = 1;

    for (auto it : adj[curr])
    {
        if (!vis[it])
        {
            if (chkcycle(adj, vis, it, curr))
                return true;
        }
        else if (it != parent)
            return true;
    }

    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (chkcycle(adj, vis, i, -1))
                return true;
        }
    }

    return false;
}