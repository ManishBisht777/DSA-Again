vector<int> numberOfPairs(vector<int> &nums)
{

    vector<int> count(101, 0);
    vector<int> ans(2, 0);

    for (int i = 0; i < nums.size(); i++)
    {
        count[nums[i]]++;
    }

    for (int i = 0; i < count.size(); i++)
    {
        ans[0] += count[i] / 2;
        ans[1] += count[i] % 2;
    }

    return ans;
}