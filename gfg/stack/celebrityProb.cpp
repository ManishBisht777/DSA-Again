int celebrity(vector<vector<int>> &M, int n)
{
    // code here
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (M[a][b] == 1)
            s.push(b);
        else
            s.push(a);
    }

    int ans = s.top();

    int row = 0, col = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] == 0)
            row++;
    }

    if (row != n)
        return -1;

    for (int i = 0; i < n; i++)
    {
        if (M[i][ans] == 1)
            col++;
    }

    if (col != n - 1)
        return -1;

    return ans;
}

// without stack

int celebrity(vector<vector<int>> &M, int n)
{
    int c = 0;
    for (int i = 1; i < n; i++)
    {
        if (M[c][i] == 1)
        {
            c = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i != c && (M[c][i] == 1 || M[i][c] == 0))
            return (-1);
    }

    return (c);
}