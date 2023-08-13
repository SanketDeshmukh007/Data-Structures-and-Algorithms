#include<bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    bool ans = false;
    int n = s.length();
    stack<char> st;

    for(int i = 0; i < n; i++)
    {
        char ch = s[i];

        if(ch == '(')
        st.push(ch);
        else if(ch == '+' or ch == '-' or ch == '*' or ch == '/')
        st.push(ch);
        else if(ch == ')')
        {
            if(st.top() == '(')
            ans = true;

            while(!st.empty() and st.top() != '(')
            st.pop();

            st.pop();
        }
    }
    return ans;
}

int main()
{
    string s = "(a + b * c) + (d))";

    if(findRedundantBrackets(s))
    cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}