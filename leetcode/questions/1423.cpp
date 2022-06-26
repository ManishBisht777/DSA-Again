
// dp tle

int helper(vector<int> &arr, int k, int i, int j, int sum, vector<vector<int>> &dp)
{
    if (k == 0)
        return sum;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = max(helper(arr, k - 1, i + 1, j, sum + arr[i], dp), helper(arr, k - 1, i, j - 1, sum + arr[j], dp));
}

int maxScore(vector<int> &arr, int k)
{

    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));

    return helper(arr, k, 0, arr.size() - 1, 0, dp);
}

// sliding window

int maxScore(vector<int> &arr, int k)
{

    int ans = 0;
    int n = arr.size();

    for (int i = n - k; i < n; i++)
    {
        ans += arr[i];
    }

    int curr = ans;

    for (int i = 0; i < k; i++)
    {
        curr += arr[i];
        curr -= arr[arr.size() - k + i];

        ans = max(ans, curr);
    }

    return ans;
}