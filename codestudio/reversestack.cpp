void insertatbottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    insertatbottom(s, x);

    s.push(num);
}

void solve(stack<int> &s)
{
    if (s.empty())
        return;
    int num = s.top();
    s.pop();

    solve(s);

    insertatbottom(s, num);
}

void reverseStack(stack<int> &s)
{
    // Write your code here
    solve(s);
}