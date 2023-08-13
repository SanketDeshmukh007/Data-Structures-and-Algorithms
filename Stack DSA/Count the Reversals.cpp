#include <bits/stdc++.h>
using namespace std;

int countRev(string s)
{
    if (s.size() & 1)
        return -1;

    int count = 0;
    int n = s.length();

    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        char curr = s[i];

        if (curr == '{')
            st.push(curr);
        else
        {
            if (!st.empty() and st.top() == '{')
                st.pop();
            else
                st.push(curr);
        }
    }

    while (!st.empty())
    {
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();

        if ((a == '{' and b == '{') or (a == '}' and b == '}'))
            count += 1;
        else
            count += 2;
    }
    return count;
}

int main()
{
    cout << countRev("}{{}}{{{") << endl;

    return 0;
}