#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        // Opening Bracket
        if (ch == '(' or ch == '[' or ch == '{')
        {
            st.push(ch);
        }
        // Closing Bracket
        else
        {
            if (!st.empty())
            {
                char Top = st.top();
                if (ch == ')' and Top == '(')
                    st.pop();
                else if (ch == ']' and Top == '[')
                    st.pop();
                else if (ch == '}' and Top == '{')
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
    }

    if (st.empty())
        return true;

    return false;
}

int main()
{
    // string s = "([{}])";
    string s = "([}{])";

    if(isValid(s)) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}