vector<vector<int>> dp;

int solve(vector<int> &nums, int i, int prev)
{
    if (i >= nums.size())
        return 0;

    if (dp[i][prev + 1] != -1)
        return dp[i][prev + 1];

    int donttake = solve(nums, i + 1, prev);
    int take = 0;

    if (prev == -1 || nums[i] > nums[prev])
        take = 1 + solve(nums, i + 1, i);

    return dp[i][prev + 1] = max(take, donttake);
}

int lengthOfLIS(vector<int> &nums)
{

    dp.resize(nums.size(), vector<int>(nums.size() + 1, -1));

    return solve(nums, 0, -1);
}