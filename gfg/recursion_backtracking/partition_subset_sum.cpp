void helper(int arr[], int n, int idx, int sum1, int sum2, int &ans)
{
    if (sum1 == sum2)
    {
        ans += 1;
        return;
    }

    if (idx < 0 || idx >= n || sum1 > sum2)
        return;

    sum1 += arr[idx];
    helper(arr, n, idx + 1, sum1, sum2, ans);

    sum1 -= arr[idx];
    helper(arr, n, idx + 1, sum1, sum2, ans);
}

int equalPartition(int n, int arr[])
{
    // code here
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum2 += arr[i];
    }

    if (sum2 % 2 != 0)
        return 0;

    sum2 = sum2 / 2;

    int ans = 0;

    helper(arr, n, 0, 0, sum2, ans);

    if (ans == 0)
        return 0;

    return 1;
}