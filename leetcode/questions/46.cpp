void helper(vector<vector<int>> &ans, vector<int> num, int pos)
{
    if (pos >= num.size())
    {
        ans.push_back(num);
        return;
    }

    for (int i = pos; i < num.size(); i++)
    {
        swap(num[i], num[pos]);

        helper(ans, num, pos + 1);

        // revert the chanegs
        swap(num[i], num[pos]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{

    vector<vector<int>> result;
    helper(result, nums, 0);

    return result;
}