// Giving TLE

void helper(vector<string> vowel, vector<string> &temp, int idx, int &cnt, int n)
{
    if (temp.size() == n)
    {
        cnt++;
        return;
    }

    for (int i = idx; i < vowel.size(); i++)
    {
        temp.push_back(vowel[i]);

        helper(vowel, temp, i, cnt, n);

        temp.pop_back();
    }
}

int countVowelStrings(int n)
{
    vector<string> vowel = {"a", "e", "i", "o", "u"};
    vector<string> temp;
    int cnt = 0;

    helper(vowel, temp, 0, cnt, n);

    return cnt;
}

// Optimised Sol

int countVowelStrings(int n)
{
    int a = 1, e = 1, i = 1, o = 1, u = 1;

    while (--n)
    {
        o += u;
        i += o;
        e += i;
        a += e;
    }

    return a + e + i + o + u;
}