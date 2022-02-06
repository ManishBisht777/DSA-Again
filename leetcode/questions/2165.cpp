long long smallestNumber(long long n)
{

    bool flag = (n < 0) ? true : false;
    n = abs(n);
    vector<int> a;
    while (n != 0)
    {
        a.push_back(n % 10);
        n = n / 10;
    }
    if (a.size() == 0 || a.size() == 1)
        return n;
    if (flag)
        sort(a.begin(), a.end(), greater<int>());
    else
        sort(a.begin(), a.end());
    int i;
    for (i = 0; i < a.size() && a[i] == 0; i++)
        ;
    swap(a[i], a[0]);
    long long num = 0;
    for (auto i : a)
    {
        num = num * 10 + i;
    }
    if (flag)
        return -num;
    else
        return num;
}