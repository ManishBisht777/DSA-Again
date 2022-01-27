bool wordPattern(string pattern, string s)
{
    unordered_map<char, int> patternmap;
    unordered_map<string, int> wordmap;

    string word;
    int i = 0;
    int n = pattern.size();

    istringstream in(s);

    for (word; in >> word; i++)
    {
        if (i == n || patternmap[pattern[i]] != wordmap[word])
            return false;

        patternmap[pattern[i]] = wordmap[word] = i + 1;
    }

    return i == n;
}