static bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}

int maxEnvelopes(vector<vector<int>> &env)
{
    int n = env.size();

    sort(env.begin(), env.end(), cmp);

    vector<int> lis;
    int len = 1;
    lis.push_back(env[0][1]);

    for (int i = 1; i < env.size(); i++)
    {
        int ele = env[i][1];

        if (ele > lis.back())
            lis.push_back(ele), len++;

        else
        {
            int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();
            lis[idx] = ele;
        }
    }

    return len;
}