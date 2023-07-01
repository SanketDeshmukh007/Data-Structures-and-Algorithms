#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    int m1[256] = {0};
    int m2[256] = {0};
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (!m1[s[i]] && !m2[t[i]])
        {
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];

        }
        else if (m1[s[i]] != t[i])
            return false;
    }
    return true;
}

int main()
{
    string s = "egg", t = "add";
    bool ans = isIsomorphic(s,t);
    if(ans)
    cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}