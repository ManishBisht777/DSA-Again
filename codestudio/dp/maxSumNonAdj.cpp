int helper(vector<int> &nums, int idx, vector<int> &dp)
{
    if (idx >= nums.size())
        return 0;

    if (dp[idx])
        return dp[idx];

    int pick = nums[idx] + helper(nums, idx + 2, dp);
    int notpick = helper(nums, idx + 1, dp);

    return dp[idx] = max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    vector<int> dp(nums.size(), 0);
    int ans = helper(nums, 0, dp);
    return ans;
}