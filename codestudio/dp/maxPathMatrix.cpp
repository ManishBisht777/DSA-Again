// recursion and memo
int maxpath(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp)
{
    if (col < 0 || col >= matrix[0].size())
        return -1e8;

    if (row == 0)
        return matrix[row][col];

    if (dp[row][col])
        return dp[row][col];

    int up = matrix[row][col] + maxpath(matrix, row - 1, col, dp);
    int ld = matrix[row][col] + maxpath(matrix, row - 1, col - 1, dp);
    int rd = matrix[row][col] + maxpath(matrix, row - 1, col + 1, dp);

    return dp[row][col] = max(up, max(ld, rd));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(matrix[0].size(), 0));
    int ans = -1e8;
    for (int i = 0; i < matrix[0].size(); i++)
    {
        int curr = maxpath(matrix, n - 1, i, dp);
        ans = max(ans, curr);
    }

    return ans;
}

// tabulation

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(matrix[0].size(), 0));

    for (int i = 0; i < m; i++)
    {
        dp[0][i] = matrix[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int down = matrix[i][j] + dp[i - 1][j];

            int left = matrix[i][j];
            if (j - 1 >= 0)
                left += dp[i - 1][j - 1];
            else
                left += -1e9;

            int right = matrix[i][j];
            if (j + 1 < m)
                right += dp[i - 1][j + 1];
            else
                right += -1e9;

            dp[i][j] = max(down, max(left, right));
        }
    }

    int maxi = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, dp[n - 1][i]);
    }

    return maxi;
}

// space optimization

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m, 0), curr(m, 0);

    for (int i = 0; i < m; i++)
    {
        prev[i] = matrix[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int down = matrix[i][j] + prev[j];

            int left = matrix[i][j];
            if (j - 1 >= 0)
                left += prev[j - 1];
            else
                left += -1e9;

            int right = matrix[i][j];
            if (j + 1 < m)
                right += prev[j + 1];
            else
                right += -1e9;

            curr[j] = max(down, max(left, right));
        }
        prev = curr;
    }

    int maxi = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, prev[i]);
    }

    return maxi;
}