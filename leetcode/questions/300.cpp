
// dp solution
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

// binary search solution

int lengthOfLIS(vector<int> &nums)
{

    vector<int> temp;
    temp.push_back(nums[0]);
    int len = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > temp.back())
            temp.push_back(nums[i]), len++;

        else
        {
            int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();

            temp[idx] = nums[i];
        }
    }

    return len;
}