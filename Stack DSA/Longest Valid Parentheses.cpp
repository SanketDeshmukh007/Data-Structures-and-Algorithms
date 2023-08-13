#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int maxLength = 0;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        char curr = s[i];

        if (curr == '(')
            st.push(i);
        else
        {
            st.pop();

            if (st.empty())
                st.push(i);
            else
            {
                int length = i - st.top();
                maxLength = max(maxLength, length);
            }
        }
    }
    return maxLength;
}

int main()
{
    string s = ")()())";

    cout << "MaxLength: " << longestValidParentheses(s) << endl;

    return 0;
}