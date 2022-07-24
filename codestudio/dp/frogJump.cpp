int helper(int n, vector<int> &heights, int idx, vector<int> &dp)
{
    if (idx >= n)
        return INT_MAX;
    if (idx == n - 1)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int left = helper(n, heights, idx + 1, dp) + abs(heights[idx] - heights[idx + 1]);

    int right = INT_MAX;
    if (idx < n - 2)
    {
        right = helper(n, heights, idx + 2, dp) + abs(heights[idx] - heights[idx + 2]);
    }

    return dp[idx] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    return helper(n, heights, 0, dp);
}