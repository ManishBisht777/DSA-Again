void solve(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();
    solve(s, x);

    s.push(num);
}

stack<int> pushAtBottom(stack<int> &s, int x)
{
    // Write your code here.
    solve(s, x);

    return s;
}