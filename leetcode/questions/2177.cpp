vector<long long> sumOfThree(long long num)
{
    vector<long long> ans;

    long long b = num / 3;
    long long a = b - 1;
    long long c = b + 1;

    if (a + b + c == num)
    {
        ans.push_back(a);
        ans.push_back(b);
        ans.push_back(c);
    }
    return ans;
}