bool compare(val &v1, val &v2)
{
    return (v1.second < v2.second || (v1.second == v2.second && v1.first < v2.first));
}

int maxChainLen(struct val p[], int n)
{
    // Your code here
    sort(p, p + n, compare);

    int ans = 1;
    int prev = p[0].second;

    for (int i = 1; i < n; i++)
    {
        if (p[i].first > prev)
            ans++, prev = p[i].second;
    }

    return ans;
}