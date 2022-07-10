int fillCups(vector<int> &a)
{
    int ans = 0;
    while (1)
    {
        sort(a.begin(), a.end());
        if (a.back() <= 0)
            break;
        --a[1], --a[2];
        ++ans;
    }
    return ans;
}