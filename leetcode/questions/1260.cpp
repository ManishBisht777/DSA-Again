vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int newj = (j + k) % m;

            int newi = (i + (j + k) / m) % n;

            ans[newi][newj] = grid[i][j];
        }
    }

    return ans;
}