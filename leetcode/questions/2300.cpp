vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{

    vector<int> res;
    sort(potions.begin(), end(potions));

    for (int i = 0; i < spells.size(); i++)
    {
        int ans = 0;
        int l = 0, r = potions.size(), ref = r;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            long long t = (long long)potions[m] * (long long)spells[i];
            if (t >= success)
                r = m;
            else
                l = m + 1;
        }
        res.push_back((ref - r) > 0 ? (ref - r) : 0);
    }
    return res;
}