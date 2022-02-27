class Solution
{
public:
    int minSteps(string s, string t)
    {

        vector<int> count(26);
        int steps = 0;

        for (int i = 0; i < s.size(); i++)
        {
            count[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++)
        {
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            steps += abs(count[i]);
        }

        return steps;
    }
};