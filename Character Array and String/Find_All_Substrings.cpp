#include<bits/stdc++.h>
using namespace std;

vector<string> SubString(string s)
{
    vector<string> ans;
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= n-i; j++)
        ans.push_back(s.substr(i,j));
    }
    return ans;
}

int main()
{
    string s = "abc";
    vector<string> ans = SubString(s);
    for(auto x : ans)
    cout << x << " ";
    return 0;
}