int helper(vector<vector<int>> &triangle, int x, int y, vector<vector<int>> &dp)
{
    if (x >= triangle.size() || y >= triangle[x].size())
        return 0;

    if (dp[x][y])
        return dp[x][y];

    int down = triangle[x][y] + helper(triangle, x + 1, y, dp);
    int diag = triangle[x][y] + helper(triangle, x + 1, y + 1, dp);

    return dp[x][y] = min(down, diag);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n, 0));
    return helper(triangle, 0, 0, dp);
}

// tabulation

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n, 0));
    //     return helper(triangle,0,0,dp);

    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diag = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diag);
        }
    }
}

// space optimization

int minimumPathSum(vector<vector<int>> &triangle, int n)
{

    vector<int> front(n, 0), curr(n, 0);

    for (int j = 0; j < n; j++)
    {
        front[j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + front[j];
            int diag = triangle[i][j] + front[j + 1];

            curr[j] = min(down, diag);
        }
        front = curr;
    }

    return front[0];
}
