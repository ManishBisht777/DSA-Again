class Solution
{
public:
    char findTheDifference(string s, string t)
    {

        char r = 0;
        for (char i : s)
            r = r ^ i;
        for (char j : t)
            r = r ^ j;

        return r;
    }
};