int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                ans = max(ans, areamax(grid, i, j));
            }
        }
    }
    return ans;
}

int areamax(vector<vector<int>> &grid, int i, int j)
{
    if (i >= 0 && i <= grid.size() - 1 && j >= 0 && j <= grid[0].size() - 1 && grid[i][j] == 1)
    {
        grid[i][j] = 0;

        return 1 + areamax(grid, i + 1, j) + areamax(grid, i - 1, j) + areamax(grid, i, j + 1) + areamax(grid, i, j - 1);
    }

    return 0;
}