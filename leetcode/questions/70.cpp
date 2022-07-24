int helper(int n, int i, vector<int> &dp)
{
    if (i > n)
        return 0;
    if (i == n)
        return 1;

    if (dp[i])
        return dp[i];

    return dp[i] = helper(n, i + 1, dp) + helper(n, i + 2, dp);
}

int climbStairs(int n)
{

    vector<int> dp(n, 0);
    return helper(n, 0, dp);
}