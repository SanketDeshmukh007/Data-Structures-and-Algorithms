#include <bits/stdc++.h>
using namespace std;

vector<string> subsequence(string s)
{
    int n = s.length();
    vector<string> ans;
    // 2^n = 2^3 = 8 = 1000 = 1 << n

    for (int i = 0; i < (1 << n); i++)
    {
        string temp;
        for (int j = 0; j < n; j++)
        {
            char ch = s[j];
            if (i & (1 << j))
                temp.push_back(ch);
        }
        if (int(temp.length()) >= 0)
            ans.push_back(temp);
    }
    return ans;
}

int main()
{
    vector<string> ans = subsequence("abc");
    for(auto x : ans)
        cout << x << " ";

    return 0;
}