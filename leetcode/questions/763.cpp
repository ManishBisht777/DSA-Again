vector<int> partitionLabels(string s)
{
    unordered_map<char, int> mp;

    // max range of character
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        mp[ch] = i;
    }

    vector<int> ans;
    int prev = -1;
    int maxi = 0;

    for (int i = 0; i < s.size(); i++)
    {
        maxi = max(maxi, mp[s[i]]);

        if (maxi == i)
        {
            ans.push_back(maxi - prev);
            prev = i;
        }
    }

    return ans;
}
