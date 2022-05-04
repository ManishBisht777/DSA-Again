int maxOperations(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    int i = 0, j = nums.size() - 1;
    int cnt = 0;
    while (i < j)
    {
        if (nums[i] + nums[j] == k)
        {
            cnt++;
            i++;
            j--;
        }
        else if (nums[i] + nums[j] < k)
            i++;
        else
            j--;
    }

    return cnt;
}

// T(n) - O(N)
// Space - O(N)

int maxOperations(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    int ans = 0;
    for (auto cur : nums)
    {
        int complement = k - cur;
        if (freq[complement] > 0)
        {
            ans++;
            freq[complement]--;
        }
        else
            freq[cur]++;
    }
    return ans;
}