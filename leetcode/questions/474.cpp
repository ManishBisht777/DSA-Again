int dp[101][101][601] = {};

int solve(vector<string> &strs, int m, int n, int idx)
{
    if (idx >= strs.size())
        return 0;

    if (m == 0 && n == 0)
        return 0;

    if (dp[m][n][idx] > 0)
        return dp[m][n][idx];

    int zero = 0;
    int one = 0;

    string str = strs[idx];

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '0')
        {
            zero++;
        }
        else
            one++;
    }

    int skip = 0, notskip = 0;

    if (m >= zero && n >= one)
        notskip = 1 + solve(strs, m - zero, n - one, idx + 1);

    skip = solve(strs, m, n, idx + 1);

    return dp[m][n][idx] = max(skip, notskip);
}

int findMaxForm(vector<string> &strs, int m, int n)
{

    return solve(strs, m, n, 0);
}