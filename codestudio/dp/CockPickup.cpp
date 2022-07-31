
// recursion nand memoiazation

int maxcherry(vector<vector<int>> &grid, int i, int j1, int j2, int row, int col, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 >= col || j2 >= col)
        return -1e8;

    if (i == row - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2])
        return dp[i][j1][j2];

    int maxi = -1e8;

    for (int dj1 = -1; dj1 <= +1; dj1++)
    {
        for (int dj2 = -1; dj2 <= +1; dj2++)
        {
            int val = 0;
            if (j1 == j2)
                val = grid[i][j1];
            else
                val = grid[i][j1] + grid[i][j2];

            val += maxcherry(grid, i + 1, dj1 + j1, dj2 + j2, row, col, dp);
            maxi = max(maxi, val);
        }
    }

    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
    return maxcherry(grid, 0, 0, c - 1, r, c, dp);
}

// tabulation

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
    //     return maxcherry(grid,0,0,c-1,r,c,dp);

    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            else
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= +1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= +1; dj2++)
                    {
                        int val = 0;
                        if (j1 == j2)
                            val = grid[i][j1];
                        else
                            val = grid[i][j1] + grid[i][j2];

                        if (dj1 + j1 >= 0 && dj1 + j1 < c && dj2 + j2 >= 0 && dj2 + j2 < c)
                            val += dp[i + 1][dj1 + j1][dj2 + j2];
                        else
                            val += 1e9;
                        maxi = max(maxi, val);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][c - 1];
}