int percentageLetter(string s, char letter)
{
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == letter)
            count++;
    }

    int n = s.size();

    return (count * 100) / n;
}