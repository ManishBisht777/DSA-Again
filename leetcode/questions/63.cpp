int uniquePathsWithObstacles(vector<vector<int>> &obs)
{

    vector<vector<int>> dp(obs.size(), vector<int>(obs[0].size()));
    return solve(dp, obs, 0, 0);
}

int solve(vector<vector<int>> &dp, vector<vector<int>> &obs, int i, int j)
{
    if (i >= obs.size() || j >= obs[0].size())
        return 0;

    if (obs[i][j])
        return dp[i][j] = 0;

    if (j == obs[0].size() - 1 && i == obs.size() - 1 && !obs[i][j])
        return 1;

    if (dp[i][j])
        return dp[i][j];

    dp[i][j] = solve(dp, obs, i + 1, j) + solve(dp, obs, i, j + 1);
    return dp[i][j];
}