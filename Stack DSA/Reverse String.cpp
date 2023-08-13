#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char> &s)
{
    stack<char> st;
    for (auto x : s)
        st.push(x);

    while (s.size())
        s.pop_back();

    while (!st.empty())
    {
        int ele = st.top();
        s.push_back(ele);
        st.pop();
    }
}

int main()
{
    vector<char> s = {'h','e','l','l','o'};
    for(auto x : s)
    cout << x;
    cout << endl;
    reverseString(s);
    for(auto x : s)
    cout << x;
    cout << endl;

    return 0;
}