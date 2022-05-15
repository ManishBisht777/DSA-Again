bool isAnargam(string s, string t)
{

    if (s.size() != t.size())
        return false;
    int count[26] = {0};
    for (auto ch : s)
    {
        count[ch - 'a']++;
    }

    for (auto ch : t)
        if (count[ch - 'a']-- <= 0)
            return false;

    return true;
}

vector<string> removeAnagrams(vector<string> &words)
{

    vector<string> ans;

    ans.push_back(words[0]);

    bool flag = true;

    for (int i = 1; i < words.size(); i++)
    {
        if (!isAnargam(words[i], words[i - 1]))
            ans.push_back(words[i]);
    }
    return ans;
}