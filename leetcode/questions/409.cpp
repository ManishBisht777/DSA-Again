int longestPalindrome(string s)
{
    int n = s.size();
    int count[100] = {0};
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        count[s[i] - '0']++;
    }

    bool isodd = false;
    for (int i = 0; i < 100; i++)
    {
        ans += count[i] - count[i] % 2;
        if (count[i] % 2 == 1)
            isodd = true;
    }

    if (isodd)
        return ans + 1;
    else
        return ans;
}