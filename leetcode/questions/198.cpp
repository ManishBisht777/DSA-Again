int helper(vector<int> &nums, int idx, vector<int> &dp)
{
    if (idx == nums.size() - 1)
        return nums[idx];
    if (idx >= nums.size())
        return 0;

    if (dp[idx])
        return dp[idx];

    int take = nums[idx] + helper(nums, idx + 2, dp);
    int nottake = helper(nums, idx + 1, dp);

    return dp[idx] = max(take, nottake);
}

int rob(vector<int> &nums)
{

    vector<int> dp(nums.size(), 0);
    // return helper(nums,0,dp);

    int prev = nums[0], prev2 = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        int take = nums[i];
        if (i > 1)
            take += prev2;

        int nottake = prev;

        int curr = max(take, nottake);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}