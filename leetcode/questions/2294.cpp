int partitionArray(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    int ans = 1, prev = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] - nums[prev] <= k)
            continue;
        ans++;
        prev = i;
    }

    return ans;
}