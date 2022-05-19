int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> dp;

int solve(vector<vector<int>> &matrix, int i, int j)
{
    if (dp[i][j])
        return dp[i][j];

    dp[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
        int newi = i + moves[k][0];
        int newj = j + moves[k][1];

        if (newi < 0 || newj < 0 || newi >= matrix.size() || newj >= matrix[0].size() || matrix[i][j] >= matrix[newi][newj])
            continue;

        dp[i][j] = max(dp[i][j], 1 + solve(matrix, newi, newj));
    }

    return dp[i][j];
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int maxpath = INT_MIN;

    dp.resize(matrix.size(), vector<int>(matrix[0].size()));

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            maxpath = max(maxpath, solve(matrix, i, j));
        }
    }

    return maxpath;
}