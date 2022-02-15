#include <stack>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            // ch ya toh ')' hai or lowercase letter
            if (ch == ')')
            {
                bool flag = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        flag = false;
                    }
                    st.pop();
                }
                if (flag == true)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}