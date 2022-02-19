vector<long long> maximumEvenSplit(long long finalSum)
{
    if (finalSum % 2 == 1)
        return {};

    vector<long long> ans;
    long long cur = 2;
    while (cur <= finalSum)
    {
        ans.push_back(cur);
        finalSum -= cur;
        cur += 2;
    }

    ans.back() += finalSum;
    return ans;
}
