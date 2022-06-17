int toyCount(int n, int k, vector<int> arr)
{
    // code here
    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            ans++;
            k -= arr[i];
        }
    }

    return ans;
}