void combination(vector<vector<int>> &ans, vector<int> &comb, vector<int> candidates, int currsum, int curridx, int target)
{
    if (currsum > target)
        return;

    if (currsum == target)
    {
        ans.push_back(comb);
        return;
    }

    for (int i = curridx, i < candidates.size(); i++)
    {
        comb.push_back(candidates[i]);
        currsum += candidates[i];

        combination(ans, comb, candidates, currsum, curridx, target);

        comb.pop_back();
        currsum -= candidates[i];
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{

    vector<vector<int>> ans;
    vector<int> comb;

    combination(result, comb, candidate, 0, 0, target);

    return ans;
}