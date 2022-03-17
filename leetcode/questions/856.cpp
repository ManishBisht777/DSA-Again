int scoreOfParentheses(string s)
{

    stack<int> s;
    int score = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            s.push(0);
            score = 0;
        }
        else
        {
            score = s.top() + max(score * 2, 1);
            s.pop();
        }
    }

    return score;
}