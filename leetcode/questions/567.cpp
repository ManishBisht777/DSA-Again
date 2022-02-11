bool checkInclusion(string s1, string s2)
{

    int len = s1.size();
    vector<int> count1(26, 0);
    vector<int> count2(26, 0);

    if (s1.size() > s2.size())
        return false;
    if (s1 == s2)
        return true;

    for (int i = 0; i < len; i++)
    {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }
    if (count1 == count2)
        return true;

    int j = 0;
    for (int i = len; i < s2.size(); i++)
    {
        if (count1 == count2)
            return true;

        count2[s2[i] - 'a']++;
        count2[s2[j] - 'a']--;
        j++;

        if (count1 == count2)
            return true;
    }

    return false;
}