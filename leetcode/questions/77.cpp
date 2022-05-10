void combination(vector<vector<int>> &result, vector<int> &comb, int curridx, int n, int k)
{
    if (comb.size() == k)
    {
        result.push_back(comb);
        return;
    }

    for (int i = curridx; i <= n; i++)
    {
        comb.push_back(i);

        combination(result, comb, i + 1, n, k);

        comb.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> result;
    vector<int> comb;

    combination(result, comb, 1, n, k);

    return result;
}