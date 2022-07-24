int helper(int n, vector<int> &heights, int idx, vector<int> &dp)
{
    if (idx >= n)
        return INT_MAX;
    if (idx == n - 1)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int left = helper(n, heights, idx + 1, dp) + abs(heights[idx] - heights[idx + 1]);

    int right = INT_MAX;
    if (idx < n - 2)
    {
        right = helper(n, heights, idx + 2, dp) + abs(heights[idx] - heights[idx + 2]);
    }

    return dp[idx] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n, 0);
    // return helper(n, heights, 0, dp);

    // base case
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);

        int ss = INT_MAX;
        if (i > 1)
            ss = d[i - 2] + abs(heigths[i] - heights[i - 2]);

        dp[i] = min(fs, ss);
    }

    return dp[n - 1];
}


int frogJump(int n, vector<int> &heights)
{
    
    int prev=0,prev2=0;
    
    for(int i=1; i<n ;i++)
    {
        int fs=prev + abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        
        if(i>1) ss=prev2 + abs(heights[i]-heights[i-2]);
        
        int curr=min(fs,ss);
        prev2=prev;
        prev=curr;
    }
    return prev;
}