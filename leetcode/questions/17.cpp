#include <bits/stdc++.h>

using namespace std;

vector<string> letterCombinations(string digits)
{

    if (digits.empty())
        return {};

    const vector<string> help = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};

    vector<string> result;
    result.push_back("");

    for (auto num : digits)
    {
        vector<string> temp;

        for (auto candidate : help[num - '0'])
        {
            for (auto i : result)
            {
                temp.push_back(i + candidate);
            }
        }

        result.swap(temp);
    }
    return result;
}