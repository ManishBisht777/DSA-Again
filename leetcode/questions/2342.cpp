int maximumSum(vector<int> &nums)
{

    vector<int> digitsum;
    vector<pair<int, int>> count;
    int ans = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        int a = nums[i];
        int sum = 0;
        while (a > 0)
        {
            sum += a % 10;
            a /= 10;
        }

        digitsum.push_back(sum);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        count.push_back({digitsum[i], nums[i]});
    }

    sort(count.begin(), count.end());

    for (int i = 1; i < nums.size(); i++)
    {
        if (count[i].first == count[i - 1].first)
        {
            ans = max(ans, count[i].second + count[i - 1].second);
        }
    }
    return ans;
}