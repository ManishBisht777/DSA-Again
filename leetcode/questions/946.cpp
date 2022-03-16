bool validatestack(vector<int> &pushed, vector<int> &popped)
{
    int j = 0;
    stack<int> s;

    for (auto i : pushed)
    {
        s.push(i);

        while (!s.empty() && s.top() == popped[i])
        {
            s.pop();
            j++;
        }
    }

    if (s.empty())
        return true;
    return false;
}