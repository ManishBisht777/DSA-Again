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

// tabulation

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int take = 0;
        if (i > 1)
            take = nums[i] + dp[i - 2];
        else
            take = nums[i];

        int nottake = dp[i - 1];

        dp[i] = max(take, nottake);
    }
    return dp[nums.size() - 1];
}

// space optimization

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
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