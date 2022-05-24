int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int previdx = st.top();
        if (previdx != -1 && s[i] == ')' && s[previdx] == '(')
        {
            st.pop();
            ans = max(ans, i - st.top());
        }
        else
            st.push(i);
    }
    return ans;
}