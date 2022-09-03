vector<int> numsSameConsecDiff(int n, int k)
{

    vector<int> curr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 2; i <= n; i++)
    {
        vector<int> curr2;
        for (int x : curr)
        {
            int lastDigit = x % 10;

            if (lastDigit + k < 10)
                curr2.push_back(x * 10 + lastDigit + k);
            if (lastDigit - k >= 0 && k > 0)
                curr2.push_back(x * 10 + lastDigit - k);
        }

        curr = curr2;
    }
    return curr;
}