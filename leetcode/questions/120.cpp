int helper(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (i >= arr.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = arr[i][j] + min(helper(arr, i + 1, j, dp), helper(arr, i + 1, j + 1, dp));
}

int minimumTotal(vector<vector<int>> &arr)
{
    int rows = arr.size();
    vector<vector<int>> dp(rows, vector<int>(rows, -1));
    return helper(arr, 0, 0, dp);
}