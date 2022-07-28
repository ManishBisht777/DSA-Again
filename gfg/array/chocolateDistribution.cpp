long long findMinDiff(vector<long long> a, long long n, long long m)
{
    long long ans = INT_MAX;
    sort(a.begin(), a.end());

    long long i = 0;
    long long j = m - 1;

    while (j < n)
    {
        ans = min(ans, a[j] - a[i]);
        i++;
        j++;
    }
    return ans;
}