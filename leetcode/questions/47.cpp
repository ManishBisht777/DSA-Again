void helper(vector<vector<int>> &ans, vector<int> curr, unordered_map<int, int> &counter, int size)
{
    if (curr.size() == size)
    {
        ans.push_back(curr);
        return;
    }

    for (auto [key, value] : counter)
    {
        if (value == 0)
            continue;

        curr.push_back(key);
        counter[key]--;

        helper(ans, curr, counter, size);

        curr.pop_back();
        counter[key]++;
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> curr;

    unordered_map<int, int> counter;

    for (auto i : nums)
    {
        counter[i]++;
    }

    helper(ans, curr, counter, nums.size());

    return ans;
}