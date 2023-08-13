#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s)
{
    string ans;
    stack<char> st;

    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        char curr = s[i];

        if (!st.empty() and st.top() == curr)
        {
            st.pop();
        }
        else
            st.push(curr);
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    cout << removeDuplicates("abbaca") << endl;

    return 0;
}